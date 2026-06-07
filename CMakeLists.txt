cmake_minimum_required(VERSION 3.14)
project(SlidingPuzzle VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
    GIT_TAG        v5.0.0
)
FetchContent_MakeAvailable(ftxui)

add_executable(sliding_puzzle
    src/main.cpp
    src/game.cpp
    src/game.hpp
)

target_link_libraries(sliding_puzzle
    ftxui::screen
    ftxui::dom
    ftxui::component
)