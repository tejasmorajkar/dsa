#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct CompareListNode {
	bool operator()(ListNode* l1, ListNode* l2) {
		return l1->val > l2->val;
	}
};

// TC: O(mlogk)
// SC: O(m)
// m is count of all elements
// k is size of list
ListNode* mergeKLists(vector<ListNode*> &lists) {
    if (lists.size() == 0)
        return NULL;
    priority_queue<ListNode*, vector<ListNode*>, CompareListNode> pq; 
    for(int i=0; i<lists.size(); i++) {
        if (lists[i])
            pq.push(lists[i]);
    }
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    while(!pq.empty()) {
        ListNode* temp = pq.top();
        curr->next = temp;
        pq.pop();
        if (temp && temp->next)
            pq.push(temp->next);
        curr = curr->next;
    }
    return head->next;
}

void print(ListNode* node) {
	ListNode* curr = node;
	while(curr) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << "\n";
}

int main(){
	ListNode *head1 = new ListNode(4);
	head1->next = new ListNode(5);
	head1->next->next = new ListNode(6);

	ListNode *head2 = new ListNode(100);
	head2->next = new ListNode(101);
	head2->next->next = new ListNode(102);

	ListNode *head3 = new ListNode(-4);
	head3->next = new ListNode(-2);
	head3->next->next = new ListNode(10);

	vector<ListNode*> lists = {head1, head2, head3};
	ListNode* ans = mergeKLists(lists);
	print(ans);
	return 0;
}