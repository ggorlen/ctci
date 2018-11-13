# 2.7
# 
# Implement a function to check if a linked list is a palindrome

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

class LinkedList
  def self.length head
    length = 0

    while head
      head = head.next_node
      length += 1
    end

    length
  end

  def self.palindrome? head
    len = length(head) + 1
    mid = len / 2
    curr = head

    mid.odd? ? mid : mid + 1.times do 
      len -= 2
      runner = curr
      len.times {runner = runner.next_node}

      return false if curr.data != runner.data

      curr = curr.next_node
    end

    true
  end
end

p LinkedList.palindrome? Node.new(1, Node.new(2, Node.new(3, Node.new(1, nil))))
p LinkedList.palindrome? Node.new(1, Node.new(2, Node.new(2, Node.new(1, nil))))
p LinkedList.palindrome? Node.new(1, Node.new(2, Node.new(3, nil)))
p LinkedList.palindrome? Node.new(1, Node.new(2, Node.new(1, nil)))
p LinkedList.palindrome? Node.new(1, Node.new(2, nil))
p LinkedList.palindrome? Node.new(1, Node.new(1, nil))
p LinkedList.palindrome? Node.new(1, nil)
