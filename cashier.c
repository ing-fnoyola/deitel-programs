#include <stdio.h>

int main(void) { 
    
    int o = 0;
    float bal = 0;
    float aux = 0;

    float op1=-9999, op2=-9999, op3=-9999, op4=-9999;
    char o1='N', o2='N', o3='N', o4='N', auxO='N';

    while(o != 4) {

        printf("\nSelect an option: \n");
        printf("1-View balance\n2-Deposit\n3-Withdraw\n4-Close program\n\n");

        if(scanf("%d", &o)) {
            switch(o) {
                case 1:
                    printf("\nCurrent balance: $%.2f\n", bal);
                    printf("Last operations:\n");
                    if(o1 != 'N') {
                        printf("%s%.2f\n",(o1=='D')?"Deposit ":"Withdrawal: ", op1);
                    } else{
                        printf("No operations yet...\n");
                    }
                    if(o2 != 'N') {
                        printf("%s%.2f\n", (o2=='D')?"Deposit ":"Withdrawal: ", op2);
                    }
                    if(o3 != 'N') {
                        printf("%s%.2f\n", (o3=='D')?"Deposit ":"Withdrawal: ", op3);
                    }
                    if(o4 != 'N') {
                        printf("%s%.2f\n", (o4=='D')?"Deposit ":"Withdrawal: ", op4);
                    }
                    break;
                case 2:
                    printf("\nInput the amount to deposit:\n");
                    scanf("%f", &aux);

                    if(aux<0) {
                        printf("\nInput a valid amount (positive)!\n");
                    }
                    else {
                        bal += aux;
                        printf("New balance: $%.2f\n\n", bal);
                        op4=op3;
                        op3=op2;
                        op2=op1;
                        op1=aux;
                        o4=o3;
                        o3=o2;
                        o2=o1;
                        o1='D';
                    }
                    break;
                case 3:
                    printf("\nInput the amount to withdraw:\n");
                    scanf("%f", &aux);

                    if(aux<0) {
                        printf("\nInput a valid amount (positive)!\n\n");
                    }
                    else {
                        if(aux>bal) {
                            printf("\nInsufficient funds!\n\n");
                        }
                        else {
                            bal -= aux;
                            printf("New balance: $%.2f\n\n", bal);
                            op4=op3;
                            op3=op2;
                            op2=op1;
                            op1=aux;
                            o4=o3;
                            o3=o2;
                            o2=o1;
                            o1='W';
                        }
                    }
                    break;
                case 4:
                    printf("Closing program...\n\n");
                    o=4;
                    break;
                default:
                    printf("Input a valid option!\n\n");
                    break;
            }
        }
        else {
            printf("Input a valid option!\n");
            while( getchar() != '\n' );
        }

        
    }
    
    return 0;

}
