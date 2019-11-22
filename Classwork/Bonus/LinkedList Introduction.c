/*| Matt J. | Started on: 11/16/19 @8:01PM | CIS-170 |

Desc: LinkedList bonus assignment.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void inputLoop(char request[], char funcName[], int *valuePointerInt, double *valuePointerLF, int mode);
struct Part * partSearch(struct Part **head, int partNum, char funcName[]);
void modifyStructure(struct Part **head);
void insertStructure(struct Part **head);
int deleteStructure(struct Part **head);
int selectPrint(struct Part **head);
void printList(struct Part **head);
void deleteList(struct Part **head);
void saveList(struct Part **head);
int createList(struct Part **head);

//End
int main(){
    //Parts
    struct Part *Part1 = (struct Part *)malloc(sizeof(struct Part));
    Part1->num = 2;
    Part1->quantity = 11;
    Part1->price = 1.11;
    struct Part *Part2 = (struct Part *)malloc(sizeof(struct Part));
    Part2->num = 4;
    Part2->quantity = 22;
    Part2->price = 2.22;
    struct Part *Part3 = (struct Part *)malloc(sizeof(struct Part));
    Part3->num = 6;
    Part3->quantity = 33;
    Part3->price = 3.33;
    //Head/Next
    struct Part *head = Part1;
    Part1->next = Part2;
    Part2->next = Part3;
    Part3->next = NULL;

    puts("LinkedList session begin.");
    printHelp();
    insertStructure(&head);
    modifyStructure(&head);
    deleteStructure(&head);
    selectPrint(&head);
    printList(&head);
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
// inputLoop | Gets user input (float/int) and loops until the value is valid. | Updating
//////////
void inputLoop(char request[], char funcName[], int *valuePointerInt, double *valuePointerLF, int mode){//Mode 1 - Int | Mode 2 - Double
    puts(request);
    while(1){
        fputs("Input: ", stdout);
        switch(mode){
            case 1:
                if(!(scanf("%d", valuePointerInt))){//If scanf does NOT have match..
                    while(getchar() != '\n'); //Clear buffer
                    printf("[%s]: Invalid input. Try again.");
                    continue;

                }

                break;
            case 2:
                if(!(scanf("%lf", valuePointerLF))){//If scanf does NOT have match..
                    while(getchar() != '\n'); //Clear buffer
                    printf("[%s]: Invalid input. Try again.");
                    continue;

                }

            //---

        }

        while(getchar() != '\n'); //Clear buffer
        break;

    }

}

//////////
// partSearch | Searches for a part by number and returns the pointer to the part struct if it exists. | Updating
//////////
struct Part * partSearch(struct Part **head, int partNum, char funcName[]){
    //Misc Vars
    struct Part *temp = *head;
    int i;

    i = 0;
    if(funcName){
       printf("[%s]: Searching for Part number %d.\n", funcName, partNum);

    }

    while(temp){
        if(temp->num == partNum){
            if(funcName){
                printf("[%s]: Part Number %d found at index %d.\n", funcName, partNum, i);

            }

            return temp;

        }

        temp = temp->next;
        i++;

    }

    if(funcName){
        printf("[%s]: Part not found.\n", funcName);

    }

    return NULL;

};

//////////
// modifyStructure | Finds a part by number and lets the user input modified values. | WIP
//////////
void modifyStructure(struct Part **head){
    if(*head){
        //Misc Vars
        int i;

        //Part Related
        int partNum;
        double partPrice;
        struct Part *partPointer = NULL;

        inputLoop("[Modify]: Enter the Part number you wish to modify.", "Modify", &partNum, 0, 1);
        if(partPointer = partSearch(head, partNum, "Modify")){
            puts("----------\n");//10 Dashes
            inputLoop("Enter new Part quantity.", "Modify", &partPointer->quantity, 0, 1);
            inputLoop("Enter new Part price.", "Modify", 0, &partPointer->price, 2);
            printf("\tPart Number: %d | Part Quantity: %d | Part Price: $%.2lf\n", partPointer->num, partPointer->quantity, partPointer->price);
            puts("\n----------");//10 Dashes

        }

    }
    else{
        puts("[Modify]: No list currently exists to modify a part from!");

    }

}

//////////
// insertStructure | Inserts a part by number into the linked list. | Updating
//////////
void insertStructure(struct Part **head){
    //Misc Vars
    struct Part *temp = *head;
    int i, skipLoop = 0;

    //Part Related
    int partNum, partQuan;
    double partPrice;
    struct Part *partPointer = NULL;


    puts("[Insert]: Enter the Part Number.");
    while(1){
        fputs("Input: ", stdout);
        if(!(scanf("%d", &partNum))){//If scanf does NOT have match..
            while(getchar() != '\n'); //Clear buffer
            puts("[Insert]: Invalid input. Try again.");
            continue;

        }

        if(partSearch(head, partNum, 0)){//If the part number is found..
            puts("[Insert]: That part number already exists. Try again.");
            continue;

        }

        while(getchar() != '\n'); //Clear buffer
        break;


    }

    puts("[Insert]: Enter the Part Quantity.");
    while(1){
        fputs("Input: ", stdout);
        if(!(scanf("%d", &partQuan))){//If scanf does NOT have match..
            while(getchar() != '\n'); //Clear buffer
            puts("[Insert]: Invalid input. Try again.");
            continue;

        }

        while(getchar() != '\n'); //Clear buffer
        break;

    }

    puts("[Insert]: Enter the Part Price.");
    while(1){
        fputs("Input: ", stdout);
        if(!(scanf("%lf", &partPrice))){//If scanf does NOT have match..
            while(getchar() != '\n'); //Clear buffer
            puts("[Insert]: Invalid input. Try again.");
            continue;

        }

        while(getchar() != '\n'); //Clear buffer
        break;

    }

    if(!(partPointer = (struct Part *)malloc(sizeof(struct Part)))){
        puts("[Insert]: Part creation failed (out of memory)! Sorry, program exiting.");
        exit(EXIT_FAILURE);

    }

    partPointer->num = partNum;
    partPointer->quantity = partQuan;
    partPointer->price = partPrice;
    partPointer->next = NULL;

    if(!(*head)){
        i = 0;
        //puts("Skipped loop.");
        *head = partPointer;
        skipLoop = 1;

    }

    if(!skipLoop){
        i = 1; //Since head is included.
        while(temp){
            //printf("Current pNum: %d | Next pNum: %d\n", temp->num, temp->next->num);
            if((temp->num < partPointer->num) && (!(temp->next) || partPointer->num < temp->next->num)){//Basically if --> Less < Part < Greater(or doesn't exist)
                partPointer->next = temp->next;
                temp->next = partPointer;
                //printf("Current partPointer: %d | Next partPointer: %p\n", partPointer->num, partPointer->next);
                break;

            }

            temp = temp->next;
            i++;

        }

    }

    printf("[Insert]: Part Number %d inserted into the list at index %d.\n", partNum, i);

}

//////////
// deleteStructure | Deletes a stucture and fixes list connections | Updating
//////////
int deleteStructure(struct Part **head){
if(*head){
        //Misc Vars
        struct Part *previous = NULL;
        struct Part *next = NULL;
        struct Part *temp = *head;
        int i;

        //Part Related
        int partNum;

        puts("[Delete]: Enter the Part number you wish to delete.");
        while(1){
            fputs("Input: ", stdout);
            if(!(scanf("%d", &partNum))){//If scanf does NOT have match..
                while(getchar() != '\n'); //Clear buffer
                puts("[Delete]: Invalid input. Try again.");
                continue;

            }

            while(getchar() != '\n'); //Clear buffer
            break;

        }

        printf("[Delete]: Searching for Part number %d.\n", partNum);
        i = 0;
        while(temp){
            if(temp->num == partNum){
                if(previous){//If previous structure in list exists..
                    previous->next = temp->next;//Then the previous structure's next pointer now points to the structure the current structure points to (since it will be deleted)

                }
                else{//If there is no previous structure..
                    *head = temp->next;//Then the target structure must be the head, and thus the next structure is now the head.

                }
                free(temp);
                printf("[Delete]: Part Number %d found and deleted at index %d.\n", partNum, i);
                return 1;//Success

            }

            previous = temp;
            temp = temp->next;
            i++;

        }

        puts("[Delete]: Part not found.");

    }
    else{
        puts("[Delete]: No list currently exists to delete a part from!");

    }

}

//////////
// selectPrint | Prints specific part based on part number | Updating
//////////
int selectPrint(struct Part **head){
    if(*head){
        //Misc Vars
        struct Part *partPointer = NULL;

        //Part Related
        int partNum;

        puts("[Select]: Enter the Part number you wish to print.");
        while(1){
            fputs("Input: ", stdout);
            if(!(scanf("%d", &partNum))){//If scanf does NOT have match..
                while(getchar() != '\n'); //Clear buffer
                puts("[Select]: Invalid input. Try again.");
                continue;

            }

            while(getchar() != '\n'); //Clear buffer
            break;

        }

        if(partPointer = partSearch(head, partNum, "Select")){
            puts("----------\n");//10 Dashes
            printf("\tPart Number: %d | Part Quantity: %d | Part Price: $%.2lf\n", partPointer->num, partPointer->quantity, partPointer->price);
            puts("\n----------");//10 Dashes

        }

    }
    else{
        puts("[Select]: No list currently exists to print a part from!");

    }

}

//////////
// printList | Prints the entire list from head to tail | Updating
//////////
void printList(struct Part **head){
    if(*head){
        //Misc Vars
        struct Part *temp = *head;
        int i;

        puts("[Print]: List found. Printing items.");
        puts("----------\n");//10 Dashes
        i = 0;
        while(temp){
          printf("\t[%d] Part Number: %d | Part Quantity: %d | Part Price: $%.2lf\n", i, temp->num, temp->quantity, temp->price);
          temp = temp->next;
          i++;

        }

        puts("\n----------");//10 Dashes
        puts("[Print]: Print complete.");

    }
    else{
        puts("[Print]: No list currently exists to print!");

    }

}

//////////
// saveList | Saves the list to file | Updating
//////////
void saveList(struct Part **head){
    if(head){//If head exists..
		//Misc Vars
		int i; //Validation Var1 & loop increment

		//File Vars
	    FILE *exportFileOut; //Export file out
	    DIR *exportFolOut; //Export folder out
	    char fileName[65], path[77] = "export/";//Filename Size 64 characters w/null 65 characters | export/ + .csv  + null + fileName = 77(?)

	    //IO Vars
	    int foundNewLine; //fgets related

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

	    puts("[Save]: Export folder created, enter your filename. [Max 64 characters]");//For now, assume user doesn't exceed 64 character limit.

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
	    struct Part *temp = *head;
	    i = 0;
	    puts("----------\n");//10 Dashes
	    while(temp){
	    	if(fprintf(exportFileOut, "%d,%d,%.2lf\n", temp->num, temp->quantity, temp->price)> 0){//num, quant, price
				printf("\tPart Number: %d saved to file.\n", temp->num);
				temp = temp->next;

	    	}
	    	else{
	    		puts("[Save]: One list member failed to save! Sorry, program exiting.");
	    		exit(EXIT_FAILURE);

			}

			i++;

		}
		puts("\n----------");
		printf("[Save]: Save complete (%d parts saved). Check the exports folder.\n", i);
		fclose(exportFileOut);
		closedir(exportFolOut);
	    //printf("Export folder pointer: %p\n", exportFolOut);

	}
	else{
		printf("[Save]: No list currently exists to save!");

	}

}

//////////
// deleteList | Deletes the entire list from head to tail | Done
//////////
void deleteList(struct Part **head){
    if(*head){ //If head exists
        struct Part *temp = (*head)->next;
        //printf("Head data: %d\n", (*head)->num);
        //int i = 1;

        //puts("[Delete]: List found. Deleting.");
        free(*head); //Free head first
        while(temp){
            *head = temp;
            temp = temp->next;
            free(*head);
            //i++;

        }

        *head = NULL;
        //printf("[Delete]: %d list items deleted. List cleared.\n", i);

    }
    //else{
    //    puts("[Delete]: No list exists currently to delete!");
    //
    //}

}

//////////
// createList | Creates a new list. If the list exists, attempt to save. | WIP
//////////
int createList(struct Part **head){//1 Return success, else fail (for now).
    //IO Vars
    char yesNo = 0;

    if(!*head){//If head is null, AKA no list
        puts("[Create]: No head pointer detected, assuming new list.");
        return 0;

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N]");
        while(1){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer

            switch(yesNo){
                case 'Y': case 'y':
                    saveList(head);
                    return 1;//temp
                    break;

                case 'N': case 'n':
                    puts("[Create]: Discarding current list, and creating new list.");
                    //printf("Head value before: %p\n", *head);
                    deleteList(head);
                    //printf("Head value after: %p\n", *head);
                    createList(head);
                    return 1;

                default:
                    puts("[Create]: Invalid input. Enter either Y or N.");

                //---

            }

        }

    }

}

//End of program []
