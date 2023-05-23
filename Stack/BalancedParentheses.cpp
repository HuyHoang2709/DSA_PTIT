#include <bits/stdc++.h>

using namespace std;

/*
Input:
2
[()]{}{[()()]()}
[(])

Output:
YES
NO
*/

int check(string s)
{
    int n = s.length();
    stack<char> st;
    for(char i : s)
    {
        if(i == '(' || i == '[' || i == '{') st.push(i);
        else 
        {
            if(st.empty()) return 0;
            char in = st.top(), out = i;
            if(in == '(' && out == ')') st.pop();
            else if(in == '[' && out == ']') st.pop();
            else if(in == '{' && out == '}') st.pop();
        }
    }
    return st.empty();
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
        if(check(s)) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}