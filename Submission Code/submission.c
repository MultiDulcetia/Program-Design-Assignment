/*
DCP5101 Program Design @ Multimedia University
Trimester 2310 - 2023/24
Assignment Topic: 9x9 Tic-Tac-Toe Minigame
Group Members: 1. @MultiDulcetia
               2. @KahHeng0401
               3. @riceo180
               4. @ygjiaa
*/ 

/*
Requirements:
You have to apply at least 5 elements in your program. Elements that you can apply are:
    1. Control Structure (Selection & Repetition)
    2. Functions
    3. Array
    4. Pointers
    5. Structures
    6. File
*/

//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
// Using windows.h so that we can use the sleep() function to autoclose after 5 sec and not have the cmd auto close
#include <windows.h>

// Defining the size of the board which is 9x9
#define SIZE 9
// Creating an array to hold the board
// Completed 1/5 elements (Array) from the requirements
char board[SIZE][SIZE];

// Function prototypes
void resetBoard();
void printBoard();
void checkWin();
void checkFreeSpace();
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

// Print the 9x9 tic-tac-toe board
void printBoard()
{




}

int main()
{

    // Variables
    int main_menu_choice;

    // Main Menu
    printf("\nWelcome to 9x9 Tic-Tac-Toe Minigame!\n");
    printf("Created by: Teo Kah Heng\n");
    printf("            Teow Dickson\n");
    printf("            Liew Hui Xuan\n");
    printf("            Loh Yong Jia\n");

    // Main Menu Select
    printf("\nPlease select an option:\n");
    printf("1. Start Game\n");
    printf("2. View Leaderboard\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");

    // Scanning for user input
    // Completed 2/5 elements (Selection) from the requirements
    scanf("%d", &main_menu_choice);

    // Using if loop to do what the user selected
    if (main_menu_choice == 1)
    {
        printf("Starting game...\n");
        resetBoard;
        printBoard;

    }
    else if (main_menu_choice == 2)
    {
        
        // Variables
        // Creating a pointer
        FILE *file;
        // Creating a string to hold the leaderboard
        char leaderboard_string[10000];

        printf("\nViewing leaderboard...\n");
        file = fopen("leaderboard.txt", "r");
        if (file == NULL)
        {
            printf("Error opening file!\n");
            printf("Exiting in 5 seconds...\n\n");
            Sleep(5000);
            exit(1);


        }else
        
        fgets(leaderboard_string, 10000, file);
        printf("%s\n", leaderboard_string);
        




        fclose(file);
    }
    else if (main_menu_choice == 3)
    {
        printf("\nThank you for playing!\n");
        printf("Exiting in 5 seconds...\n");
    }
    else
    {
        printf("Invalid input! Please try again.\n");
    }
    
    








    // pause for 5 sec before closing
    Sleep(5000);
    return 0;
}


