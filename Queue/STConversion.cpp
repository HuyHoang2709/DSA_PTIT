#include <bits/stdc++.h>

using namespace std;

/*
Problem:
Cho hai số nguyên dương S và T (S, T < 10000) và hai thao tác (a), (b) dưới đây:
Thao tác (a): Trừ S đi 1  (S = S-1) ;
Thao tác (b): Nhân S với 2 ( S = S*2);
Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất. Ví dụ với S = 2, T = 5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau:
Thao tác (a): 2 * 2 = 4;
Thao tác (b): 4 - 1 = 3;
Thao tác (a): 3 * 2 = 6;
Thao tác (b): 6 - 1 = 5;

Input:
3
2 5
3 7
7 4

Output:
4
4
3
*/

int converse(int s, int t)
{
    int a[20001] = {};
    queue<int> q;
    q.push(s);
    while (a[t] == 0)
    {
        int x = q.front();
        q.pop();
        if (x - 1 > 0 && a[x - 1] == 0)
        {
            a[x - 1] = a[x] + 1;
            q.push(x - 1);
        }
        if (x * 2 < 20000 && a[x * 2] == 0)
        {
            a[x * 2] = a[x] + 1; // count the number of conducted steps
            q.push(x * 2);
        }
    }
    return a[t];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << converse(a, b) << '\n';
    }
    return 0;
}