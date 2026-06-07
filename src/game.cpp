#include "game.hpp"
#include <random>
#include <chrono>
#include <algorithm>

Game::Game() { Reset(); }

void Game::Reset() {
    for (int i = 0; i < 15; ++i) board_[i] = i + 1;
    board_[15] = 0;
    empty_row_ = empty_col_ = 3;
    moves_ = 0;
    status_ = GameStatus::Playing;
    RandomShuffle(200);
}

bool Game::TryMove(int dx, int dy) {
    if (status_ != GameStatus::Playing) return false;
    int nr = empty_row_ + dy, nc = empty_col_ + dx;
    if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) return false;
    std::swap(board_[Index(empty_row_, empty_col_)], board_[Index(nr, nc)]);
    empty_row_ = nr; empty_col_ = nc;
    if (++moves_ && IsWin()) status_ = GameStatus::Won;
    return true;
}

bool Game::IsWin() const {
    for (int i = 0; i < 15; ++i) if (board_[i] != i + 1) return false;
    return board_[15] == 0;
}

void Game::RandomShuffle(int steps) {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dir(0, 3);
    const int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    for (int s = 0; s < steps; ++s) {
        int d = dir(rng);
        int nr = empty_row_ + dy[d], nc = empty_col_ + dx[d];
        if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
            std::swap(board_[Index(empty_row_, empty_col_)], board_[Index(nr, nc)]);
            empty_row_ = nr; empty_col_ = nc;
        }
    }
    moves_ = 0;
    status_ = GameStatus::Playing;
}