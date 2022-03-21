#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(vector<int> &A, int B) {
    int count = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < A.size(); i++)
    {
        auto it = map.find(B ^ A[i]);
        // Check if xor - element exists in map
        if (it == map.end()) 
        {
            // Check if element already exists in map
            if (map.find(A[i]) == map.end())
            { 
               map[A[i]] = i;
            }
        } else {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> A {3, 6, 8, 10, 15, 50};
    int B = 5;
    int result = solve(A, B);
    printf("%d\n", result);
    return 0;
}