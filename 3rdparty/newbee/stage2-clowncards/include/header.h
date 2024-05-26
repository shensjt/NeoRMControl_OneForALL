#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

class CARD {
private:
    std::string SUIT[4] = { "♠", "♥", "♣", "♦" };
    int num[8] = { 0 };
    std::string suit[8] = { " " };

public:
    // 设置点数和花色
    void INI_CARD() {
        for (int i = 0; i < 8; i++) {
            if (num[i] == 0) {
                num[i] = 1 + rand() % 13;
                int temp = rand() % 4;
                suit[i] = SUIT[temp];
                for (int x = 0; x < 8; x++) {
                    if (x == i) {
                        continue;
                    }
                    if (num[i] == num[x] && suit[i] == suit[x]) {
                        num[i] = 0;
                        i = i - 1;
                    }
                }
            }
        }

    }

    std::string get_suit(int i) {
        return suit[i];
    }

    int get_num(int i) {
        return num[i];
    }

    void reset_num(int i) {
        num[i] = 0;
    }
};


void input_(std::vector<int> input_int,std::string input ){
    do{
            bool check_isinput = true;
            input_int.clear();
            std::getline(std::cin,input);
            std::istringstream iss(input);
            int number;

            if(input == "q"){
                break;
            }
            while(iss >> number){
                input_int.push_back(number);
                if(iss.peek()!=' ' && !iss.eof()){
                    check_isinput = false;
                    break; 
                }
            }

        // 判定输入数字的范围（具体实际情况还没确定） 全负数，全正数
             if(!iss.eof()){
                 check_isinput = false;;
            }
            for(const auto& num : input_int){
                if(num > 8){
                    check_isinput = false;
                    break;
                }
 
                // 确保全正 或 全负数                
                bool positive = false;
                bool negative = false;
                if(num > 0){
                    positive = true;
                }else{ // 0 在之前已经排除过
                    negative = true;
                }

                if(positive && negative){
                    check_isinput = false;
                }

            }



            if(check_isinput = false){
                std::cout << "输入错误，请重新输入" << std::endl;
                continue;
            }
            break;
        }while(true);
}