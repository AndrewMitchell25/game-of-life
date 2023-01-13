# Game of Life
This is a program that was designed to model [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

# Running the Program
This program is designed to run in the Linux terminal. To run the project, download the files from this repo onto your local machine. Open the terminal and move to the folder containing the project files. Use the command `make` to build the project files. The program has two modes: getting interactive input, or getting input from a file. To use the first mode, interactive, simply run the program with the `./playlife`. When prompted, provide input for the starting scenario of the Game of Life in the following manner: 
* `a #x #y` - adds an X at position x, y
* `r #x #y` - removes an X at position x, y
* `n` - moves forward one step or generation in the Game of Life
* `p` - starts the Game of Life
* `q` - ends the program

Adding a file name after the command to run the program (ex. `./playlife scene1.txt`) will use the contents of that file as input instead of taking input from the user (I suggest trying the included scenes 3-5).

Have fun!
