class Number
  def to_ruby
    "-> e { #{value.inspect} }"
  end
end

class Boolean
  def to_ruby
    "-> e { #{value.inspect} }"
  end
end

class Variable
  def to_ruby
    "-> e { e[#{name.inspect}]}"
  end
end
