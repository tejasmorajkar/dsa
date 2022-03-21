#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solve(vector<int> &v)
{
    int count = 0;
    int ans = 0;
    unordered_set<int> set;
    for (int i = 0; i < v.size(); i++)
    {
        set.insert(v[i]);
    }

    for (auto& it: set)
    {
        int start;   
        // find smallest and then check for seq
        if(set.find(it - 1) == set.end())
        {
            count = 1;
            start = it;
            // Check if consecutive elements of start exists
            // and increment count and start
            while (set.find(start + 1) != set.end())
            {
                count++;
                start++;
            }
        }
        ans = max(ans, count);
        if (ans >= set.size()/2) {
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> A {9,3,10,4,20,2};
    int result = solve(A);
    cout << result << endl;
    return 0;
}