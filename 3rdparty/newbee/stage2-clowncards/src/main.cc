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
        card.newgame(); // 初始化基本设置,!!!!应该在小一轮结束后清楚

    do{
        // 刷新屏幕
        clearScreen();

        // 初始化与更新
        card.INI_CARD();

        // 界面展示
        card.window();
        for(int number : input_int){
            std::cout << number << " " << std::endl;
        }

        // 输入

        card.input_get(input_int, input);

        // 处理输入


        // 判断游戏进程




        


    }while(input != "q");


    }while(input != "q" ); // 重复游戏选项（未完成）

    return 0;
}