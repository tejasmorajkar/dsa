#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int closest_min_max(vector<int> &A) 
{
    int size = A.size();

    if (size == 0) 
    {
        return 0;
    } else if (size == 1)
    {
        return 1;
    }

    int min = INT_MAX;
    int max = -INT_MAX;
    int max_index = -1;
    int min_index = -1;
    int result_min_to_max = INT_MAX, result_max_to_min = INT_MAX;

    min = *min_element(A.begin(), A.end());
    max = *max_element(A.begin(), A.end());

    if (min == max)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        if (A[i] == max)
        {
            max_index = i;
        } else if (max_index != -1 && A[i] == min)
        {
            result_max_to_min = std::min(result_max_to_min, i - max_index + 1);
        }
        if (A[i] == min) 
        {
            min_index = i;
        } else if (min_index != -1 && A[i] == max)
        {
            result_min_to_max = std::min(result_min_to_max, i - min_index + 1);
        }
    }
    return std::min(result_max_to_min, result_min_to_max);
}

int main()
{
    vector<int> A{5,4,3,1,2};
    int result = closest_min_max(A);
    printf("%d\n", result);
    return 0;
}