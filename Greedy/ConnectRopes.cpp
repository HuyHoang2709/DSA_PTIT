#include <bits/stdc++.h>

using namespace std;

/*
Input:
8
9 7 12 8 6 5 14 4

Output:
190
*/

int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        q.push(x);
    }
    long long kq = 0;
    while (q.size() >= 2)
    {
        // Cu lien tuc lay ra 2 day co chieu dai nho nhat hien tai de noi voi nhau, toi khi toan bo day da duoc noi
        int min1 = q.top();
        q.pop();
        int min2 = q.top();
        q.pop();
        int sum = min1 + min2;
        kq += sum;
        q.push(sum);
    }
    cout << kq;
    return 0;
}