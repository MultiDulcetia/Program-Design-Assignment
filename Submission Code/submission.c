/*
DCP5101 Program Design @ Multimedia University
Trimester 2310 - 2023/24
Assignment Topic: 3x3 Tic-Tac-Toe Minigame
Group Members: 1. @MultiDulcetia
               2. @KahHeng0401
               3. @riceo180
               4. @ygjiaa
*/ 

/*
Requirements:
You have to apply at least 5 elements in your program. Elements that you can apply are:
    1. Control Structure (Selection & Repetition) - done
    2. Functions - done
    3. Array - done
    4. Pointers - done
    5. Structures - done
    6. File - done
*/

//Preprocessor directives
#include <stdio.h>
// Using <stdlib.h> so that we can use the exit() function to exit the program
#include <stdlib.h>
// Using windows.h so that we can use the sleep() function to autoclose after 3 sec and not have the command prompt auto close
#include <windows.h>

// Defining the size of the board which is 3x3
#define SIZE 3

// Defining the colour for the printf thank you statment later
#define BLUE "\e[0;34m"
#define RESET_COLOR "\e[m"

// Creating an array to hold the board
// Completed 1/5 elements (Array) from the requirements
char board[3][3];

// creating a struct to hold playername and symbol
// completed 2/5 elements (Structures) from the requirements
struct Player{
    char name[50]; // setting array name to hold 50 characters
    char symbol; // setting variable symbol to hold a player's symbol
};

// creating global variables for player 1 and player 2
struct Player Player1, Player2;

// creating global variable to hold the winner and reset it to 0
int winner = 0;

// Function prototypes
void resetBoard();
void printBoard();
char checkWin();
int checkFreeSpace();
void player1Move();
void player2Move();
void printWinner();
void saveWinner();

// Reset and initialize the tic-tac-toe board
// completed 3/5 elements (Functions) from the requirements
void resetBoard()
{
    // using for loop to loop through each row and column of the board and set it to empty
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Print the 3x3 tic-tac-toe board
void printBoard()
{

    printf("\n %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");


}

// function to check if there is a winner
char checkWin()
{

    //checking rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == Player1.symbol)
            {
                winner = 1;
            }else if(board[i][0] == Player2.symbol)
            {
                winner = 2;
            }
        }
    }

    //checking columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == Player1.symbol)
            {
                winner = 1;
            }else if(board[0][i] == Player2.symbol)
            {
                winner = 2;
            }
        }
    }
    
    //check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
    (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
    if (board[1][1] == Player1.symbol)
        {
            winner = 1;
        }
    else if (board[1][1] == Player2.symbol)
        {
            winner = 2;
        }
    }
    return ' ';
}

// checking for any free space left on the board, if none then draw, if there's still empty spots then continue playing
int checkFreeSpace(int* freeSpace)
{

    *freeSpace = 9; // setting freeSpace to 9 because there's 9 spots on a 3x3 board

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                (*freeSpace)--; // decreasing freeSpace by 1 if there's no empty spot
            }
        }
        
    }

    // if there's no freespace left, set winner to 3 which means that it's a draw
    if (*freeSpace == 0)
    {
        winner = 3;
    }
    
    return *freeSpace;
}

// printing the winner
void printWinner(int freeSpace)
{
    if (winner == 1) // if winner is 1 = player 1 won
    {
        printf("Congratulations! %s has won!\n",Player1.name);
    }else if (winner == 2) // if winner is 2 = player 2 won
    {
        printf("Congratulations! %s has won!\n",Player2.name);
    }else if (winner == 3) // if winner is 3 = draw
    {
        printf("Aww, unfortunately it's a draw!\n");
        printf("Nice try, %s and %s!\n",Player1.name,Player2.name); 
    }
    
}

