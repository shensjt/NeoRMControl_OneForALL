#include "header.h"




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

        input_get(input_int, input);



    } while(input != "q");


    }while(input != "q" ); // 重复游戏选项（未完成）

    return 0;
}