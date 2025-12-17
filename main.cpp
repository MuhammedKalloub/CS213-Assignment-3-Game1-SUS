#include "BoardGame_Classes.h"
#include "SUS_Board.h"
#include "SUS_UI.h"
#include <iostream>
using namespace std;

int main() {
    SUS_Board board;
    SUS_UI ui;

    int choice;
    cout << "Choose Gamemode:\n";
    cout << "1: Human vs Human\n";
    cout << "2: Human vs AI\n";
    cout << "3: AI vs AI\n";
    cout << " : ";
    cin >> choice;

    Player<char>* players[2];

    string name1 = "Player 1";
    string name2 = "Player 2";

    if (choice == 1) { //PvP
        players[0] = ui.create_player(name1, 'S', PlayerType::HUMAN);
        players[1] = ui.create_player(name2, 'U', PlayerType::HUMAN);
    }
    else if (choice == 2) { //PvAI
        players[0] = ui.create_player(name1, 'S', PlayerType::HUMAN);
        players[1] = ui.create_player(name2, 'U', PlayerType::COMPUTER);
    }
    else { //AIvAI
        players[0] = ui.create_player(name1, 'S', PlayerType::COMPUTER);
        players[1] = ui.create_player(name2, 'U', PlayerType::COMPUTER);
    }

    GameManager<char> game(&board, players, &ui);
    game.run();

    return 0;
}
