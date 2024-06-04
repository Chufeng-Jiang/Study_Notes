class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """

        """
        We can create a dummy node to start our new linkedlist, and declare a cursor to mark current node pointing to this dummy node.
        """
        cur = dum = ListNode(0)

        """
        Then we compare the values of the pointed nodes in the existed sorted linked lists: 
            (1) we linked the node with smaller value to the next pointer of the current node;
            (2) if the values are the same, we firstly linked the node from the second list.
            (3) once one of the linkedlists end, the next pointer of the current node will linked to the rest part of the other linkedlist.
        """
        while list1 and list2:
            if list1.val < list2.val:  ## case(1)
                cur.next, list1 = list1, list1.next
            else:  ## case(2)
                cur.next, list2 = list2, list2.next
            cur = cur.next

        cur.next = list1 if list1 else list2  # case (3)

        return dum.next


""""""""""""""""""""""""""""""""


def linked_list_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next
    return result


def test():
    solution = Solution()
    nodel1_1 = ListNode(1)
    nodel1_2 = ListNode(2)
    nodel1_4 = ListNode(4)
    nodel1_1.next = nodel1_2
    nodel1_2.next = nodel1_4

    nodel2_1 = ListNode(1)
    nodel2_2 = ListNode(3)
    nodel2_4 = ListNode(4)
    nodel2_1.next = nodel2_2
    nodel2_2.next = nodel2_4

    q3 = solution.mergeTwoLists(nodel1_1, nodel2_1)
    result_list = linked_list_to_list(q3)
    expected_list = [1, 1, 2, 3, 4, 4]

    if result_list == expected_list:
        print("Q3 Test case passed.\n")


test()
