#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solve(string A)
{
    int count = 0;
    string str = "bob";
    for (int i = 0; i <= A.length() - str.length(); i++)
    {
        bool is_match = false;
        for (int j = i; j < i + str.length(); j++)
        {
            if (A[j] != str[j - i])
            {
                is_match = false;
                break;
            } else {
                is_match = true;
            }
        }
        if (is_match)
        {
            count++;
        }
    }

    return count;
}

int solve2(string A)
{
    int count = 0;
    string str = "bob";
    for (int i = 0; i <= A.length() - str.length(); i++)
    {
        bool is_match = false;
        if (A.substr(i, i + str.length() - 1) == str) 
        {
            count++;
        }
    }

    return count;
}

int solve3(string A)
{
    int index = 0;
    int found;
    int count = 0;
    found = A.find("bob",index);
    while(found != -1) {
        count++;
        index = found;
        found = A.find("bob",index+1);
    }
    return count;
}

int main()
{
    int result = solve3("bobob");
    cout << result << endl;
	return 0;
}
