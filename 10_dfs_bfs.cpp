#include <iostream>
using namespace std;

const int V = 6;
const int MAX = 100;

struct AdjNode
{
    int dest;
    AdjNode* next;
};

AdjNode* adj[V];
bool visited[V];

void addEdge(int u, int v)
{
    if (u < 0 || u >= V || v < 0 || v >= V)
    {
        cout << "Invalid edge (" << u << ", " << v << ")\n";
        return;
    }

    AdjNode* n = new AdjNode();
    n->dest = v;
    n->next = adj[u];
    adj[u] = n;

    AdjNode* m = new AdjNode();
    m->dest = u;
    m->next = adj[v];
    adj[v] = m;
}

// --- BFS using manual queue ---

int bfsQueue[MAX];
int bFront = 0;
int bRear = 0;

void bfsEnqueue(int x)
{
    if (bRear == MAX)
    {
        cout << "BFS Queue Overflow\n";
        return;
    }

    bfsQueue[bRear++] = x;
}

int bfsDequeue()
{
    if (bFront == bRear)
    {
        cout << "BFS Queue Underflow\n";
        return -1;
    }

    return bfsQueue[bFront++];
}

bool bfsEmpty()
{
    return bFront == bRear;
}

void bfs(int start)
{
    if (start < 0 || start >= V)
    {
        cout << "Invalid start vertex\n";
        return;
    }

    for (int i = 0; i < V; i++) visited[i] = false;
    bFront = bRear = 0;

    visited[start] = true;
    bfsEnqueue(start);

    cout << "BFS: ";

    while (!bfsEmpty())
    {
        int v = bfsDequeue();
        cout << v << " ";

        AdjNode* n = adj[v];
        while (n)
        {
            if (!visited[n->dest])
            {
                visited[n->dest] = true;
                bfsEnqueue(n->dest);
            }
            n = n->next;
        }
    }

    cout << "\n";
}

// --- DFS using manual stack ---

int dfsStack[MAX];
int dfsTop = -1;

void dfsPush(int x)
{
    if (dfsTop == MAX - 1)
    {
        cout << "DFS Stack Overflow\n";
        return;
    }

    dfsStack[++dfsTop] = x;
}

int dfsPop()
{
    if (dfsTop == -1)
    {
        cout << "DFS Stack Underflow\n";
        return -1;
    }

    return dfsStack[dfsTop--];
}

bool dfsEmpty()
{
    return dfsTop == -1;
}

void dfs(int start)
{
    if (start < 0 || start >= V)
    {
        cout << "Invalid start vertex\n";
        return;
    }

    for (int i = 0; i < V; i++) visited[i] = false;
    dfsTop = -1;

    dfsPush(start);

    cout << "DFS: ";

    while (!dfsEmpty())
    {
        int v = dfsPop();

        if (visited[v]) continue;
        visited[v] = true;
        cout << v << " ";

        AdjNode* n = adj[v];
        while (n)
        {
            if (!visited[n->dest])
                dfsPush(n->dest);
            n = n->next;
        }
    }

    cout << "\n";
}

int main()
{
    for (int i = 0; i < V; i++) adj[i] = nullptr;

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    bfs(0);
    dfs(0);

    bfs(10);  // invalid vertex
    return 0;
}
