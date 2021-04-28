// ValidParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;

        stack<char> st;
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':

                st.push(c);
                break;

            case ')':
            case '}':
            case ']':

                if (st.empty())
                    return false;

                auto temp = st.top();
                if ((c == ')' && temp != '(') ||
                    (c == '}' && temp != '{') ||
                    (c == ']' && temp != '['))
                {
                    return false;
                }

                st.pop();

                break;

            }
        }

        if (!st.empty())
            return false;

        return true;

    }
};
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
