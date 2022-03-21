package com.problemsolving;

public class MergeTwoSortedList {
	// Iterative approach
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if (l1 == null)
			return l2;

		if (l2 == null)
			return l1;

		ListNode head = null;
		ListNode tail = null;
		ListNode newNode;
		while (l1 != null || l2 != null) {
			if (l1 != null && (l2 == null || (l1.val < l2.val))) {
				newNode = new ListNode(l1.val);
				l1 = l1.next;
			} else {
				newNode = new ListNode(l2.val);
				l2 = l2.next;
			}
			if (head == null) {
				head = newNode;
				tail = newNode;
			} else {
				tail.next = newNode;
				tail = tail.next;
			}
		}
		return head;
	}
	
	// Recursion solution
	public static ListNode mergeTwoLists2(ListNode l1, ListNode l2) {
		if (l1 == null) 
			return l2;
		if (l2 == null) 
			return l1;
		
		if (l1.val < l2.val) {
			l1.next = mergeTwoLists2(l1.next, l2);
			return l1;
		} else {
			l2.next = mergeTwoLists2(l1, l2.next);
			return l2;
		}
	}

	public static void print(ListNode l) {
		while (l != null) {
			System.out.print(l.val + " ");
			l = l.next;
		}
	}

	public static void main(String[] args) {
		ListNode l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
		ListNode l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
//		var l1 = new ListNode();
//		var l2 = new ListNode();

		ListNode result = mergeTwoLists2(l1, l2);
		print(result);
	}
}