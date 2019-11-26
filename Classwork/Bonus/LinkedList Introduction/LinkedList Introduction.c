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

void createList(struct Part **head, int *savePointer);
void printList(struct Part **head);
void selectPrint(struct Part **head);
void modifyStructure(struct Part **head);
void deleteStructure(struct Part **head);
void insertValidation(struct Part **head, char funcName[]);
void saveList(struct Part **head);
void importList(struct Part **head);
void exitProgram(struct Part **head, int *savePointer);
void printHelp();
//Extra
void inputLoop(char request[], char funcName[], int *valuePointerInt, double *valuePointerLF, int mode);
struct Part * partSearch(struct Part **head, int partNum, char funcName[]);
void insertPart(struct Part **head, struct Part *partPointer, char funcName[]);
void deleteList(struct Part **head);
void emergencySave(struct Part **head);

//End
int main(){
    //Head
    struct Part *head = NULL;

    //IO Vars
    int i, foundNewLine, save = 0;
    char userInput[12];

    puts("LinkedList session begin.");
    printHelp();
    //---
    while(1){
        puts("[Main]: Enter your command.");
        fputs("Input: ", stdout);
        fgets(userInput, sizeof(userInput), stdin);
        i = 0;
        foundNewLine = 0;
        while(userInput[i]){//While it's not the end of the string
            if(userInput[i] == '\n'){//If newline character found..
                userInput[i] = '\0';//Change to null
                foundNewLine = 1;

            }
            else if(userInput[i] == ' '){
                userInput[i] = '\0';

            }

            i++;

        }

        if(!foundNewLine){//If the newline character wasn't found..
            while(getchar() != '\n'); //Clear buffer

        }


        if(!(strcmp(userInput, "create"))){ //Create
            createList(&head, &save);
            save = 0;

        }
        else if(!(strcmp(userInput, "print"))){ //Print
            printList(&head);

        }
        else if(!(strcmp(userInput, "select"))){ //Select
            selectPrint(&head);

        }
        else if(!(strcmp(userInput, "modify"))){ //Modify
            modifyStructure(&head);
            save = 0;

        }
        else if(!(strcmp(userInput, "delete"))){ //Delete
            deleteStructure(&head);
            save = 0;

        }
        else if(!(strcmp(userInput, "insert"))){ //Insert
            insertValidation(&head, "Insert");
            save = 0;

        }
        else if(!(strcmp(userInput, "save"))){ //Save
            saveList(&head);
            save = 1;

        }
        else if(!(strcmp(userInput, "add")) || !(strcmp(userInput, "import"))){ //Add
            importList(&head);
            save = 0;

        }
        else if(!(strcmp(userInput, "exit"))){ //Exit
            exitProgram(&head, &save);

        }
        else if(!(strcmp(userInput, "help"))){ //Help
            printHelp();

        }
        else{
            puts("[Main]: Invalid command.");

        }

    }

    return 0;

}

//////////
// createList | Creates a new list. If the list exists, attempt to save. | Done
//////////
void createList(struct Part **head, int *savePointer){
    //IO Vars
    char yesNo = 0;

    if(*savePointer == 1){
        deleteList(head);

    }

    if(!(*head)){//If head is null, AKA no list
        puts("[Create]: Creating new list.");
        insertValidation(head, "Create");
        while(1){
            puts("[Create]: Do you want to make another part? [Y/N]");
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer
            switch(yesNo){
                case 'Y': case 'y':
                    insertValidation(head, "Create");
                    break;

                case 'N': case 'n':
                    puts("[Create]: List creation complete.");
                    return;

                default:
                    puts("[Create]: Invalid input. Enter either Y or N.");

                //---

            }

        }

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N/C]");
        while(1){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer

            switch(yesNo){
                case 'Y': case 'y':
                    saveList(head);
                    deleteList(head);
                    createList(head, savePointer);
                    return;//temp

                case 'N': case 'n':
                    deleteList(head);
                    puts("[Create]: Discarded current list.");
                    createList(head, savePointer);
                    return;

                case 'C': case 'c':
                    puts("[Create]: List creation canceled.");
                    return;

                default:
                    puts("[Create]: Invalid input. Enter either Y, N or C (for cancel).");

                //---

            }

        }

    }

}

