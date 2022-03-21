#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	bool isEnd;
};

TrieNode* getNewTrieNode() {
	TrieNode* temp = new TrieNode;
	temp -> isEnd = false;
	return temp;
}

void insert(TrieNode* root, string str) {
	TrieNode* curr = root;
	for (char c : str) {
		if ((curr -> children).find(c) == (curr -> children).end())
			(curr -> children)[c] = getNewTrieNode();
		curr = (curr -> children)[c];
	}
	curr -> isEnd = true;
}

bool query(TrieNode* cur, int i, string &s, int flag, bool last) {
	bool ans = false;
	int n = s.size();
	if (i == n) {
		if (flag == 1 && last)
			return true;
		return false;
	}
	char c = s[i];

	if (flag == 0) {
		for (auto it = (cur -> children).begin(); it != (cur -> children).end(); it++) {
			if (it->first == c)
				ans = ans | query(it->second, i + 1, s, flag, it->second ->isEnd);
			else
				ans = ans | query(it->second, i + 1, s, 1 - flag, it->second ->isEnd);
		}
	} else {
		if ((cur -> children).find(c) != (cur -> children).end())
			ans = ans | query((cur -> children)[c], i + 1, s, flag, (cur->children)[c] -> isEnd);
	}
	return ans;
}

string solve(vector<string> &A, vector<string> &B) {
	TrieNode* root = getNewTrieNode();

	for (int i = 0; i < A.size(); i++)
		insert(root, A[i]);

	string result = "";
	for (int i = 0; i < B.size(); i++) {
		bool ans = query(root, 0, B[i], 0, false);
		if (ans)
			result += "1";
		else
			result += "0";
	}
	return result;
}

int main() {
	// vector<string> A = {"data", "circle", "cricket"};
	// vector<string> B = {"date", "circel", "crikket", "data", "circl"};
	// "10100"

	vector<string> A = {"hello", "world"};
	vector<string> B = {"hella", "pello", "pella"};
	// "110"

	string ans = solve(A, B);
	cout << ans << "\n";
	return 0;
}