#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TC: O(N*log(k))
// SC: O(k)
vector<int> solve(vector<int> &nums, int k) {
    int n = nums.size();
    int size = (n==k) ? k: k+1;
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + size);
    int i = 0;
    vector<int> result;
    for (int i = k+1; i < n; i++) {
        result.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}

int main(){
    vector<int> nums = {1, 40, 2, 3, 5, 4, 7, 6};
    int k = 2;

    // vector<int> nums = {2, 1, 17, 10, 21, 95};
    // int k = 1;
    // 1 2 10 17 21 95

    vector<int> ans = solve(nums, k);
    for (int num: ans)
        printf("%d ", num);
    printf("\n");
    return 0;
}