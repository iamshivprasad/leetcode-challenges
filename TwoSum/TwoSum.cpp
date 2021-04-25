// TwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> table;

        vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int toFind = target - nums[i];

            if (table.find(toFind) != table.end())
            {
                result.push_back(table[toFind]);
                result.push_back(i);
                break;
            }

            table[nums[i]] = i;
        }

        return result;
    }
};

int main()
{
    cout << "Enter the target, size and elements of array: " << endl;

    int size, target;
    vector<int> nums;

    cin >> target >> size;

    nums.reserve(size);

    int t = 0;
    for (int i = 0; i < size; ++i)
    {
        cin >> t;
        nums.push_back(t);
    }

    Solution obj;
    auto res = obj.twoSum(nums, target);

    for (auto i : res)
    {
        cout << i << "\n";
    }
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
