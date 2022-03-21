#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
	void updateindex(vector<int> &index, int a, int ai, int b, int bi) {
    	index[a] = ai;
    	index[b] = bi;
	}

	int minSwapsUtil(vector<int> &A, vector<int> &pairs, vector<int> &index, int i, int n) {
		// swapping completed
	    if (i > n)
	        return 0;

	    // pair already exists
	    if (pairs[A[i]] == A[i+1])
	         return minSwapsUtil(A, pairs, index, i+2, n);

	    // find pair of A[i] and swap with A[i+1]
	    int one = A[i+1], indexone = index[pairs[A[i]]];
	    int two = A[index[pairs[A[i]]]], indextwo = i+1;

	    swap(A[i+1], A[indexone]);
	    updateindex(index, one, indexone, two, indextwo);

	    int a = minSwapsUtil(A, pairs, index, i+2, n);

	    // backtrack
	    swap(A[i+1], A[indexone]);
	    updateindex(index, one, indextwo, two, indexone);

	    // swap A[i] with correct pair
	    one = A[i], indexone = index[pairs[A[i+1]]];
	    two = A[index[pairs[A[i+1]]]], indextwo = i;

	    swap(A[i], A[indexone]);
	    updateindex(index, one, indexone, two, indextwo);

	    int b = minSwapsUtil(A, pairs, index, i+2, n);

	    // backtrack
	    swap(A[i], A[indexone]);
	    updateindex(index, one, indextwo, two, indexone);

	    return 1 + min(a, b);
	}

	vector<int> convertToPairsBasedOnIndexing(vector<vector<int>> &C){
    	int n = C.size();
    	vector<int> pairs(n+n+1);
    	for(int i=0; i < n; ++i){
        	pairs[C[i][0]]=C[i][1];
        	pairs[C[i][1]]=C[i][0];
    	}
    	return pairs;
	}

public:
	int solve(int A, vector<int> &B, vector<vector<int>> &C) {
		B.insert(B.begin(), 0);
    	vector<int> pairs = convertToPairsBasedOnIndexing(C);
    	vector<int> index(A+A+1);
    	for(int i=1; i<=A; ++i)
        	index[B[i]]=i;
    	return minSwapsUtil(B,pairs,index,1,2*A);
	}
};

int main() {
	int A = 3;
	vector<int> B = {3, 5, 6, 4, 1, 2}; // 2
	vector<vector<int>> C = {{1, 3}, {2, 6}, {4, 5}};
	// int A = 1;
	// vector<int> A = {1,2};
	// vector<vector<int>> C = {{1,2}};
	Solution s;
	int ans = s.solve(A, B, C);
	printf("%d\n", ans);
	return 0;
}