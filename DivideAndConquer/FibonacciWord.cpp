#include <iostream>

using namespace std;

int n;
long long k;
long long F[100];

void Init()
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= 92; ++i) F[i] = F[i - 1] + F[i - 2];
}

char FibonacciWord(int n, long long k)
{
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= F[n - 2]) return FibonacciWord(n - 2, k);
    return FibonacciWord(n - 1, k - F[n - 2]);
}

int main()
{
    Init();
    cin >> n >> k;
    cout << FibonacciWord(n, k) << '\n';
    return 0;
}