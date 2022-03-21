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

vector<int> solve(vector<int> &A, vector<int> &B) {
    vector<int> result;
    unordered_map<int,int> map;
    for (int i = 0; i < A.size(); i++)
    {
        if (map.find(A[i]) == map.end())
        {
            map[A[i]] = 1;
        } else 
        {
            map[A[i]]++;
        }
    }
    for (int i = 0; i < B.size(); i++)
    {
        if (map.find(B[i]) != map.end())
        {
            result.push_back(B[i]);
            map[B[i]]--;
            if (map[B[i]] == 0)
            {
                map.erase(B[i]);
            }
        }
    }
    return result;
}

int main()
{
    vector<int> A{1,2,2,1};
    vector<int> B{2,3,1,2};
    vector<int> result = solve(A,B);
    printArray(result);
    return 0;
}