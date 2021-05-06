    // MaxSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_ending_here = 0;
        int max_so_far = INT_MIN;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= nums[i] + max_ending_here)
            {
                max_ending_here += nums[i];
            }
            else
            {
                max_ending_here = nums[i];
            }

            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
            }

        }

        return max_so_far;


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
