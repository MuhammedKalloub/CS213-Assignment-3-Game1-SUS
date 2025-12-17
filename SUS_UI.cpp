#include "SUS_UI.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

SUS_UI::SUS_UI() : UI<char>("SUS Game", 3) {
    srand(time(0));
}
Move<char>* SUS_UI::get_move(Player<char>* player) {
    int x, y;
    if (player->get_type() == PlayerType::HUMAN) {
        cout << "Enter row and column (0-2): ";
        cin >> x >> y;
    }
    else {
        x = rand() % 3;
        y = rand() % 3;
        cout << "Computer plays at: " << x << " " << y << endl;
    }
    return new Move<char>(x, y, player->get_symbol());
}
