#include <bits/stdc++.h>

using namespace std;

/*
Input:
1
6 9 1 6
1 2
1 3
2 3
2 5
3 4
3 5
4 5
4 6
5 6

Output:
1 2 5 6
*/

bool OK;
string res;
int v, e, s, t;
bool visited[1005];
vector<int> adj[1005];

void reInit()
{
    res = "";
    OK = false;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 1005; i++) adj[i].clear();
}

void BFS(int a) {
    queue<pair<int, string>> q;
    q.push({ a, to_string(a) });
    while (!q.empty())
    {
        pair<int, string> fr = q.front();
        q.pop();
        visited[fr.first] = true;
        for (auto b : adj[fr.first])
        {
            if (!visited[b])
            {
                visited[b] = true;
                if (b == t)
                {
                    OK = true;
                    res = fr.second + " " + to_string(b);
                }
                q.push({ b, fr.second + " " + to_string(b) });
            }
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        reInit();

        cin >> v >> e >> s >> t;
        for (int i = 1; i <= e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        BFS(s);
        if (!OK) cout << -1;
        else cout << res;
        cout << '\n';
    }
    return 0;
}
