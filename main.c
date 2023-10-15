#include <stdio.h>

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("  1   2   3\n");
    printf("1 %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("  ---------\n");
    printf("2 %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("  ---------\n");
    printf("3 %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if a move is valid
int isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to check if the game is over (win or draw)
int isGameOver(char board[3][3]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Column win
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonal win
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonal win

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Game is not over yet
        }
    }

    return -1; // It's a draw
}

int main() {
    char board[3][3];
    int currentPlayer = 1; // Player 1 starts

    initializeBoard(board);

    int row, col, move;
    int gameStatus = 0; // 0: Game in progress, 1: Player 1 wins, 2: Player 2 wins, -1: Draw

    while (gameStatus == 0) {
        // Display the board
        displayBoard(board);

        // Get the current player's move
        printf("Player %d, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(board, row - 1, col - 1)) {
            if (currentPlayer == 1) {
                board[row - 1][col - 1] = 'X';
                currentPlayer = 2;
            } else {
                board[row - 1][col - 1] = 'O';
                currentPlayer = 1;
            }
        } else {
         r   printf("Invalid move. Try again.\n");
        }

        gameStatus = isGameOver(board);
    }

    displayBoard(board);

    if (gameStatus == -1)
        printf("It's a draw!\n");
    else
        printf("Player %d wins!\n", gameStatus);

    return 0;
}
 