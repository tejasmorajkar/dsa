#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string solve(string A)
{
    if (A.length() == 1)
    {
        return A;
    }

    string result;
    vector<string> str;

    // Remove leading spaces
    int end = A.length();
    while (A[end] == ' ' && end >= 0)
    {
        end--;
    }
    end++;
    // Remove trailing spaces
    int start = 0;
    while (A[start] == ' ' && start < A.length() - 1)
    {
        start++;
    }

    // Update str by removing leading and removing spaces
    A = A.substr(start, end - start + 1);

    // Start from end
    start = A.length() - 1;
    end = A.length() - 1;
    int i = A.length() - 1;

    while (i >= 0)
    {
        // stop when first space occurs
        while (A[i] != ' ' && i >= 0)
        {
            start--;
            i--;
        }
        start = start + 1;
        string s = A.substr(start, end - start + 1);
        if (s != " ")
        {
            str.push_back(s);
        }

        // Ignore spaces between words and stop when aplhabet is found
        while (A[i] == ' ' && i >= 0)
        {
            i--;
        }

        if (i >= 0)
        {
            start = end = i;
        }
        else
        {
            break;
        }
    }
    // Create a new string by joining vector
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str[i].length(); j++)
        {
            if (str[i][j] != ' ')
            {
                result += str[i][j];
            }
        }

        if (i != str.size() - 1)
        {
            result += ' ';
        }
    }

    // Remove leading spaces
    end = result.length();
    while (result[end] == ' ' && end >= 0)
    {
        end--;
    }
    // Remove trailing spaces
    start = 0;
    while (result[start] == ' ' && start < result.length() - 1)
    {
        start++;
    }

    // Update str by removing leading and removing spaces
    result = result.substr(start, end - start + 1);
    return result;
}

// Using list of words
string solve2(string A)
{
    if (A.length() == 1)
    {
        return A;
    }
    string word = "";
    vector<string> words;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == ' ')
        {
            if (word == "")
            {
                continue;
            }
            else
            {
                words.push_back(word);
            }
            word = "";
        }
        else
        {
            word += A[i];
        }
    }
    // last word which might not have a space at end so it is missed
    // add last word to list
    if (word != "")
    {
        words.push_back(word);
    }
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--)
    {
        if (result != "")
        {
            result += " ";
        }
        result += words[i];
    }
    return result;
}

void reverse(string &str)
{
    for (int i = 0; i < (str.length() / 2); i++)
    {
        swap(str[i], str[str.length() - i - 1]);
    }
}

// Without having list of words
string solve3(string A)
{
    if (A.length() == 1)
    {
        return A;
    }
    string word = "";
    string ans = "";
    for (int i = A.length(); i >= 0; i--)
    {
        if (A[i] == ' ')
        {
            if (word == "" && word != " ")
            {
                continue;
            }
            reverse(word);
            if (ans != "")
            {
                ans += " ";
            }
            cout << word << endl;
            cout << word.length() << endl;
            ans += word;
            word = "";
        }
        else
        {
            word += A[i];
        }
    }
    // first word which might not have a space at end
    // add first word to answer
    if (word != "" && word != " ")
    {
        reverse(word);
        if (ans != "")
        {
            ans += " ";
        }
        ans += word;
    }
    ans.pop_back();
    return ans;
}

int main()
{
    string A = "fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
    string result = solve3(A);
    cout << result.length() << endl;
    cout << result << endl;
    return 0;
}
