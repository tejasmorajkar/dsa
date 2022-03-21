#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	char val;
	int count;
	unordered_map<char, TrieNode*> child;
};

TrieNode* getNewTrieNode(char v) {
	TrieNode* temp = new TrieNode;
	temp -> val = v;
	temp -> count = 0;
	return temp;
}

void insert(TrieNode* root, string word) {
	TrieNode* curr = root;

	for (char c : word) {
		if ((curr -> child).find(c) == (curr -> child).end()) {
			TrieNode* node = getNewTrieNode(c);
			(curr -> child)[c] = node;
		}
		curr = (curr -> child)[c];
		curr -> count = curr -> count + 1;
	}
}

int query(TrieNode* root, string word) {
	TrieNode* curr = root;
	int ans = 0;
	for (char c : word) {
		if ((curr -> child).find(c) == (curr -> child).end()) {
			return 0;
		}
		ans = ((curr -> child)[c] -> count);
		curr = (curr -> child)[c];
	}
	return ans;
}

vector<int> solve(vector<int> &A, vector<string> &B) {
	TrieNode* root = getNewTrieNode('0');
	int n = A.size();
	vector<int> result;
	for (int i = 0; i < n; i++) {
		int type = A[i];
		if (type == 0) {
			insert(root, B[i]);
		} else {
			int ans = query(root, B[i]);
			result.push_back(ans);
		}
	}
	return result;
}

int main() {
	// vector<int> A = {0, 0, 1, 1};
	// vector<string> B = {"hack", "hacker", "hac", "hak"};
	// 2 0

	vector<int> A = {0, 1};
	vector<string> B = {"abcde", "abc"};
	//

	vector<int> result = solve(A, B);
	for (int num : result)
		cout << num << " ";
	cout << "\n";
	return 0;
}