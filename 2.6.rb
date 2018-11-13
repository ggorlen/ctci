# 2.6
#
# Given a circular linked list, implement an algorithm which 
# returns the node at the beginning of the loop. 
# 
# DEFINITION:
# Circular linked list: a corrupt linked list in which a node's 
# next pointer points to an earlier node, so as to make a loop 
# in the linked list.
# 
# EXAMPLE:
# Input: A -> B -> C -> D -> E -> C (the same C as earlier)
# Output: C

class Node
  attr_accessor :data, :next_node

  def initialize data, next_node
    @data = data
    @next_node = next_node
  end  
      
  def to_s
    "#{@data}->#{@next_node}"
  end  
end  

def find_circular_node head
  seen = {}
  curr = head

  while curr
    return curr if seen.has_key? curr

    seen[curr] = 1
    curr = curr.next_node
  end
end


e = Node.new "E", nil
d = Node.new "D", e
c = Node.new "C", d
b = Node.new "B", c
a = Node.new "A", b
e.next_node = c
puts find_circular_node(a).data
