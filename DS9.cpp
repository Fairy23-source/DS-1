#include <iostream>
#include <queue>
using namespace std;

int graph[10][10], visited[10], n;

// Depth First Search (DFS)
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Breadth First Search (BFS)
void BFS(int start)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;

    return 0;
}