#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
(A+(B+C)
((A*B)+C)

Output:
ABC++
AB*C+
*/

int precedence(char x)
{
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    return 3;
}

void converse(string s)
{
    stack<char> st;
    string kq = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (isalpha(s[i])) kq += s[i];
        else if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                kq += c;
            }
            if (st.top() == '(') st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                char c = st.top();
                st.pop();
                kq += c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        kq += c;
    }
    cout << kq << '\n';
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        converse(s);
    }
    return 0;
}