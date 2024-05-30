#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class CARD
{
   private:
    const std::string SUIT[4] = { "♠", "♥", "♣", "♦" };
    const std::string NUM[14] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    const std::string JOKER[1] = { "灰色小丑" };
    const int SCORE[10] = { 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200 };  // 最大分数

    bool is_use = false;
    int ROUND = -1;        // 游戏重新开始时重置
    bool is_over = false;  // 游戏结束标志，游戏结束时在选择继续游戏后重置
    int WINDOW = 0;        // 重开游戏时重置

    int playcount = 3;             // 剩余出牌次数 ，小轮结束后重置
    int discardcount = 4;          // 弃牌次数
    std::vector<int> discard_num;  // 弃牌区 （需要清空的方法）小轮结束后清除
    std::vector<std::string> discard_suit;
    int score;  // 当前分数,小轮结束后重置

    int num[8] = { 0 };             // 手牌点数 （在INI_CARD中更新）
    std::string suit[8] = { " " };  // 手牌花色

    std::vector<int> usecard_num;  // 使用牌 （需要清空的方法）打出一次手牌后清除
    std::vector<std::string> usecard_suit;
    int temp_score;  // 临时分数，打出一次手牌后重置

   public:
    // 设置点数和花色
    void INI_CARD() {
        
        for (int i = 0; i < 8; i++) {
            if (num[i] == 0) {
                num[i] = 1 + rand() % 13;
                int temp = rand() % 4;
                suit[i] = SUIT[temp];
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

    // 拿取内部数据
    std::string get_suit(int i) {
        return suit[i];
    }
    std::string get_num(int i) {
        return NUM[num[i]];
    }
    int get_score() {
        return score;
    }
    int get_SCORE(int i) {
        return SCORE[i];
    }
    bool get_is_over() {
        return is_over;
    }

    // 选择卡牌
    void reset_num(int i) {
        num[i] = 0;
    }

    // 新的一局

    void new_game() {
        ROUND = -1;
        is_over = false;
        is_use = false;
        WINDOW = 0;
    }
    // 新一回合，清空废牌区,得分,暂存的打出手牌
    void new_round() {
        ROUND++;
        discard_suit.clear();
        discard_num.clear();
        playcount = 3;
        discardcount = 4;
        score = 0;
    }
    // 新一次出牌
    void new_usecard() {
        usecard_num.clear();
        usecard_suit.clear();
        temp_score = 0;
    }
    // 增加弃牌区
    void add_discard(int i) {
        discard_num.push_back(num[i]);
        discard_suit.push_back(suit[i]);
    }

    // 增加使用牌
    void add_usecard(int i) {
        usecard_num.push_back(num[i]);
        usecard_suit.push_back(suit[i]);
    }

    // 牌型检测
    int check_type() {
        if (usecard_num.size() >= 5) {
            // 同花
            for (int i = 0; i < 4; i++) {
            }
            int temp_max = 0;
            for (int i : usecard_num) {
                if (i > temp_max) {
                    temp_max = i;
                }
            }
            WINDOW = 1;
            return temp_max;
        }

        return 0;
    }

    // 更新分数以及 返回值判断是否进入下一回合
    bool score_update() {
        score += check_type();

        if (is_use) {
            playcount--;
        } else {
            discardcount--;
        }

        if (score >= SCORE[ROUND]) {
            return true;
        } else {
            if (playcount == 0) {
                is_over = true;
            }
        }

        if (is_over) {
            WINDOW = 2;
        }

        return false;
    }
    // 窗口________________________________________
    void window() {
        switch (WINDOW) {
            case 1:
                std::cout << "__________________" << std::endl;
                std::cout << "您打出了" << "   " << "您的有效输出是：" << "   !!!     " << std::endl;
                std::cout << "此次出牌得分是：" << " !!!  " << std::endl;
                std::cout << "______________________________" << "  !!!    " << std::endl;
                break;

            case 2:
                std::cout << "您输掉了游戏！" << std::endl;
                std::cout << "如果要继续请输入y,其余输入将退出游戏。" << std::endl;
                break;

            default:
                std::cout << "__________________" << std::endl;
                std::cout << "当前回合数：" << ROUND + 1 << std::endl;
                std::cout << "目前拥有的小丑牌：" << std::endl;
                std::cout << "剩余出牌次数：" << playcount << "       " << "弃牌次数：" << discardcount << std::endl;
                std::cout << "当前分数：" << score << "             " << "目标分数" << SCORE[ROUND] << std::endl;
                std::cout << "当前手牌：" << std::endl;
                std::cout << "退出请输入q" << std::endl;

                for (int i = 0; i < 8; i++) {
                    std::cout << suit[i] << num[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "序号：";
                for (int i = 0; i < 8; i++) {
                    std::cout << i + 1;
                }
                std::cout << std::endl;

                // test
                for (size_t i = 0; i < discard_num.size(); i++) {
                    std::cout << discard_suit[i] << ":" << discard_num[i] << " ";
                }
        }
    }

    // 输入_________________________________________

    void input_get(std::vector<int>& input_int, std::string& input) {
        while (true) {
            bool positive = false;
            bool negative = false;
            bool check_isinput = true;
            input_int.clear();
            input.clear();
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
                } else {  // 0 在之前已经排除过
                    negative = true;
                }

                if (positive && negative) {
                    check_isinput = false;
                    break;
                } else {
                    is_use = positive;
                }

                if (iss.peek() != ' ' && !iss.eof()) {
                    check_isinput = false;
                    break;
                }
            }

            if (!iss.eof()) {
                check_isinput = false;
            }

            if (check_isinput == false) {
                std::cout << "输入错误，请重新输入" << std::endl;
                continue;
            }

            // 弃牌不足
            if (discardcount == 0 && is_use == false) {
                std::cout << "您已经没有弃牌次数了，请重新选择" << std::endl;
                continue;
            }

            break;
        }
        // 处理输入的负数
        if (is_use == false) {
            for (int& num : input_int) {
                num = -num;
            }
        }
        // 增加使用和弃牌，以及重置手牌
        for (int number : input_int) {
            add_usecard(number - 1);
            add_discard(number - 1);
            reset_num(number - 1);
        }
    }

} card;

void clearScreen() {
   std::cout << "\033[2J\033[1;1H";

}

//_______________________________________________
void calculate(const std::vector<int>& input_int) {
    // 同花 顺子 同花顺
}

// 还差 计算分数 （小丑牌 的规则）

// 小丑牌，目标分，

// 界面设计

// 分数的计算存在问题