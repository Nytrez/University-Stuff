class Integer
    # class variable
    @@liczby_slownie = ["zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec"]
  
    def czynniki
      czynnik = []
      for i in 1..self
        czynnik << i if self % i == 0
      end
      czynnik
    end
  
    def ack(y)
      return y + 1 if self == 0
      return (self-1).ack(1) if y == 0
      (self-1).ack(self.ack(y-1))
    end
  
    def doskonala?
      self == self.czynniki.sum - self # czynniki liczby minus ta liczba czy rowne 0
    end
  
    def slownie
        if self == 0
            return @@liczby_slownie[0]
        end

        num = self
        napis = ""
        while num > 0
            napis+= @@liczby_slownie[num%10] + " "
            num/=10
        end
        napis.split.reverse.join(" ")
        
    end
  end
  
  puts "czynniki of 6 = #{6.czynniki}"
  puts "czynniki of 12 = #{12.czynniki}"
  puts "ack(2,1) = #{2.ack(1)}"
  puts "is 6 doskonala?: #{6.doskonala?}"
  puts "is 28 doskonala?: #{28.doskonala?}"
  puts "is 42 doskonala?: #{42.doskonala?}"
  puts "6 = #{6.slownie}"
  puts "42 = #{42.slownie}"
  puts "0 = #{0.slownie}"
  puts "307 = #{307.slownie}"