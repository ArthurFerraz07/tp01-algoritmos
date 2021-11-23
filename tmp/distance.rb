M = 5
N = 5

def distance(x1, y1, x2, y2)
  dx = (x1 - x2).abs
  dy = (y1 - y2).abs

  min = [dx, dy].min
  max = [dx, dy].max

  diagonal_steps = min
  straight_steps = max - min

  # diagonal_steps -= 1 unless diagonal_steps.zero?
  # straight_steps -= 1 unless straight_steps.zero?

  # puts diagonal_steps
  # puts straight_steps



  # if diagonal_steps >= [M, N].min - 1
  #   diagonal_steps -= 1
  # end
  diagonal_steps

  d = diagonal_steps + straight_steps
  d.zero? ? d : d - 1
end


# def distance(x1, y1, x2, y2)
#   w = (x2 - x1).abs




# end









x1 = 1
y1 = 1
x2 = 6
y2 = 5

puts "Distance from (#{x1},#{y1}) to (#{x2},#{y2}) is #{distance(x1, y1, x2, y2)}"

(0..0).each do |x1|
  (0..0).each do |y1|
    (0..4).each do |x2|
      (0..4).each do |y2|
        distance = distance(x1, y1, x2, y2)
        puts "Distance from (#{x1},#{y1}) to (#{x2},#{y2}) is #{distance}"# if distance == 4
      end
    end
  end
end
