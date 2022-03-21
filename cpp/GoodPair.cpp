#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
 
int solve(vector<int> &A, int B) {
	for (int i = 0; i < A.size(); i++) {
		int current = A.at(i);
		for (int j = i+1; j < A.size(); j++) {
			if (current + A.at(j) == B) {
				return 1;
			}
		}
	}

	return 0;
}

int solve2(vector<int> &A, int B) {
	unordered_set<int> s;
    for (int i = 0; i < A.size(); i++)
    {
    	int current = A.at(i);
        int diff = B - current;
 
        if (s.find(diff) != s.end())
            return 1;

        s.insert(current);
    }
    return 0;
}

int oddEvenSubsequence(vector<int> &A) {
	int count = 0;
	vector<int> oddEven;
	bool prevIsEven = false;

	for (int i = 0; i < A.size(); i++) {
		int current = A.at(i);
		bool isEven = current % 2 == 0;
		if (isEven && !prevIsEven) {
			count++;
			result.push_back(current);
			prevIsEven = isEven;
		} else if (!isEven && prevIsEven) {
			count++;
			result.push_back(current);
			prevIsEven = isEven;
		}
	}
	return oddEven.size();
}


int main() {
	// vector<int> A = {1,2,3,4,5};
	// int B = 7;

	// int result = solve2(A, B);
	// printf("%d\n", result);
	vector<int> A = {1, 2, 2, 5, 6};
	int result = oddEvenSubsequence(A);
	printf("%d\n", result);
	return 0;
}