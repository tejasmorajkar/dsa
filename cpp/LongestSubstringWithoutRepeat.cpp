#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string A) {
    int i = 0, j = 0, n = A.length(), len = 1;
    unordered_map<char, int> freq;

    while (j < n && i <= j) {
    	freq[A[j]]++;
    	if (freq.find(A[j]) != freq.end() && freq[A[j]] == 1) {
    		len = max(len, j - i + 1);
    		j++;
    	} else {
    		while (freq[A[j]] > 1) {
    			freq[A[i]]--;
    			i++;
    		}
    		j++;
    	}
    }
    return len;
}

int main() {
	string A = "abcabcbb"; // 3
	// string A = "AaaA"; // 2
	// string A = "dadbc"; // 4
	int ans = lengthOfLongestSubstring(A);
	printf("%d\n", ans);
	return 0;
}