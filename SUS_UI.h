#ifndef SUS_UI_H
#define SUS_UI_H
#include "BoardGame_Classes.h"

class SUS_UI : public UI<char> {
public:
    SUS_UI();
    Move<char>* get_move(Player<char>* player) override;
};

#endif
