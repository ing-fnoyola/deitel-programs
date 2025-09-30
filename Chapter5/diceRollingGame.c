#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

enum Status {CONTINUE, WON, LOST}; //Constants represent game status

int rollDice(void); //Function prototype
void playGame(void);

int main(void) {
    srand(time(NULL)); //applying the seed that we input

    bool running = true; //bool para controlar el bucle
    int sentinel = 0;

    while(running) {

        printf("Input 1 for PLAY, -1 for exit: \n");

        int result = scanf("%d", &sentinel);

        if(result == 1) { //scanf si recibió un int 
            if(sentinel == 1) {
                playGame();
            }
            else if(sentinel == -1) {
                running = false;
            }
            else { //si ingresó numero pero no es 1 ni -1
                printf("Please input a valid option!\n");
            }
        }
        else{ //scanf no recibió un int
            if(feof(stdin)) {
                printf("\nEnd of Input Detected\n");
                running = false;
            }
            else {
                printf("Please input a valid number!\n");
                while(getchar() != '\n');
            }
        }
    }
    printf("Closing game...\n");

}

int rollDice(void) {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;

    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    
    return die1 + die2; //return sum of dice
}

void playGame(void) {
    int myPoint = 0; //player must make this point to win
    enum Status gameStatus = CONTINUE; //may be CONTINUE, WON or LOST
    int sum = rollDice(); //first roll of the dice
    
    //determine the game status based on sum of dice
    switch(sum) {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sum; //remember the point
            printf("Point it %d\n", myPoint);
            break;
    }

    while(CONTINUE == gameStatus) {
        sum = rollDice(); //roll the dice again

        //determine game status
        if(sum == myPoint) {
            gameStatus = WON;
        }
        else if(7 == sum) {
            gameStatus = LOST;
        }
    }
    
    //display won or lost message
    if(WON == gameStatus) {
        puts("Player wins!");
    }
    else {
        puts("Player loses :(");
    }
}