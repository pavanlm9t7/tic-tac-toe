#include <stdio.h>


char spot[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
char mark = 'X'; //X or O
int  position, player, gameStatus; //Status to continue or finish the game 

char checkForWinner();
void drawBoard();
void updatePlayer();
void markSpot(int position);
char checkDraw();
void endGame(char W);


int main(){
player = 1;
gameStatus = 0;
do{
    drawBoard();
    printf("Enter the spot for player[%d]: ", player);
    scanf("%d", &position);
    markSpot((position-1));
    char c = checkForWinner(); 
    char d = checkDraw();  
    if(c != 'c' && d != 'f'){
        endGame(c);
    }
    drawBoard();
    
}while(gameStatus != 1);
}


/*
This function would check the non empty space characters ' ' and count them if it is equal to the totoal number of spots
and end the loop
*/
char checkDraw(){
    int count = 0;
    for(int i = 0; i <(sizeof(spot)/sizeof(spot[0])); i++){
        if(spot[i] != ' '){
            count++;
        }
    }
    if(count == (sizeof(spot)/sizeof(spot[0])))
    {   
        printf("Its a draw game !!!\n");
        gameStatus = 1;
        drawBoard();
        return 'f';
    }
    return 't';
}


/*
This function checks the row wise, column wise and then diagonally if the characters are same then returns the character that is
occured else returns 'c'
*/
char checkForWinner(){
    for(int i = 0; i <= 6; i += 3){
        if(spot[i] != ' '){
            if(((spot[i] == 'X') && (spot[i] == spot[i+1]) && (spot[i] == spot[i+2])) || ((spot[i] == 'O') && (spot[i] == spot[i+1]) && (spot[i] == spot[i+2]))){
                return spot[i];
                break;
            }
        }
        
    }
    for(int i = 0; i < 3; i++){

        if(spot[i] != ' '){
            if(((spot[i] == 'X') && (spot[i] == spot[i+3]) && (spot[i] == spot[i+6])) || ((spot[i]== 'O') && (spot[i] == spot[i+3]) && (spot[i] == spot[i+6]))){
                return spot[i];
                break;
            }
        }
        
    }
    for(int i = 0; i<3; i += 3){
        if(spot[i] != ' '){
            if(((spot[i] == 'X') && (spot[i] == spot[i+4]) && (spot[i] == spot[i+8])) || ((spot[i] == 'O') && (spot[i] == spot[i+4]) && (spot[i] == spot[i+8]))){
                return spot[i];
                break;
            }
        }
    }

    return 'c';
}
/*
This function is called if the checkforWinner function returns character other than 'c', Then checks if it is 'X' or 'O' then prints Winner
*/
void endGame(char w){
    gameStatus = 1;
    if(w == 'X'){
        printf("Player 1 wins \n");
    }
    if(w == 'O'){
        printf("Player 2 wins\n");
    }
}
/*
This function would update the player credentials accordingly the chance, as the rule the first player should choose symbol 'X'
*/
void updatePlayer(){
    if(player == 1){
        player = 2;
        mark = 'O';
    }else{
        player = 1;
        mark = 'X';
    }
}
/*
This function would check for empty spots and would retain th eplayer chance if non empty spot from 0-8 is choosed
*/
void markSpot(int position){
    if(spot[position] == ' ' && position >= 0 && position <= 8){
        spot[position] = mark;
        updatePlayer();
    }else{
        printf("Invalid spot selected chose empty spot!!!\n");
    }
    
}
/*
This function would print the updated positions of the array in matrix form till the player won or its draw.
*/ 
void drawBoard(){
    printf("\n");
    printf("        |        |        \n");
    printf("    %c   |    %c   |   %c   \n", spot[0], spot[1], spot[2]);
    printf("        |        |        \n");
    printf("---------------------------\n");
    printf("        |        |        \n");
    printf("    %c   |    %c   |   %c   \n", spot[3], spot[4], spot[5]);
    printf("        |        |        \n");
    printf("---------------------------\n");
    printf("        |        |        \n");
    printf("    %c   |    %c   |   %c   \n", spot[6], spot[7], spot[8]);
    printf("        |        |        \n");
}



