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

    std::string get_suit(int i) {
        return suit[i];
    }

    int get_num(int i) {
        return num[i];
    }

    void reset_num(int i) {
        num[i] = 0;
    }
};