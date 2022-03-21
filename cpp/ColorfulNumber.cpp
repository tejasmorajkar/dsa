#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// Converting int to string 
// taking each char and then converting it to int
int colorful(int A)
{
    string num_str = to_string(A);
    int str_length = num_str.length();
    if (str_length == 1)
    {
        return 1;
    }
    long int product;
    unordered_set<long int> set;
    for (int i = 0; i < str_length; i++)
    {
        for (int j = i; j < str_length; j++)
        {
            product = 1;
            string s;
            for (int k = i; k <= j; k++)
            {
                s.assign(1, num_str.at(k));
                product *= stoi(s);
            }
            if (set.find(product) == set.end())
            {
                set.insert(product);
            }
            else
            {
                return 0;
            }
        }
    }

    return 1;
}

// Converting int to vector<int> to hold digits
int colorful2(int A)
{
    vector<int> digits;
    while (A > 0)
    {
        digits.insert(digits.begin(), A % 10);
        A /= 10;
    }
    int digits_count = digits.size();
    long int product;
    unordered_set<long int> set;
    for (int i = 0; i < digits_count; i++)
    {
        for (int j = i; j < digits_count; j++)
        {
            product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= digits[k];
            }
            if (set.find(product) == set.end())
            {
                set.insert(product);
            }
            else
            {
                return 0;
            }
        }
    }

    return 1;
}

int colorful3(int A)
{
    char str[20];
    sprintf(str, "%d", A);
    int str_len = strlen(str);
    unordered_set<long int> set;
    for (int i = 0; i < str_len; ++i) {
        long long product = 1;
        for (int j = i; j < str_len; ++j) {
            product *= (long long)(str[j] - '0');
            if (set.find(product) != set.end())
                return 0;
            set.insert(product);
        }
    }
    return 1;
}

int main()
{
    int result = colorful3(23);
    cout << result << endl;
    return 0;
}