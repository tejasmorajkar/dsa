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

// using set lookup is O(1)
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
	bool prevIsEven = false;

	for (int i = 0; i < A.size(); i++) {
		int current = A.at(i);
		bool isEven = current % 2 == 0;
		if ((isEven && i == 0) || (isEven && !prevIsEven)) {
			count++;
			prevIsEven = isEven;
		} else if ((!isEven && i == 0) || (!isEven && prevIsEven)) {
			count++;
			prevIsEven = isEven;
		}
	}
	return count;
}

int timeToEquality(vector<int> &A) {
	int max = *max_element(A.begin(), A.end());
	vector<int>::iterator it;
	int cost = 0;

	for (it = A.begin(); it < A.end(); it++) {
		cost += (max - *it);
	}
	return cost;
}

void reverseArray(vector<int> &v, int start, int end) {
	int temp;
	while (start < end) {
		temp = v[start];
		v[start] = v[end];
		v[end] = temp;
		start++;
		end--;
	}
}

void rotate(vector<int> &v, int size, int k) {
	k = k % size;
	reverseArray(v, 0, size - 1);
	reverseArray(v, 0, k - 1);
	reverseArray(v, k, size - 1);
}

int main() {
	int testcaseNum;
	scanf("%d", &testcaseNum);
	vector<vector<int>> result;

	for (int i = 0; i < testcaseNum; i++) {
		int size;
		scanf("%d", &size);

		vector<int> v;
		for (int j = 0; j < size; j++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		int k;
		scanf("%d", &k);

		rotate(v, size, k);
		result.push_back(v);
	}

	for (int i = 0; i < testcaseNum; i++) {
		vector<int> v = result[i];
		int size = v.size();
		for (int j = 0; j < size; j++) {
			printf("%d ", v[j]);
		}
		printf("\n");
	}

	return 0;
}