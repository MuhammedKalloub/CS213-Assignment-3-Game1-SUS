#include "SUS_Board.h"

SUS_Board::SUS_Board() : Board(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = '.';
}

bool SUS_Board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();

    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        return false;

    if (board[x][y] != '.')
        return false;

    board[x][y] = move->get_symbol();
    n_moves++;
    return true;
}

bool SUS_Board::is_win(Player<char>* player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'S' && board[i][1] == 'U' && board[i][2] == 'S')
            return true;
        if (board[0][i] == 'S' && board[1][i] == 'U' && board[2][i] == 'S')
            return true;
    }
    return false;
}

bool SUS_Board::is_draw(Player<char>* player) {
    return n_moves == 9 && !is_win(player);
}

bool SUS_Board::is_lose(Player<char>* player) {
    return false;
}

bool SUS_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}
