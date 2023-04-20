/* 
   Jacob Neiheisel 

   Place all your Connect4 functions here --- except for main.
   main() needs to go in its own separate .c file.
*/
#include "connect4.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
Board * createBoard(int height, int width, int wLength){
     
Board* b;
int heightBoard = height;
int widthBoard = width;
    
    
    
    char** boardMatrix;
    b = (Board *) malloc(sizeof(b));
    

boardMatrix = (char **)malloc(heightBoard * sizeof(char *)); // Allocate row pointers

int index;
for(index = 0; index < heightBoard; index++){
boardMatrix[index] = malloc(widthBoard * sizeof(char));
}
    

int rowInd;
int colInd;
for(rowInd = 0; rowInd < heightBoard; rowInd++){
for (colInd = 0; colInd < widthBoard; colInd++){				
	boardMatrix[rowInd][colInd] = (char) '-';
	}
} 
b->gridMat = boardMatrix;
b->ncols = widthBoard;
b->nrows = heightBoard;
return b;
}


void printBoard(Board* board){

 int arrLen;
 int arrWid;
 for (arrWid = 0; arrWid < (*board).nrows; ++arrWid){
   
    for (arrLen = 0; arrLen < (*board).ncols; ++arrLen){
         
        printf("%c", (*board).gridMat[arrWid][arrLen]);
    }
    printf("\n");
    
 }
 for (arrLen = 0; arrLen < (*board).ncols; ++arrLen){
        printf("%c", 65+arrLen);
    }
    printf("\n");

}

char isValidCol(Board* board, char col, int player){
    char boardCol = col;
    boardCol = toupper(boardCol);
    int colIn = (int)(boardCol) - 65;   
    // zk Just curious:  Why not board->ncols?
    while (colIn < 0 || colIn > (*board).ncols - 1){ 
        fflush(stdin);
        fflush(stdout);
        printf("Invalid Input: Player %d, please enter a column: ", player);
        scanf(" %1c", &boardCol);
        boardCol = toupper(boardCol);
        if(boardCol == 'Q'){
            return 'Q';
        }

        // zk Saying 'A' is cleaner than 65.
        colIn = (int)(boardCol) - 65; 
        fflush(stdin);
        fflush(stdout);
    } 
    //throw a flag if the column is full
    int colFull = 1;
    int forCount;
    for (forCount = (*board).nrows-1; forCount >= 0; forCount --){
        if((char)(*board).gridMat[forCount][colIn] == '-'){
            colFull = 0;
        }
    }
    while(colFull == 1){
        fflush(stdin);
        fflush(stdout);
        printf("Invalid Input: Player %d, please enter a column: ", player);
        scanf(" %1c", &boardCol);
        boardCol = toupper(boardCol);
        if(boardCol == 'Q'){
            return 'Q';
        }
        colIn = (int)(boardCol) - 65;   
        fflush(stdin);
        fflush(stdout);
        colFull = 1;
    for (forCount = (*board).nrows-1; forCount >= 0; forCount --){
        if((char)(*board).gridMat[forCount][colIn] == '-'){
            colFull = 0;
        }
    }
    }
    return colIn;
}
int updateBoard(char col, Board* board, int player){
char colMod = toupper(col);
int column = isValidCol(board, colMod, player);
if(column == 81){
    return -1;
}
int forCount;
int placed = 0;
for (forCount = (*board).nrows-1; forCount >= 0; forCount --){
    
    if((char)(*board).gridMat[forCount][column] == '-'){

        // zk Short-cut:
        // char letter = player == 1 ? 'O' : 'X'

        if(player == 1){
        (*board).gridMat[forCount][column] = 'O'; 
        }
        if(player == 2){
          (*board).gridMat[forCount][column] = 'X'; 
        }
        placed = 1;
        break;
    }
}

return longestCount(board, forCount, column, player);
}


//[row] [col]

int longestCount(Board* board, int rowNum, int colNum, int player){
    int bestCounter;
    int tempCounter;
    int lDiagRow = rowNum;
    int lDiagCol = colNum;
    int rDiagRow = rowNum;
    int rDiagCol = colNum;
    char playerToken;
    if(player == 1){
        playerToken = 'O';
    }
    else{
        playerToken = 'X';
    }
     
    while (lDiagCol + 1 > 0 && lDiagCol + 1 < (*board).ncols && lDiagRow + 1 > 0 && lDiagRow + 1 < (*board).nrows){
        lDiagCol++;
        lDiagRow++;
        
    }
   

    while (rDiagCol - 1 >= 0 && rDiagCol - 1 < (*board).ncols && rDiagRow +1 > 0 && rDiagRow +1 < (*board).nrows){
        rDiagCol--;
        rDiagRow++;
    }
    int rowCounter;
    int colCounter;
    tempCounter = 0;
    bestCounter = 0;
    //get the column count of pieces in a column to see a column win
    for (rowCounter = 0; rowCounter < (*board).nrows; rowCounter++){
        
        if((*board).gridMat[rowCounter][colNum] == playerToken){
            tempCounter++;
        }
        else{
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
            tempCounter = 0;
        }
        if(rowCounter == (*board).nrows-1){
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
        }
    }

    //get the row count of pieces in a row to see a row win
    tempCounter = 0;

    for (colCounter = 0; colCounter < (*board).ncols; colCounter++){
        
        if((*board).gridMat[rowNum][colCounter] == playerToken){
            tempCounter++;
            
        }
        else{
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
            tempCounter = 0;
        }
        if(colCounter == (*board).ncols-1){
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
        }
    }
        tempCounter = 0;
         
    while (lDiagCol >= 0 && lDiagCol - 1 < (*board).ncols && lDiagRow >= 0 && lDiagRow - 1 < (*board).nrows){
        
        if((*board).gridMat[lDiagRow][lDiagCol] == playerToken){
            tempCounter++;
        }
        else{
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
            tempCounter = 0;
        }
        
        lDiagCol--;
        lDiagRow--;
       
    }
     if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }

    tempCounter = 0;
   
    while (rDiagCol + 1 > 0 && rDiagCol < (*board).ncols && rDiagRow >= 0 && rDiagRow < (*board).nrows){
       
         if((*board).gridMat[rDiagRow][rDiagCol] == playerToken){
            tempCounter++;
        }
        else{
            if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
            tempCounter = 0;
        }
       
        rDiagCol++;
        rDiagRow--;
       
    }
     if(tempCounter > bestCounter){
                bestCounter = tempCounter;
            }
return bestCounter;
}

int isBoardFilled(Board* board){
    int rowCount;
    int colCount;
    for (rowCount = 0; rowCount < (*board).nrows; rowCount ++){
    for (colCount = 0; colCount < (*board).ncols; colCount ++){			
	if((*board).gridMat[rowCount][colCount] == (char) '-'){
        return 0;
    }
	}
} 
return 1;
}
// You don't have to use this.  It's just here as a demo.
int x_in_a_row(int x, int length, int array[]) {
    
    // This isn't correct.  It's just for demonstration purposes.
    if (length >=2 && array[0] == array[1]) {
        return array[0];
    } else {
        return -1;
    };
}