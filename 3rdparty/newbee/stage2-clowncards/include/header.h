#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class CARD
{
   private:
    // 模板
    const std::string SUIT[4] = { "黑桃", "红桃", "梅花", "方块" };
    const std::string NUM[14] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const std::string JOKER[1] = { "灰色小丑" };

    // 手牌
    int num[8] = { 0 };   // 手牌点数 （在INI_CARD中更新）
    int suit[8] = { 0 };  // 手牌花色

    // 使用牌
    std::vector<int> usecard_num;   // 使用牌 （需要清空的方法）打出一次手牌后清除
    std::vector<int> usecard_suit;  // 使用牌花色

    // 弃牌区
    std::vector<int> discard_num;   // 弃牌区 （需要清空的方法）小轮结束后清除
    std::vector<int> discard_suit;  // 弃牌区花色

    int temp_score = 0;  // 临时分数
    int score = 0;       // 总分数
    // 目标分数
    int target_score = 1000;  // 计算规则未知 ！！！！！！！！

    int discardcount = 3;  // 弃牌次数
    int usecount = 3;      // 使用次数
    bool is_use = false;   // 是否使用牌

   public:
   void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
    // 初始化手牌
    void INI_CARD() {
        for (int i = 0; i < 8; i++) {
            if (num[i] == 0) {
                num[i] = 1 + rand() % 13;

                suit[i] = rand() % 4;
                // 废牌区
                for (size_t x = 0; x < discard_num.size(); x++) {
                    if (discard_num[x] == num[i] && discard_suit[x] == suit[i]) {
                        num[i] = 0;
                        i = i - 1;
                    }
                }

                // 自身不重复
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
    // 检查窗口
    void window_check() {
        std::cout << "window_check" << std::endl;
        std::cout << "手牌" << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << SUIT[suit[i]] << ":" << NUM[num[i]] << suit[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "使用牌" << std::endl;
        for (int i = 0; i < usecard_num.size(); i++) {
            std::cout << SUIT[usecard_suit[i]] << ":" << NUM[usecard_num[i]] << usecard_suit[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "弃牌区" << std::endl;
        for (int i = 0; i < discard_num.size(); i++) {
            std::cout << SUIT[discard_suit[i]] << ":" << NUM[discard_num[i]] << discard_suit[i] << " ";
        }
        std::cout << std::endl;
    }

    // 拿到用户输入
    
    bool game_loop() {
        while (true) {
            clearScreen();
            if (usecount == 0 && score < target_score) {
                return false;
            }
            INI_CARD();
            window_check();

        }
    }
} card;
