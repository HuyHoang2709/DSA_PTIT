#include <bits/stdc++.h>

using namespace std;

/*
Input:
1
6 9
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6

Output:
1 2 3 4 5 6
*/

bool visited[1005];
vector<int> adj[1005];

void DFS(int u)
{
    stack<int> st;
    st.push(u);
    cout << u << ' ';
    visited[u] = true;
    while(!st.empty())
    {
        int t = st.top(); st.pop();
        for(int v : adj[t])
        {
            if(!visited[v])
            {
                cout << v << ' ';
                visited[v] = true;
                st.push(t);
                st.push(v);
                break;
            }
        }
    }
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
        DFS(1);
        cout << '\n';
    }
    return 0;
}