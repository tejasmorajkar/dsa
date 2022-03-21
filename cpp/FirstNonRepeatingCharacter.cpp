#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	string solve(string A) {
	    queue<char> q;
	    unordered_map<char, int> freq;
	    string ans = "";
	    
	    for (char ch: A) {
	        freq[ch]++;
	        // Push to queue only when freq of char is 1
	        if (freq[ch] == 1)
	        	q.push(ch);

	        // Use freq map to remove duplicates from queue
	        // Pop q until freq of q.front is 1 
	        while (!q.empty() && freq[q.front()] > 1)
	            q.pop();

	        if (q.empty())
	            ans += '#';
	        else
	            ans += q.front();        
	    }
	    return ans;
	}
 };

int main() {
	// string A = "abadbc"; // aabbdd
	// string A = "abcabc"; // aaabc#
	string A = "jyhrcwuengcbnuchctluxjgtxqtfvrebveewgasluuwooupcyxwgl";
	// jjjjjjjjjjjjjjjjjjjjjyyyyyyyyyyyyyyyyyyyyyyyyyyyqqqqq

	Solution s;
	string result = s.solve(A);
	printf("%s\n", result.c_str());
	return 0;
}