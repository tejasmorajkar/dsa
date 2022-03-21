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
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reorderList(ListNode* head) {
	// 1. Divide LL into 2 parts from middle
    ListNode* slow = head;
    ListNode* fast = head -> next;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // slow now points to middle
    ListNode* head2 = slow -> next;
    // Unlink 
    slow -> next = NULL;

    // 2. Reverse the second part of the LL
    ListNode* curr = head2;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while (curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    // 3. Link the 2 LL in zig-zag fashion
    ListNode* curr1 = head;
    // prev points to last node of second LL
    ListNode* curr2 = prev;

    while (curr1 != NULL && curr2 != NULL) {
        ListNode* temp1 = curr1 -> next;
        curr1 -> next = curr2;
        curr1 = temp1;
        ListNode* temp2 = curr2 -> next;
        curr2 -> next = curr1;
        curr2 = temp2;
    }
    return head;
	}
};