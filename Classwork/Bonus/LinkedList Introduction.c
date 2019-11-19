/*| Matt J. | Started on: 11/16/19 @8:01PM | CIS-170 |

Desc: LinkedList bonus assignment.

*/
#include <stdio.h>
#include <stdlib.h>
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
void createList(struct Part *head, DIR *exportP);

//End
int main(){
    struct Part Part1 = {10, 10, 9.99, NULL};
    struct Part *head = &Part1;
    DIR *exportP; //Export folder pointer.
    FILE *importP; //Import file pointer.

    puts("[Main]: LinkedList session begin.\n");
    printHelp();
    createList(head, exportP);
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
// createList
//////////
void createList(struct Part *head, DIR *exportP){
    FILE *exportOut;
    char yesNo = 0, fileName[128], path[137] = "exports/";

    if(!head){
        puts("[Create]: No head pointer detected, assuming new list.");

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N]");
        while(!yesNo){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Rid ALL extra characters.

            printf("User entered: %c", yesNo);
            switch(yesNo){
                case 'Y': case 'y':
                    if(!(exportP = opendir("exports"))){ //If exports folder doesn't exist
                            puts("[Create]: Attempting to make folder for exports..");
                        if(!mkdir("exports")){ //If the directory is created
                            puts("[Create]: Exports folder successfully created.");


                        }
                        else{
                            puts("[Create]: Exports folder creation failed! Exiting.");
                            exit(EXIT_FAILURE);

                        }

                    }

                    yesNo = 0;
                    while(yesNo){
                        puts("[Create]: Enter the list filename.");
                        fputs("Input: ", stdout);
                        fgets(fileName, sizeof(fileName), stdin);
                        int i = 0;
                        while(fileName[i] != '\0'){ //Removing newline character if present.
                            if(fileName[i] == '\n'){
                                fileName[i] = '\0';

                            }

                            i++;

                        }

                        strcat(strcat(path, fileName), ".csv");
                        //printf("Full path: %s\n", path);
                        if(!(exportOut = fopen(path, "w"))){
                            int failBool = 0;

                            puts("File creation failed! Do you want to try again? [Y/N]");
                            while(!failBool){
                                fputs("Input: ", stdout);
                                yesNo = getchar();
                                while(getchar() != '\n');

                                switch(yesNo){
                                    case 'Y': case 'y':
                                        puts("User chose yes.");
                                        failBool = 1;
                                        break;

                                    case 'N': case 'n':
                                        puts("User chose no.");
                                        failBool = 1;
                                        break;

                                    default:
                                        puts("Invalid input. [Y or N]");

                                }

                            }

                        }

                    }
                    //printf("User entered: %s | fileName Size: %d", fileName, sizeof(fileName));
                    break;

                case 'N': case 'n':
                    puts("[Create]: List discarded and creating new list.");
                    break;

                default:
                    yesNo = 0;
                    puts("Invalid input. --> [Y or N]");

            }

        }

    }

}

//End of program []
