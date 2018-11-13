# 3.2 
# 
# How would you design a stack which, in addition to push and pop, 
# also has a function min which returns the minimum element? Push, pop
# and min should all operate in O(1) time.

class MinStack
  def initialize 
    @stack = []
    @min = []
  end

  def min
    @min.last
  end

  def pop
    @min.pop
    @stack.pop
  end

  def push item
    @stack << item
    @min << (@min.empty? ? item : [item, @min.last].min)
  end

  def to_s
    @stack.to_s
  end
end

ms = MinStack.new
9.times {ms.push rand(1..9)}
9.times do 
  puts "stack: #{ms} min: #{ms.min}"
  puts "stack: #{ms} pop: #{ms.pop}"
end
