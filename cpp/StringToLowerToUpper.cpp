#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<char> to_lower(vector<char> &A) {
    for (int i = 0; i < A.size(); i++) {
        int c = A[i];
        if (c >= 65 && c <= 90) {
            char c = 'a' + A[i] - 'A';
            A[i] = c;
        }
    }
    return A;
}

vector<char> to_upper(vector<char> &A) {
    for (int i = 0; i < A.size(); i++) {
        int c = A[i];
        if (c >= 97 && c <= 122) {
            char c = 'A' + A[i] - 'a';
            A[i] = c;
        }
    }
    return A;
}

int is_alpha(vector<char> &A ) {
    for (int i = 0; i < A.size(); i++) {
        int c = A[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            continue;
        }
        return 0;
    }
    return 1;
}

int main()
{
    // vector<char> input {'S', 'c', 'a', 'L', 'e', 'R', '#', '2', '0', '2', '0'};
    // vector<char> result = to_lower(input);
    // vector<char> result = to_upper(input);

    // for (int i = 0; i < result.size(); i++) {
    //     printf("%c ", result[i]);
    // }
    // printf("\n");
    vector<char> input {'S', 'c', 'a', 'l', 'e', 'r', 'A', 'c', 'a', 'd', 'e', 'm', 'y'};
    int result = is_alpha(input);
    cout << result << endl;
	return 0;
}
