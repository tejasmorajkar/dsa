#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void print_vector(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int count_subArray_with_given_sum(vector<int> &A, int k)
{
    vector<int> prefix_sum{0};
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        prefix_sum.push_back(prefix_sum[i] + A[i]);
    }

    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0 ; i < prefix_sum.size(); i++)
    {
        if (map.find(prefix_sum[i] - k) != map.end())
        {
            count += map[prefix_sum[i] - k];
        }
        map[prefix_sum[i]]++;
    }
    return count;
}

vector<int> first_subArray_with_given_sum(vector<int> &A, int B)
{
    vector<long int> prefix_sum;
    prefix_sum.push_back(0);
    long int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        prefix_sum.push_back(prefix_sum[i] + A[i]);
    }

    unordered_map<long int, int> map;
    for (int i = 0; i < prefix_sum.size(); i++)
    {
        if (map.find(prefix_sum[i] - B) != map.end())
        {
            int start_index = map[prefix_sum[i] - B] + 1;
            int end_index = i - 1;
            vector<int> result{A.begin() + start_index, A.begin() + end_index + 1};
            return result;
        } else {
            map.insert({prefix_sum[i], i - 1});
        }
    }
    return {-1};
}

int main()
{
    vector<int> A{1,2,3,4,5};
    int B = 5;
    vector<int> result = first_subArray_with_given_sum(A, B);
    print_vector(result);
}