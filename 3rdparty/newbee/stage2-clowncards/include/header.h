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

    //
    int WINDOW = 1;
    int ROUND = 1;         // 第几轮
    int playcount = 3;     // 剩余出牌次数
    int discardcount = 3;  // 弃牌次数

    int num[8] = { 0 };
    std::string suit[8] = { " " };

    std::vector<int> discard_num;  // 弃牌区 （需要清空的方法）小轮结束后清除
    std::vector<std::string> discard_suit;
    std::vector<int> usecard_num;  // 使用牌 （需要清空的方法）打出一次手牌后清除
    std::vector<std::string> usecard_suit;

    int score;

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

    // 选择卡牌
    void reset_num(int i) {
        num[i] = 0;
    }

    // 清空废牌区,得分,暂存的打出手牌
    void newgame() {
        discard_suit.clear();
        discard_num.clear();
        score = 0;
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
    // 清除使用牌
    void clear_usecard() {
        usecard_num.clear();
        usecard_suit.clear();
    }

    // 牌型检测
    int check_type(const std::vector<int>& input_int) {
        if (input_int.size() >= 5) {
            for (int i = 0; i < 4; i++) {
                for (int x = 0; x < input_int.size(); x++) {
                }
            }
        }
    }

    // 窗口________________________________________
    void window() {
        switch (WINDOW) {
            case 1:
                std::cout << "__________________" << std::endl;
                std::cout << "您的有效输出是：" << std::endl;
                std::cout << "目前拥有的小丑牌：" << std::endl;
                std::cout << "剩余出牌次数：" << playcount << "       " << "弃牌次数：" << discardcount << std::endl;
                std::cout << "当前分数：" << score << "             " << "目标分数" << SCORE[ROUND] << std::endl;
                std::cout << "当前手牌：";

                break;

            case 2: break;

            default:
                std::cout << "__________________" << std::endl;
                std::cout << "目前拥有的小丑牌：" << std::endl;
                std::cout << "剩余出牌次数：" << playcount << "       " << "弃牌次数：" << discardcount << std::endl;
                std::cout << "当前分数：" << score << "             " << "目标分数" << SCORE[ROUND] << std::endl;
                std::cout << "当前手牌：";
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

            break;
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
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
#endif
}

//_______________________________________________
void calculate(const std::vector<int>& input_int) {
    // 同花 顺子 同花顺
}

// 实现了废牌区
// 还差 计算分数 （小丑牌 的规则）

// 小丑牌，目标分，

// 再次进行游戏
// 界面设计
// 对输入的int 进行处理 是弃牌还是打牌
// 使用次数，与弃牌次数
// 结束判断