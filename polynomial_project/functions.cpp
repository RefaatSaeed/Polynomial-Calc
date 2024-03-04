//
// Created by refaa on 5/19/2023.
//
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include "header.h"

void menu(){
    printf("\n1.insert term in first function\n");
    printf("2.insert term in second function\n");
    printf("3.print polynomial 1\n");
    printf("4.print polynomial 2\n");
    printf("5.Sum two polynomials\n");
    printf("6.Multiply two polynomials\n");
    printf("7.Evaluate\n");
    printf("0.Exit\n");
    printf("\nchoice: ");

}

bool isValid_ch(char *exp){
    bool valid=true;
    int i=0;

    while(exp[i]!='\0'){
        if(!isdigit(exp[i]) || exp[i]==' '){
            valid=false;
            break;
        }
        i++;
    }
    return valid;
}
bool isValid(char *exp){
    int i=0;
    while(exp[i]!='\0'){
        if(!isdigit(exp[i])) {
            if(exp[i] != '.' && exp[i]!= '-')
                return false;
        }
        i++;
    }
    return true;
}

node * sum(node *pol1 ,node *pol2){
    if(!(pol1) || !(pol2)){
        printf("Please enter two polynomial functions first to sum\n");
        return nullptr;
    }
    node *sum=NULL;
    node *n;
    node *p1=pol1;
    node *p2;
    int expon_equal;
    //printf("\npol1 = ");print(pol1);
    //printf("\npol2 = ");print(pol2);
    while(p1){
        p2=pol2;
        expon_equal=0;
        while(p2 && p1->expon <= p2->expon){
            //printf("%d. p1 coef= %d,expon= %d\n",i,p1->coef,p1->expon);
            //printf("%d. p2 coef= %d,expon= %d\n",i++,p2->coef,p2->expon);
            if(p2->expon == p1->expon){
                n=new_node (p1->coef + p2->coef,p1->expon);
                //printf("%d. %dX^%d\n",i++,n->coef,n->expon);
                insert_sorted(&sum,n);
                expon_equal=1;
                break;
            }
            p2=p2->link;
        }
        if(expon_equal == 0){
            n=new_node(p1->coef,p1->expon);
            insert_sorted(&sum,n);
        }
        p1=p1->link;
    }
    p2=pol2;
    while(p2){
        if(missing_term(pol1,p2)){
            n=new_node (p2->coef,p2->expon);
            insert_sorted(&sum,n);
        }
        p2=p2->link;
    }
    printf("sum: \n");
    print(sum);
    return sum;
}

bool missing_term(node *head,node *term){
    node *p=head;
    while(p){
        if(term->expon == p->expon)
            return false;
        p=p->link;
    }
    return true;

}


node * multiply(node *pol1,node *pol2){
    if(!(pol1) || !(pol2)){
        printf("Please enter two polynomial functions first to multiply\n");
        return nullptr;
    }
    node *mul=NULL;
    node *p1=pol1;
    node *p2;
    node *n;
    while(p1){
        p2=pol2;
        while(p2){
            n=new_node(p1->coef * p2->coef,p1->expon +p2->expon);
            insert_sorted(&mul,n);
            p2=p2->link;
        }
        p1=p1->link;
    }
    printf("Mul: \n");
    print(mul);
    return mul;
}



void evaluate(node *pol,float x){
    if(!pol){
        printf("Enter equation first\n");
        return;
    }
    else{
        node *p=pol;
        float res=0;
        while(p){
            res+= (p->coef*pow(x,p->expon));
            p=p->link;
        }
        printf("Result: %.1f\n",res);
    }
}