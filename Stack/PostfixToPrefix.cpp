#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
AB+CD-*
ABC/-AK/L-*

Output:
*+AB-CD
*-A/BC-/AKL
*/

void converse(string s)
{
    stack<string> st;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string tmp = s[i] + se + fi;
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