#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// Get size of LL
	// Move till prev of node to be deleted
	// point prev node to next of next
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p1 = head,*p2 = head;
		int size = 0;

		while (p1) {
			p1 = p1 -> next;
			size++;
		}

		if (n >= size) {
			head = head -> next;
		} else {
			for (int i = 0; i < size - n - 1; i++) {
				p2 = p2 -> next;
			}
			p2 -> next = p2 -> next -> next;
		}
		return head;
	}

	void printLL(ListNode *head) {
		ListNode *curr = head;
		while (curr) {
			printf("%d ", curr -> val);
			curr = curr -> next;
		}
		printf("\n");
	}
};

int main() {
	ListNode *head;
	head -> val = 1;
	ListNode *p1;
	p1 -> val = 2;
	head -> next = p1;
	ListNode *p2;
	p2 -> val = 3;
	p1 -> next = p2;
	ListNode *p3;
	p3 -> val = 4;
	ListNode *p4;
	p4 -> val = 5;
	p3 -> next = p4;
	int n = 2;

	Solution s;
	ListNode *ans = s.removeNthFromEnd(head, n);
	// s.printLL(ans);

	return 0;
}