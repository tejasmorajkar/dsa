class Solution {
public:
    int candy(vector<int> &A) {
        int n = A.size();
        vector<int> l_to_r(n), r_to_l(n);
        int prev_rating = 0, prev_candy = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > prev_rating) {
                l_to_r[i] = prev_candy + 1;
            } else {
                l_to_r[i] = 1;
            }
            prev_rating = A[i];
            prev_candy = l_to_r[i];
        }
        prev_rating = 0, prev_candy = 0;
        for (int i = n-1; i >= 0; i--) {
            if (A[i] > prev_rating) {
                r_to_l[i] = prev_candy + 1;
            } else {
                r_to_l[i] = 1;
            }
            prev_rating = A[i];
            prev_candy = r_to_l[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = max(l_to_r[i], r_to_l[i]);
            ans += x;
        }
        return ans;
    }
};