void saveWinner()
{

    // creating a pointer
    // completed 4/5 elements (Pointers) from the requirements
    FILE *FILE;


    // completed 5/5 elements (File) from the requirements
    // opening the file in append mode or create one if file does not exist
    FILE = fopen("leaderboard.txt", "a");

    if (winner == 1) // if winner is 1 then save player 1's name
    {
        fprintf(FILE,"\n%s",Player1.name);
    }else if (winner == 2) // if winner is 2 then save player 2's name
    {
        fprintf(FILE,"\n%s",Player2.name);
    }else if (winner == 3) // if winner is 3 then save draw
    {
        fprintf(FILE,"\n%s and %s tied!",Player1.name, Player2.name);
    }

    // closing the file to prevent memory leak
    fclose(FILE); 

}

// function for player 1's move
void player1Move()
{
    // setting variable x and y to hold the row and column
    int x;
    int y;

    // setting player 1's symbol to x
    Player1.symbol = 'x';

    // asking for player 1 to enter a row
    printf("\nEnter row #(1-3): ");
    if (scanf("%d", &x) != 1) // checking if the input is an integer
    {
        printf("\nInvalid input. Please enter a value from 1-3.\n");
        fflush(stdin); // flushing the input buffer to prevent it from looping if something is left in the input buffer
        player1Move(); // recalling the function to ask for input again
        return;
    }

    // decreasing x by 1 because array starts with 0 but we want to start with 1 to make it easier for the users
    x--; 
    
    // asking for player 1 to enter a column
    printf("Enter column #(1-3): ");
    if (scanf("%d", &y) != 1) // checking if the input is an integer
    {
        printf("\nInvalid input. Please enter a value from 1-3.\n");
        fflush(stdin); // flushing the input buffer to prevent it from looping if something is left in the input buffer
        player1Move(); // recalling the function to ask for input again
        return;
    }

    // decreasing y by 1 because array starts with 0 but we want to start with 1 to make it easier for the users
    y--;

    // creating an if else loop to check if the input is valid
    // checking if the input is within the board
    // if yes, then proceed to the next check
    // if no, then ask for input again
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
    {
        printf("\nInvalid move, please try again.\n");
        player1Move(); // recalling the function to ask for input again
    }
    else if (board[x][y] != ' ') // checking if the spot is empty
    {
        printf("\nInvalid move. Spot already taken. Please enter another one\n");
        player1Move(); // recalling the function to ask for input again
    }
    else // if input is valid then set the spot in the array to player 1's symbol
    {
        board[x][y] = Player1.symbol;
    }
}

// function for player 2's move
void player2Move()
{
    // setting variable x and y to hold the row and column
    int x;
    int y;  

    // setting player 2's symbol to o
    Player2.symbol = 'o';

    // asking for player 2 to enter a row
    printf("\nEnter row #(1-3): ");
    if (scanf("%d", &x) != 1) // checking if the input is an integer
    {
        printf("\nInvalid input. Please enter a value from 1-3.\n"); 
        fflush(stdin); // flushing the input buffer to prevent it from looping if something is left in the input buffer
        player2Move(); // recalling the function to ask for input again
        return;
    }

    // decreasing x by 1 because array starts with 0 but we want to start with 1 to make it easier for the users
    x--; 
    
    printf("Enter column #(1-3): ");
    if (scanf("%d", &y) != 1)
    {
        printf("\nInvalid input. Please enter a value from 1-3.\n");
        fflush(stdin); // flushing the input buffer to prevent it from looping if something is left in the input buffer
        player2Move(); // recalling the function to ask for input again
        return;
    }

    // decreasing y by 1 because array starts with 0 but we want to start with 1 to make it easier for the users
    y--; 

    // creating an if else loop to check if the input is valid
    // checking if the input is within the board
    // if yes, then proceed to the next check
    // if no, then ask for input again
    if (x < 0 || x >= 3 || y < 0 || y >= 3) 
    {
        printf("\nInvalid move, please try again.\n");
        player2Move(); // recalling the function to ask for input again
    }
    else if (board[x][y] != ' ') // checking if the spot is empty
    {
        printf("\nInvalid move. Spot already taken. Please enter another one\n");
        player2Move();
    }
    else // if input is valid then set the spot in the array to player 2's symbol
    {
        board[x][y] = Player2.symbol; // setting the spot in the array to player 2's symbol
    }
}

