// ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    Solution() :m_hash(46, 0)
    {

    }

    int climbStairs(int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        if (m_hash[n])
            return m_hash[n];

        m_hash[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return m_hash[n];
    }

private:

    vector<int> m_hash;

};

int main()
{
    std::cout << "Hello World!\n";

    Solution ob;
    std::cout << ob.climbStairs(4);
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
