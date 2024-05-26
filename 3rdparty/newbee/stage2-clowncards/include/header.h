#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

class CARD {
private:
    std::string SUIT[4] = { "♠", "♥", "♣", "♦" };
    int num[8] = { 0 };
    std::string suit[8] = { " " };

    std::vector<int> discard_num; // 暂存已经出现的牌 （需要清空的方法）
    std::vector<std::string> discard_suit;

    int score;
public:
    // 设置点数和花色
    void INI_CARD() {
        for (int i = 0; i < 8; i++) {
            if (num[i] == 0) {
                num[i] = 1 + rand() % 13;
                int temp = rand() % 4;
                suit[i] = SUIT[temp];
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
    int get_num(int i) {
        return num[i];
    }
    int get_score(){
        return score;
    }


    // 选择卡牌
    void reset_num(int i) {
        num[i] = 0;
    }

    //  清空分数
    void reset_score(){
        score = 0;
    }
    // 清空废牌区
    void reset_discard(){
        discard_suit.clear();
        discard_num.clear();
    }
}card;

//_________________________________________





void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
#endif
}
//___________________________________________
void window() {
    switch (3)
    {

    case 1:

        break;

    case 2:

        break;

    default:
        std::cout << "__________________" << std::endl;
        std::cout << "目前拥有的小丑牌：" << std::endl;
        std::cout << "剩余出牌次数：" << std::endl;
        std::cout << "当前分数："<< card.get_score() <<"             "<< "目标分数" << std::endl;
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
//_______________________________________________
void calculate(const std::vector<int>& intput_int){



}