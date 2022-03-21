#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
	void merge(vector < int > & a, int start, int mid, int end) {
	    int n1 = (mid - start + 1);
	    int n2 = (end - mid);
	    int L[n1], R[n2];
	    for (int i = 0; i < n1; i++)
	        L[i] = a[start + i];
	    for (int j = 0; j < n2; j++)
	        R[j] = a[mid + 1 + j];
	    int i = 0, j = 0;
	    for (int k = start; k <= end; k++) {
	        if (j >= n2 || (i < n1 && L[i] <= R[j]))
	            a[k] = L[i++];
	        else
	            a[k] = R[j++];
	    }
	}

	int mergesort_and_count(vector < int > & a, int start, int end) {
	    if (start < end) {
	        int mid = (start + end) / 2;
	        int count = mergesort_and_count(a, start, mid) + mergesort_and_count(a, mid + 1, end);
	        int j = mid + 1;
	        for (int i = start; i <= mid; i++) {
	            while (j <= end && a[i] > a[j] * 2L)
	                j++;
	            count += j - (mid + 1);
	        }
	        merge(a, start, mid, end);
	        return count;
	    } else
	        return 0;
	}

public:
	int solve(vector < int > & A) {
	    int n = A.size();
	    return mergesort_and_count(A, 0, n - 1);
	}
};

int main() {
	vector<int> A = {1, 3, 2, 3, 1}; // 2
	// vector<int> A = {4, 1, 2}; // 1
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
	return 0;
}