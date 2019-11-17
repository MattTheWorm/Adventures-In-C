#include <stdio.h>
#include <stdlib.h>
//Struct Declaration

struct dataNode{
    int data;
    struct dataNode *next;

};

//End
//Function Declaration

void addNode(struct dataNode *head); //Add node at end of list.
void printList(struct dataNode *head); //Print the entire list from head to tail.

//End

int main(){
    int i;
    struct dataNode *head;

    head = (struct dataNode *)malloc(sizeof(struct dataNode));
    head->next = 0;
    head->data = 0;
    for(i = 0; i != 20; i++){
        addNode(head);

    }

    printList(head);
    return 0;

}

void addNode(struct dataNode *head){
    if(head){
        int i = 1;
        struct dataNode *temp = head;

        printf("Attempting node creation.. Head value: %p\n", head);
        while(temp->next){
            //printf("Temp next value: %p\n", temp->next);
            temp = temp->next;
            i++;

        }

        temp->next = (struct dataNode *)malloc(sizeof(struct dataNode));
        if(temp->next){
            printf("Successfully made an additional node! | Address: %p | Index: %d\n", temp->next, i);
            temp->next->next = 0;
            temp->next->data = i;

        }
        else{
            printf("Could not create node.\n");

        }

    }

}

void printList(struct dataNode *head){
    if(head){
        int i = 0;
        struct dataNode *temp = head;

        printf("Print request received. Attempting to print linked list from head.\n");
        printf("--------------------\n");//20
        while(temp){
            printf("Node found! [Index %d | Address: %p | Data: %d]\n", i, temp, temp->data);
            temp = temp->next;
            i++;

        }

        printf("--------------------\n");//20
        printf("List printing complete. %d nodes in total found.\n", i);

    }

}


