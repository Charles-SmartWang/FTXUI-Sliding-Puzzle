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
```

## 操作说明

| 按键 | 功能               |
|------|------------------|
| ↑    | 向上移动数字块       |
| ↓    | 向下移动数字块       |
| ←    | 向左移动数字块       |
| →    | 向右移动数字块       |
| R    | 重新开始游戏（随机打乱） |
| Q    | 退出游戏            |

## 项目结构

```
FTXUI-Sliding-Puzzle/
├── CMakeLists.txt      # CMake 构建配置
├── README.md           # 项目说明
├── .gitignore          # Git 忽略文件
└── src/
    ├── game.hpp        # 游戏逻辑头文件
    ├── game.cpp        # 游戏逻辑实现
    └── main.cpp        # 主程序入口与界面渲染
```

## 技术实现

- **界面**：使用 FTXUI 库在终端中绘制网格、文本和边框，支持键盘事件。
- **游戏逻辑**：经典的 15-puzzle 规则，随机打乱时使用逆推法确保谜题有解。
- **构建系统**：CMake 自动下载 FTXUI 依赖，无需手动安装。


