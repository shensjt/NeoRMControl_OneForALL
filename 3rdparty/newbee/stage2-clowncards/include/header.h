#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

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
    bool is_use;           // 是 使用牌 还是 弃牌

public:
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

    // 测试分数计算
//     void INI_CARD() {
//         for (int i = 0; i < 8; i++) {
//             if (num[i] == 0) {
//                 if (i != 4) {
//                     num[i] = i + 1;
//                 }
//                 else {
//                     num[i] = 12;
//                 }
//                 suit[i] = 1;
//             }
//         }
//}
    
    // 检查窗口
    void window_check() {
        std::cout << "window_check" << std::endl;
        std::cout << "手牌" << std::endl;
        for (int i = 0; i < 8; i++) {
            std::cout << SUIT[suit[i]] << ":" << NUM[num[i]] << " ";
        }
            std::cout << std::endl;

            std::cout << "使用牌" << std::endl;
            for (int i = 0; i < usecard_num.size(); i++) {
                std::cout << SUIT[usecard_suit[i]] << ":" << NUM[usecard_num[i]] << " ";
            }
            std::cout << std::endl;

            std::cout << "弃牌区" << std::endl;
            for (int i = 0; i < discard_num.size(); i++) {
                std::cout << SUIT[discard_suit[i]] << ":" << NUM[discard_num[i]] << " ";
            }
            std::cout << std::endl;
            std::cout << "使用次数：" << usecount << "   " << " 弃牌次数：" << discardcount << " 总分数：" << score << std::endl;
    }

    // 拿到用户输入

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
            usecard_num.clear();
            usecard_suit.clear();
            if (input == "q") {
                break;
            }

            while (iss >> number) {
                input_int.push_back(number);

                // 判定输入数字的范围（具体实际情况还没确定） 全负数，全正数
                if (number > 8 || input_int.size() > 5) {
                    check_isinput = false;
                    break;
                }

                // 确保全正 或 全负数
                if (number > 0) {
                    positive = true;
                }
                else {  // 0 在之前已经排除过
                    negative = true;
                }

                if (positive && negative) {
                    check_isinput = false;
                    break;
                }
                else {
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
            // 弃牌区的增加
            discard_num.push_back(num[number - 1]);
            discard_suit.push_back(suit[number - 1]);

            usecard_num.push_back(num[number - 1]);
            usecard_suit.push_back(suit[number - 1]);

            num[number - 1] = 0;
        }
    }

    void score_update() {
        if (is_use == true) {
            usecount--;
        }
        else {
            discardcount--;
        }

        // 计算分数
        if (is_use) {
            // 整理使用牌
            if (usecard_num.size() != usecard_suit.size()) {
                std::cout << "使用牌的数量和花色不匹配" << std::endl;
            }
            
            bool is_flush = true;
                bool is_straight = true;
                int chip = 0;
                int bet = 0;
                int two_1 = 0;
                int two_2 = 0;
                int three = 0;
                int four = 0;
                int index = 1;
                for (int i = 0; i < usecard_num.size(); i++) {
                    for (int j = 0; j < usecard_num.size() - 1; j++) {
                        if (usecard_num[j] > usecard_num[j + 1]) {
                            int temp_num = usecard_num[j];
                            int  temp_suit = usecard_suit[j];
                            usecard_num[j] = usecard_num[j + 1];
                            usecard_suit[j] = usecard_suit[j + 1];
                            usecard_num[j + 1] = temp_num;
                            usecard_suit[j + 1] = temp_suit;
                        }
                    }
                }
                // 分数计算
                
                // 同花顺 同花 顺子
                if (usecard_num.size() == 5) {
                    // 同花
                    for (int i = 0; i < 4; i++) {
                        if (usecard_suit[0] != usecard_suit[i]) {
                            is_flush = false;
                        }
                        if (i < 4) {
                            if (usecard_num[i] != usecard_num[i + 1] - 1) {
                                is_straight = false;
                            }
                        }
                    }
                }
                else {
                    is_flush = false;
                    is_straight = false;
                }

                // 对子类
                // 设计几个变量来存储两，三，四。
                int temp = usecard_num[0];
                for (int i = 0; i < usecard_num.size() - 1; i++) {
                    
                    if (temp == usecard_num[i + 1]) {
                        index++;
                    }
                    else {
                        index = 1;
                        temp = usecard_num[i + 1];
                    }
                    if (index == 2) {
                        if (two_1 == 0) {
                            two_1 = temp;
                        }
                        else {
                            two_2 = temp;
                        }
                    }
                    if (index == 3) {
                        if (two_2 == 0) {
                            two_1 = 0;
                            three = temp;
                        }
                        else {
                            two_2 = 0;
                            three = temp;
                        }
                    }

                    if (index == 4) {
                        three = 0;
                        four = temp;
                    }
                }

                // 计算分数
                // chip and bet 还未写重置
                // 一牌型的基础倍率和筹码
                if (is_flush && is_straight) {
                    for (int num : usecard_num) {
                        if (num >= 11 && num <= 13) {
                            num = 10;
                        }
                        else if (num == 1) {
                            num = 11;
                        }
                        chip += num;
                    }
                    chip += 100;
                    bet += 8;
                }
                else if (four) {
                    if (four >= 11 && four <= 13) {
                        four = 10;
                    }
                    else if (four == 1) {
                        four = 11;
                    }
                    chip += 60;
                    chip += four * 4;
                    bet += 7;
                }

                else if (three && two_1) {
                    if (three >= 11 && three <= 13) {
                        three = 10;
                    }
                    else if (three == 1) {
                        three = 11;
                    }
                    if (two_1 >= 11 && two_1 <= 13) {
                        two_1 = 10;
                    }
                    else if (two_1 == 1) {
                        two_1 = 11;
                    }
                    chip += 40;
                    chip += (three * 3 + two_1 * 2);
                    bet += 4;
                }
                else if (is_flush) {
                    for (int num : usecard_num) {
                        if (num >= 11 && num <= 13) {
                            num = 10;
                        }
                        else if (num == 1) {
                            num = 11;
                        }
                        chip += num;
                    }
                    chip += 35;
                    bet += 4;
                }
                else if (is_straight) {
                    for (int num : usecard_num) {
                        if (num >= 11 && num <= 13) {
                            num = 10;
                        }
                        else if (num == 1) {
                            num = 11;
                        }
                        chip += num;
                    }
                    chip += 30;
                    bet += 4;
                }
                else if (three) {
                    if (three >= 11 && three <= 13) {
                        three = 10;
                    }
                    else if (three == 1) {
                        three = 11;
                    }
                    chip += 30;
                    chip += three * 3;
                    bet += 3;
                }
                else if (two_1 && two_2) {
                    if (two_1 >= 11 && two_1 <= 13) {
                        two_1 = 10;
                    }
                    else if (two_1 == 1) {
                        two_1 = 11;
                    }
                    if (two_2 >= 11 && two_2 <= 13) {
                        two_2 = 10;
                    }
                    else if (two_2 == 1) {
                        two_2 = 11;
                    }
                    chip += 20;
                    chip += (two_1 * 2 + two_2 * 2);
                    bet += 2;
                }
                else if (two_1) {
                    if (two_1 >= 11 && two_1 <= 13) {
                        two_1 = 10;
                    }
                    else if (two_1 == 1) {
                        two_1 = 11;
                    }
                    chip += 10;
                    chip += two_1 * 2;
                    bet += 2;
                }
                else {
                    int max_tem = 0;
                    for (int num : usecard_num) {
                        if (num == 1) {
                            max_tem = 11;
                            break;
                        }
                        if (num > max_tem) {
                            max_tem = num;
                            if (max_tem > 10) {
                                max_tem = 10;
                            }
                        }
                    }
                    chip += 5;
                    chip += max_tem;
                    bet += 1;
                }
 temp_score = chip * bet;
                score += temp_score;
            }
               
        }
        
    bool game_loop() {
        std::vector<int> input_int;  // 输入值处理后得到整数
        std::string input;           // 输入的存放
        while (true) {
            clearScreen();

            INI_CARD();

            window_check();
            
         input_get(input_int, input);

            if (input == "q") { return false; }


            score_update();

            if (usecount == 0 && score < target_score) {
                return false;                // 失败判定后面结果处理 ！！！！
            }

        }
    }
} card;
