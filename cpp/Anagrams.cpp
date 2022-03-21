#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> anagrams2(const vector<string> &A)
{
    int n = A.size();
    map<string, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        string s = A[i];
        sort(s.begin(), s.end());
        auto it = mp.find(s);
        if (it == mp.end())
        {
            vector<int> value;
            value.push_back(i + 1);
            mp.insert({s, value});
        }
        else
            it->second.push_back(i + 1);
    }
    vector<vector<int>> result;
    for (auto i : mp)
    {
        result.push_back(i.second);
    }
    return result;
}

int main()
{
    // vector<string> A = {"cat", "dog", "god", "tca"};
    // vector<string> A = {"rat", "tar", "art"};
    vector<string> A = {"abbbaabbbabbbbabababbbbbbbaabaaabbaaababbabbabbaababbbaaabbabaabbaabbabbbbbababbbababbbbaabababba", "abaaabbbabaaabbbbabaabbabaaaababbbbabbbaaaabaababbbbaaaabbbaaaabaabbaaabbaabaaabbabbaaaababbabbaa", "babbabbaaabbbbabaaaabaabaabbbabaabaaabbbbbbabbabababbbabaabaabbaabaabaabbaabbbabaabbbabaaaabbbbab", "bbbabaaabaaaaabaabaaaaaaabbabaaaabbababbabbabbaabbabaaabaabbbabbaabaabaabaaaabbabbabaaababbaababb", "abbbbbbbbbbbbabaabbbbabababaabaabbbababbabbabaaaabaabbabbaaabbaaaabbaabbbbbaaaabaaaaababababaabab", "aabbbbaaabbaabbbbabbbbbaabbababbbbababbbabaabbbbbbababaaaabbbabaabbbbabbbababbbaaabbabaaaabaaaaba", "abbaaababbbabbbbabababbbababbbaaaaabbbbbbaaaabbaaabbbbbbabbabbabbaabbbbaabaabbababbbaabbbaababbaa", "aabaaabaaaaaabbbbaabbabaaaabbaababaaabbabbaaaaababaaabaabbbabbababaabababbaabaababbaabbabbbaaabbb"};
    vector<vector<int>> result = anagrams2(A);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}