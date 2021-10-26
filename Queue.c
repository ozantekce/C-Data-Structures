#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node* next;
    struct Node* prev;
};


struct Queue{

    int size;
    struct Node* first;
    struct Node* last;

}queue;


void add(int data){

    if(queue.size==0){
        queue.first = (struct Node*) malloc(sizeof(struct Node));
        queue.first->data = data;
        queue.last = queue.first;
        queue.size++;
    }else{
        queue.last->prev = (struct Node*) malloc(sizeof(struct Node));
        queue.last->prev->next = queue.last;
        queue.last = queue.last->prev;
        queue.last->data = data;
        queue.size++;
    }

}


int dequeue(){

    if(queue.size>0){
        int val = queue.first->data;
        queue.first = queue.first->prev;
        queue.size--;
        return val;
    }

    return -1;
}


int main(){

    
    for (int i = 0; i < 10; i++)
    {
        add(i);
    }

    while (queue.size>0)
    {
        printf("%d\n",dequeue());
    }
    



    return 0;

}

