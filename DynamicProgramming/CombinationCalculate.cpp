#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
5 2
10 3

Output:
10
120
*/

long long C[1001][1001];
int mod = 1e9 + 7;

void Init()
{
	for(int i = 0; i <= 1000; ++i)
	{
		for(int j = 0; j <= i; ++j)
		{
			if(j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
}

int main()
{
	Init();
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cout << C[n][k] << '\n';
	}
	return 0;
}