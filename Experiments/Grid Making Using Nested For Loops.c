#include <stdio.h>

int main(){
  int i, i2, x = 10, y = 10, graphSizeX = 10, graphSizeY = 10;

  //X and Y represent the location the point intersects. Just like a normal graph.
  for(i2 = 0; i2 != graphSizeY; i2++){//Y
    printf("[ ");
    for(i = 0; i != graphSizeX; i++){//X
      if(i2 + 1 == y && i + 1 == x){
        printf("! ");

      }
      else{
        printf(". ");

      }
    
    }

    printf("]\n");

  }

  puts("\n-------------------------"); //25
  printf("Graph Size X: %d\nGraph size Y: %d\nPoint Location (%d, %d)", graphSizeX, graphSizeY, x, y);
  return 0;

}