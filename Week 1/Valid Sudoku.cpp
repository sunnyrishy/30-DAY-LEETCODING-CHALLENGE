class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowcase[9][9] = {0};    //store occurances of number in rows
        int colcase[9][9] = {0};    //store occurances of number in columns
        int gridcase[9][9] = {0};   //store occurances of number in 3x3 grid

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    int number = board[i][j] - '0';  //converting character to integer  --> "5" is taken as 5

                    int k = i/3 * 3 + j/3;   //used to determine the grid index for each integer input

                    if(rowcase[i][number-1]++ || colcase[j][number-1]++ || gridcase[k][number-1]++) {  //while checking the conditions if it encounters 1, it returns false
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
