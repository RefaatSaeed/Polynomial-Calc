//
// Created by refaa on 5/19/2023.
//

#ifndef POLYNOMIAL_PROJECT_HEADER_H
#define POLYNOMIAL_PROJECT_HEADER_H
//LL.cpp
struct node{
    float coef;
    int expon;
    node *link;

};
node *new_node (float coef,int expon);
bool is_empty(node *head);
void insert_first(node **head,node *n);
void insert_end(node **head,node *n);
bool expo_equality(node ** head,node *n);
void insert_sorted(node **head,node *n);
void print(node *head);

//functions.cpp
void menu();
node * sum(node *pol1 ,node *pol2);
bool missing_term(node *head,node *term);
bool isValid(char *exp);
bool isValid_ch(char *exp);
node * multiply(node *pol1,node *pol2);
void evaluate(node *pol,float x);


#endif //POLYNOMIAL_PROJECT_HEADER_H
