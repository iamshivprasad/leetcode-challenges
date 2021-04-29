// MergeSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;

        ListNode* head = new ListNode();
        ListNode* tail = head;


        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;

                l1 = l1->next;
            }

            else if (l2->val < l1->val)
            {
                tail->next = l2;

                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1)
        {
            tail->next = l1;
        }

        if (l2)
        {
            tail->next = l2;
        }

        return head->next;
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
