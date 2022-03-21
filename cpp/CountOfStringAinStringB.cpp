#include <iostream>
#include <string>

using namespace std;

// Approach 1: Comparing arrays by checking all 26 elements
// TC: 26 * M = O(N) 
// Not optimal when more charset is large e.g 256 charset
bool compare_string(int A[], int B[])
{
    for (int i = 0; i < 26; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

int solve(string &A, string &B)
{
    int n = A.length();
    int m = B.length();
    int freq_A[26] = {0};
    int freq_B[26] = {0};

    // Find freq of chars in A
    // Find freq of starting n chars of B
    for (int i = 0; i < n; i++)
    {
        freq_A[A[i] - 'a']++;
        freq_B[B[i] - 'a']++;
    }

    int count = 0;
    if (compare_string(freq_A, freq_B))
    {
        count++;
    }

    // Use sliding window to update count of ith char and delete count of i - n char
    for (int i = n; i < m; i++)
    {
        freq_B[B[i] - 'a']++;
        freq_B[B[i - n] - 'a']--;

        if (compare_string(freq_A, freq_B))
        {
            count++;
        }
    }

    return count;
}

// Approach 2: Comparing only N length of chars
// TC: O(N)
int solve2(string &A, string &B)
{
    int n = A.length(), m = B.length(), count = 0;
    int need = n;
    int freq[26] = {0};

    for (int i = 0; i < n; i++)
    {
        // Find freq of starting n chars of A
        freq[A[i] - 'a']++;
    }

    // Form 1st window and identify current need
    for (int i = 0; i < n; i++)
    {
        freq[B[i] - 'a']--;
        if (freq[B[i] - 'a'] >= 0)
            need--;
    }

    if (need == 0)
        count++;
    
    for (int i = n; i < m; i++)
    {
        if (B[i] != B[i - n])
        {
            freq[B[i] - 'a']--;
            freq[B[i - n] - 'a']++;
            if (freq[B[i] - 'a'] >= 0)
                need--;
            if (freq[B[i - n] - 'a'] > 0)
                need++;
        }
        if (need == 0)
            count++;
    }
    return count;
}

int main()
{
    string A = "abcc";
    string B = "klmnoccbaqwabccoplkbacc";
    int result = solve2(A,B);
    cout << result << endl;
    return 0;
}