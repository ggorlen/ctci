'''
2.5

You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds the two numbers and
returns the sum as a linked list.

Ex:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2), that is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

Follow up:
Suppose the digits are stored in forward order. Repeat the above problem.

Ex: 
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
'''

class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def __str__(self):
        return "%s->%s" % (self.data, self.next_node)


def list_sum(a, b):
    remainder = 0
    head = Node()
    current = head

    while a or b:
        a_value = 0
        b_value = 0

        if a:
            a_value = a.data
            a = a.next_node

        if b:
            b_value = b.data
            b = b.next_node

        total = a_value + b_value + remainder
        
        if total > 9:
            current.data = int(str(total)[1])
            remainder = 1
        else:
            current.data = total 
            remainder = 0
            
        if a or b:
            current.next_node = Node()
            current = current.next_node
    
    if remainder > 0:
        current.next_node = Node(remainder)

    return head

    
def list_sum2(a, b):
    return list_reverse(list_sum(list_reverse(a), list_reverse(b)))
    

def list_reverse(head):
    current = head.next_node
    previous = head

    while current:
        previous.next_node = current.next_node
        next_current = current.next_node
        current.next_node = head
        head = current
        current = next_current

    return head


if __name__ == "__main__":
    print(list_sum(Node(7, Node(1, Node(6))), Node(5, Node(9, Node(2)))))
    print(list_sum2(Node(6, Node(1, Node(7))), Node(2, Node(9, Node(5)))))
