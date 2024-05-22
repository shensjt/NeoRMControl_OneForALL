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

    for (int i = 0; i < 9; i++) {

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
        for (int i = 0; i < 9; i++) {
            std::cout << card.get_suit(i) << card.get_num(i) << " ";
        }
        std::cout << std::endl;
        std::cout << "序号：";
        for (int i = 0; i < 9; i++) {
            std::cout << i+1;
        }
        std::cout << std::endl;
        break;
    }


}




int main(void) {

    std::srand((unsigned int)time(nullptr));

    std::string input = "y";

    do {
        // 刷新屏幕
        clearScreen();

        // 初始化与更新
        card.INI_CARD();

        // 界面展示
        window();
        
        // 输入
        std::getline(std::cin,input);

        // 输入分析与计算 || 判断胜负 || 调整界面
        if (input == "1") {
            card.set_num(0, 1);
        }

    } while (input != "q");


    return 0;
}