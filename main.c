#include <stdio.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();

void printBoard();

int checkFreeSpace();

void playerMove(char);

char checkWinner();

void printWinner(char);

int main() {
    char winner = ' ';

    resetBoard();

    while (winner == ' ' && checkFreeSpace() != 0) {
        printBoard();

        playerMove(PLAYER1);
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpace() == 0)
            break;


        printBoard();

        playerMove(PLAYER2);
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpace() == 0)
            break;

    }

    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpace() {
    int freeSpaces = 9;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(char pl) {
    int x;
    int y;

    do {
        printf("\n");
        printf("Enter row  #(1-3):");
        scanf("%d", &x);
        x--;
        printf("Enter column  #(1-3):");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') {
            printf("Invalid move\n");
        } else {
            board[x][y] = pl;
            break;
        }
    } while (board[x][y] != ' ');

}

char checkWinner() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
    }
    return ' ';

}

void printWinner(char winner) {
    if (winner == PLAYER1) {
        printf("Player 1 WON!");
    } else if (winner == PLAYER2) {
        printf("Player 2 WON!");
    } else {
        printf("DRAW!");
    }
}
