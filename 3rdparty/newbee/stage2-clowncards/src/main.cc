#include "header.h"

CARD card;
enum check_window{
    begin,
    end
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
#endif
}

void test_show(CARD card) {

    for (int i = 0; i < 8; i++) {

        std::cout << card.get_suit(i) << ":" << card.get_num(i) << "  ";

    }
    printf("\n");
}


void window() {
    check_window show = begin;
    switch (3)
    {

    case begin:

        break;

    case end:

        break;

    default:
        std::cout << "__________________" << std::endl;
        std::cout << "目前拥有的小丑牌：" << std::endl;
        std::cout << "剩余出牌次数：" << std::endl;
        std::cout << "当前分数："<<"             "<< "目标分数" << std::endl;
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




int main(void) {

    std::srand((unsigned int)time(nullptr));
    std::vector<int> input_int;
    std::string input;

    do {
        // 刷新屏幕
        clearScreen();

        // 初始化与更新
        card.INI_CARD();

        // 界面展示
        window();
        for(int number : input_int){
            std::cout << number << " " << std::endl;
        }

        // 输入

        while(true){
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
                if (iss.peek() != ' ' && !iss.eof()) {
                    check_isinput = false;
                    break;
                }
            }

            // 判定输入数字的范围（具体实际情况还没确定） 全负数，全正数
            if (!iss.eof()) {
                check_isinput = false;;
            }

            for (const auto& num : input_int) {
                if (num > 8) {
                    check_isinput = false;
                    break;
                }

            // 确保全正 或 全负数                
                bool positive = false;
                bool negative = false;
                if (num > 0) {
                    positive = true;
                }
                else { // 0 在之前已经排除过
                    negative = true;
                }

                if (positive && negative) {
                    check_isinput = false;
                }
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



    } while(input != "q");


    return 0;
}