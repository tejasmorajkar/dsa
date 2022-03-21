#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string longestCommonPrefix(vector<string> &A) {
    if (A.size() == 1)
    {
        return A[0];
    }

    string ans = "";
    for (int col_index = 0; col_index < A[0].size(); col_index++)
    {
        char current_char = '\0';
        bool is_match = false;
        for (int row_index = 0; row_index < A.size(); row_index++)
        {
            
            if (col_index + 1 > A[row_index].length())
            {
                return ans;
            }
            if (current_char == '\0')
            {
                current_char = A[row_index][col_index];
            }
            else
            {
                if (A[row_index][col_index] == current_char)
                {
                    is_match = true;
                }
                else
                {
                    is_match = false;
                    break;
                }
            }
        }
        if (is_match)
        {
            ans += current_char;
        }
        else {
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<string> A{"abcd", "abcd", "efgh"};
    string result = longestCommonPrefix(A);
    cout << result << endl;
	return 0;
}
