#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int top=-1;//GLOBAL VARIABLE NO NEED TO PASS TO FUNCTIONS

char* push(char* stack, char c);

char* pop(char* stack);

char Top(char* stack);

bool empty(char* stack);

void print_stack(char* stack);

int main(){
    char stack[50];
    char input_string[100];
    
    printf("enter string of parentheses: ");
    scanf("%s",input_string);//auto null terminates
    //printf("len is: %ld\n",strlen(input_string)); len not including NULL char
    int n = strlen(input_string);
    for (int i=0;i<n;i++){
        char c = input_string[i];
        switch(c){
            case '(':{
                strcpy(stack,push(stack,')'));//deals with top inside function only
                print_stack(stack);
                break;
            }
            case '[':{
                strcpy(stack,push(stack,']'));
                print_stack(stack);
                break;                
            }
            case '{':{
                strcpy(stack,push(stack,'}'));
                print_stack(stack);
                break;                
            }
            default:{
                if (Top(stack)!=c){
                    printf("not balanced\n");
                    return 0;
                }
                else{
                    strcpy(stack,pop(stack));
                }
            }
        }
    }
    if (empty(stack)){
        printf("balanced string\n");
    }
    return 0;
}

char* push(char* stack, char c){
    stack[++top]=c;
    return stack;
}

char* pop(char* stack){
    top--;
    return stack;
}

char Top(char* stack){
    return stack[top];
}

bool empty(char* stack){
    if (top==-1)
      return true;
    return false;
}

void print_stack(char* stack){
    printf("stack is: ");
    for (int i=0;i<=top;i++){
        printf("%c ",stack[i]);
    }
    printf("\n");
}