#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];

void Init() 
{
    cin >> n;
    for(int i = 1; i <= n; ++i) a[i] = 0;
}

void print(int i)
{
    for(int j = 1; j <= i; ++j) cout << a[j] << ' ';
    cout << '\n';
}

void Try(int x, int i, int s)
{
    for(int j = x; j >= 1; --j)
    {
        a[i] = j;
        if(j == s) print(i);
        else if(j < s) Try(j, i+1, s-j); 
    }
}

int main()
{
    Init();
    Try(n, 1, n);
    return 0;
}