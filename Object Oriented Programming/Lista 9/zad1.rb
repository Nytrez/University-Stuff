class Funkcja

    def initialize (&init)
        @function = init
    end
  
    def value (x)
      @function.call x
    end
  
    def zero (a, b, e)

      i = a
      
      while i <= b
        if value(i) == 0
          return i 
        end
        i=i+e 
      end 

      return nil
    end
  
    def field (a, b)
      pole = 0
      $n = 1000
      @dx = (b - a) / $n.to_f
  
      $n.times { |x| pole += @dx * value( a + x * @dx) }
  
      return pole
    end
  
    def deriv (x)
      $h = 1.0e-10 
      return (value(x + $h) - value(x)) / $h
    end
  
  end
  if __FILE__ == $0
    f = Funkcja.new { |x| x * x - 1}
    puts f.value(3)
    puts f.deriv(3)
    puts f.field(-1, 1)
    puts f.zero(-2, 2, 1)
    puts f.zero(0, 3, 0.00001)
  
  end