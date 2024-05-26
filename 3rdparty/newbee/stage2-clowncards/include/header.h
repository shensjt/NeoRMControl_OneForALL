#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

class CARD {
private:
    const std::string SUIT[4] = { "♠", "♥", "♣", "♦" };
    const std::string NUM[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    
    int CARDS_SUIT[8] = {0};
    int CARDS_NUM[8] = {0};


    std::vector<int> discard_num; // 暂存已经出现的牌 （需要清空的方法）
    std::vector<std::string> discard_suit;

    int score;
public:
    // 设置点数和花色
    void INI_CARD() {
            for(int i = 0; i<8 ;i++){
                



            }
        }

    // 拿取内部数据
    std::string get_suit(int i) {
        return SUIT[ CARDS_SUIT[i] ];
    }
    std::string get_num(int i) {
        return NUM[ CARDS_NUM[i] ];
    }
    int get_score(){
        return score;
    }


    // 选择卡牌
    void reset_num(int i) {
        CARDS_NUM[i] = 0;
    }

    //  清空分数
    void reset_score(){
        score = 0;
    }
    // 清空废牌区
    void reset_discard(){
        discard_suit.clear();
        discard_num.clear();
    }
}card;

// 输入_________________________________________

void input_get(std::vector<int>& input_int, std::string& input){

    while(true){
            bool positive = false;
            bool negative = false;
            bool check_isinput = true;
            input_int.clear();
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int number;

            if (input == "q") {
            break;
            }
            
            while (iss >> number) {
                input_int.push_back(number);

            // 判定输入数字的范围（具体实际情况还没确定） 全负数，全正数
                if (number > 8) {
                    check_isinput = false;
                    break;
                }

            // 确保全正 或 全负数
                if (number > 0) {
                    positive = true;
                }
                else { // 0 在之前已经排除过
                    negative = true;
                }

                if (positive && negative) {
                    check_isinput = false;
                    break;
                }

                if (iss.peek() != ' ' && !iss.eof()) {
                    check_isinput = false;
                    break;
                }
            }

            if (!iss.eof()) {
                check_isinput = false;;
            }

            if(check_isinput == false){
                std::cout << "输入错误，请重新输入" << std::endl;
                continue;
            }

            break;
        }
        // 输入分析与计算 || 判断胜负 || 调整界面
        for(int number : input_int){
            card.reset_num(number-1);
        }

}



void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
#endif
}
//窗口________________________________________
void window() {
    switch (3)
    {

    case 1:

        break;

    case 2:

        break;

    default:
        std::cout << "__________________" << std::endl;
        std::cout << "目前拥有的小丑牌：" << std::endl;
        std::cout << "剩余出牌次数：" << std::endl;
        std::cout << "当前分数："<< card.get_score() <<"             "<< "目标分数" << std::endl;
        std::cout << "当前手牌：";
        for (int i = 0; i < 8; i++) {
            std::cout << card.get_suit(i) << card.get_num(i) << " ";
        }
        std::cout << std::endl;
        std::cout << "序号：";
        for (int i = 0; i < 8; i++) {
            std::cout << i+1;
        }
        std::cout << std::endl;
    }


}
//_______________________________________________
void calculate(const std::vector<int>& input_int){

    for(int number : input_int ){






    }

}