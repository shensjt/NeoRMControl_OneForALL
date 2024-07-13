#include "header.h"

int main() {
    CARD card;
    std::srand((unsigned int)time(nullptr));

    bool game_check = true;

   
    while (game_check) { 
        game_check = card.game_loop();
    }
    return 0;
}