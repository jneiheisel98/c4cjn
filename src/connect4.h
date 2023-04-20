//Jacob Neiheisel
#ifndef CONNECT4_H
#define CONNECT4_H

// Declare your helper functions here.
typedef struct Board{
	char * grid;
	char **gridMat;
	int nrows;
	int ncols;
    int wLen;
    
} Board;
void printBoard(Board* board);
Board* createBoard(int length, int width, int wLength);
// You don't have to use this.  It's just here as a demo.
int isBoardFilled(Board* board);
int updateBoard(char col, Board* board, int player);
int x_in_a_row(int x, int length, int array[]);
int longestCount(Board* board, int rowNum, int colNum, int player);
char isValidCol(Board* board, char col, int player);

#endif