package day_2;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class Solution {
    public static Node copyRandomList(Node head) {
        Map<Node, Node> copyMap = new HashMap<>();
        return copyRandomList(head, copyMap);
    }

    public static Node copyRandomList(Node node, Map<Node, Node> copyMap) {
        if (Objects.isNull(node)) {
            return null;
        }
        Node res = new Node(node.val);
        copyMap.put(node, res);
        res.next = copyRandomList(node.next, copyMap);
        res.random = copyMap.get(node.random);
        return res;
    }
}

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
