/*| Matt J. | Started on: 11/16/19 @8:01PM | CIS-170 |

Desc: LinkedList bonus assignment.

*/
#include <stdio.h>
#include <stdlib.h>
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
void createList(struct Part *head);

//End
int main(){
    struct Part Part1 = {10, 10, 9.99, NULL};
    struct Part *head = &Part1;

    printf("LinkedList session begin.\n");
    printHelp();
    createList(head);
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
void createList(struct Part *head){
    char yesNo = 0;

    if(!head){
        puts("[Create]: No head pointer detected, assuming new list.");

    }
    else{
        puts("[Create]: List detected. Do you want to save the current list to file? [Y/N]");
        while(!yesNo){
            fputs("Input: ", stdout);
            yesNo = getchar();
            while(getchar() != '\n'); //Rid ALL extra characters.

            switch(yesNo){
                case 'Y': case 'y':
                    //printf("User chose yes.\n");
                    break;

                case 'N': case 'n':
                    //printf("User chose no.\n");
                    break;

                default:
                    yesNo = 0;
                    puts("Invalid input. --> [Y or N]\n");

            }
        }

        printf("Head Data\nNum: %d\nQuant: %d\nPrice: $%.2lf\nNextPtr: %p", head->num, head->quantity, head->price, head->next);

    }

}

//End of program []
