#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare_string(string a, string b) {
    return a + b > b + a;
}

string largestNumber(const vector<int> &A) {
    string result;
    vector<string> str_arr;
    // Create a vector of string with given vector of integers
    for (int i = 0; i < A.size(); i++) {
        str_arr.push_back(to_string(A[i]));
    }
    // Sort using custom sort function
    sort(str_arr.begin(), str_arr.end(), compare_string);
    // concatenate string vector to a single result string
    for (int i = 0; i < str_arr.size(); i++) {
        result += str_arr[i];
    }
    // Remove any trailing 0's from string
    int nonzero_index = 0;
    while (result.at(nonzero_index) == '0' && nonzero_index + 1 < result.length()) {
        nonzero_index++;
    }
    // Update result by removing trailing 0's
    result = result.substr(nonzero_index);
    return result;
}

int main()
{
    vector<int> A{3, 30, 34, 5, 9};
    string result = largestNumber(A);
    printf("%s\n", result.c_str());
	return 0;
}
