package com.problemsolving;

public class ImplementStrStr {
	public static int strStr(String haystack, String needle) {
		if (needle.isEmpty())
			return 0;
		if (needle.length() > haystack.length()) {
			return -1;
		}

		int result = -1;

		for (int haystackIndex = 0; haystackIndex < haystack.length(); haystackIndex++) {
			int needleStartIndex = 0;
			int needleEndIndex = needle.length() - 1;
			boolean matchFound = false;
			if ((haystackIndex + needleEndIndex) < haystack.length()) {
				while (needleStartIndex < needle.length() && needleStartIndex <= needleEndIndex) {
					if (((haystackIndex + needleStartIndex) < haystack.length()
							&& haystack.charAt(haystackIndex + needleStartIndex) == needle.charAt(needleStartIndex))
							&& haystack.charAt(haystackIndex + needleEndIndex) == needle.charAt(needleEndIndex)) {
						if (needleStartIndex == 0) {
							result = haystackIndex;
						}
						needleStartIndex++;
						needleEndIndex--;
						matchFound = true;
					} else {
						matchFound = false;
						result = -1;
						break;
					}
				}
				if (matchFound) {
					break;
				}
			}
		}
		return result;
	}

	public static void main(String[] args) {
		System.out.println(strStr("a", "a"));
	}
}
