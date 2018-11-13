# 2.4
# 
# Write code to partition a linked list around a value x, such that all 
# nodes less than x come before all nodes greater than or equal to x

class Node
  attr_accessor :val, :next_node

  def initialize val, next_node
    @val = val
    @next_node = next_node
  end    

  def to_s
    "#{@val}->#{@next_node}"
  end
end

def partition_around head, n
  curr = head
  left_head, left_curr = nil
  right_head, right_curr = nil

  while curr
    if curr.val < n
      if left_head
        left_curr.next_node = curr
        left_curr = left_curr.next_node
      else
        left_head, left_curr = curr, curr
      end
    else
      if right_head
        right_curr.next_node = curr
        right_curr = right_curr.next_node
      else
        right_head, right_curr = curr, curr
      end
    end

    curr = curr.next_node
  end

  left_curr.next_node = right_head if left_curr
  head = left_head if left_head
  right_curr.next_node = nil
  head
end
                

head = Node.new 7, nil
curr = head

[2, 9, 1].each do |v|
  curr.next_node = Node.new v, nil
  curr = curr.next_node
end

puts head
puts partition_around head, 5