//////////
// printList | Prints the entire list from head to tail | Done
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
// selectPrint | Prints a specific part based on part number | Done
//////////
void selectPrint(struct Part **head){
    if(*head){
        //Misc Vars
        struct Part *partPointer = NULL;

        //Part Related
        int partNum;

        inputLoop("Enter the Part number you wish to print.", "Print", &partNum, 0, 1);
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
// modifyStructure | Finds a part by number and lets the user input modified values. | Done
//////////
void modifyStructure(struct Part **head){
    if(*head){
        //Part Related
        int partNum;
        struct Part *partPointer = NULL;

        inputLoop("Enter the Part number you wish to modify.", "Modify", &partNum, 0, 1);
        if(partPointer = partSearch(head, partNum, "Modify")){
            inputLoop("Enter new Part quantity.", "Modify", &partPointer->quantity, 0, 1);
            inputLoop("Enter new Part price.", "Modify", 0, &partPointer->price, 2);
            printf("[Modify]: Part Number: %d | Part Quantity: %d | Part Price: $%.2lf\n", partPointer->num, partPointer->quantity, partPointer->price);

        }

    }
    else{
        puts("[Modify]: No list currently exists to modify a part from!");

    }

}

//////////
// deleteStructure | Deletes a stucture and fixes list connections | Done
//////////
void deleteStructure(struct Part **head){
    if(*head){
        //Misc Vars
        struct Part *previous = NULL;
        struct Part *temp = *head;
        int i;

        //Part Related
        int partNum;

        inputLoop("Enter the Part number you wish to delete.", "Delete", &partNum, 0, 1);
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
                return;

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
// insertValidation | Validation for user input insertion. | Done
//////////
void insertValidation(struct Part **head, char funcName[]){
    //Part Related
    int partNum, partQuan;
    double partPrice;
    struct Part *partPointer = NULL;


    printf("[%s]: Enter the Part Number.\n", funcName);
    while(1){
        fputs("Input: ", stdout);
        if(!(scanf("%d", &partNum))){//If scanf does NOT have match..
            while(getchar() != '\n'); //Clear buffer
            printf("[%s]: Invalid input. Try again.\n", funcName);
            continue;

        }

        if(partSearch(head, partNum, 0)){//If the part number is found..
            printf("[%s]: That part number already exists. Try again.\n", funcName);
            while(getchar() != '\n'); //Clear buffer
            continue;

        }

        while(getchar() != '\n'); //Clear buffer
        break;

    }

    inputLoop("Enter the Part Quantity.", funcName, &partQuan, 0, 1);
    inputLoop("Enter the Part Price.", funcName, 0, &partPrice, 2);
    if(!(partPointer = (struct Part *)malloc(sizeof(struct Part)))){
        printf("[%s]: Part creation failed (out of memory)! Sorry, program exiting.\n", funcName);
        emergencySave(head);
        exit(EXIT_FAILURE);

    }

    partPointer->num = partNum;
    partPointer->quantity = partQuan;
    partPointer->price = partPrice;
    partPointer->next = NULL;
    insertPart(head, partPointer, funcName);

}

//////////
// saveList | Saves the list to file | Done
//////////
void saveList(struct Part **head){
    if(*head){//If head exists..
		//Misc Vars
		int i; //Validation Var1 & loop increment

		//File Vars
	    FILE *exportFileOut; //Export file out
	    DIR *exportFolOut; //Export folder out
	    char fileName[65], path[77] = "export/";//export/ (7) + .csv (4)  + null (1) + fileName (64) = 77(?)

	    //IO Vars
	    int foundNewLine; //fgets related

	    puts("[Save]: Save session started.");
	    if(!(exportFolOut = opendir("export"))){//If export folder doesn't exist
	        if(!mkdir("export")){//Then attempt to make export folder
	            if(!(exportFolOut = opendir("export"))){//If it still can't be opened..
	                puts("[Save]: Export folder creation failed! Sorry, program exiting.");
	                emergencySave(head);
	                exit(EXIT_FAILURE);

	            }

	        }
	        else{//If export folder can't be made..
	            puts("[Save]: Export folder creation failed! Sorry, program exiting.");
	            emergencySave(head);
	            exit(EXIT_FAILURE);

	        }

	    }

	    puts("[Save]: Export folder created, enter your filename. (.csv will be appended automatically)[Max 64 characters]");
        fputs("Input: ", stdout);
        fgets(fileName, sizeof(fileName), stdin);
        i = 0;
        foundNewLine = 0;
        while(fileName[i]){//While it's not the end of the string
            if(fileName[i] == '\n'){//If newline character found..
                fileName[i] = '\0';//Change to null
                foundNewLine = 1;

            }

            i++;

        }

        if(!foundNewLine){//If the newline character wasn't found..
            while(getchar() != '\n'); //Clear buffer

        }

        //printf("File Path: %s", strcat(strcat(path, fileName), ".csv"));
        if(!(exportFileOut = fopen(strcat(strcat(path, fileName), ".csv"), "w"))){
            puts("[Save]: File creation failed! Sorry, program exiting.");
            emergencySave(head);
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
	    	if(fprintf(exportFileOut, "%d,%d,%.2lf\n", temp->num, temp->quantity, temp->price) > 0){//num, quant, price
				printf("\tPart Number: %d saved to file.\n", temp->num);
				temp = temp->next;

	    	}
	    	else{
	    		puts("[Save]: One list member failed to save! Sorry, program exiting."); //Might not be needed. With how the program currently works, part must be corrupted somehow.
	    		emergencySave(head);
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
		puts("[Save]: No list currently exists to save!");

	}

}

//////////
// importList | Imports parts from a file into the current list. | Updating
//////////
void importList(struct Part **head){
    //Misc Vars
    int i, x; //Loop increment

    //File Vars
    FILE *importFileIn; //Export file out
    char path[260]; //260 based on Windows 10 MAX_PATH

    //IO Vars
    char yesNo = 0;
    int endLoop = 1, endLoop2 = 1, foundNewLine;

    puts("[Import]: Import session started. Enter the path to the target file.");
    i = 0;
    while(endLoop2){
        fputs("Input: ", stdout);
        fgets(path, sizeof(path), stdin);
        while(path[i]){//While it's not the end of the string
            if(path[i] == '\n'){//If newline character found..
                path[i] = '\0';//Change to null
                foundNewLine = 1;

            }

            i++;

        }

        if(!foundNewLine){//If the newline character wasn't found..
            while(getchar() != '\n'); //Clear buffer

        }

        //printf("File Path: %s", path);
        if(!(importFileIn = fopen(path, "r"))){
            puts("[Import]: File failed to open. Would you like to try a new path? [Y/N]");
            endLoop = 1;
            while(endLoop){
                fputs("Input: ", stdout);
                yesNo = getchar();
                while(getchar() != '\n'); //Clear buffer
                switch(yesNo){
                    case 'Y': case 'y':
                        puts("[Import]: Enter the new path.");
                        endLoop = 0;
                        break;

                    case 'N': case 'n':
                        puts("[Import]: File import canceled.");
                        return;

                    default:
                        puts("[Import]: Invalid input. Enter either Y or N.");

                    //---
                }

            }

        }
        else{
            endLoop2 = 0;

        }

    }

    puts("[Import]: File read successfully. Attempting to import list.");
    /*----------

    LIST IMPORT

    ----------*/
    //Part Related
    struct Part *tempPartPointer = NULL;
    char fileLine[256];
    int numberInputs;

    i = 0;
    x = 0;
    puts("----------\n");//10 Dashes
    while(fgets(fileLine, sizeof(fileLine),importFileIn)){
        //printf("Line data: %s", fileLine);
        tempPartPointer = (struct Part *)malloc(sizeof(struct Part));
        numberInputs = sscanf(fileLine, "%d,%d,%lf", &tempPartPointer->num, &tempPartPointer->quantity, &tempPartPointer->price);
        //PartNum | Quantity | Price
        //PartNum
        if(numberInputs != 3){
            puts("Part corrupted in file. Import failed. (Type mismatch)");
            //printf("%d", numberInputs);
            free(tempPartPointer);
            x++;
            continue;

        }
        else if(partSearch(head, tempPartPointer->num, 0)){
            printf("Part %d already exists. Import failed.\n", tempPartPointer->num);
            free(tempPartPointer);
            x++;
            continue;

        }

        printf("Imported Part Number %d\n", tempPartPointer->num);
        //printf("Part Number %d | Part Quan: %d | Part Price: %lf\n", tempPartPointer->num, tempPartPointer->quantity, tempPartPointer->price);
        insertPart(head, tempPartPointer, 0);
        i++;

    }
    free(tempPartPointer);
    puts("\n----------");
    printf("[Import]: Import complete (%d parts imported | %d parts failed).\n", i, x);
    fclose(importFileIn);
    //printf("Export file pointer: %p\n", importFileIn);

}

//////////
// exitProgram | Exits the program. If there's a list prompts to save. | Done
//////////
void exitProgram(struct Part **head, int *savePointer){
    //IO Vars
    char yesNo = 0;

    if(*savePointer == 1 || !(*head)){
        puts("Program will now exit..");
        exit(EXIT_SUCCESS);

    }
    else{
        puts("[Exit]: List detected. Do you want to save the current list to file? [Y/N/C]");
        while(1){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Clear buffer

            switch(yesNo){
                case 'Y': case 'y':
                    saveList(head);
                    puts("Program will now exit..");
                    exit(EXIT_SUCCESS);

                case 'N': case 'n':
                    puts("Program will now exit..");
                    exit(EXIT_SUCCESS);

                case 'C': case 'c':
                    puts("[Exit]: Exit canceled.");
                    return;

                default:
                    puts("[Exit]: Invalid input. Enter either Y, N or C (for cancel).");

                //---

            }

        }

    }

}

//////////
// printHelp | Prints the help menu. | Done
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

//Extra
//////////
// inputLoop | Gets user input (float/int) and loops until the value is valid. | Done
//////////
void inputLoop(char request[], char funcName[], int *valuePointerInt, double *valuePointerLF, int mode){//Mode 1 - Int | Mode 2 - Double
    printf("[%s]: %s\n", funcName, request);
    while(1){
        fputs("Input: ", stdout);
        switch(mode){
            case 1:
                if(!(scanf("%d", valuePointerInt))){//If scanf does NOT have match..
                    while(getchar() != '\n'); //Clear buffer
                    printf("[%s]: Invalid input. Try again.\n", funcName);
                    continue;

                }

                break;
            case 2:
                if(!(scanf("%lf", valuePointerLF))){//If scanf does NOT have match..
                    while(getchar() != '\n'); //Clear buffer
                    printf("[%s]: Invalid input. Try again.\n", funcName);
                    continue;

                }

            //---

        }

        while(getchar() != '\n'); //Clear buffer
        break;

    }

}

//////////
// partSearch | Searches for a part by number and returns the pointer to the part struct if it exists. | Done
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

}

//////////
// insertPart | Inserts a part by number into the current list. Automatically sorts position. Assumes part can always be inserted without error (other functions that call this should validate any input). | Done
//////////
void insertPart(struct Part **head, struct Part *partPointer, char funcName[]){
    //Part Related
    struct Part *temp = *head;

    //Misc Vars
    int i, skipLoop = 0;

    if(!(*head)){
        i = 0;
        //puts("Skipped loop. (No head detected)");
        *head = partPointer;
        skipLoop = 1;

    }
    else if(partPointer->num < (*head)->num){
        i = 0;
        //puts("Skipped loop. (New part num is less than head)");
        partPointer->next = *head;
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

    if(funcName){
        printf("[%s]: Part Number %d inserted into the list at index %d.\n", funcName, partPointer->num, i);

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
// emergencySave | If a list exists on program error, attempts to save to the local directory. | Done
//////////
void emergencySave(struct Part **head){
    if(*head){
		//File Vars
	    FILE *exportFileOut; //Export file out

        if(!(exportFileOut = fopen("export.csv", "w"))){
            exit(EXIT_FAILURE);

        }

	    /*----------

	    LIST SAVING

	    ----------*/
	    struct Part *temp = *head;

	    while(temp){
	    	if(fprintf(exportFileOut, "%d,%d,%.2lf\n", temp->num, temp->quantity, temp->price) > 0){//num, quant, price
				temp = temp->next;

	    	}
	    	else{
	    		exit(EXIT_FAILURE);

			}

		}
		puts("Saved list to \"export\" in local program directory..");
		fclose(exportFileOut);

	}

}

//End of program 11/23/19@4:07AM
