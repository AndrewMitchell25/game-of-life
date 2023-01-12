#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define ROWS 40
#define COLS 40

// function takes in a 2D array and the number of rows and columns.
void create_board(char board[ROWS][COLS], int rows, int cols)
{
    // initialize the array by using nested for loops to access every value and set it to space
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// function takes in a 2D array and an x and y position
void add_x(char board[ROWS][COLS], int posx, int posy)
{
    // set the value at the index of the inputted position to X
    board[posy][posx] = 'X';
}

// function takes in a 2D array and an x and y position
void remove_x(char board[ROWS][COLS], int posx, int posy)
{
    // set the value at the index of the inputted position to space
    board[posy][posx] = ' ';
}

// function takes in a 2D array and the number of rows and columns
void display(char board[ROWS][COLS], int rows, int cols)
{
    // use a for loop to print the top row of the box
    for (int i = 0; i <= cols; i++)
    {
        printf("---");
    }
    printf("\n");
    // use nested for loops to print every value of the array
    for (int i = 0; i < rows; i++)
    {
        // print the walls of the box
        printf("|");
        for (int j = 0; j < cols; j++)
        {
            printf("%3c", board[i][j]);
        }
        printf("|\n");
    }
    // use a for loop to print the bottom row of the box
    for (int i = 0; i <= cols; i++)
    {
        printf("---");
    }
    printf("\n");
}

// function takes in a 2D array and two values representing a position
int count_neighbors(char board[ROWS][COLS], int posx, int posy)
{
    // create a variable to hold the count
    int n = 0;
    // use two for loops to run through a 3x3 box around the inputted position
    for (int i = posy - 1; i <= posy + 1; i++)
    {
        for (int j = posx - 1; j <= posx + 1; j++)
        {
            // check to see if the values are inside the bounds of the array and not the current position itself
            if ((i == posy && j == posx) || (i < 0 || j < 0) || (i >= ROWS || j >= COLS))
            {
                continue;
            }
            // if the value of the position being checked is an X then increase the count
            if (board[i][j] == 'X')
            {
                n++;
            }
        }
    }
    return n; // return the count
}

// function takes in two 2D arrays and the number of rows and columns
void calculate(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    // use two for loops to iterate through every value in the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // call the count_neighbors function on the current value
            int n = count_neighbors(board, j, i);
            // these if statements check the rules of the game, setting values to space or X depending on the rules
            if (board[i][j] == ' ' && n == 3)
            {
                new_board[i][j] = 'X';
            }
            else if (board[i][j] == 'X' && (n == 2 || n == 3))
            {
                new_board[i][j] = 'X';
            }
            else
            {
                new_board[i][j] = ' ';
            }
        }
    }
    // after calculating the positions into the new board, use nested loops to set the old board equal to the new board
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}

// function takes in two 2D arrays and the number of rows and columns
void update(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    // clear the current screen
    system("clear");
    // call the calculate function to set the board equal to the new position
    calculate(board, new_board, rows, cols);
    // call the display function to print the board to the screen
    display(board, rows, cols);
}

// function takes in two 2D arrays and the number of rows and columns
void continuous_update(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    // use an infinite while loop to continue updating
    while (1)
    {
        // call the update function
        update(board, new_board, rows, cols);
        // wait before running through the loop again
        usleep(100000);
    }
}

// function takes in two 2D char arrays and the number of rows and columns
int get_input(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    // create variables
    char in;
    int posx;
    int posy;
    // get user input
    printf("Enter input: ");
    scanf("%c", &in);
    getchar();
    // use a switch statement for the various cases of user input
    switch (in)
    {
    case 'a':
        scanf("%d %d", &posx, &posy);
        getchar();
        add_x(board, posx, posy);
        break;
    case 'r':
        scanf("%d %d", &posx, &posy);
        getchar();
        remove_x(board, posx, posy);
        break;
    case 'n':
        update(board, new_board, rows, cols);
        break;
    case 'p':
        continuous_update(board, new_board, rows, cols);
        break;
    case 'q':
        return 0;
        break;
    default:
        printf("Invalid input. Please try again.");
        break;
    }
    return 1;
}

// function takes in a char array, two 2D arrays and the number of rows and columns
void get_file_input(char argv[], char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    char in;
    int posx;
    int posy;
    // create a file pointer and open the file that was input
    FILE *fp;
    fp = fopen(argv, "r");
    // print an error if the file is not found
    if (!fp)
    {
        printf("File %s cannot be found.\n", argv);
        return;
    }
    // use an infinite while loop to continually get input
    while (1)
    {
        // read the next char in the file
        in = fgetc(fp);
        // use a switch statement to handle individual cases
        switch (in)
        {
        case 'a':
            fscanf(fp, "%d %d", &posx, &posy);
            add_x(board, posx, posy);
            break;
        case 'r':
            fscanf(fp, "%d %d", &posx, &posy);
            remove_x(board, posx, posy);
            break;
        case 'p':
            continuous_update(board, new_board, rows, cols);
            break;
        case 'q':
            return;
            break;
        default:
            printf("Invalid input. Please try again.");
            break;
        }
        if (feof(fp))
        {
            printf("Reached end of file.\n");
            return;
        }
    }
    return;
}

// function takes in two 2D char arrays and the number of rows and columns
void interactive_init(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols)
{
    // calls the create_board function on the two inputted arrays
    create_board(board, ROWS, COLS);
    create_board(new_board, ROWS, COLS);
    // continuously call the get_input function using a while loop
    int cont = 1;
    while (cont == 1)
    {
        cont = get_input(board, new_board, rows, cols);
    }
}

// function takes in two 2D char arrays and the number of rows and columns
void batch_init(char board[ROWS][COLS], char new_board[ROWS][COLS], int rows, int cols, int argc, char argv[])
{
    // calls create_board on the two char arrays
    create_board(board, ROWS, COLS);
    create_board(new_board, ROWS, COLS);
    // calls the get_file_input function
    get_file_input(argv, board, new_board, rows, cols);
}
