#include <bits/stdc++.h>
#include <iostream>
#define vi vector<int>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> anagram;
        map<string, vector<string>> mapGroup;
        for (auto s : strs)
        {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
                        mapGroup[sorted].push_back(s);
            // auto itr = mapGroup.find(sorted);
            // if(itr==mapGroup.end()){
            //     mapGroup.insert({sorted,vector<string>{s}});
            // }else
            // {
            //     itr->second.push_back(s);
            // }
        }

        for (auto it : mapGroup)
        {
            anagram.push_back(it.second);
        }
        return anagram;
    }
};

int main()
{
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> output = s.groupAnagrams(input);
    for (vector<string> out : output)
    {
        for (string s : out)
        {
            cout << s + "\t";
        }
        cout << endl;
    }
}