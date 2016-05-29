#!/usr/bin/env ruby
# encoding: UTF-8
#Se ejecuta haciendo ruby script.rb <tu nombre con la primera letra en mayusculas>
system( "g++ -std=c++11 ./src/cena_gala_nacho.cpp -o ./bin/cena_gala_nacho" )
system( "mkdir ./data/" + ARGV[0].to_s )
system( "mkdir ./grphx/" + ARGV[0].to_s )
puts "Ejecutando cena_gala_nacho..."
(1..250).each do |x|
  if(x%50==0)
    puts "Iteracion: " + x.to_s
  end
  system( "./bin/cena_gala_nacho " + x.to_s + " >> ./data/" + ARGV[0].to_s + "/cena_gala_nacho" + ".dat")
end
puts "Generando gráfica de cena_gala_nacho..."
system("gnuplot graficas_" + ARGV[0].to_s + ".gp")
