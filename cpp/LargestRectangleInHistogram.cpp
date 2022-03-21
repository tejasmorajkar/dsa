#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	vector<int> get_left_nse(vector<int> A) {
		int n = A.size();
		stack<int> st;
		vector<int> ans(n);

		for (int i = 0; i < A.size(); i++) {
        	while (!st.empty() && A[st.top()] >= A[i])
        		st.pop();

	        if (st.empty()) {
	            ans[i] = -1;
	        } else {
	            ans[i] = st.top();
	        }
        	st.push(i);
    	}
		return ans;
	}

	vector<int> get_right_nse(vector<int> A) {
		stack<int> st;
		int n = A.size();
		vector<int> ans(n);

		for (int i = n - 1; i >= 0; i--) {
        	while (!st.empty() && A[st.top()] > A[i])
        		st.pop();

	        if (st.empty()) {
	            ans[i] = n;
	        } else {
	            ans[i] = st.top();
	        }
        	st.push(i);
    	}
		return ans;
	}

public:
	int largestRectangleArea(vector<int> &A) {
		int n = A.size();

		vector<int> nse_right = get_right_nse(A);
		// printf("NSE RIGHT\n");
		// print(nse_right);

		vector<int> nse_left = get_left_nse(A);
		// printf("NSE LEFT\n");
		// print(nse_left);

		long largest_rectangle_area = INT32_MIN;

		for (int i = 0; i < n; i++) {
			long height = (long)(A[i]);
			long width = (long)(nse_right[i] - nse_left[i] - 1);
			largest_rectangle_area = max(largest_rectangle_area, height * width);
		}

		return (int)largest_rectangle_area;
	}

	int largestRectangleArea_Scaler(vector <int> &A) {
	    vector <int> height;
	    height = A;
	    int ret = 0;
	    height.push_back(0);
	    vector <int> index;
	    for (int i = 0; i < height.size(); i++) {
	        while (index.size() > 0 && height[index.back()] >= height[i]) {
	            int h = height[index.back()];
	            index.pop_back();

	            int sidx = index.size() > 0 ? index.back() : -1;
	            if (h * (i - sidx - 1) > ret)
	                ret = h * (i - sidx - 1);
	        }
	        index.push_back(i);
	    }
	    return ret;
	}

	void print(vector<int> A) {
		for (int i = 0; i < A.size(); i++)	
			printf("%d ", A[i]);
		printf("\n");
	}
};

int main() {
	vector<int> A = {2, 1, 5, 6, 2, 3}; // 10
	// index	
	// ret 		

	// vector<int> A = {2}; // 2
	Solution s;
	int ans = s.largestRectangleArea_Scaler(A);
	printf("%d\n", ans);
	return 0;
}