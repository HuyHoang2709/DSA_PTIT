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
1 2 3 4 5 6
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

void DFS(int a, string str) {
    visited[a] = true;
    for (auto b : adj[a]) {
        if (!visited[b]) {
            if (b == t) {
                OK = true;
                res = str + " " + to_string(b);
            }
            DFS(b, str + " " + to_string(b));
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

        DFS(s, to_string(s));
        if (!OK) cout << -1;
        else cout << res;
        cout << '\n';
    }
    return 0;
}
