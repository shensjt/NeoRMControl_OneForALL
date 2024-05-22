#include "header.h"

std::string SUIT[4] = {"♠", "♥", "♣", "♦"};
int num[9] = {0};
std::string suit[9] = {" "};
void INI_CARD(){
  for(int i = 0; i<9;i++){
    if(num[i == 0]){
      num[i] = 1 + rand()%13;
      int temp = rand()%4;
      suit[i] = SUIT[temp];
      for(int x = 0;x<9;x++){
        if(x == i){
            continue;
        }
        if(num[i] == num[x] && suit[i] == suit[x]){
          num[i] = 0;
          i = i-1;
        }
      }
    }
  }
}


int main(){

  std::srand((unsigned int)time(nullptr));

  INI_CARD();

  for(int i ;i<9;i++){
    std::cout << suit[i] << ":" << num[i] << std::endl;
  }

  num[2] = 0;
  num[3] = 0;

  INI_CARD();

   for(int i ;i<9;i++){
    std::cout << suit[i] << ":" << num[i] << std::endl;
  }

  return 0;
}