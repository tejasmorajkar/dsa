package com.problemsolving;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class ClimbingLeaderboard {
	public static List<Integer> climbingLeaderboard(List<Integer> ranked, List<Integer> player) {
		List<Integer> result = new ArrayList<Integer>();
		removeDuplicates(ranked);
		int currentScoreIndex = ranked.size() - 1;
		for (int i = 0; i < player.size(); i++) {
			int currentScore = player.get(i);
			currentScoreIndex = getRank(ranked, currentScore, currentScoreIndex);
			ranked.add(currentScoreIndex, currentScore);
			result.add(currentScoreIndex + 1);
		}

		return result;
	}

	private static void removeDuplicates(List<Integer> ranked) {
		HashSet<Integer> set = new HashSet<Integer>(ranked);
		ranked.clear();
		ranked.addAll(set);
	}

	public static int getRank(List<Integer> list, int currentScore, int currentScoreIndex) {
		for (int i = currentScoreIndex; i >= 0; i--) {
			if (currentScore == list.get(i)) {
				return i - 1;
			} else if (currentScore < list.get(i)) {
				return i + 1;
			}
		}
		return 0;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Integer> ranked = new ArrayList<Integer>();
		List<Integer> player = new ArrayList<Integer>();
		String[] str = "100 100 50 40 40 20 10".split(" ");
		for (String s : str) {
			ranked.add(Integer.valueOf(s));
		}
		str = "5 25 50 120".split(" ");
		for (String s : str) {
			player.add(Integer.valueOf(s));
		}
		List<Integer> result = climbingLeaderboard(ranked, player);
		System.out.println(result);
	}
}
