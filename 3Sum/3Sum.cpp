// 3Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;

        std::sort(nums.begin(), nums.end());

        auto size = nums.size();
        for (size_t i = 0; i < size; i++)
        {
            auto target = -nums[i];

            auto front = i + 1;
            auto back = size - 1;

            while (front < back)
            {
                int sum = nums[front] + nums[back];

                if (sum < target)
                    ++front;

                else if (sum > target)
                    --back;

                else
                {
                    vector<int> triplet = { nums[i], nums[front], nums[back] };
                    result.push_back(triplet);

                    // to skip thex same combination
                    while (front < back && nums[front] == triplet[1])
                        ++front;

                    while (front < back && nums[back] == triplet[2])
                        --back;

                }
            }

            while (i + 1 < size && nums[i + 1] == nums[i])
                ++i;
        }

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
