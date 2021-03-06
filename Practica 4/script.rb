#!/usr/bin/env ruby
# encoding: UTF-8
#Se ejecuta haciendo ruby script.rb <tu nombre con la primera letra en mayusculas>
system( "g++ -std=c++11 ./src/cena_gala_nacho.cpp -o ./bin/cena_gala_nacho" )
system( "mkdir ./data/" + ARGV[0].to_s )
system( "mkdir ./grphx/" + ARGV[0].to_s )
system( "rm ./data/" + ARGV[0].to_s + "/*" )
puts "Ejecutando cena_gala_nacho..."
(1..250).each do |x|
  if(x%50==0)
    puts "Iteracion: " + x.to_s
  end
  system( "./bin/cena_gala_nacho " + x.to_s + " >> ./data/" + ARGV[0].to_s + "/cena_gala_nacho" + ".dat")
end

system( "g++ -std=c++11 ./src/cena_gala_backtracking_cuentaperdida.cpp -o ./bin/cena_gala_backtracking_cuentaperdida" )
puts "Ejecutando cena_gala_backtracking_cuentaperdida..."
(1..10).each do |x|
  puts "Iteracion: " + x.to_s
  system( "./bin/cena_gala_backtracking_cuentaperdida " + x.to_s + " >> ./data/" + ARGV[0].to_s + "/cena_gala_backtracking_cuentaperdida" + ".dat")
end

system("g++ -std=c++11 ./src/cena_gala_luis.cpp -o ./bin/cena_gala_luis")
puts "Ejecutando cena_gala_luis..."
(1..10).each do |x|
  puts "Iteracion: " + x.to_s
  system("./bin/cena_gala_luis " + x.to_s + " >> ./data/" + ARGV[0].to_s + "/cena_gala_luis" + ".dat")
end

system("g++ -std=c++11 ./src/cena_gala_diego.cpp -o ./bin/cena_gala_diego")
puts "Ejecutando cena_gala_diego..."
(2..20).each do |x|
  puts "Iteracion: " + x.to_s
  system("./bin/cena_gala_diego " + x.to_s + " >> ./data/" + ARGV[0].to_s + "/cena_gala_diego" + ".dat")
end

puts "Generando gráficas..."
system("gnuplot graficas_" + ARGV[0].to_s + ".gp")
