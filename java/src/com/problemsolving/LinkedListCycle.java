package com.problemsolving;

import java.util.ArrayList;
import java.util.List;

public class LinkedListCycle {
	// Iterative approach
	public static boolean hasCycle2(ListNode head) {
		List<ListNode> visited = new ArrayList<ListNode>();
		while(head != null) {
			if (visited.contains(head)) {
				return true;
			}
			visited.add(head);
			head = head.next;
		}
		return false;
    }
	
	// O(1) memory
	public static boolean hasCycle(ListNode head) {
		if (head == null || head.next == null)
			return false;
		
		ListNode walker = head;
		ListNode runner = head;
		
		while(runner.next != null && runner.next.next != null) {
			walker = walker.next;
			runner = runner.next.next;
			
			if (walker == runner) 
				return true;
		}
		
		return false;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode tail = new ListNode(4);
		ListNode l1 = new ListNode(3, new ListNode(2, new ListNode(0, tail)));
		int pos = 1;
		ListNode current = l1;
		if (pos != -1) {
			while(pos != 0) {
				current = current.next;
				pos--;
			}
			tail.next = current;
		}
		boolean result = hasCycle(l1);
		System.out.println(result);
	}
}
