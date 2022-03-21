#include <bits/stdc++.h>

using namespace std;

class Solution {
public:	
	vector<int> solve(vector<int> &A, vector<int> &B) {
	    int n = A.size();
	    int m = B.size();
	    vector<long long int> prefix_sum;
	    prefix_sum.push_back((long long int)A[0]);
	    
	    for (int i = 1; i < n; i++)
	        prefix_sum.push_back(prefix_sum.back() + (long long int)A[i]);
	        
	    vector<pair<long long int, int>> b_pair;
	    
	    for (int i = 0; i < m; i++)
	        b_pair.push_back(make_pair((long long int)B[i], i));
	        
	    sort(b_pair.begin(), b_pair.end());
	    
	    int count = 0;
	    vector<int> result(m);
	    int j = 0;
	    for (int i = 0; i < m; i++) {
	        while (j < n && b_pair[i].first >= prefix_sum[j]) {
	            count++;
	            j++;
	        }
	        result[b_pair[i].second] = count; 
	    }
	    return result;
	}
};

int main() {
	vector<int> A = {3,4,4,6};
	vector<int> B = {20,4,10,2,25,30};
	// 4 1 2 0
	Solution s;
	vector<int> result = s.solve(A, B);
	for (int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
	printf("\n");
	return 0;
}