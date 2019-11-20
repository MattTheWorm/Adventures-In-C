/*| Matt J. | Started on: 11/16/19 @8:01PM | CIS-170 |

Desc: LinkedList bonus assignment.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <string.h>
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
<<<<<<< HEAD
void deleteList(struct Part **head);
void saveList(struct Part **head);
int createList(struct Part **head);

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
=======
void createList(struct Part *head);

//End
int main(){
    struct Part Part1 = {10, 10, 9.99, NULL};
    struct Part *head = &Part1;

    puts("[Main]: LinkedList session begin.\n");
    printHelp();
    createList(head);
>>>>>>> master
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
// saveList
//////////
void saveList(struct Part **head){
    //File Vars
    FILE *exportFileOut; //Export file out
    DIR *exportFolOut; //Export folder out
    char fileName[65], path[77] = "export/";//Filename Size 64 characters w/null 65 characters | export/ + .csv  + null + fileName = 77(?)

    //IO Vars
    int failLoop = 1, i; //Validation Var1

    puts("[Save]: Save session started.");
    if(!(exportFolOut = opendir("export"))){//If export folder doesn't exist
        if(!mkdir("export")){//Then attempt to make export folder
            if(!(exportFolOut = opendir("export"))){//If it still can't be opened..
                puts("[Save]: Export folder creation failed! Sorry, program exiting.");
                exit(EXIT_FAILURE);

            }

        }
        else{//If export folder can't be made..
            puts("[Save]: Export folder creation failed! Sorry, program exiting.");
            exit(EXIT_FAILURE);

        }

    }

    puts("[Save]: Export folder created, enter your filename. [Max 64 characters]");
    while(failLoop){
        fputs("Input: ", stdout);
        fgets(fileName, sizeof(fileName), stdin);
        i = 0;
        while(fileName[i] != '\0'){//While it's not the end of the string
            //printf("Current char: %c | Index: %d\n", fileName[i], i);
            if(fileName[i] == '\n'){//If newline character found..
                //printf("Found. | Index: %d", i);
                fileName[i] = '\0';//Change to null

            }

            i++;

        }

        //printf("User entered: %s", fileName);
        if(!(exportFileOut = fopen(strcat(strcat(path, fileName), ".csv"), "w"))){
            puts("[Save]: File creation failed! Sorry, program exiting.");
            exit(EXIT_FAILURE);

        }

    puts("[Save]: File creation succeeded. Attempting to save list.");
    /*----------

    LIST SAVING

    ----------*/



    }

    //printf("Export folder pointer: %p\n", (void *)exportFolOut);

}
//////////
// deleteList
//////////
void deleteList(struct Part **head){
    if(*head){ //If head exists
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
        printf("[Delete]: %d list items deleted. List cleared.\n", i);

    }
    else{
        puts("[Delete]: List doesn't exist!");

    }

}
//////////
// createList
//////////
<<<<<<< HEAD
int createList(struct Part **head){//0 Return success, else fail (for now).
    //IO Vars
    char yesNo = 0;

    if(!*head){//If head is null, AKA no list
=======
void createList(struct Part *head){
    //File Vars
    FILE *exportFileOut; //Export file pointer
    DIR *exportFolOut; //Export folder pointer
    char fileName[128], path[137] = "exports/";
    //IO Vars
    char yesNo;

    if(!head){//If list head exists (AKA list exists)
>>>>>>> master
        puts("[Create]: No head pointer detected, assuming new list.");
        return 0;

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N]");
<<<<<<< HEAD
        while(1){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer

            switch(yesNo){
                case 'Y': case 'y':
                    saveList(head);
                    break;

                case 'N': case 'n':
                    puts("[Create]: Discarding current list, and creating new list.");
                    //printf("Head value before: %p\n", (void *)*head);
                    deleteList(head);
                    //printf("Head value after: %p\n", (void *)*head);
                    createList(head);
                    return 0;

                default:
                    puts("[Create]: Invalid input. Enter either Y or N.");

                //-----

            }
=======
        fputs("Input: ", stdin);
        yesNo = getchar();
        while(getchar() != '\n'); //Clear buffer
        getchar();
>>>>>>> master

        }

    }
}

//End of program []