// main function to run the program
int main()
{

    // Variables
    int main_menu_choice; // variable to hold the user's choice in the main menu
    int freeSpace; // variable to hold the number of free space left on the board

    // do loop to keep looping until user chooses to exit
    do
        {
        // Main Menu Select
        system("cls"); // clearing terminal to prevent clutter

        // Main Menu
        // print welcome message and our names
        printf("Welcome to 3x3 Tic-Tac-Toe Minigame!\n");
        printf("Created by: @KahHeng0401\n");
        printf("            @MultiDulcetia\n");
        printf("            @riceo180\n");
        printf("            @ygjiaa\n");

        // print main menu options
        printf("\nPlease select an option:\n");
        printf("1. Start Game\n");
        printf("2. View Leaderboard\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Scanning for user input
        // Completed 6/5 elements (Selection) from the requirements
        fflush(stdin); // flushing the input buffer to prevent it from infinitely looping if something is left in the input buffer
        scanf("%d", &main_menu_choice); 

        // Using if loop to do what the user selected
        if (main_menu_choice == 1) // if user chooses 1, then start game
        {
            printf("\nStarting game...\n");

            printf("Enter Player 1's name: ");
            fflush(stdin); // flushing the input buffer
            scanf("%s", Player1.name);  // wait for user input and store it in Player1 name variable

            printf("Enter Player 2's name: ");
            fflush(stdin); // flushing the input buffer
            scanf("%s", Player2.name); // wait for user input and store it in Player2 name variable

            // calling resetBoard funtion to reset board
            resetBoard();

            // calling printBoard function to print the board
            printBoard();

            // do loop to keep playing until there is a winner or a draw
                do
                {
                    //Player 1's turn
                    printf("It's %s's turn", Player1.name);
                    // calling player1Move function to ask for input    
                    player1Move(); 
                    // calling printBoard function to print the board
                    printBoard();
                    // calling checkFreeSpace function to check if there's any free space left
                    checkFreeSpace(&freeSpace); // updating freeSpace variable by calling checkFreeSpace function
                    // calling checkWin function to check if there's a winner
                    checkWin(); 
                    // if there's a winner or no free space left then break from the loop
                    if (winner != 0 || freeSpace == 0)  // if there's a winner or no free space left then break from the loop
                    {
                        break;
                    }

                    //Player 2's turn
                    printf("It's %s's turn", Player2.name);
                    // calling player2Move function to ask for input
                    player2Move();
                    // calling printBoard function to print the board
                    printBoard();
                    // calling checkFreeSpace function to check if there's any free space left
                    checkFreeSpace(&freeSpace); // updating freeSpace variable by calling checkFreeSpace function
                    // calling checkWin function to check if there's a winner
                    checkWin();
                    // if there's a winner or no free space left then break from the loop
                    if (winner != 0 || freeSpace == 0) // if there's a winner or no free space left then break from the loop
                    {
                        break;
                    }
                } while(1);

            // printing winner
            printWinner(winner);

            // saving winner to leaderboard
            if (winner == 1 || winner == 2) // if winner is 1 or 2 then save winner
            {
                printf("\nSaving winner to leaderboard...\n");
                saveWinner(); // calling saveWinner function to save the winner
            }else{ // else save draw
                printf("\nSaving draw to leaderboard...\n");
                saveWinner(); // calling saveWinner function to save the draw
            }
            
            // print thank u message
            printf("Thanks for playing!\n\n");
            system("pause"); // pausing the program until player enters a key
            system("cls"); // clearing terminal to make it look cleaner

            // return to main menu
            printf("Returning to main menu in 3 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Returning to main menu in 2 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Returning to main menu in 1 seconds...\n\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic


            // resetting winner to 0
            winner = 0;

            // resetting board
            resetBoard();

        }
        else if (main_menu_choice == 2) // if user chooses 2, then view leaderboard
        {
            // Variables
            // Creating a pointer
            FILE *file;

            // Creating a string to hold the leaderboard
            char leaderboard_string[10000];

            // clearing terminal to prevent clutter
            system("cls");

            printf("\nViewing leaderboard...\n");
            // opening the file in read mode
            file = fopen("leaderboard.txt", "r");
            
            // if file does not exist, print error and exit program
            if (file == NULL)
            {
                printf("\nWarning: Error opening file!\n");
                printf("File does not exist or is corrupted.\n\n");
            }else {
                printf("\n------------------------------------");
                printf("\n        Start of Leaderboard        ");
                printf("\n------------------------------------\n");
                 do // do loop to keep printing until end of file 
                    {
                        fgets(leaderboard_string, 10000, file);
                        printf("%s", leaderboard_string);
                    } while (!feof(file)); // feof = file end of file
                printf("\n------------------------------------");
                printf("\n         End of Leaderboard         ");
                printf("\n------------------------------------\n\n");

                    }
            
            // close file to prevent memory leak
            fclose(file); 

            // pausing the program until player enters a key
            system("pause"); 
        }
        else if (main_menu_choice == 3) // if user chooses 3, then exit program
        {
            
            system("cls"); // clearing terminal to make it look cleaner

            printf("Thank you for playing!\n");
            Sleep(500); // pausing the terminal for 0.5 sec so that user can see the tq message
            system("cls"); // clearing terminal to make it look dynamic
            printf("Exiting in 3 seconds...\n");
            Sleep(1000); // pausing the terminal for 1 sec
            system("cls"); // clearing terminal to make it look dynamic
            printf("Exiting in 2 seconds...\n");
            Sleep(1000); // pausing the terminal for 1 sec
            system("cls"); // clearing terminal to make it look dynamic
            printf("Exiting in 1 seconds...\n");
            Sleep(1000); // pausing the terminal for 1 sec
            system("cls"); // clearing terminal to make it look dynamic

            
            printf(BLUE".___________. __    __       ___      .__   __.  __  ___    ____    ____  ______    __    __  ");
            Sleep(300); // pausing the terminal for 0.5 sec
            printf("\n|           ||  |  |  |     /   \\     |  \\ |  | |  |/  /    \\   \\  /   / /  __  \\  |  |  |  | ");
            Sleep(300); // pausing the terminal for 0.5 sec
            printf("\n`---|  |----`|  |__|  |    /  ^  \\    |   \\|  | |  '  /      \\   \\/   / |  |  |  | |  |  |  | ");
            Sleep(300); // pausing the terminal for 0.5 sec
            printf("\n    |  |     |   __   |   /  /_\\  \\   |  . `  | |    <        \\_    _/  |  |  |  | |  |  |  | ");
            Sleep(300); // pausing the terminal for 0.5 sec
            printf("\n    |  |     |  |  |  |  /  _____  \\  |  |\\   | |  .  \\         |  |    |  `--'  | |  `--'  | ");
            Sleep(300); // pausing the terminal for 0.5 sec
            printf("\n    |__|     |__|  |__| /__/     \\__\\ |__| \\__| |__|\\__\\        |__|     \\______/   \\______/  "RESET_COLOR);
            

            Sleep(500); // show explosion for 0.5 sec
            system("cls"); // clearing terminal to make it look dynamic
            
            break; // break from do loop to prevent it from looping again
        }
        else // if user enters an invalid choice, print error message and ask for input again
        {
            printf("\nInvalid input! Please try again.\n");
        }

    } while (1);

    // pause for 3 sec before closing
    // Sleep(3000);
    return 0;
}