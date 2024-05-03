#include<iostream>
using namespace std;
#define MAX 100
#define initial 1
#define visited 2

// Global variables
int n;                          
int adj[MAX][MAX];              
int state[MAX];                 
int stack[MAX];                 
int top=-1;                     
// Function prototypes
void push(int v);               
int pop();                      
void crtgraph();                
void dfstravers();              
void dfs(int v);                
int isempty_stack();           

int main() 
{
    crtgraph();    
    dfstravers();             
    return 0;
}
void dfstravers() 
{
    int v;
    // Initialize all vertices as unvisited
    for(v=0;v<n;v++)
        state[v] = initial;

    // Take input for starting vertex
    cout << "Enter starting vertex for depth-first search: ";
    cin >> v;
// Start DFS traversal from the given vertex   
    dfs(v);                     
}
void dfs(int v) 
{
    int i;
    push(v);                

    while (!isempty_stack())    // While stack is not empty
    {
        v = pop();              // Pop a vertex from the stack
        if(state[v]==initial)   // If the vertex is unvisited
        {
            cout << v << " ";   // Print the vertex
            state[v] = visited; // Mark the vertex as visited
        }
        
// Traverse the adjacency matrix of vertex v
        for (i = n-1; i >=0 ; i--) 
        {
// If there is an edge from v to i and i is unvisited, push i onto the stack
            if (adj[v][i] == 1 && state[i] == initial) 
                push(i);
        }
    }
}
void crtgraph() 
{
    int i, max_edges, origin, destin ;
    // Input the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;
    // Calculate the maximum number of edges
    max_edges = n * (n - 1);
    // Initialize the adjacency matrix
    for (i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            adj[i][j] = 0;
        }
    }
    // Input the edges of the graph
    for (i = 1; i <= max_edges; i++) 
    {
        cout << "Enter edge (-1 -1 to quit): ";
        cin >> origin >> destin;
        if (origin == -1 && destin == -1)
            break;
        if (origin == -1 || destin >= n || origin < 0 || destin < 0) 
        {
            cout << "Invalid edge.\n";
            i--;
        }
        else
            adj[origin][destin] = 1;    
            // Mark the edge in the adjacency matrix
    }
}
void push(int v) 
{
    if (top >= (MAX-1)) // Check for stack overflow
    {
        cout << "stack overflow\n";
        return;
    }
    
    top = top + 1;
    stack[top] = v;     
}
int pop() 
{
    int v;
    if(top == -1)
    {
        cout << "stack is underflow\n";
        // Fix: return an error code instead of exit(1)
        return -1;
    }
    else
    {
        v = stack[top];    
        top = top - 1;
        return v;
    }
}
int isempty_stack() 
{
    if (top == -1)     
        return 1;
    else
        return 0;
}

