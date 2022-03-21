package com.problemsolving;

import java.util.Stack;

/**
 * Definition for singly-linked list.
 */
class ListNode {
	int val;
	ListNode next;

	ListNode() {
	}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}

class Solution {

	/**
	 * Iterative approach
	 * 
	 * @param head Input linked list
	 * @return reversed Input linked list
	 */
	public ListNode reverseList(ListNode head) {
		ListNode headNode = null;
		ListNode tailNode = null;
		ListNode current = head;
		Stack stack = new Stack<Integer>();

		while (current != null) {
			stack.push(current.val);
			current = current.next;
		}

		while (!stack.isEmpty()) {
			ListNode newNode = new ListNode((Integer) stack.pop());
			if (headNode == null) {
				headNode = newNode;
				tailNode = newNode;
			} else {
				tailNode.next = newNode;
				tailNode = newNode;
			}
		}
		return headNode;
	}

	// Iterative approach without extra stack or array object
	public ListNode reverseList2(ListNode head) {
		ListNode previous = null;
		ListNode current = head;
		ListNode next = null;

		while (current != null) {
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
		}

		return previous;
	}

	// Using recursion
	public ListNode reverseList3(ListNode head) {
		if (head == null || head.next == null)
			return head;

		ListNode current = reverseList3(head.next);
		head.next.next = head;
		head.next = null;
		return current;
	}
}

public class ReverseLinkedList {
	public static void main(String[] args) {
		ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
		new Solution().reverseList3(head);
	}
}
