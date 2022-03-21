#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int arrayNesting(vector<int>& nums) {
    unordered_set<int> set;
    int n = nums.size();
    int next_index = 0;
    set.insert(nums[next_index]);
    next_index = nums[next_index];
    while(next_index < n && set.find(nums[next_index]) != set.end())
    {
        set.insert(nums[next_index]);
        next_index = nums[next_index];
    }
    return set.size();
}

int main()
{
    vector<int> nums {0,2,1};
    int result = arrayNesting(nums);
    cout << result << "\n";
    return 0;
}