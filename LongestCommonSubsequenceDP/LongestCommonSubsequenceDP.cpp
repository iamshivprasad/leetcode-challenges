// LongestCommonSubsequenceDP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// reference: https://www.youtube.com/watch?v=ASoaQq66foQ&t=782s
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

class SubString
{
public:

    string longestCommonSubString(const string& s1, const string& s2)
    {
        vector<vector<int>> table;
        table.resize(s1.size() + 1);

        int m = s1.size();
        int n = s2.size();

        for (auto& v : table)
        {
            v.resize(s2.size() + 1);
        }
        
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    table[i][j] = 0;
                }
                else if (s1[i] == s2[i])
                {
                    table[i][j] = 1 + table[i - 1][j - 1];
                }
                else
                {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }

        int i = m;
        int j = n;

        string result;
        auto index = table[m][n];
        result.resize(index);
        
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                result[index] = s1[i - 1];
                --i;
                --j;
                --index;
            }
            else if (table[i - 1][j] > table[i][j - 1])
            {
                --i;
            }
            else
                --j;
        }

        return result;
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
