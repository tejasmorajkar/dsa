#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int check_if_subarr_with_zero_sum_exists(vector<int> &A)
{
    int sum = 0;
    unordered_set<int> set;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (set.find(sum) == set.end() && sum != 0)
        {
            set.insert(sum);
        } else {
            return 1;
        }
    }
    return 0;
}

int main()
{
    vector<int> A {-1, 1};
    int result = check_if_subarr_with_zero_sum_exists(A);
    cout << result << endl;
    return 0;
}