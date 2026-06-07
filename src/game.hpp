#pragma once
#include <array>

enum class GameStatus { Playing, Won };

class Game {
public:
    Game();
    void Reset();
    bool TryMove(int dx, int dy);
    bool IsWin() const;
    const std::array<int, 16>& GetBoard() const { return board_; }
    int GetEmptyRow() const { return empty_row_; }
    int GetEmptyCol() const { return empty_col_; }
    int GetMoves() const { return moves_; }
    GameStatus GetStatus() const { return status_; }

private:
    void RandomShuffle(int steps = 200);
    int Index(int row, int col) const { return row * 4 + col; }
    std::array<int, 16> board_;
    int empty_row_ = 3, empty_col_ = 3, moves_ = 0;
    GameStatus status_ = GameStatus::Playing;
};