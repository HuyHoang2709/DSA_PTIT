#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
7
6 2 5 4 5 1 6
3
2 2 2

Output:
12
6
*/

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long H[n], L[n], R[n];
        for(int i = 0; i < n; ++i) cin >> H[i];
        
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; ++i)
        {
            while(st.size() > 1 && H[st.top()] >= H[i]) st.pop();
            L[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();

        st.push(n);
        for(int i = n-1; i >= 0; --i)
        {
            while(st.size() > 1 && H[st.top()] >= H[i]) st.pop();
            R[i] = st.top() - 1;
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; ++i) res = max(res, (R[i] - L[i] + 1) * H[i]);
        cout << res << '\n';
    }
    return 0;
}