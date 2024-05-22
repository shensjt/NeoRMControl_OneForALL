#include "header.h"
void test_show(CARD card) {

    for (int i = 0; i < 9; i++) {

        std::cout << card.get_suit(i) << ":" << card.get_num(i) << std::endl;

    }

}
int main(void) {

    std::srand((unsigned int)time(nullptr));
    CARD card;

    card.INI_CARD();
    test_show(card);

    card.set_num(0, 1);
    card.set_num(0, 0);

    card.INI_CARD();
    test_show(card);
	return 0;
}