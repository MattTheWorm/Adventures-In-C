/*| Matt J. | Started on: 12/13/19 @7:25PM |

Desc: Program to automating the creation of logs.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//Struct Declaration

typedef struct tm tm;

//End
//Function Declaration

//--
void newLogCreation(FILE **filePtrPtr);
void filePrintIO(FILE **filePtrPtr, char inputMessage[], char outputMessage[], char buffer[], size_t bufferSize);
//--

//End
int main(){
    FILE *filePtr;

    newLogCreation(&filePtr);
    return 0;

}

//////////
// newLog | Set-up for making a new log. | WIP
//////////

void newLogCreation(FILE **filePtrPtr){
    time_t currentTime;
    tm *localT;
    char yesNo, logName[129], fullPath[256], userInput[256];
    int i = 0;


    puts("Welcome Matt!\nSet log name? (Y / N)");
    while(1){//YesNo validation
        fputs("Input: ", stdout);
        scanf("%c", &yesNo);
        while(getchar() != '\n'); //Clear buffer
        switch(yesNo){
            case 'Y': case 'y':
                fputs("Alright, enter the log name (will be saved locally).\nInput: ", stdout);
                fgets(logName, sizeof(logName), stdin);//Assume there will be no overflow..
                while(logName[i]){
                    logName[i] = (logName[i] == '\n') ? '\0' : logName[i];
                    i++;

                }
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
    localT = localtime(&currentTime);
    snprintf(fullPath, sizeof(fullPath), "[%02d-%02d-%02d] %s.txt", localT->tm_mon + 1, localT->tm_mday, (localT->tm_year + 1900) - 2000, ((yesNo == 'y') ? logName : ""));
    if(!(*filePtrPtr = fopen(fullPath, "w"))){
        puts("Log creation failed!");
        exit(EXIT_FAILURE);

    }

    printf("Log creation ready! --> %s\n", fullPath);
    fprintf(*filePtrPtr, "Date: %d/%d/%d\n", localT->tm_mon + 1, localT->tm_mday, localT->tm_year + 1900);
    filePrintIO(filePtrPtr, "How are you feeling?", "How I'm feeling: ", userInput, sizeof(userInput));
    filePrintIO(filePtrPtr, "What's your location?", "Location: ", userInput, sizeof(userInput));
    fputs("\n", *filePtrPtr);
    puts("What are you listening to?");
    fputs("Input: ", stdout);
    fgets(userInput, sizeof(userInput), stdin);
    i = 0;
    while(userInput[i]){
        userInput[i] = (userInput[i] == '\n') ? '\0' : userInput[i];
        i++;

    }

    currentTime = time(0);
    localT = localtime(&currentTime);
    switch(strcmpi("na", userInput)){
        case 0:
            fprintf(*filePtrPtr, "Currently listening to: \"N/A\" ");
            break;

        default:
            fprintf(*filePtrPtr, "Currently listening to: \"%s\" ", userInput);

        //

    }

    fprintf(*filePtrPtr, "[%02d:%02dAM]\n", localT->tm_hour, localT->tm_min);

}

void filePrintIO(FILE **filePtrPtr, char inputMessage[], char outputMessage[], char buffer[], size_t bufferSize){
    printf("%s\n", inputMessage);
    fputs("Input: ", stdout);
    fgets(buffer, bufferSize, stdin);
    fprintf(*filePtrPtr, "%s%s", outputMessage, buffer);

}

//////////////////////////////
