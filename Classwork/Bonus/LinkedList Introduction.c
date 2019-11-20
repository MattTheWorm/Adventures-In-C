/*| Matt J. | Started on: 11/16/19 @8:01PM | CIS-170 |

Desc: LinkedList bonus assignment.

*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
//Structure Declaration

struct Part{
    int num;
    int quantity;
    double price;

    struct Part *next;

};

//End
//Function Declaration

void printHelp();
void createList(struct Part **head);

//End
int main(){
    //Parts
    struct Part *Part1 = (struct Part *)malloc(sizeof(struct Part));
    Part1->num = 10;
    Part1->quantity = 10;
    Part1->price = 9.99;
    struct Part *Part2 = (struct Part *)malloc(sizeof(struct Part));
    Part2->num = 10;
    Part2->quantity = 10;
    Part2->price = 9.99;
    struct Part *Part3 = (struct Part *)malloc(sizeof(struct Part));
    Part3->num = 10;
    Part3->quantity = 10;
    Part3->price = 9.99;
    //Head/Next
    struct Part *head = Part1;
    Part1->next = Part2;
    Part2->next = Part3;
    Part3->next = NULL;

    puts("LinkedList session begin.");
    printHelp();
    createList(&head);
    return 0;

}

//////////
// printHelp (C)
//////////
void printHelp(){

    int i;
    for(i = 0; i != 86; i++){//85 Dashes
        putchar('-');

    }

    putchar('\n');
    puts(" What would you like to do?\n");
    printf("\t\"create\"%6s-Create a new part list.\n", "");
    printf("\t\"print\"%7s-Print the current part list if it exists.\n", "");
    printf("\t\"select\"%6s-Print an existing part within the current list.\n", "");
    printf("\t\"modify\"%6s-Modify an existing part within the current list.\n", "");
    printf("\t\"delete\"%6s-Delete an existing part within the current list.\n", "");
    printf("\t\"insert\"%6s-Insert a new part into the current list.\n", "");
    printf("\t\"save\"%8s-Save the part list to a file if it exists.\n", "");
    printf("\t\"add\"%9s-Accept a file of parts and append them to the current list.\n", "");
    printf("\t\"exit\"%8s-Exit the program.\n\n", "");
    printf("\t\"help\"%8s-Open this menu.\n\n", "");
    for(i = 0; i != 86; i++){
        putchar('-');

    }

    putchar('\n');

}
//////////
// deleteList
//////////
void deleteList(struct Part **head){
    if(*head){
        struct Part *temp = (*head)->next;
        //printf("Head data: %d\n", (*head)->num);
        int i = 1;

        puts("[Delete]: List found. Deleting.");
        free(*head); //Free head first
        while(temp){
            *head = temp;
            temp = temp->next;
            free(*head);
            i++;

        }

        *head = NULL;
        printf("[Delete]: %d list items deleted. List cleared.", i);

    }
    else{
        puts("[Delete]: List doesn't exist!");

    }

}
//////////
// createList
//////////
void createList(struct Part **head){
    //File Vars
    FILE *exportFileOut; //Export file out
    DIR *exportFolOut; //Export folder out
    char fileName[65], path[128] = "export/";//Filename Size 64 characters

    //IO Vars
    int failLoop = 1; //Validation var1
    char yesNo = 0;

    if(!*head){//If head is null, AKA no list
        puts("[Create]: No head pointer detected, assuming new list.");

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N]");
        while(failLoop){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer

            switch(yesNo){
                case 'Y': case 'y':
                    puts("User chose yes.");
                    //failLoop = 0;
                    break;

                case 'N': case 'n':
                    puts("[Create]: Discarding current list.");
                    //printf("Head value before: %p\n", *head);
                    deleteList(head);
                    //printf("Head value after: %p\n", *head);
                    //failLoop = 0;
                    break;

                default:
                    puts("[Create]: Invalid input. Enter either Y or N.");

                //-----

            }

        }

    }

}

//End of program []
