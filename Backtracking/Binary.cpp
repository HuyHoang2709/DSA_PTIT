#include <bits/stdc++.h>

using namespace std;

int n;
int B[30];

void print()
{
	for(int i = 1; i <= n; ++i) cout << B[i] << ' ';
	cout << '\n';
}

void Try(int i)
{
	for(int j = 0; j <= 1; ++j)
	{
		B[i] = j;
		if(i == n) print();
		else Try(i+1);
	}
}

int main()
{
	cin >> n;
	Try(1);
}