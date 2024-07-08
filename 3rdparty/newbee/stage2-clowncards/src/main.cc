#include "header.h"

void test_show(CARD card) {
    for (int i = 0; i < 8; i++) {
        std::cout << card.get_suit(i) << ":" << card.get_num(i) << "  ";
    }
    printf("\n");
}

int main(void) {
    std::srand((unsigned int)time(nullptr));
    std::vector<int> input_int;  // 输入值处理后得到整数
    std::string input;           // 输入的存放

    do {
        card.new_round();
        do {
            // 刷新屏幕
            clearScreen();
            
            // 初始化与更新
            card.INI_CARD();
            if(card.score_update()){
                break;
            }
            // 界面展示
            card.window();
            for (int number : input_int) {
                std::cout << number << " " << std::endl;
            }

            // 判断游戏进程
            if (card.get_is_over() == true) {
                char check;
                std::cin >> check;
                getchar();
                if (check == 'y') {
                    card.new_game();
                    break;
                } else {
                    input = "q";
                    break;
                }
            }
            // 输入
            card.new_usecard();
            card.input_get(input_int, input);

        } while (input != "q");  // 更换小回合判断条件
        card.new_round( );
    } while (input != "q");  // 重复游戏选项（未完成）

    return 0;
}