/*| Matt J. | Started on: 12/13/19 @7:25PM |

Desc: Program to automating the creation of logs.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define USR_INPUT 512
#define PATH_SIZE 256
//Struct Declaration

typedef struct tm tm;

//End
//Function Declaration

// Main Functions
//--
void newLogCreation(FILE **filePtrPtr);
void filePrintIO(FILE **filePtrPtr, char inputMessage[], char outputMessage[], char buffer[], size_t bufferSize);
//--
void createCLT(FILE **filePtrPtr);

// IO/Cleanup Functions
int validateBuffer(char string[]);
void removeNewline(char string[]);
void clrBuffer();

//End
int main(){
    FILE *filePtr;

    newLogCreation(&filePtr);
    return 0;

}

//////////
//
// Main Functions
//
//////////


//////////
// newLog | Set-up for making a new log. | Updating
//////////

void newLogCreation(FILE **filePtrPtr){
    time_t currentTime;
    tm *localT;
    char yesNo, logName[129], fullPath[PATH_SIZE], userInput[USR_INPUT];
    int i = 0;


    puts("Welcome Matt!\nSet log name? (Y / N)");
    while(1){//YesNo validation
        fputs("Input: ", stdout);
        scanf("%c", &yesNo);
        clrBuffer();
        switch(yesNo){
            case 'Y': case 'y':
                fputs("Alright, enter the log name (will be saved locally).\nInput: ", stdout);
                fgets(logName, sizeof(logName), stdin);
                if(validateBuffer(logName)) removeNewline(logName);
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
    createCLT(filePtrPtr);

}

void filePrintIO(FILE **filePtrPtr, char inputMessage[], char outputMessage[], char buffer[], size_t bufferSize){
    printf("%s\n", inputMessage);
    fputs("Input: ", stdout);
    fgets(buffer, bufferSize, stdin);
    validateBuffer(buffer);
    fprintf(*filePtrPtr, "%s%s", outputMessage, buffer);

}

//////////////////////////////

//////////
// createCLT | Function for creating a "Currently listening to:" line. | Updating
//////////

void createCLT(FILE **filePtrPtr){
    time_t currentTime;
    tm *localT;
    char userInput[USR_INPUT];

    puts("What are you listening to? Use \"NA\" or \"na\" for nothing.");
    fputs("Input: ", stdout);
    fgets(userInput, sizeof(userInput), stdin);
    if(validateBuffer(userInput)) removeNewline(userInput);
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

    fprintf(*filePtrPtr, "[%d:%02d%s]\n", (localT->tm_hour % 12 == 0) ? 12 : localT->tm_hour % 12 , localT->tm_min, (localT->tm_hour >= 12) ? "PM" : "AM");

}

//////////
//
// IO/Cleanup Functions
//
//////////

//////////
// validateBuffer | Assumes string has newline character at the end. If it does, there **should** be no characters in the buffer. Otherwise, clear buffer. Linear time. | Done
// Return Value: 1 - Found newline character successfully. 0 - Newline character not found.
//////////

int validateBuffer(char string[]){
    int i = 0;

    while(string[i]){
        if(string[i] == '\n'){
          return 1;

        }

        i++;

    }
    puts("[WARN] Buffer overflow detected! Characters dropped.");
    clrBuffer();
    return 0;

}

//////////
// removeNewline | Currently removes (all) newline characters from a string. Preferably for fgets inputs. Linear time. | Done
//////////

void removeNewline(char string[]){
    int i = 0;

    while(string[i]){
        if(string[i] == '\n') string[i] = '\0';
        i++;

    }

}

//////////
// clrBuffer | Clears the current buffer with a simple getchar() loop. Assumes the buffer actually has extra characters (otherwise program will wait for input). | Done
//////////

void clrBuffer(){
    int i = 0;

    while(getchar() != '\n');

}


