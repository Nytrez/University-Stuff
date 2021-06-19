  class Jawna  
    def initialize(string)
      @string = string
    end

    def to_s
        @string
    end
  
    def zaszyfruj(key)
      zaszyfrowane = ""
      inverted = key.invert
      for letter in @string.split('')
        if inverted.include? letter
          zaszyfrowane += inverted[letter]
        else
          zaszyfrowane += letter
        end
      end
      Cypher.new(zaszyfrowane)
    end
  end

  class Cypher
    def initialize(string)
      @string = string
    end

    def to_s
        @string
    end
  
    def oszyfruj(key)
      zaszyfrowane = ""
      for letter in @string.split('')
        if key.include? letter
          zaszyfrowane += key[letter]
        else
          zaszyfrowane += letter
        end
      end
      Jawna.new(zaszyfrowane)
    end
  end
  
  klucze = {"a"=>"c", "b"=>"d", "c"=>"e", "d"=>"f", "e"=>"g", "f"=>"h", "g"=>"i", "h"=>"j", "i"=>"k",
      "j"=>"l", "k"=>"m", "l"=>"n", "m"=>"o", "n"=>"p", "o"=>"r", "p"=>"s", "r"=>"t", "s"=>"u", "t"=>"v",
      "u"=>"w", "v"=>"x", "w"=>"y", "x"=>"z", "y"=>"a", "z"=>"b"}
      
  szyfrowane = Cypher.new("ciezki szyfr").oszyfruj(klucze)
  puts szyfrowane
  deszyfrowane = szyfrowane.zaszyfruj(klucze)
  puts deszyfrowane