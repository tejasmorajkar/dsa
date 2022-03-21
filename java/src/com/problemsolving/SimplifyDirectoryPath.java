package com.problemsolving;

import java.util.ArrayList;
import java.util.Vector;

class SimplifyDirectoryPathSolution {
    //region Using reverse linked list
    private class Node {
        String value;
        Node parent;

        Node(String str, Node parent) {
            this.value = str;
            this.parent = parent;
        }
    }

    private Node createNewNode(Node parent, String value) {
        Node newNode = new Node(value, parent);
        return newNode;
    }

    public String simplifyPath(String A) {
        Node root = this.createNewNode(null, "");
        Node current = root;
        String[] strArr = A.split("/");
        for (int i = 0; i < strArr.length; i++) {
            String str = strArr[i];
            if (str.equals("..")) {
                if (current != null)
                    current = current.parent;
            } else if (str.equals(".") || str.equals("")) {
                continue;
            } else {
                current = createNewNode(current, str);
            }
        }
        StringBuilder sb = new StringBuilder("/");
        while (current != null) {
            if (!current.value.equals("")) {
                if (!sb.toString().equals("/"))
                    sb.insert(0, "/");
                sb.insert(1, current.value);
            }
            if (current.parent != null)
                current = current.parent;
            else
                current = null;
        }
        return sb.toString();
    }
    //endregion

    //region Using ArrayList
    public String simplifyPath2(String A) {
        StringBuilder sb = new StringBuilder("/");
        ArrayList<String> strList = new ArrayList<>();
        String[] strArr = A.split("/");
        for(String str: strArr) {
            if (str.equals("") || str.equals(".")) {
                continue;
            } else if (str.equals("..")) {
                if(strList.size() > 0)
                    strList.remove(strList.size() - 1);
            } else {
                strList.add(str);
            }
        }
        for (int i = 0; i < strList.size(); i++) {
            sb.append(strList.get(i));
            if (i+1 < strList.size())
                sb.append("/");
        }
        return sb.toString();
    }
    //endregion
}

public class SimplifyDirectoryPath {
    public static void main(String[] args) {
        SimplifyDirectoryPathSolution sol = new SimplifyDirectoryPathSolution();
//        String A = "/./../../giq/xns/zvk/../vkd/qhp/pyf/wie/atv/thv/./kqs/seq/fzw/cav/./../.././rjn/elx/gyn/lla/gkd/zig/qud/vyx/./eqd/ple/vst/loc/./../uak/wvz/vxe/ibc/../bns/psb/./kjo/bky/oks/./cjg/yyh/spf/abt";
//        String A = "/home/";
//        String A = "/a/./b/../../c/";
        String A = "/../";
        String result = sol.simplifyPath2(A);
        System.out.println(result);
    }
}
