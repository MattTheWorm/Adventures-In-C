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
    time_t currentTime = time(0);
    tm *myTime = localtime(&currentTime);
    int test;

    printf("Hello World! Current time & date: %d/%d/%d", myTime->tm_mon + 1, myTime->tm_mday, myTime->tm_year + 1900);
    return 0;

}

//////////
// newLog | Creates a new list. If the list exists, attempt to save. | WIP
//////////

void newLogCreation(FILE *filePtr){





}
