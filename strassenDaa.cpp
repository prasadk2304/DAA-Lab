#include<iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], c[2][2], i, j;
    int p, q, r, s, t, u, v;

    // Prompt user to enter elements of the first matrix
    cout << "Enter the four elements of the first matrix: ";
    cout << "\n";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }

    // Prompt user to enter elements of the second matrix
    cout << "\n";
    cout << "Enter the four elements of the second matrix: ";
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cin >> b[i][j];
        }
    }

    cout << "\n";
    cout << "The first matrix is:";

    // Display the first matrix
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "\t\n" << a[i][j];
        }
    }

    cout << "\n";
    cout << "The second matrix is:";

    // Display the second matrix
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "\t\n" << b[i][j];
        }
    }

    // Strassen's algorithm
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = (a[1][0] + a[1][1]) * (b[0][0]);
    r = (a[0][0]) * (b[0][0] - b[1][1]);
    s = (a[1][1]) * (b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1]) * (b[1][1]);
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    // Resultant matrix
    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p - q + r + u;

    cout << "\nStrassen's algorithm";
    cout << "\n";
    // Display the resultant matrix
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "\t\n" << c[i][j];
        }
    }

    return 0;
}
