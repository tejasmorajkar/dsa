#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int solve(vector<string> &A, string B)
{
    int total_words = A.size();
    // If only word
    if (total_words == 1)
    {
        return 1;
    }
    // Fill map with lexical ordering
    unordered_map<char, int> map;
    for (int i = 0; i < B.length(); i++)
    {
        map[B.at(i)] = i;
    }

    // check each word
    for (int word_index = 0; word_index < total_words - 1; word_index++)
    {
        // Compare each char of current word and next word
        for (int char_index = 0; char_index < min(A[word_index].size(), A[word_index + 1].size()); char_index++)
        {
            // If current word char and next word char are different
            if (map[A[word_index].at(char_index)] != map[A[word_index + 1].at(char_index)])
            {
                // If current word char value is greater than next word char value
                if (map[A[word_index].at(char_index)] > map[A[word_index + 1].at(char_index)])
                {
                    return 0;
                }
                else
                {
                    // If current word char value is less than next word char value
                    // and current word char value is less than last word char value
                    if (word_index + 1 == total_words - 1)
                    {
                        return 1;
                    } else {
                        // move to next word
                        break;
                    }
                }
            }
            else
            {
                // If current word char and next word char are same
                // and current word length is greater than next word length
                if (A[word_index].length() > A[word_index + 1].length())
                {
                    return 0;
                }
            }
        }
    }
    // Compared all chars of each word and everything is sorted
    return 1;
}

int main()
{
    vector<string> A{"hello", "scaler", "interviewbit"};
    string B = "adhbcfegskjlponmirqtxwuvzy";
    int result = solve(A, B);
    printf("Sorted: %d\n", result);
    return 0;
}