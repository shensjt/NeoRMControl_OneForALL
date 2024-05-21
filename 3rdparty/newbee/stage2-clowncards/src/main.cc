#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


int nums[9] = {0};
std::string suits[9];

void set_card(){}


int main(){
  srand((unsigned int)time(nullptr));

  std::string a[4] = {"♠", "♥", "♣", "♦"};
  char continueLoop = y;

do{
  for(int i = 0 ;i<9;i++){
    if(nums[i] == 0){
      int temp;
      nums[i] = 1 + rand()%13;
      temp = rand()%4;
      suits[i] = a[temp];
    }
    for(int x = 0;x<9;x++){
      if(x == i){
        x++;
        continue;
      }
      if(nums[i] == nums[x] && suits[i] == suits[x]){
        i--;
      }
    }
  }


  for(int i = 0; i < 9;i++){

    std::cout << suits[i] << ":" << nums[i] << ' ';

  }

std::cout <<endl;
}while(0)

  return 0;
}