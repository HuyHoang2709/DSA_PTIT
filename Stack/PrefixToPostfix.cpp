#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
*+AB-CD
*-A/BC-/AKL

Output:
AB+CD-*
ABC/-AK/L-*
*/

void converse(string s)
{
    stack<string> st;
    for(int i = s.length()-1; i >= 0; --i)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = fi + se + s[i];
            st.push(tmp);
        }
        else st.push(string(1, s[i]));
    }
    cout << st.top() << '\n';
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        cin >> s;
        converse(s);
    }
    return 0;
}