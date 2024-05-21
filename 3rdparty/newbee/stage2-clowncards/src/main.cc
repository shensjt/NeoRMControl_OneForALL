#include <iostream>
#include <string>

int nums[9] = {0};

void set_card(){


}


int main(){

  std::string a[4] = {"♠", "♥", "♣", "♦"};




  for(int i = 0; i < 4;i++){

    std::cout << a[i] << ":" << nums[i] <<" ";

  }


  return 0;
}