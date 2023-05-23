#include <bits/stdc++.h>

using namespace std;

/*
Problem:
Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.

Input:
2
2
5

Output:
1 10
1 10 11 100 101
*/

void generate(int n)
{
    queue<string> q;
    q.push("1");
    while(n--)
    {
        string s = q.front();
        cout << s << ' ';
        q.pop();
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        generate(n);
    }
    return 0;
}