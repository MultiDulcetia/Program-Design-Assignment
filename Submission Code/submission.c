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
    2. Functions
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
// including conio.h so that we can use getch() function and clrscr() function
#include <conio.h>

// Defining the size of the board which is 3x3
#define SIZE 3

// Creating an array to hold the board
// Completed 1/5 elements (Array) from the requirements
char board[3][3];

// creating a struct to hold playername and symbol
// completed 2/5 elements (Structures) from the requirements

struct Player{
    char name[50];
    char symbol;
};

// creating global variables for player 1 and player 2
struct Player Player1, Player2;

// Player1.symbol = 'x';
// Player2.symbol = 'o';

// struct Player1{
//     char name[20];
//     char symbol;
// };

// struct Player2{
//     char name[20];
//     char symbol;
// };






// creating a constant to hold p1 and p2 symbol
// const char Player1Symbol = 'x';
// const char Player2Symbol = 'o';


// creating global variable to hold the winner and reset it to 0
int winner = 0;

// using array to hold the player names
// char Player1[20];
// char Player2[20];

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
void resetBoard()
{
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

char checkWin()
{

    // struct Player Player1, Player2; //replaced with global variables

    //check rows
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
    //check columns
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
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == Player1.symbol)
        {
            winner = 1;
        }else if(board[0][0] == Player2.symbol)
        {
            winner = 2;
        }
    }
    return ' ';
}

int checkFreeSpace(int* freeSpace)
{

    *freeSpace = 9;

    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                (*freeSpace)--;
            }
        }
        
    }

    if (freeSpace == 0)
    {
        winner = 3;
    }
    

    return *freeSpace;
}

void printWinner(int freeSpace)
{
    if (winner == 1)
    {
        printf("Congratulations! %s has won!\n",Player1.name);
    }else if (winner == 2)
    {
        printf("Congratulations! %s has won!\n",Player2.name);
    }else if (winner == 3)
    {
        printf("Aww, unfortunately it's a draw!\n");
        printf("Nice try,%s and %s!\n",Player1,Player2);
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

    if (winner == 1)
    {
        fprintf(FILE,"%s\n",Player1.name);
    }else if (winner == 2)
    {
        fprintf(FILE,"%s\n",Player2.name);
    }else if (winner == 3)
    {
        fprintf(FILE,"%s and %s tied!\n",Player1.name, Player2.name);
    }

    fclose(FILE); // closing the file to prevent memory leak

}



void player1Move()
{
    int x;
    int y;

    Player1.symbol = 'x';

    printf("\nEnter row #(1-3): ");
    scanf("%d", &x);
    x--;
    printf("Enter column #(1-3): ");
    scanf("%d", &y);
    y--;

    if(board[x][y] != ' ')
    {
        printf("\nInvalid move, please try again.\n");
        player1Move();
    }else
    {
        board[x][y] = Player1.symbol;

    }
    
}

void player2Move()
{

    Player2.symbol = 'o';

    int x;
    int y;

    printf("\nEnter row #(1-3): ");
    scanf("%d", &x);
    x--;
    printf("Enter column #(1-3): ");
    scanf("%d", &y);
    y--;

    if(board[x][y] != ' ')
    {
        printf("\nInvalid move, please try again.\n");
        player2Move();
    }else
    {
        board[x][y] = Player2.symbol;

    }
    
}

int main()
{

    // Variables
    int main_menu_choice;
    int freeSpace;

    

    // do loop to keep looping until user chooses to exit
    do
        {
        // Main Menu Select



        system("cls"); // clearing terminal to prevent clutter

        // Main Menu
        printf("Welcome to 3x3 Tic-Tac-Toe Minigame!\n");
        printf("Created by: @KahHeng0401\n");
        printf("            @MultiDulcetia\n");
        printf("            @riceo180\n");
        printf("            @ygjiaa\n");

        printf("\nPlease select an option:\n");
        printf("1. Start Game\n");
        printf("2. View Leaderboard\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Scanning for user input
        // Completed 2/5 elements (Selection) from the requirements
        fflush(stdin); // flushing the input buffer to prevent it from infinitely looping if something is left in the input buffer
        scanf("%d", &main_menu_choice);

        // Using if loop to do what the user selected
        if (main_menu_choice == 1)
        {
            printf("\nStarting game...\n");

            printf("Enter Player 1's name: ");
            fflush(stdin); // flushing the input buffer
            scanf("%s", Player1.name);

            printf("Enter Player 2's name: ");
            fflush(stdin); // flushing the input buffer
            scanf("%s", Player2.name);

            // resetting board
            resetBoard();

            // printing board
            printBoard();

            // do loop to keep playing until there is a winner or a draw
                do
                {
                    //Player 1's turn
                    printf("It's %s's turn", Player1.name);
                    player1Move();
                    printBoard();
                    checkFreeSpace(&freeSpace);
                    checkWin();
                    if (winner != 0 || freeSpace == 0)
                    {
                        break;
                    }

                    //Player 2's turn
                    printf("It's %s's turn", Player2.name);
                    player2Move();
                    printBoard();
                    checkFreeSpace(&freeSpace);
                    checkWin();
                    if (winner != 0 || freeSpace == 0)
                    {
                        break;
                    }
                } while(1);
                // } while (freeSpace != 0 && checkWin() == 0 && winner == 0);

            // printing winner
            printWinner(winner);

            // saving winner to leaderboard
            if (winner == 1 || winner == 2)
            {
                printf("\nSaving winner to leaderboard...\n");
                saveWinner();
            }else{
                printf("\nSaving draw to leaderboard...\n");
                saveWinner();
            }
            
            printf("Thanks for playing!\n");
            printf("Returning to main menu in 3 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Returning to main menu in 2 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Returning to main menu in 1 seconds...\n\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic


            // resetting winner
            winner = 0;

            // resetting board
            resetBoard();

        }
        else if (main_menu_choice == 2)
        {

            
            
            // Variables
            // Creating a pointer
            FILE *file;
            // Creating a string to hold the leaderboard
            char leaderboard_string[10000];

            system("cls"); // clearing terminal to prevent clutter

            printf("\nViewing leaderboard...\n");
            file = fopen("leaderboard.txt", "r");
            
            // if file does not exist, print error and exit program
            if (file == NULL)
            {
                printf("\nWarning: Error opening file!\n");
                printf("File does not exist or is corrupted.\n\n");

                // system("pause"); // pausing the program until player enters a key
                
                


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

            // fgets(leaderboard_string, 10000, file);
            // printf("%s\n", leaderboard_string);
            



            fclose(file); // close file to prevent memory leak
            system("pause"); // pausing the program until player enters a key
        }
        else if (main_menu_choice == 3)
        {
            
            system("cls"); // clearing terminal to prevent clutter

            printf("Thank you for playing!\n");
            printf("Exiting in 3 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Exiting in 2 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            printf("Exiting in 1 seconds...\n");
            Sleep(1000);
            system("cls"); // clearing terminal to make it look dynamic
            
            
            break; // break from do loop to prevent it from looping again
        }
        else
        {
            printf("\nInvalid input! Please try again.\n");
        }

    } while (1);
    
    
    
    








    // pause for 3 sec before closing
    // Sleep(3000);
    return 0;
}


