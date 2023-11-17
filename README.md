# game_life
This is a console game life, made according to the principles of Conway. 
The right one CMakeLists.txt located in the app directory. Standard input file: example.life.
Standard output file: output Universe.life. The format of the game files is life1.06 with two 
new lines #N name and #R B<numbers in 0..8>/S<numbers in 0..8>. 

There are 2 game modes:
./game_life <input_file> - online mode
./game_life <input_file> <count_ticks> <output_file> - offline mode
