#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

long long Exponential(int n, int k)
{
    if(k == 0) return 1;
    long long x = Exponential(n, k / 2);
    if(k % 2 == 0) return x * x % mod;
    else return n * (x * x % mod) % mod;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << n << '^' << k << " = " << Exponential(n, k);
    return 0;
}