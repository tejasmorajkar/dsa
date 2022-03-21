#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMedian(vector<vector<int> > &A) {
	    int low = 1, high = 1e9;
	    int n = A.size(), m = A[0].size();
	    int desired_count = (n * m) >> 1;
	    while (low <= high) {
	        int mid = (low + high) >> 1;
	        int count = 0;

	        for (int i = 0; i < n; i++) {
	            int l = 0, h = m - 1;

	            while (l <= h) {
	                int m = (l + h) >> 1;

	                if (A[i][m] <= mid) 
	                    l = m + 1;
	                else
	                    h = m - 1;
	            }
	            count += l;
	        }

	        if (count <= desired_count)
	            low = mid + 1;
	        else
	            high = mid - 1;
	    }
	    return low;
	}
};

int main() {
	vector<vector<int>> A = {{1,3,5}, {2,6,9}, {3,6,9}}; // 5
	Solution s;
	int ans = s.findMedian(A);
	printf("%d\n", ans);
	return 0;
}