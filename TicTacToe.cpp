#include<iostream>
#include <ctime>

// Function prototypes
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    // Initialize the game variables
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Represents the Tic-Tac-Toe board
    char player = 'X'; // Player's marker
    char computer = 'O'; // Computer's marker
    bool running = true; // Flag to control the game loop

    // Display the initial board
    drawBoard(spaces);

    // Main game loop
    while(running){
        // Player's turn
        playerMove(spaces, player);
        drawBoard(spaces);

        // Check if player wins or ties
        if(checkWinner(spaces, player, computer)){
            running = false; // Game ends if there's a winner
            break;
        }
        else if(checkTie(spaces)){
            running = false; // Game ends in tie
            break;
        }

        // Computer's turn
        computerMove(spaces, computer);
        drawBoard(spaces);

        // Check if computer wins or ties
        if(checkWinner(spaces, player, computer)){
            running = false; // Game ends if there's a winner
            break;
        }
        else if(checkTie(spaces)){
            running = false; // Game ends in tie
            break;
        }
    }

    // After the game ends, print a message
    std::cout << "Thanks for playing!\n";

    return 0;
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

// Function for player's move
void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--; // Convert to zero-indexed
        // Check if the chosen spot is empty
        if(spaces[number] == ' '){
           spaces[number] = player; // Place the player's marker
           break; // Exit the loop if the move is valid
        }
        else {
            std::cout << "Invalid move. Please choose an empty spot.\n";
        }
    } while(number < 0 || number > 8); // Ensure the input is within valid range
}

// Function for computer's move
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0)); // Seed for random number generation based on current time

    while(true){
        number = rand() % 9; // Generate a random number between 0 and 8
        // Check if the chosen spot is empty
        if(spaces[number] == ' '){
            spaces[number] = computer; // Place the computer's marker
            break; // Exit the loop if the move is valid
        }
    }
}

// Function to check if there's a winner
bool checkWinner(char *spaces, char player, char computer){
    // Check all possible win conditions
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false; // No winner yet
    }
    return true; // There's a winner
}

// Function to check if the game is tied
bool checkTie(char *spaces){
    // Check if all spots are filled
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false; // Game is not tied
        }
    }
    std::cout << "IT'S A TIE!\n"; // If all spots are filled and no winner
    return true; // Game is tied
}
