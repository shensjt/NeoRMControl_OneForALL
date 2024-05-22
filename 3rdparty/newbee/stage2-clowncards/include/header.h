#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


class CARD{
    private:
        std::string SUIT[4] = {"♠", "♥", "♣", "♦"};
        int num[9] = {0};
        std::string suit[9] = {" "};

    public:
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

        std::string get_suit(int i){
            return suit[i];
        }

        int get_num(int i){
            return num[i];
        }
}card;

void test_show(CARD card){

    for(int i ;i<9;i++){

        std::cout << card.get_suit(i) << ":" << card.get_num() <<std::endl ;
        
    }

}