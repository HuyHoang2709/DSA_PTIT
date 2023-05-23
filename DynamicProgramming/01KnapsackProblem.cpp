#include <bits/stdc++.h>

using namespace std;

/*
Input:
1
15 10
5 2 1 3 5 2 5 8 9 6 3 1 4 7 8
1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

Output:
15
*/

int n, M;
int w[1005];
int v[1005];
int c[1005][1005];

int dp()
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= M; ++j)
		{
			c[i][j] = c[i-1][j];
			if(j >= w[i])
			{
				c[i][j] = max(c[i][j], c[i-1][j-w[i]] + v[i]);	
			}	
		}	
	}
	return c[n][M];	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> M;
		for(int i = 1; i <= n; ++i) cin >> w[i];
		for(int i = 1; i <= n; ++i) cin >> v[i];
		cout << dp() << '\n';
	}
	return 0;
}