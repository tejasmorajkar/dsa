#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printArray(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		printf("%d ", A[i]);
	}
    printf("\n");
}

vector<int> twoSum(const vector<int> &A, int B) {
    vector<int> result;
    unordered_map<int, int> map;

    for (int i = 0; i < A.size(); i++)
    {
        auto it = map.find(B - A[i]);
        // Check if sum - element exists in map
        if (it == map.end()) 
        {
            // Check if element already exists in map
            if (map.find(A[i]) == map.end())
            { 
               map[A[i]] = i;
            }
        } else {
            result.push_back((int)it->second + 1);
            result.push_back(i + 1);
            return result;
        }
    }
    return result;
}

int main()
{
    vector<int> A {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    int B = -3;
    vector<int> result = twoSum(A, B);
    printArray(result);
    return 0;
}