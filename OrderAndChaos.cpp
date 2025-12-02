#include <iostream>
#include <vector>
using namespace std;

int main()
{
    char board[6][6] = { 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '}, 
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    // const char playerX = 'X';
    // const char playerO = 'O';
    const string playerOrder = "Order";
    const string playerChaos = "Chaos";

    string currentPlayer = playerOrder;
    char symbolToPlace = 'Z';
    int r = -1;
    int c = -1;
    char winner = ' ';

    for (int i = 0; i < 36; i++) {
        // print game board
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << board[0][3] << " | " << board[0][4] << " | " << board[0][5] << endl;

        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << " | " << board[1][4] << " | " << board[1][5] << endl;


        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << " | " << board[2][4] << " | " << board[2][5] << endl;

        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | " << board[3][3] << " | " << board[3][4] << " | " << board[3][5] << endl;

        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[4][0] << " | " << board[4][1] << " | " << board[4][2] << " | " << board[4][3] << " | " << board[4][4] << " | " << board[4][5] << endl;

        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |   " << endl;
        cout << " " << board[5][0] << " | " << board[5][1] << " | " << board[5][2] << " | " << board[5][3] << " | " << board[5][4] << " | " << board[5][5] << endl;
        cout << "   |   |   |   |   |   " << endl;

        if (winner != ' ') {
            break;
        }

        // get player input
        cout << currentPlayer << endl;
        while (true) {
            cout << "Pls enter your move (symbol X or O, row and column from 0 to 5): " << endl;
            cin >> symbolToPlace >> r >> c;
            if (r < 0 || r > 5 || c < 0 || c > 5 || (symbolToPlace != 'x' && symbolToPlace != 'o')) {
                cout << "Invalid input, try again." << endl;
            }
            else if (board[r][c] != ' ') {
                cout << "Tile is full, try again" << endl;
            }
            else {
                break;
            }
            r = -1;
            c = -1;
            cin.clear(); // clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }


        board[c][r] = symbolToPlace;
        currentPlayer = (currentPlayer == playerChaos) ? playerOrder : playerChaos;

        // check for winner

        // row check
        for (int i = 0; i < 6; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && 
                board[i][3] == board[i][4] && board[i][4] != ' ') {
                winner = 'O';
                break;
            }

            if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && 
                board[i][4] == board[i][5] && board[i][5] != ' ') {
                winner = 'O';
                break;
            }
        }

        // column check
        for (int j = 0; j < 6; j++) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j] && 
                board[3][j] == board[4][j] && board[4][j] != ' ') {
                winner = 'O';
                break;
            }
            if (board[1][j] == board[2][j] && board[2][j] == board[3][j] && board[3][j] == board[4][j] && 
                board[4][j] == board[5][j] && board[5][j] != ' ') {
                winner = 'O';
                break;
            }
        }

        // diagonal check (top-left to bottom-right)
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
            board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[4][4] != ' ') {
            winner = 'O';
            break;
        }
        
        if (board[1][1] == board[2][2] && board[2][2] == board[3][3] &&
            board[3][3] == board[4][4] && board[4][4] == board[5][5] && board[5][5] != ' ') {
            winner = 'O';
            break;
        }

        if (board[0][1] == board[1][2] && board[1][2] == board[2][3] &&
            board[2][3] == board[3][4] && board[3][4] == board[4][5] && board[4][5] != ' ') {
            winner = 'O';
            break;
        }

        if (board[1][0] == board[2][1] && board[2][1] == board[3][2] &&
            board[3][2] == board[4][3] && board[4][3] == board[5][4] && board[5][4] != ' ') {
            winner = 'O';
            break;
        }



        // diagonal check (top-right to bottom-left)
        if (board[0][5] == board[1][4] && board[1][4] == board[2][3] && 
            board[2][3] == board[3][2] && board[3][2] == board[4][1] && board[4][1] != ' ') {
            winner = 'O';
            break;
        }

        if (board[1][4] == board[2][3] && board[2][3] == board[3][2] && 
            board[3][2] == board[4][1] && board[4][1] == board[5][0] && board[5][0] != ' ') {
            winner = 'O';
            break;
        }

        if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && 
            board[2][2] == board[3][1] && board[3][1] == board[4][0] && board[4][0] != ' ') {
            winner = 'O';
            break;
        }

        if (board[1][5] == board[2][4] && board[2][4] == board[3][3] && 
            board[3][3] == board[4][2] && board[4][2] == board[5][1] && board[5][1] != ' ') {
            winner = 'O';
            break;
        }


    }

    if (winner == ' ') {
        cout << "Chaos wins" << endl;
    } else {
        cout << winner << " wins!" << endl;
    }

    return 0;
}