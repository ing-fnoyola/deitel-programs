#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int guessNumber(int number, int guess);
int validate(void);

int main(void) {
    srand(time(NULL)); //randomize rand() every iteration
    int r = 0;

    while( r != -1) {

        int number = (rand() % 1000) + 1;
        int guess = 0;
        int win = 0;

        printf("Im thinking in a number between 1-1000. Try to guess!\n");

        while(win != 1) {
            int lock1 = scanf("%d", &guess);
            if(lock1 == 1) {
                win = guessNumber(number, guess);
            } else {    
                r = validate();
                if(r == -1) {
                    break;
                }
            }
        }
      
    }
    printf("Closing program...\n");
}

int guessNumber(int number, int guess) {

    if(number == guess) {
        printf("Congrats! Are you using magic?\n");
        return 1;
    } else {
        if(guess < number) {
            printf("Too low buddy! Try again...\n");
            return 0;
        } else {
            printf("Too high buddy! Try again...\n");
            return 0;
        }

    }

}

int validate(void) {
    if( feof(stdin) ) { //EOF - End of File 
        printf("\n End of Input Detected\n");
        return -1;
    } else {
        printf("Please input a valid number!\n\n");
        while( getchar() != '\n' );
        return 1;
    }
}