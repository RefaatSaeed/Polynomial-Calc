
#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(){

    char choice[10];
    int ch;
    char coef[10],expon[10];
    node *pol1=NULL;
    node *pol2=NULL;
    node *n;
    node *mul=NULL;
    node *s=NULL;
    while (1) {
        menu();
        scanf_s(" %[^\n]s", choice);
        if (isValid_ch(choice)) {

            ch = atoi(choice);
            switch (ch) {
                case 1:
                    label1:
                        printf("Coef: ");
                        scanf_s(" %[^\n]s", coef);
                        printf("Expon: ");
                        scanf_s(" %[^\n]s", expon);
                        if(isValid(coef) && isValid_ch(expon)) {
                            n = new_node(atof(coef), atoi(expon));
                            insert_sorted(&pol1, n);
                        }
                        else{
                            printf("Only numbers are allowed\n");
                            goto label1;
                        }
                        break;

                case 2:
                label2:
                    printf("Coef: ");
                    scanf_s(" %[^\n]s", coef);
                    printf("Expon: ");
                    scanf_s(" %[^\n]s", expon);
                    if(isValid(coef) && isValid_ch(expon)){
                        n= new_node(atof(coef),atoi(expon));
                        insert_sorted(&pol2,n);
                    }
                    else{
                        printf("Only numbers are allowed\n");
                        goto label2;
                    }
                    break;
                case 3:
                    print(pol1);
                    break;
                case 4:
                    print(pol2);
                    break;
                case 5:
                    s=sum(pol1, pol2);
                    break;
                case 6:
                    mul=multiply(pol1,pol2);
                    break;
                case 7:
                    char y[10];
                    float x;
                    label3:
                    printf("Value of X: ");
                    scanf_s(" %[^\n]s", y);
                    printf("1. Evaluate pol1\n");
                    printf("2. Evaluate pol2\n");
                    printf("3. Evaluate sum\n");
                    printf("4. Evaluate mul\n");
                    printf("choice: ");
                    scanf_s(" %[^\n]s", choice);
                    if (isValid_ch(choice)&& isValid(y)) {
                        ch = atoi(choice);
                        x=atof(y);
                        switch(ch){
                            case 1:
                                evaluate(pol1,x);
                                break;
                            case 2:
                                evaluate(pol2,x);
                                break;
                            case 3:
                                evaluate(s,x);
                                break;
                            case 4:
                                evaluate(mul,x);
                                break;
                            default:
                                printf("invalid inputs\n");
                                goto label3;
                        }
                    }
                    else{
                        printf("Only numbers are allowed\n");
                        goto label3;
                    }
                    break;
                case 0:
                    printf("See you later\n");
                    exit(-1);
                default:
                    printf("Invalid Inputs\n");
            }
        } else
            printf("Invalid Inputs\n");

    }
}