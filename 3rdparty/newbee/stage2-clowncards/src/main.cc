#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  for(int i = 0;i< 10 ;i++){

    printf("\033[2J");

    for(int j = 0;j <10;j++ ){
      std::cout << " ";
    }
    std::cout << "A" << std::endl;

    sleep(1);

  }

  return 0;
}