#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;
    struct Node* prev;
};


struct Stack{

    int size;
    struct Node* top;

}stack;


void push(int data){

    if(stack.size==0){
        stack.size++;
        stack.top = (struct Node*) malloc(sizeof(struct Node));
        stack.top->data = data;
        return;
    }

    stack.size++;

    stack.top->next = (struct Node*) malloc(sizeof(struct Node));

    stack.top->next->prev = stack.top;

    stack.top = stack.top->next;
    
    stack.top->data = data;

}


int pop(){

    if(stack.size>0){
        int val = stack.top->data;
        if(stack.size>1)
        stack.top =stack.top->prev;
        stack.size--;
        return val;
    }else{

        return -1;

    }

}

int main(){

    
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    while (stack.size>0)
    {
        printf("%d\n",pop());
    }
    



    return 0;

}

