class Solution(object):
    def middleNode(self, head):
        current_node = head
        runner_node = head

        while runner_node is not None and runner_node.next is not None:
            current_node = current_node.next
            runner_node = runner_node.next.next

        return current_node
