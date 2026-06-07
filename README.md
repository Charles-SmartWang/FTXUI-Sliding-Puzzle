# FTXUI-Sliding-Puzzle

一个基于 **FTXUI** 库开发的 **数字华容道**（15 Puzzle）终端小游戏，完全使用 C++17 编写。  
该项目是“AI驱动的开发实践”课程大作业，代码由 AI 辅助生成。

## 游戏规则

- 游戏盘面为 4×4 网格，包含数字 1~15 和一个空格。
- 使用键盘方向键（↑ ↓ ← →）移动与空格相邻的数字块。
- 目标：将所有数字按从左到右、从上到下的顺序排列，空格位于右下角。
- 每移动一步，步数加 1。游戏胜利后会显示祝贺信息。

## 构建与运行

### 依赖

- CMake ≥ 3.14
- C++17 兼容的编译器（GCC 7+ / Clang 5+ / MSVC 2017+）
- 网络连接（首次构建时自动下载 FTXUI 库）

### 构建步骤

```bash
# 克隆仓库
git clone https://github.com/你的用户名/FTXUI-Sliding-Puzzle.git
cd FTXUI-Sliding-Puzzle

# 配置并编译
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# 运行游戏
# Linux / macOS:
./build/sliding_puzzle
# Windows:
.\build\Release\sliding_puzzle.exe
