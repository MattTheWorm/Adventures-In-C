/*| Matt J. | Started on: 11/24/19 @1:47AM | CIS-170 |

Desc: Movie Structure CSV Assignment.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    struct Movie movieArray[10];
    char fileLine[128], *token, *rating;
    float rate1, rate2, rate3;
    int runtime;

    puts("---------");//10 Dashes
    i = 0;
    while(fgets(fileLine, sizeof(fileLine), importFile)){
        //Name, Rating, Runtime, Rate1, Rate2, Rate3
        //printf("Line data: %s", fileLine);
        //Name
        strcpy(movieArray[i].name, strtok(fileLine, ","));
        //Rating
        strcpy(movieArray[i].mpaa, strtok(NULL, ","));
        //Runtime
        movieArray[i].minutes = atoi(strtok(NULL, ","));
        //Rate1
        movieArray[i].ratingOne = atof(strtok(NULL, ","));
        //Rate2
        movieArray[i].ratingTwo = atof(strtok(NULL, ","));
        //Rate3
        movieArray[i].ratingThree = atof(strtok(NULL, "\n"));
        printf("[%d] Movie Name: %s | Movie Rating: %s | Runtime: %d | Ratings [%.2f, %.2f, %.2f]\n", i, movieArray[i].name, movieArray[i].mpaa, movieArray[i].minutes, movieArray[i].ratingOne, movieArray[i].ratingTwo, movieArray[i].ratingThree);
        i++;
        
    }
	//
    //File Export
    //
    FILE *exportFile;
    
	puts("\nEnter the target export path (extension included).");
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
        if(!(exportFile = fopen(path, "w"))){
            puts("Failed to create file. Try again or exit the program.");
            //printf("File pointer: %p\n", (void *)importFile);
            continue;

        }

        puts("Export file created.");
        break;

    }
    
    for(i = 0; i != 10; i++){
    	fputs("------------\n", exportFile);//12 Dashes
    	fprintf(exportFile, "| Movie #%d |\n", i + 1);
    	fputs("------------\n\n", exportFile);//12 Dashes
    	fprintf(exportFile, "\tMovie Name: %s (%dm Runtime)\n", movieArray[i].name, movieArray[i].minutes);
    	fprintf(exportFile, "\tMovie Rating: %s\n", movieArray[i].mpaa);
    	fprintf(exportFile, "\tCritic Ratings: [*%.2f, *%.2f,*%.2f] (Critic Average: *%.2f)\n\n", movieArray[i].ratingOne, movieArray[i].ratingTwo, movieArray[i].ratingThree, (movieArray[i].ratingOne + movieArray[i].ratingTwo + movieArray[i].ratingThree)/3.0);
    	
	}
	
	printf("File saved at %s", path);
    return 0;

}

//End of program 11/27/19@~2:05PM
