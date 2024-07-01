class Solution:
    def getListLength(self, head: Optional[ListNode]) -> int:
        curr = head
        length = 0
        while curr:
            curr = curr.next
            length += 1
        return length

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = self.getListLength(head)
        if length == n:
            temp = head.next
            del head
            return temp
        remaining = length - n - 1
        curr = head
        while remaining:
            curr = curr.next
            remaining -= 1
        curr.next = curr.next.next
        return head

        