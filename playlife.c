#include "lifefunc.h" //include the header file


int main(int argc, char *argv[]){
    //use an if statemtn to check the number of arguments input and run the program in interactive or batch mode
    if(argc == 1){
	//create two 2D arrays and then call the initialization function
        char board[ROWS][COLS];
        char new_board[ROWS][COLS];
        interactive_init(board, new_board, ROWS, COLS);
    } else if(argc == 2){
	//create two 2D arrays and then call the batch initialization function
        char board[ROWS][COLS];
        char new_board[ROWS][COLS];
        batch_init(board, new_board, ROWS, COLS, argc, argv[1]);
    } else {
	//if too many inputs print an error and end the program
        printf("Error - too many inputs.\n");
        return 0;
    }
    return 0;
}
