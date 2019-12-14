/*| Matt J. | Started on: 12/13/19 @7:25PM |

Desc: Program to automating the creation of logs.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Struct Declaration

typedef struct tm tm;

//End
//Function Declaration



//End
int main(){
    FILE *filePtr;


    return 0;

}

//////////
// newLog | Set-up for making a new log. | WIP
//////////

void newLogCreation(FILE **filePtrPtr){
    time_t currentTime;
    tm *myTime;
    char yesNo, logName[129], date;


    puts("Welcome Matt!\nSet log name? (Y / N)");
    while(1){
        fputs("Input: ", stdout);
        scanf("%c", &yesNo);
        while(getchar() != '\n'); //Clear buffer
        switch(yesNo){
            case 'Y': case 'y':
                fputs("Alright, enter the log name: ", stdout);
                fgets(logName, sizeof(logName), stdin);//Assume there will be no overflow..
                break;

            case 'N': case 'n':
                break;

            default:
                puts("Something went wrong, try again. (Invalid input?)");
                continue;

            //

        }

        break;

    }

    currentTime = time(0);
    myTime = localtime(&currentTime);
    if(!(*filePtrPtr = fopen(strcat(logName, ".txt"), "w"))){
        puts("Log creation failed! Sorry, program exiting.");
        exit(EXIT_FAILURE);

    }

    printf(("Log creation ready! %s Date: %d/%d/%d\n", yesNo = (yesNo == 'y') ? logName : "(No name)", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year);

}
