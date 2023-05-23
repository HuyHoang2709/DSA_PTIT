#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int n;
    int d = 2;

    cin >> s;
    int a['z' + 1] = { 0 };
    n = s.size();
    for (int i = 0; i < n; ++i) ++a[s[i]];

    // Tim ki tu co so lan xuat hien nhieu nhat trong chuoi
    int m = *max_element(a, a + 'z');
    
    if ((m - 1) * d < n) cout << 1;
    else cout << -1;
    return 0;
}