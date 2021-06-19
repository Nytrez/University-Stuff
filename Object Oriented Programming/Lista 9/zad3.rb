require_relative 'zad1'
require 'gnuplot'
class Funkcja
  def plot a, b

    Gnuplot.open do |gp|
     Gnuplot::Plot.new( gp ) do |plot|

         plot.terminal "svg"
         plot.output "graph.svg"
         plot.xrange "[#{a}:#{b}]"
         plot.ylabel "x"
         plot.xlabel "y"

         x = (a..b) .collect { |v|v.to_f }
         y = x.collect { |v| value(v)}

         plot.data << Gnuplot::DataSet.new( [x, y] ) do |ds|
           ds.with = "lines"
         end


     end
    end
  end
end

if  __FILE__ == $0
  f = Funkcja.new { |x| x*x  }
  f.plot -100, 100
end