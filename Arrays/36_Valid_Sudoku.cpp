#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (colSet.count(board[i][j])) return false;
                    colSet.insert(board[i][j]);
                }
            }
        }

        for (int block = 0; block < 9; block++) {
            unordered_set<char> boxSet;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = 3 * (block / 3) + i;
                    int col = 3 * (block % 3) + j;
                    if (board[row][col] != '.') {
                        if (boxSet.count(board[row][col])) return false;
                        boxSet.insert(board[row][col]);
                    }
                }
            }
        }
        return true;
    }
};
