#include <stdio.h>

int main(void) { 
    
    int n = 0;
    while(n != -1) {

        printf("%s", "Input a decimal number: \n");

        if(scanf("%d", &n)) {

            if(n==-1) {
                 printf("Closing program...\n");
            } else {
            
                //CONVERSION A BINARIO
                int aux = n;
                int div = 1;

                //DIVISOR INICIA EN 1 Y SE INCREMENTA EN 2 (BITS) HASTA SER EL NUMERO MAS GRANDE POSIBLE
                //PERO MENOR O IGUAL A N
                while(div <= n) {
                    div *= 2;
                }
                div /= 2;

                printf("Decimal: %d\n", n);

                printf("Binario: ");

                while(div > 0) {
                    printf("%d", aux/div);
                    aux %= div;
                    div /= 2;
                }
                printf("%s", "\n");

                //CONVERSION A OCTAL
                aux = n;
                div = 1;

                //DIVISOR INICIA EN 1 Y SE INCREMENTA POR 8 (OCTALES) HASTA SER EL NUMERO MAS GRANDE POSIBLE
                //PERO MENOR O IGUAL A N
                
                printf("Octal: ");

                while(div <= n) {
                    div *= 8;
                }
                div /= 8;

                while(div > 0) {
                    printf("%d", aux/div);
                    aux %= div;
                    div /= 8;
                }
                printf("%s", "\n");

                printf("Hexadecimal: ");

                //CONVERSION A HEXADECIMAL
                aux = n;
                div = 1;

                while(div <= aux) {
                    div *= 16;
                }
                div /= 16;

                int aux2 = 0;
                while(div > 0) {
                    aux2 = aux/div;
                    switch(aux2) {
                        case 10:
                            printf("A");
                            break;
                        case 11:
                            printf("B");
                            break;
                        case 12:
                            printf("C");
                            break;
                        case 13:
                            printf("D");
                            break;
                        case 14:
                            printf("E");
                            break;
                        case 15:
                            printf("F");
                            break;
                        default:
                            printf("%d", aux2);
                    }
                    aux %= div;
                    div /= 16;

                }
                printf("\n");

            }

        }
        else {
            printf("%s", "Input a decimal number!\n");
            while(getchar() != '\n');
        }
        
    }
    
    return 0;

}
