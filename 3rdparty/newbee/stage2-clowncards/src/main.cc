#include "header.h"
// card在头文件中定义



void test_show(CARD card) {

    for (int i = 0; i < 8; i++) {

        std::cout << card.get_suit(i) << ":" << card.get_num(i) << "  ";

    }
    printf("\n");
}







int main(void) {

    std::srand((unsigned int)time(nullptr));
    std::vector<int> input_int; // 输入值处理后得到整数
    std::string input; // 输入的存放
    do{
        card.reset_discard();
        card.reset_score();
    do{
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



    } while(input != "q");


    }while(input != "q" ); // 重复游戏选项（未完成）

    return 0;
}