#include <bits/stdc++.h>

using namespace std;

/*
Input:
1
5 6 
1 2 
1 3 
2 3 
3 4 
3 5 
4 5

Output:
1
*/

bool visited[1005];
vector<int> adj[1005];

void DFS(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v]) DFS(v);
    }
}

int findComps(int v)
{
    int numberOfComps = 0;
    for(int i = 1; i <= v; ++i)
    {
        if(!visited[i])
        {
            ++numberOfComps;
            DFS(i);
        }
    }
    return numberOfComps;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 1005; ++i) adj[i].clear();
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= e; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout << findComps(v) << '\n';
    }
    return 0;
}