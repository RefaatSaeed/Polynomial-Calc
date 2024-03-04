//
// Created by refaa on 5/19/2023.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coef;
    int expon;
    node *link;

}node;

node *new_node (float coef,int expon){
    node *n=(node *)malloc(sizeof(node));
    n->coef=coef;
    n->expon=expon;
    n->link=NULL;
    return n;
}
bool is_empty(node *head){
    return !(head);
}

bool check_zero_coef(node *n){
    return !n->coef;
}

bool check_zero_expon(node *n){
    return !n->expon;
}
void insert_first(node **head,node *n){
    if(is_empty(*head))
        *head=n;
    else{
        n->link=*head;
        *head=n;
    }
}

void insert_end(node **head,node *n){
    if(is_empty(*head))
        *head=n;
    else{
        node *p=*head;
        while(p->link){
            p=p->link;
        }
        p->link=n;
    }
}

bool expo_equality(node ** head,node *n){
    node *p=*head;
    while (p){
        if(p->expon == n->expon){
            p->coef +=n->coef;
            return true;
        };
        p=p->link;
    }
    return false;
}



void insert_sorted(node **head,node *n) {
    if(check_zero_coef(n))return;
    if(!expo_equality(head,n)){
        //if it is true the value will be added to the same term;
        if (is_empty(*head)){
            insert_first(head, n);}
        else if (!(*head)->link) {
            if ((*head)->expon <= n->expon)
                insert_first(head, n);
            else
                insert_end(head, n);
        }
        else {
            node *before = *head;
            node *after = (*head)->link;
            if(before->expon <n->expon)// because it will not check
            { insert_first(head, n);
                return;}
            while (after) {
                if (after->expon < n->expon) break;
                else {
                    before = before->link;
                    after = after->link;
                }
            }
            n->link=after;
            before->link=n;
        }
    }
}

void print(node *head){
    int terms=0;
    int start=1;
    if(is_empty(head))
        printf("0\n");
    else {
        node *p = head;
        printf("f(X) = ");
        while (p) {
            if (start) {
                if(p->coef == 0)goto label1;
                if(p->expon == 1 && p->coef == 1){
                    printf("X");
                    terms=1;
                }
                else if(check_zero_expon(p)){
                    printf("(%.1f)",p->coef);
                    terms=1;
                }
                else if(p->coef == 1){
                    printf("X^%d",p->expon);
                    terms=1;}
                else if(p->expon == 1){
                    printf("(%.1f)X",p->coef);
                    terms=1;
                }
                else{
                    printf("(%.1f)X^%d", p->coef, p->expon);
                    terms=1;}
                start = 0;
            }
            else {
                if(p->coef == 0)goto label1;
                if(p->expon == 1 && p->coef == 1){
                    printf(" + X");
                    terms=1;
                }
                else if(check_zero_expon(p)){
                    printf(" + (%.1f)",p->coef);
                    terms=1;
                }
                else  if(p->coef == 1){
                    printf(" + X^%d",p->expon);
                    terms=1;}
                else if(p->expon == 1){
                    printf(" + (%.1f)X",p->coef);
                    terms=1;
                }
                else{
                    printf(" + (%.1f)X^%d", p->coef, p->expon);
                    terms=1;}

            }
            label1:
            { p = p->link;
                if(terms == 0){printf("0\n");};
            }
        }
        printf("\n");
    }
}
