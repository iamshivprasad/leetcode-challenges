//// FindSubstringKMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
////--------PARTIAL IMPLMENTATION---------
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//// https://www.youtube.com/watch?v=BXCEFAzhxGY
//
//int findSubstring(const string& s, const string& key)
//{
//    vector<int> suffixPrefixTable;
//
//    int m = s.size();
//    int n = key.size();
//
//    suffixPrefixTable.resize(n);
//
//    int i = 0;
//    int j = 1;
//
//    while (i < n && j < n)
//    {
//        if(key[i] == key[j])
//        {
//            suffixPrefixTable[j] = i + 1;
//            ++i;
//        }
//        j++;
//    }
//
//    auto s_idx = 0;
//    auto k_idx = 0;
//    while (s_idx <= m - n)
//    {
//        if (s[s_idx] == key[k_idx])
//        {
//            ++k_idx;
//        }
//        else
//        {
//            k_idx = 
//        }
//
//        ++s_idx;
//    }
//
//    return 0;
//
//}
//
//int main()
//{
//    std::cout << "Hello World!\n";
//
//    string s = "";
//    string k = "dsgwadsgz";
//
//    findSubstring(s, k);
//}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
