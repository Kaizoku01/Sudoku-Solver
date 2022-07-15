// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


class Structure{
    public:
    void PrintGrid(); 
    void Brainfn();
};
class Brain: public Structure{
    private:
        bool isValid(vector<vector<char>> board, int row, int col, char c){
            for(int i = 0; i<9; i++){
                if(board[i][col] == c) return false;        
                if(board[row][i] == c) return false;
                if(board[3*(row/3) + i / 3][3*(col/3) + i % 3] == c) return false;
            }
            return true;
        }


        bool Solve(vector<vector<char>> &board){
            for(int i = 0; i<board.size(); i++){
                for(int j = 0; j<board[0].size(); j++){
                    if(board[i][j] == '.'){
                        for(char c = '1';c <= '9';c++){
                            if(isValid(board, i, j, c)){
                                board[i][j] = c;
                                if(Solve(board)) return true;
                                else
                                    board[i][j] = '.';
                            }
                        }
                            return false;
                    }
                }
            }
            return true;
        }

    public:
        void PrintGrid(vector<vector<char>> &board,string title){
            cout<<title<<'\n';
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    cout<<"|"<<" "<<board[i][j]<<" ";
                }
                cout<<"|"<<'\n';
            }
            cout<<'\n';
        }

        void Brainfn(vector<vector<char>> &board){
            Solve(board);
        }
};
int main(){

    Brain obj;
    char start;
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    cout<<"WELCOME TO THE SUDOKU SOLVER:"<<'\n';
    cout<<"Enter to Start"<<'\n';
    cin.ignore();

    obj.PrintGrid(board,"INCOMPLETE SUDOKU BOARD");

    cout<<"Enter to solve the above Sudoku Puzzle"<<'\n';
    cin.ignore();

    obj.Brainfn(board);
    // system("cls");
    obj.PrintGrid(board,"COMPLETE SUDOKU BOARD:");
}