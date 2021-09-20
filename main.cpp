#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
class Game
{
private:
    int turn;
    int **board;

public:

                    // DEFAULT CONSTRUCTOR
    Game(){
    turn = 0;
    board = NULL;
    }


                    // CONSTRUCTOR
    Game(int t){
        turn = t;
        board = new int*[7];
        for(int i =0; i < 7; i++){
            board[i] = new int[7];
        }
        for(int i = 0; i <7; i++){
            for(int j = 0; j< 7; j++){
                board[i][j] = -1;
            }
        }
    }


                    // DESTRUCTOR
    ~Game(){
        if(board != NULL){
        for (int i = 0; i < 7; i++){
            delete[] board[i];
        }
        delete []board;
    }
}


                    // SHOW BORAD
    void showboard(){
        cout << "\n\n\t\t\t\t CONNECT 4 GAME " << endl;
         cout << endl;
         cout << "\t\t\t\tGAME BOARD " << endl;
         cout << "\t\t  1    2    3    4    5    6    7 " << endl;
         cout << "\t\t------------------------------------" << endl;
         for(int i = 0; i <7; i++){
                cout << "\t\t| ";
            for(int j = 0; j< 7; j++){
              if(board[i][j] != -1){
               cout << setw(3) << left << board[i][j];
            }
            else{
                cout << setw(3) << left << " ";
            }
            cout << "| ";
            }
            cout << endl;
        }
          cout << "\t\t------------------------------------" << endl;

    }


                    // BOARD IS FULL
    bool isfull(){
        int full;
        full = 0;
        for ( int i = 0; i < 7; ++i ){
            if ( board[0][i] != -1)
                ++full;
        }
        if(full == 7){
        return true;
        }
        return false;
    }


                    // IS WON
    bool iswon(){
        int win1 = 0, win2 = 0;
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){

              if(board[i][j] == 1){
                if (j < 4 && board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1) {
                    win1 = 1;
                }
                if (j < 3 && board[i][j] == 1 && board[i][j - 1] == 1 && board[i][j - 2] == 1 && board[i][j - 3] == 1) {
                    win1 = 1;
                }
                if (i > 2 && board[i][j] == 1 && board[i - 1][j] == 1 && board[i - 2][j] == 1 && board[i - 3][j] == 1) {
                    win1 = 1;
                }
                if (i < 4 && board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1) {
                    win1 = 1;
                }
                if (i > 2 && j < 4  && board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1) {
                    win1 = 1;
                }
                if (i < 4 && j < 3 && board[i][j] == 1 && board[i + 1][j - 1] == 1 && board[i + 2][j - 2] == 1 && board[i + 3][j - 3] == 1) {
                    win1 = 1;
                }
                if (i > 2 && j < 3 && board[i][j] == 1 && board[i - 1][j - 1] == 1 && board[i - 2][j - 2] == 1 && board[i - 3][j - 3] == 1) {
                    win1 = 1;
                }
                if (i < 4 && j < 4 && board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1) {
                    win1 = 1;
                }
            }

              if(board[i][j] == 2){
                  if (j < 4 && board[i][j] == 2 && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2) {
                    win2 = 1;
                }
                if (j < 3 && board[i][j] == 2 && board[i][j - 1] == 2 && board[i][j - 2] == 2 && board[i][j - 3] == 2) {
                    win2 = 1;
                }
                if (i > 2 && board[i][j] == 2 && board[i - 1][j] == 2 && board[i - 2][j] == 2 && board[i - 3][j] == 2) {
                    win2 = 1;
                }
                if (i < 4 && board[i][j] == 2 && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2) {
                    win2 = 1;
                }
                if (i > 2 && j < 4 && board[i][j] == 2 && board[i - 1][j + 1] == 2 && board[i - 2][j + 2] == 2 && board[i - 3][j + 3] == 2) {
                    win2 = 1;
                }
                if (i < 4 && j < 3 && board[i][j] == 2 && board[i + 1][j - 1] == 2 && board[i + 2][j - 2] == 2 && board[i + 3][j - 3] == 2) {
                    win2 = 1;
                }
                if (i > 2 && j < 3 && board[i][j] == 2 && board[i - 1][j - 1] == 2 && board[i - 2][j - 2] == 2 && board[i - 3][j - 3] == 2) {
                    win2 = 1;
                }
                if (i < 4 && j < 4 && board[i][j] == 2 && board[i + 1][j + 1] == 2 && board[i + 2][j + 2] == 2 && board[i + 3][j + 3] == 2) {
                    win2 = 1;
                }
                }
            }
        }

        if(win1 == 1 && win2 == 1){
            cout << "\nGAME DRAW" << endl;
            return true;
        }

        else if(win1 == 1 && win2 == 0){
            cout << "\nCongratulations!!\nPlayer 1 won the game " << endl;
            return true;
        }

        else if(win1 == 0 && win2 == 1){
            cout << "\nCongratulations!!\nPlayer 2 won the game " << endl;
            return true;
        }

        else{
            return false;
        }
    }


                    // SWITCH TURN
    void switchturn(int player){
        int i;
        if(player == 1){
            P1INPUT:
            cout << "Player 1:: Enter value in (1-7) : ";
            cin >> turn;
             while((turn) < 1 || (turn) > 7){
                goto P1INPUT;
            }
            while(board[0][turn-1] != -1){
                cout << "No space here. Enter Again !! : ";
                cin >> turn;
            }
            for(i = 6; i >= 0 ; i--){
                if(board[i][turn-1] == -1){
                  board[i][turn-1] = 1;
                  break;
                }

            }
        }

        if(player == 2){
            P2INPUT:
            cout << "Player 2:: Enter value in (1-7) : ";
            cin >> turn;
            while((turn) < 1 || (turn) > 7){
                goto P2INPUT;
            }
            while(board[0][turn-1] != -1){
                cout << "No space here. Enter Again !! : ";
                cin >> turn;
            }
            for(i = 6; i >= 0 ; i--){

                if(board[i][turn-1] == -1){
                  board[i][turn-1] = 2;
                  break;
                }

            }

        }
    }


                    //STRAT GAME
    void start(){
        Game play(1);
        play.showboard();

        while(play.isfull() == false || play.iswon() == false){
        play.switchturn(1);
        system("cls");
        play.showboard();

        if(play.isfull()){
        cout << "\nBoard is full !! GAME DRAW " << endl;
        return;
     }
        if(play.iswon()){
        return;
    }


        play.switchturn(2);
        system("cls");
        play.showboard();
        if(play.isfull()){
        cout << "\nBoard is full !! GAME DRAW " << endl;
        return;
     }
        if(play.iswon()){
        return;
    }
    play.isfull();
    play.iswon();
    }
    return;
    }


};
int main()
{
    Game p1;
    p1.start();
    cout << endl;
    cout << "------------" << endl;
    cout << " GAME ENDED " << endl;
    cout << "------------" << endl;
    cout << "Developed By Muhammad Yasir " << endl;

    return 0;
}
