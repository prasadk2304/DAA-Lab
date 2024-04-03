#include <iostream>
using namespace std;

#define MAX 100
#define infty 9999
#define NIL -1
#define TRUE 1
#define FALSE 0

// Global variables
int n, front, rear;
int adj[MAX][MAX];
int prede[MAX];
int pl[MAX];
int ispqueue[MAX], queue[MAX];

// Function prototypes
void intlqueue();
void insrtqueue(int u);
int dltqueue();
int emptqueue();
void cretgraph();
void fndpath(int s, int v);
int bellman(int s);

int main() {
    int flag, s, v;
    cretgraph();
    cout << "Enter source vertex : ";
    cin >> s;
    flag = bellman(s);
    if(flag == -1) {
        cout << "Error : Negative cycle in graph" << endl;
        exit(1);
    }
    while(true) {
        cout << "Enter destination vertex : ";
        cin >> v;
        if(v == -1)
            break;
        if(v < 0 || v >= n)
            cout << "This vertex doesn't exist" << endl;
        else if(v == s)
            cout << "Source and destination vertex are the same" << endl;
        else if(pl[v] == infty)
            cout << "There is no path from source to destination" << endl;
        else
            fndpath(s, v);
    }
    return 0;
}

// Function to find the shortest path from source to destination
void fndpath(int s, int v) {
    int i, u, path[MAX], shortdist = 0, count = 0;
    while(v != s) {
        count++;
        path[count] = v;
        u = prede[v];
        shortdist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;
    cout << "Shortest path is : ";
    for(i = count; i >= 1; i--)
        cout << path[i] << endl;
    cout << "Shortest dist. is : " << shortdist;
}

// Function to perform Bellman-Ford algorithm
int bellman(int s) {
    int k = 0, i, current;
    for(i = 0; i < n; i++) {
        prede[i] = NIL;
        pl[i] = infty;
        ispqueue[i] = FALSE;
    }
    intlqueue();
    pl[s] = 0; 
    insrtqueue(s);
    ispqueue[s] = TRUE;
    while(!emptqueue()) {
        current = dltqueue();
        ispqueue[current] = FALSE;
        if(s == current)
            k++;
        if(k > n)
            return -1; 
        for(i = 0; i < n; i++) {
            if(adj[current][i] != 0)
                if(pl[i] > pl[current] + adj[current][i]) {
                    pl[i] = pl[current] + adj[current][i];
                    prede[i] = current;
                    if(!ispqueue[i]) {
                        insrtqueue(i);
                        ispqueue[i] = TRUE;
                    }
                }
        }
    }
    return 1;
}

// Function to initialize the queue
void intlqueue() {
    for(int i = 0; i < MAX; i++)
        queue[i] = 0;
    rear = -1;
    front = -1;
}

// Function to check if queue is empty
int emptqueue() {
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Function to insert element into the queue
void insrtqueue(int added_item) {
    if(rear == MAX - 1) {
        cout << "Queue Overflow" << endl;
        exit(1);
    }
    else {
        if(front == -1)
            front = 0; 
        rear = rear + 1; 
        queue[rear] = added_item;
    }
}

// Function to delete element from the queue
int dltqueue() {
    int d;
    if(front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        exit(1);
    }
    else {
        d = queue[front]; 
        front = front + 1;
    }
    return d; 
}

// Function to create graph
void cretgraph() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
}
