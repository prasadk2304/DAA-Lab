#include<iostream>
using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;                      
int adj[MAX][MAX];       
int state[MAX];          
int queue[MAX], front = -1, rear = -1;  

// Function prototypes
void create_graph();       
void BF_traversal();     
void bfs(int v);         
void insert_queue(int vertex); 
int delete_queue();      
int isempty_queue();    

int main() {
    create_graph();        
    BF_traversal();    
    return 0;
}
// Function to createthe graph
void create_graph() {
    int i, max_edges, origin, destin;
    cout << "Enter number of vertices: ";
    cin >> n;
    max_edges = n * (n - 1);
    for (i = 0; i < max_edges; i++) {
        cout << "Enter edge (-1 -1 to quit): ";
        cin >> origin >> destin;
        if ((origin == -1) && (destin == -1))
            break;
        adj[origin][destin] = 1;
    }
}
// Function to perform BFS traversal
void BF_traversal() {
    int v;
    cout << "Enter starting vertex for breadth-first search: ";
    cin >> v;
    for (int i = 0; i < n; i++)
        state[i] = initial; 
    bfs(v);           
}
// Function for actual BFS traversal
void bfs(int v) {
    int i;
    insert_queue(v);        
    state[v] = waiting;     // Mark it as waiting
    while (!isempty_queue()) {
        v = delete_queue(); 
        cout << v << " ";   
        state[v] = visited; 
        for (i = 0; i < n; i++) {
            // For each adjacent vertex, if it's unvisited, insert it into the queue
            if (adj[v][i] == 1 && state[i] == initial) {
                insert_queue(i);
                state[i] = waiting; // Mark it as waiting
            }
        }
    }
    cout << endl;
}
// Function to insert into the queue
void insert_queue(int vertex) {
    if (rear == MAX - 1)
        cout << "queue is overflow:";  // Overflow condition
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;   
    }
}
// Function to check if the queue is empty
int isempty_queue() {
    if (front == -1 || front > rear)
        return 1;   // Queue is empty
    else
        return 0;   // Queue is not empty
}
// Function to delete from the queue
int delete_queue() {
    int del_item;
    if (front == -1 || front > rear) {
        cout << "queue is underflow:"; 
        exit(1);
    }
    del_item = queue[front];    
    front = front + 1;
    return del_item;
}
