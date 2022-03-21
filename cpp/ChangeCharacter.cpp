#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solve(string A, int B) 
{
    int result = 0;
    unordered_map<char, int> freq;
    for (int i = 0; i < A.length(); i++)
    {
        freq[A[i]]++;
    }
    vector<int> v;
    for (auto&it: freq)
    {
        v.push_back(it.second);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() && B != 0; i++)
    {
        if (v[i] <= B)
        {
            B -= v[i];   
            v.erase(v.begin() + i);
            i--;
        }
        else
        {
            break;
        }
    }
    return v.size();
}

int main()
{
    string A = "abcabbccd";
    int B = 3;
    int result = solve(A, B);
    cout << result << endl;
	return 0;
}