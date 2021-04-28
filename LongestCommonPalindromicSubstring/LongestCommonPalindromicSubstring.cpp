// LongestCommonPalindromicSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// Reference: https://www.youtube.com/watch?v=y2BD4MJqV20

class Solution {
public:
    string longestPalindrome(const string& s) 
    {
        auto start = 0;
        auto end = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            auto l1 = expandFromMiddle(s, i, i);
            auto l2 = expandFromMiddle(s, i, i + 1);

            auto l = max(l1, l2);

            if (l > end - start)
            {
/*
Case-1 : When palindrome substring is of 'odd' length.
e.g. racecar. This palindrome is of length 7 ( odd ). Here if you see the mid, it is letter 'e'.
Around this mid 'e', you will see start ('r') and end ('r') are 'equidistant' from 'e'.
Lets assume this 'racecar' is present in our string under test-> 'aracecard'
Now, index of e is '4' in this example.
if you calculate start as i - (len-1)/2 or i - len/2, 
there would not be any difference as len being 'odd' would lead to (len -1)/2 and (len/2) being same. 
lets use start = i - (len-1)/2, and end = i + (len/2) in this case.
start = 4 - (6/2) , end = 4 + (7/2)
start = 4-3, end = 4+3
start =1, end = 7
s.substring(1, 7+1) = 'racecare'

Case-2: When palindrome substring is of 'even' length
e.g. abba
Lets see this case. Lets assume given string under test is-> 'eabbad'
In this case, your i is going to be 2. ( This is most critical part )
With the given solution by Nick, you would found this palindrome with
int len2 = expandFromMiddle(s, i, i+1)
Now if you look at this method, your left which starts with 'i' is always being compared with right which starts with i+1
That would be the case here with 'eabbad'. When i is 2 ie. 'b' . 
Then your left will be 2 (b) and right will be 2+1 ( b) and the comparison will proceed.
In this case, once you have found 'abba' then it being 'even' the index 'i' would fall in your 'first half' of the palindrome. ab | ba
if you calculate start as start = i - (len/2) , it would be wrong!! because your i is not in the mid of palindrome.
lets still try with this formula start = i - len/2
start = 2 - (4/2)   // i =2, len = 4 ( abba)
start = 2 -2 =0 ( wrong!)
end = i + (len/2)
end = 2 + 2 = 4
s.substring( 0, 4+1)   // ''eabba'  --> wrong solution!!!
Here start should have been 1
lets recalculate start as-
start = i - (len-1)/2
start = 2 - (4-1)/2
start = 2- 3/2
start = 2 -1 = 1
s.substring(1, 4+1)  // 'abba'  --> correct solution

So you should calculate start as start = i - (len-1)/2 to take care of the case when palindrome is of 'even' length. For palindrome being 'odd' length it would not matter if start is calculated as i - (len/2) or i - (len-1)/2.
*/
                start = i - (l - 1) / 2;
                end = i + (l / 2);
            }
        }

        return string(&s[start], &s[end + 1]);
    }

private:

    int expandFromMiddle(const string& s, int l, int r)
    {
        auto size = s.size();
        while (l >= 0 && r < size && s[l] == s[r])
        {
            --l;
            ++r;
        }

        /*
        Providing R - L - 1 explanation:
        e.g. racecar (length = 7. Simple math to calculate this would be  R - L  + 1  ( where L= 0 , R=6 )), considering start index is '0'.
        Now, in this example ( 'racecar' ) when loop goes into final iteration, that time we have just hit L =0, R =6 (ie. length -1)
        but before exiting the loop, we are also decrementing L by L - -  , and incrementing R by R ++ for the final time, which will make L and R as  ( L = -1, R = 7 )
        Now, after exiting the loop,  if you apply the same formula for length calculation as 'R - L +1', it would return you 7 -( - 1 )+1 = 9 which is wrong, but point to note is it gives you length increased by 2 units than the correct length which is 7.
        So the correct calculation of length would be when you adjust your R and L . to do that you would need to decrease R by 1 unit as it was increased by 1 unit before exiting the loop , and increase L by 1 unit as it was decreased by 1 unit just before exiting the loop.
        lets calculate the length with adjusted R and L
        ( R -1 ) - ( L +1 ) + 1
        R -1 - L  -1 + 1
        R -L -2 + 1
        R - L -1
        */

        return r - l - 1;
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
