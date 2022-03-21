#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
	TrieNode* left;
	TrieNode* right;
};

class Solution {
public:
	void print(vector<int> &A){
		for(int num: A)
			cout << num << " ";
		cout << "\n";
	}

	int get_ith_bit(int num, int i){
		return (num >> i)&1;
	}

	vector<int> solve(vector<int> &A){
		int n = A.size();

		// create prefix xor
		vector<int> prefix_xor(n+1);
		for (int i = 1; i <= n; i++)
			prefix_xor[i] = prefix_xor[i-1] ^ A[i-1];

		// create trie 
		TrieNode* root = new TrieNode();
		for (int num: prefix_xor) {
			TrieNode* curr = root;
			for (int i = 30; i >=0; i--){
				int bit = get_ith_bit(num, i);
				if (bit == 0){
					if(!curr->left)
						curr->left = new TrieNode();
					curr = curr->left;
				} else{
					if(!curr->right)
						curr->right = new TrieNode();
					curr=curr->right;
				}
			}
		}

		// find max_xor
		int max_xor = INT_MIN;
		for (int num: prefix_xor) {
			TrieNode* curr = root;
			int curr_xor = 0;
			for (int i = 30; i >=0; i--){
				int bit = get_ith_bit(num, i);
				if (bit == 0){
					if (curr->right) {
						curr_xor += (1<<i);
						curr = curr->right;
					} else {
						curr = curr->left;
					}
				} else {
					if (curr->left) {
						curr_xor += (1<<i);
						curr = curr->left;
					} else {
						curr = curr->right;
					}
				}
			}
			max_xor = max(max_xor, curr_xor);
		}

		// get l and r for max_xor
		vector<int> result(2);
		unordered_map<int, int> mp;
		int max_xor_len = INT_MAX, max_xor_r, max_xor_l;

		for (int i = 0; i < prefix_xor.size(); i++) {
			int x = max_xor ^ prefix_xor[i];
			if (mp.find(x) != mp.end()) {
				int r = i, l = mp[x] + 1;
				int len = r - l;
				if (max_xor_len > len) {
					max_xor_l = l, max_xor_r = r, max_xor_len = len;
				}
			}
			mp[prefix_xor[i]] = i;
		}
		result[0] = max_xor_l, result[1] = max_xor_r;
		return result;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> A;
	while (n > 0) {
		int val;
		cin >> val;
		A.push_back(val);
		n--;
	}
	Solution s;
	vector<int> ans = s.solve(A);
	for (int num: ans)
		cout << num << " ";
	cout << "\n";
	return 0;
}