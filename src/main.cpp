#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/event.hpp>
#include "game.hpp"

using namespace ftxui;

Element RenderGame(const Game& game) {
    auto board = game.GetBoard();
    std::vector<Element> rows;
    for (int r = 0; r < 4; ++r) {
        std::vector<Element> cells;
        for (int c = 0; c < 4; ++c) {
            int val = board[r*4 + c];
            std::string txt = (val == 0) ? "  " : (val < 10 ? " " + std::to_string(val) : std::to_string(val));
            cells.push_back(text(txt) | center | size(WIDTH, EQUAL, 3) | border);
        }
        rows.push_back(hbox(cells));
    }
    std::string status = game.GetStatus() == GameStatus::Won ?
        "🎉 You win! Press R to restart. 🎉" :
        "Moves: " + std::to_string(game.GetMoves());
    return vbox({
        text(" Sliding Puzzle (15 Puzzle) ") | bold | center | color(Color::Cyan),
        separator(),
        vbox(rows) | center,
        separator(),
        text(status) | center | color(game.GetStatus() == GameStatus::Won ? Color::Green : Color::Yellow),
        text(" Controls: ← ↑ ↓ → | R: restart | Q: quit ") | dim | center,
    }) | border;
}

int main() {
    auto screen = ScreenInteractive::TerminalOutput();
    Game game;
    auto component = Renderer([&] { return RenderGame(game); });
    component |= CatchEvent([&](Event event) {
        if (event == Event::ArrowUp) { game.TryMove(0, -1); return true; }
        if (event == Event::ArrowDown) { game.TryMove(0, 1); return true; }
        if (event == Event::ArrowLeft) { game.TryMove(-1, 0); return true; }
        if (event == Event::ArrowRight) { game.TryMove(1, 0); return true; }
        if (event == Event::Character('r') || event == Event::Character('R')) { game.Reset(); return true; }
        if (event == Event::Character('q') || event == Event::Character('Q')) { screen.ExitLoopClosure()(); return true; }
        return false;
    });
    screen.Loop(component);
    return 0;
}