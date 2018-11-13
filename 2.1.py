'''
2.1

Write code to remove duplicates from an unsorted linked list.

FOLLOW UP 
How would you solve this problem if a temporary buffer is not allowed?
'''

class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def __str__(self):
        return "%s->%s" % (self.data, self.next_node)


def remove_duplicates(head):
    seen = set()
    prev_node = None 

    while head:
        if head.data in seen:
            prev_node.next_node = head.next_node
        else:
            seen.add(head.data)
            prev_node = head

        head = head.next_node


def remove_duplicates2(head):
    while head:
        runner = head.next_node
        prev_node = head

        while runner:
            if runner.data == head.data:
                prev_node.next_node = runner.next_node
            else:
                prev_node = runner 

            runner = runner.next_node

        head = head.next_node


if __name__ == '__main__':
    head = Node('apple', Node('orange', Node('orange', Node('apple', Node('apple', Node('orange', Node('apple')))))))
    print(head)
    remove_duplicates(head)
    print(head)
