# Cpp-Projects
Tic-Tac-Toe Game with Computer

This is a console-based Tic-Tac-Toe game implemented in C++, featuring a simple AI for the computer player.
Overview

Tic-Tac-Toe is a classic two-player game where players take turns marking spaces in a 3x3 grid with their respective markers (X or O). The objective is to be the first to align three of one's own markers horizontally, vertically, or diagonally.
Features

    Player vs. Computer: Play against an AI that makes random moves.
    Win Detection: Automatically detects when a player or the computer wins.
    Tie Detection: Detects when the game ends in a tie.
    Simple Console Interface: Runs in the console with basic input and output.

Computer Logic
The computer player in this Tic-Tac-Toe game is implemented using a straightforward random move strategy:
Strategy

    Random Move Generation:
        The AI generates its move randomly by selecting an empty spot on the board.
        It uses rand() function to generate a random number between 0 and 8 (inclusive).
        The move is only accepted if the selected spot is currently empty (' ').

    Implementation Details:
        The AI's move is implemented in the computerMove function.
        It iteratively generates random numbers until it finds an empty spot to place its marker.

    Example of AI Logic:
        The AI does not employ any sophisticated algorithms (like minimax or alpha-beta pruning) to determine optimal moves.
        It simply aims to make a valid move in an available spot each turn.

How to Play

    Compile and Run:
        Compile the code using a C++ compiler (e.g., g++).
        Run the executable in a console or terminal.

    Gameplay:
        Players take turns to input their move by entering a number corresponding to the spot on the board (1-9).
        The game continues until a player wins or the board fills up (resulting in a tie).

    End of Game:
        After the game ends, a message is displayed indicating whether the player wins, loses, or the game ends in a tie.

Example Output

Here is an example of how the game might look during play:

mathematica

     |     |     
  X  |  O  |  X  
_____|_____|_____
     |     |     
  O  |  X  |  O  
_____|_____|_____
     |     |     
  X  |  O  |  X  
     |     |     

Enter a spot to place a marker (1-9): 5
     |     |     
  X  |  O  |  X  
_____|_____|_____
     |     |     
  O  |  X  |  O  
_____|_____|_____
     |     |     
  X  |  O  |  X  
     |     |     

YOU WIN!
Thanks for playing!
