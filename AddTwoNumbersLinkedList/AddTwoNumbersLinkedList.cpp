// AddTwoNumbersLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        auto carry = 0;
        bool isContinue = true;
        while (isContinue)
        {
            isContinue = false;
            int s = 0;
            if (l1 != nullptr)
            {
                s = l1->val;
                l1 = l1->next;
            }

            int f = 0;
            if (l2 != nullptr)
            {
                f = l2->val;
                l2 = l2->next;
            }

            auto sum = f + s + carry;
            auto newNode = new ListNode();
            newNode->val = sum % 10;
            carry = sum < 10 ? 0 : 1;

            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            if (l1 != nullptr || l2 != nullptr || carry)
                isContinue = true;

        }

        return head;
    }
};

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//    {
//
//        int len1 = 0;
//        int len2 = 0;
//        std::stack<int> s1, s2;
//
//        [&]()
//        {
//            auto temp = l1;
//            while (temp)
//            {
//                s1.push(temp->val);
//                temp = temp->next;
//                ++len1;
//            }
//
//            temp = l2;
//            while (temp)
//            {
//                s2.push(temp->val);
//                temp = temp->next;
//                ++len2;
//            }
//        }();
//
//        int diff = len1 - len2;
//        ListNode* head = nullptr;
//        ListNode* tail = nullptr;
//
//        std::stack<int>* pLongestStack = &s1;
//        if (diff < 0)
//        {
//            pLongestStack = &s2;
//        }
//
//        while (diff)
//        {
//            auto newNode = new ListNode(pLongestStack->top());
//
//            if (head == nullptr)
//            {
//                head = newNode;
//                tail = newNode;
//            }
//            else
//            {
//                tail->next = newNode;
//                tail = newNode;
//            }
//
//            pLongestStack->pop();
//            --diff;
//        }
//        
//        int carry = 0;
//        while (!s1.empty())
//        {
//            auto f = s1.top();
//            auto s = s2.top();
//
//            auto sum = s1.top() + s2.top() + carry;
//
//            auto newNode = new ListNode(sum % 10);
//            if (head == nullptr)
//            {
//                head = newNode;
//                tail = newNode;
//            }
//            else
//            {
//                tail->next = newNode;
//                tail = newNode;
//            }
//
//            carry = sum < 10 ? 0 : 1;
//
//            s1.pop();
//            s2.pop();
//        }
//
//        return head;
//    }
//};

int main()
{
    std::cout << "Hello World!\n";

    auto one = new ListNode();
    one->val = 3;

    auto two = new ListNode();
    two->val = 4;

    auto three = new ListNode();
    three->val = 2;

    three->next = two;
    two->next = one;

    auto four = new ListNode();
    four->val = 4;

    auto five = new ListNode();
    five->val = 6;

    auto six = new ListNode();
    six->val = 5;

    six->next = five;
    five->next = four;

    Solution obj;
    auto res = obj.addTwoNumbers(three, five);
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
