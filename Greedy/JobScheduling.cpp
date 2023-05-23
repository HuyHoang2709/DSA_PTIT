#include <bits/stdc++.h>

using namespace std;

/*
Input:
8
1 3 0 5 8 5 9 14
2 4 6 7 9 9 12 18

Output:
1 2 4 5 7 8
*/

struct Job
{
	int start;
	int finish;
};

int i;
int n;
Job a[20];
vector<int> ans;

bool cmp(Job &x, Job &y)
{
	return x.finish < y.finish;
}

void Init()
{
	cin >> n;
	for(int j = 1; j <= n; ++j) cin >> a[j].start;
	for(int j = 1; j <= n; ++j) cin >> a[j].finish;
	
	sort(a + 1, a + n + 1, cmp);
	ans.push_back(1);
	i = 1;
}

void Greedy()
{
	for(int j = 2; j <= n; ++j)
	{
		if(a[j].start >= a[i].finish)
		{
			ans.push_back(j);
			i = j;
		}
	}
}

int main()
{
	Init();
	Greedy();
	for(int i : ans) cout << i << ' ';
	return 0;
}

