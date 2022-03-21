#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string getLargest(string A) {
    string result = "";
    string S = "";
    string T = "";
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '_')
        {
            S = A.substr(0, i);
            T = A.substr(i + 1, A.length() - 1 - i + 1 + 1);
            break;
        }
    }
    sort(T.begin(), T.end(), greater<int>());
    for (int i = 0; i < S.length() && T.length() > 0; i++)
    {
        for (int j = 0; j < T.length(); j++)
        {
            if (S[i] < T[j])
            {
                S[i] = T[j];
                T.erase(j, 1);
                break;
            }
        }
    }
    return S;
}

int main()
{
    string A = "abb_c";
    string result = getLargest(A);
    cout << result << endl;
	return 0;
}