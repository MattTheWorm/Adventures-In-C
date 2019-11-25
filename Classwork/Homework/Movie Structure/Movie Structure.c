/*| Matt J. | Started on: 11/24/19 @1:47AM | CIS-170 |

Desc: Movie Structure CSV Assignment.

*/
#include <stdio.h>
//Struct Declaration

struct Movie{
    char name[129];
    char mpaa[6];
    int minutes;
    float ratingOne, ratingTwo, ratingThree;

};

//End
//Function Declaration



//End
int main(){
    FILE *importFile;
    FILE *exportFile;
    struct Movie movieArray[10];
    char path[257];
    int i;

    puts("Enter the target import path.");
    i = 0;
    while(1){//Path input loop
        fputs("Input: ", stdout);
        fgets(path, sizeof(path), stdin);
        while(path[i]){
            if(path[i] == '\n'){
                //puts("Newline found.");
                path[i] = '\0';

            }

            i++;

        }

        //printf("User entered: %s", path);
        if(!(importFile = fopen(path, "r"))){
            puts("That file failed to open. Try again or exit the program.");
            //printf("File pointer: %p\n", (void *)importFile);
            continue;

        }

        puts("Import file found.");
        break;

    }
    //
    //File Import
    //
    char fileLine[128], token;

    puts("---------");//10 Dashes
    while(fgets(fileLine, sizeof(fileLine), importFile)){
        //Name, Rating, Runtime, Rate1, Rate2, Rate3
        printf("Line data: %s", fileLine);

    }

    puts("---------");//10 Dashes
    return 0;

}
