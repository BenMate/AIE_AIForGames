#include <iostream>
#include <vector>

/*
you are required to implement the IsValidMove method for an 'Othello' game.
ALL TESTS CASES MUST PASS.
Extra:
   - try to implement the method 'MakeMove' which should flip the approprate tiles
     for a player at a given location, the new state should be returned.

   - Finally, migrate this code to a 'raylib' project.. write a function to render the OthelloBoardState
     render a marker on any spot that represents a 'valid' move.

   - write logic to allow a user to click into the board, and place a tile.

   - can you refactor so that the OthelloBoardState uses a single array rather than a 2D array?
*/

typedef std::vector<std::vector<char>> OthelloBoardState;

bool IsValidMove(char player, int x, int y, const OthelloBoardState& grid)
{
    auto CheckDir = [&](int xd, int yd) {
        char oponent = player == 'B' ? 'W' : 'B';
        int xi = x + xd;
        int yi = y + yd;
        int inc = 0;
        while (xi >= 0 && xi < 8 && yi >= 0 && yi < 8)
        {
            if (grid[yi][xi] != oponent)
                break;
            xi += xd;
            yi += yd;
            inc++;
        }
        if (grid[yi][xi] == player && inc >= 1)
            return true;
        return false;
    };
    if (CheckDir(-1, 0)) return true;
    if (CheckDir(1, 0)) return true;
    if (CheckDir(0, -1)) return true;
    if (CheckDir(0, 1)) return true;
    if (CheckDir(-1, -1)) return true;
    if (CheckDir(1, -1)) return true;
    if (CheckDir(1, 1)) return true;
    if (CheckDir(-1, 1)) return true;
    return false;
}

OthelloBoardState MakeMove(char player, int x, int y, OthelloBoardState grid)
{
    // if the move was not valid, just return the origional...
    if (IsValidMove(player, x, y, grid) == false)
        return grid;

    // TODO: update 'grid' so that the approprate tiles have been flipped.
    return grid;
}

int main(int argc, char** argv)
{
    OthelloBoardState state1 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };

    auto ShouldBe = [](auto result, auto expected) {
        std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
    };

    ShouldBe(IsValidMove('B', 5, 4, state1), true); // true
    ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
    ShouldBe(IsValidMove('B', 3, 2, state1), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
    ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
    ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
    ShouldBe(IsValidMove('W', 2, 4, state1), true); // true
    ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
    ShouldBe(IsValidMove('W', 3, 5, state1), true); // true
    ShouldBe(IsValidMove('W', 5, 5, state1), false); // false
    OthelloBoardState state2 =

    {// 0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };

    ShouldBe(IsValidMove('B', 2, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 1, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 2, state2), true); // true
    ShouldBe(IsValidMove('B', 4, 1, state2), true); // true

    ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
    ShouldBe(IsValidMove('W', 2, 0, state2), true); // true
    ShouldBe(IsValidMove('W', 3, 1, state2), false); // false

    return 0;
}