/* 
   Jacob Neiheisel

   Place your Connect4's main() function here.
   Anything that you want unit tested must go in a separate file.
*/
# include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "connect4.h"

int main(int argc, char* argv[]) {
    int height;
    int width;
    int winLength;
    int playerUp;
    Board *c4Board;
    int play;
    int win = 0;
 
    //if we only have 0/1 args, we are going to default to a 6*7 board
    if( argc == 0 || argc == 1 ){
        height = 6;
        width = 7;
        winLength = 4;
        c4Board = createBoard(height, width, winLength);
    }
    else {

       char *stats;
       char * stats2;
       stats = strtok(argv[1], "x");
       stats2 = strtok(NULL, "x");
        height = atoi(stats);       
        width = atoi(stats2);    
        char*  win = argv[2];
    
        winLength = atoi(win); 
        if(winLength > height && winLength > width){
        height = 6;
        width = 7;
        winLength = 4;
            c4Board = createBoard(height, width, winLength);
        }  
        else{
            c4Board = createBoard(height, width, winLength);
        }     
        
    }
   
   play = 1;
   playerUp = 1;
   printBoard(c4Board);
   while (play == 1){
    int stopPlay = isBoardFilled(c4Board);
    if(stopPlay == 1){
    printf("It's a Draw!");
        break;
    }
    char col; 
        fflush(stdin);
        fflush(stdout);
        printf("Player %d, please enter a column: \n", playerUp);
        scanf(" %1c", &col);
        if(col == 'q'){
            play = 0;
            printf("Goodbye.");
            break;
        }
        fflush(stdin);
        fflush(stdout);
        int longestString = updateBoard(col, c4Board, playerUp);
        if (longestString == winLength){
            printBoard(c4Board);
            win = 1;
            play = 0;
            printf("Congratulations, Player %d. You win.", playerUp);
        }
        else if (longestString == -1){
           play = 0;
            printf("Goodbye.");
            break; 
        }
        if(win == 0 && play == 1){
        printBoard(c4Board);
        
        
        if(playerUp == 1){
            playerUp = 2;
        }
        else{
            playerUp = 1;
        }
       
       
       }
   }
   int index;
for(index = 0; index < height; index++){
free(c4Board->gridMat[index]); 
}
    free(c4Board->gridMat);
   free(c4Board);


       return 0;

    }


   
