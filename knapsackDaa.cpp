#include<iostream>
using namespace std;

void knapsack(int n, float wt[], float pft[], float capy) {
    float x[20], tp = 0;
    int i, j, u;
    u = capy;

    // Initialize decision variables
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Greedily select items
    for (i = 0; i < n; i++) {
        if (wt[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + pft[i];
            u = u - wt[i];
        }
    }
    if (i < n)
        x[i] = u / wt[i];
    tp = tp + (x[i] * pft[i]);

    // Output the result vector
    cout << "The result vector is: " << endl;
    for(i = 0; i < n; i++)
        cout << x[i];

    // Output maximum profit
    cout << "Maximum profit is: " << tp << endl;
}

int main() {
    float wt[20], pft[20], capy;
    int num, i, j;
    float ratio[20], temp;

    // Input number of objects
    cout << "Enter the no. of objects: ";
    cin >> num;

    // Input weights and profits of each object
    cout << "Enter the wts and profits of each object: " << endl; 
    for (i = 0; i < num; i++) {
        cin >> wt[i] >> pft[i];
    }

    // Input capacity of knapsack
    cout << "Enter the capacity of knapsack: ";
    cin >> capy;
    cout << endl;

    // Calculate profit-to-weight ratio
    for(i = 0; i < num; i++) {
        ratio[i] = pft[i] / wt[i];
    }

    // Sort items based on profit-to-weight ratio in non-increasing order
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = wt[j];
                wt[j] = wt[i];
                wt[i] = temp;
                temp = pft[j];
                pft[j] = pft[i];
                pft[i] = temp;
            }
        }
    }

    // Solve knapsack problem
    knapsack(num, wt, pft, capy);

    return 0;
}
