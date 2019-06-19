#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cmath>
using namespace std;

// Function to display a header at coordinates (x, y)
void header(int x, int y);

// Function to display the game menu
void menu();

// Function to display the end of a game level with specified text
void endOfLevel(string teXt);

// Function to print a 3x3 grid at coordinates (x, y) with specified color
void print3by3Grid(string arr[][3], int size, string color, int x, int y);

// Function to print a 4x4 grid at coordinates (x, y) with specified color
void print4by4Grid(string arr[][4], int size, string color, int x, int y);

// Function to print a 5x5 grid at coordinates (x, y) with specified color
void print5by5Grid(string arr[][5], int size, string color, int x, int y);

// Function to print the first type of enemy at coordinates (x, y)
void printEnemy1(int x, int y);

// Function to print the second type of enemy at coordinates (x, y)
void printEnemy2(int x, int y);

// Function to print the third type of enemy facing right at coordinates (x, y)
void printEnemy3Right(int x, int y);

// Function to print the third type of enemy facing left at coordinates (x, y)
void printEnemy3Left(int x, int y);

// Function to handle the movement of the first type of enemy
void moveEnemy1();

// Function to handle the movement of the second type of enemy
void moveEnemy2();

// Function to handle the movement of the third type of enemy
void moveEnemy3();

// Function to determine the direction of the third type of enemy
void enemy3Direction();

// Function to handle the death of the third type of enemy at coordinates (x, y)
void deathOfEnemy3(int x, int y);

// Function to display the health of the first type of enemy at coordinates (x, y)
void healthEnemy1(int x, int y);

// Function to handle the death of the first type of enemy at coordinates (x, y)
void deathOfEnemy1(int x, int y);

// Function to handle the death of the second type of enemy at coordinates (x, y)
void deathOfEnemy2(int x, int y);

// Function to inflict damage on the health of the first type of enemy
void healthEnemy1Damage(int damage);

// Function to display the health of the second type of enemy at coordinates (x, y)
void healthEnemy2(int x, int y);

// Function to inflict damage on the health of the second type of enemy
void healthEnemy2Damage(int damage);

// Function to display the health of the third type of enemy at coordinates (x, y)
void healthEnemy3(int x, int y);

// Function to inflict damage on the health of the third type of enemy
void healthEnemy3Damage(int damage);

// Function to erase the first type of enemy from coordinates (x, y)
void eraseEnemy1(int x, int y);

// Function to erase the second type of enemy from coordinates (x, y)
void eraseEnemy2(int x, int y);

// Function to erase the third type of enemy from coordinates (x, y)
void eraseEnemy3(int x, int y);

// Function to remove enemy bullets from an array based on direction and count
void removeEnemyBulletsFromArray(int c, string direction);

// Function to initialize enemy bullets
void startEnemyBullet();

// Function to reset enemy bullets
void resetEnemyBullets();

// Function to create an enemy bullet at coordinates (x, y) and specified direction
void enemyBullet(int x, int y, string direction);

// Function to display enemy bullets at coordinates (x, y)
void printEnemyBullets(int x, int y);

// Function to handle the movement of enemy bullets
void moveEnemyBullet();

// Function to handle collisions with enemy bullets
void enemyBulletCollision();

// Player functionalities
void printRightPlayer(int x, int y); // Display the player facing right
void printLeftPlayer(int x, int y);  // Display the player facing left
void movePlayer();                 // Handle player movement
void playerDirection();                // Handle player direction change
void erasePlayer(int x, int y);        // Erase the player

// Player bullet functionalities
void startPlayerBullet();                        // Initialize player bullets
void removePlayerBulletsFromArray(int c, string direction); // Remove player bullets
void resetPlayerBullets();                         // Reset player bullets
void playerBulletCollision();                      // Handle bullet collision
void movePlayerBullet();                      // Handle bullet movement
void bullet(int x, int y);                         // Create a bullet
void erasePlayerBullet(int x, int y);              // Erase a bullet

// On-screen navigators
void gotoxy(int x, int y);                  // Move the cursor to (x, y) position
char getCharAtxy(short int x, short int y); // Get the character at (x, y) position

// Basic game functions
void increaseScore();                                   // Add score
void playerCollisionWithMagazine(int x, int y);              // Handle magazine collision (if touched, bullets increase)
void playerCollisionWithHealthPill(int x, int y);                  // Handle pill collision (if touched, health increases)
void checkItems(int x, int y);                     // Check collected items (health)
void playerHealth(int x, int y);                   // Display player health
void playerHealthDamage(int damage, int x, int y); // Inflict damage to player
void printScore();                               // Display the current score
void printRemainingBullets();                         // Display the remaining bullet count
void eraser(int x, int y);                         // Erase at (x, y) position

// Functions for InnerMaps
void Maze(); // Draw the game Maze
void displayItems();  // Display the top bar
void InnerMap();      // Display the InnerMap
void innerMap2();
void InnerMapBoxes(int x, int y, int size);                      // Display InnerMapBoxes
void verticalInnerMapBoxes(int x, int y, int width, int height); // Display vertical InnerMapBoxes
void placeObjects();                                        // Initialize game objects
void rowsOfMaze(int x, int y);                               // Draw outer rows
void columnsOfMaze(int x, int y);                               // Draw inner rows
void healthPill(int x, int y);                              // Display the health pill
void magazine(int x, int y);                                // Display the magazine
void displayHealthPill();                                   // Display health pill status

// End Key Functions
void printPassingKey(int x, int y);
void erasePassingKey(int x, int y);
void touchPassingKey(int x, int y);

// Levels
void printLevel1(int x);
void levelNo1(); // Level 1 gameplay logic
void levelNo2(); // Level 2 gameplay logic

// Coordinates of characters
int playerX, playerY, eX, eY, eX2, eY2, eX3, eY3;

// Timer for enemy 3 movement
int enemy3Timer;

// Random values for enemy movements
int randomValue;

// Counts for various types of bullets that the enemy or player has fired
int rightPlayerBulletCount, leftPlayerBulletCount, playerBulletCount, rightEnemyBulletCount, leftEnemyBulletCount;

// Health variables for characters
int maxPlayerHealth, maxhealthEnemy1, maxhealthEnemy2, maxhealthEnemy3;

// Game score
int score;

// Coordinates for items on the InnerMap
int healtPassingKeyX, healtPassingKeyY, magazineX, magazineY, levelNumber;

// End Key
int PassingKeyX, PassingKeyY;

// ASCII characters used for display
char box = 177;
char heart = static_cast<char>(3); // Replaced with heart character
char Diamond = static_cast<char>(4); // Replaced with diamond character
char Magazine = static_cast<char>(178);
char PassingKey = static_cast<char>(172);

// Direction tracking for characters
string playerdirection = "right", enemy1direction = "down", enemy2direction = "down", enemy3direction = "right";

// Player's name
string playername1 = "Player";

// Level state tracking
bool LevelRunning;
bool enemy1IsLive, enemy2IsLive, enemy3IsLive, playerIsLive;

// Arrays for player and enemy bullets' coordinates
int playerRightBulletX[1000] = {-1}, playerRightBulletY[1000] = {-1},
 playerLeftBulletX[1000] = {-1}, playerLeftBulletY[1000] = {-1};
bool activatePlayerRightBullet[1000], activatePlayerLeftBullet[1000];
int enemyRightBulletX[10000], enemyRightBulletY[10000], enemyLeftBulletX[10000],
enemyLeftBulletY[10000];
bool activateEnemyRightBullet[10000], activateEnemyLeftBullet[10000];

int main()
{
    menu();
}

void screenFrame()
{
    // Set up screen for the level
    playername1 = "Player";
    system("cls");
    displayItems();
    Maze();//
}
//////////////////////////////////////////////// LEVEL 1 ///////////////////////////////////////////////////////////////////////////////////
void levelNo1()
{
    // Variables for level 1
    int timer = 0;       // Timer for enemy 3 random direction
    int belletTimer = 0; // Timer for player's bullet removal

    // Initial assignments for global variables
    healtPassingKeyX = 51, healtPassingKeyY = 17, magazineX = 88, magazineY = 19;
    rightPlayerBulletCount = 0, leftPlayerBulletCount = 0, playerBulletCount = 200, rightEnemyBulletCount = 0, leftEnemyBulletCount = 0;
    maxPlayerHealth = 100, maxhealthEnemy1 = 100, maxhealthEnemy2 = 100, maxhealthEnemy3 = 100, score = 0, enemy3Timer = 0;
    playerX = 10, playerY = 45, eX = 30, eY = 17, eX2 = 170, eY2 = 19, eX3 = 90, eY3 = 27, levelNumber = 1;
    enemy1IsLive = true, enemy2IsLive = true, enemy3IsLive = true, playerIsLive = true;
    LevelRunning = true;
    // Set up the level interface
    screenFrame();//
    InnerMap();//
    printEnemy1(eX, eY);
    printEnemy2(eX2, eY2);
    printEnemy3Right(eX3, eY3);
    printLeftPlayer(playerX, playerY);
    printLevel1(levelNumber);
    startPlayerBullet();////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    startEnemyBullet();////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Main game loop for level 1
    while (LevelRunning)
    {
        // Player's movement and actions
        if (maxPlayerHealth > 0 && (enemy1IsLive == true || enemy2IsLive == true || enemy3IsLive == true))
        {
            movePlayer();
        }
        else if (enemy1IsLive == false && enemy2IsLive == false && enemy3IsLive == false)
        {

            LevelRunning = true;
            endOfLevel("  CONGRATULATIONS! LEVEL PASSED ");
        }
        else
        {
            LevelRunning = false;
            playerIsLive = false;
            endOfLevel("             Game Over! ");
            menu();
        }

        // Enemy 1 movements and actions
        if (maxhealthEnemy1 > 0)
        {
            moveEnemy1();//
        }
        else
        {
            deathOfEnemy1(eX, eY);
            enemy1IsLive = false;
        }

        // Enemy 2 movements and actions
        if (maxhealthEnemy2 > 0)
        {
            moveEnemy2();
        }
        else
        {
            deathOfEnemy2(eX2, eY2);
            enemy2IsLive = false;
        }

        // Enemy 3 movements and actions
        if (maxhealthEnemy3 > 0)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            if (timer == 5)
            {
                randomValue = rand() % 4;
                timer = 0;
            }
            enemy3Direction();
        }
        else
        {
            deathOfEnemy3(eX3, eY3);
            enemy3IsLive = false;
        }

        // Reset timers and handle bullet movements and collisions
        if (enemy3Timer == 120)
        {
            enemy3Timer = 0;
        }
        if (belletTimer == 20)
        {
            resetPlayerBullets();
            resetEnemyBullets();
            belletTimer = 0;
        }
        // Display health and handle bullet movements
        gotoxy(1, 0);
        playerHealth(165, 4);
        healthEnemy1(165, 6);
        healthEnemy2(165, 7);
        healthEnemy3(165, 8);
        movePlayerBullet();
        playerBulletCollision();
        moveEnemyBullet();
        enemyBulletCollision();
        timer++;
        enemy3Timer++;
        belletTimer++;
        Sleep(50);
    }
    LevelRunning = false;
}

void levelNo2()
{
    // Variables for level 2
    int timer = 0;       // Timer for enemy 3 random direction
    int belletTimer = 0; // Timer for player's bullet removal

    // Initial assignments for global variables
    healtPassingKeyX = 49, healtPassingKeyY = 17, magazineX = 154, magazineY = 23, levelNumber = 2;
    rightPlayerBulletCount = 0, leftPlayerBulletCount = 0, playerBulletCount = 150,//Number of total bullets
    rightEnemyBulletCount = 0, leftEnemyBulletCount = 0,score = 0, enemy3Timer = 0;
    maxPlayerHealth = 100, maxhealthEnemy1 = 100, maxhealthEnemy2 = 100, maxhealthEnemy3 = 100;//Total Healths Of Characters
    playerX = 10, playerY = 45, eX = 30, eY = 17, eX2 = 170, eY2 = 19, eX3 = 90, eY3 = 27, PassingKeyX = 165, PassingKeyY = 12;// initiall printing coordinates
    enemy1IsLive = true, enemy2IsLive = true, enemy3IsLive = true, playerIsLive = true, LevelRunning = true;

    // Set up the level interface
    screenFrame();
    innerMap2();
    printEnemy1(eX, eY);
    printEnemy2(eX2, eY2);
    printEnemy3Right(eX3, eY3);
    printLeftPlayer(playerX, playerY);
    printLevel1(levelNumber);
    startPlayerBullet();
    startEnemyBullet();

    // Main game loop for level 2
    while (LevelRunning)
    {
        // Player's movement and actions
        if (maxPlayerHealth > 0)
        {
            if (enemy1IsLive == false && enemy2IsLive == false && enemy3IsLive == false)
            {
                printPassingKey(PassingKeyX,PassingKeyY);
            }
            movePlayer();
        }
        else if (maxPlayerHealth == 0 )
        {
            LevelRunning = false;
            playerIsLive = false;
            endOfLevel("         Game Over! ");
            break;
        }

        // Enemy 1 movements and actions
        if (maxhealthEnemy1 > 0)
        {
            moveEnemy1();
        }
        else
        {
            deathOfEnemy1(eX, eY);
            enemy1IsLive = false;
        }

        // Enemy 2 movements and actions
        if (maxhealthEnemy2 > 0)
        {
            moveEnemy2();
        }
        else
        {
            deathOfEnemy2(eX2, eY2);
            enemy2IsLive = false;
        }

        // Enemy 3 movements and actions
        if (maxhealthEnemy3 > 0)////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        {
            if (timer == 5)
            {
                randomValue = rand() % 4;
                timer = 0;
            }
            enemy3Direction();
        }
        else
        {
            deathOfEnemy3(eX3, eY3);
            enemy3IsLive = false;
        }

        // Reset timers and handle bullet movements and collisions
        if (enemy3Timer == 120)
        {
            enemy3Timer = 0;
        }
        if (belletTimer == 20)//
        {
            resetPlayerBullets();
            resetEnemyBullets();
            belletTimer = 0;
        }
        // Display health and handle bullet movements
        gotoxy(1, 0);
        playerHealth(165, 4);
        healthEnemy1(165, 6);
        healthEnemy2(165, 7);
        healthEnemy3(165, 8);
        movePlayerBullet();
        playerBulletCollision();
        moveEnemyBullet();
        enemyBulletCollision();
        timer++;
        enemy3Timer++;
        belletTimer++;
        Sleep(50);
    }
    LevelRunning = false;
}

void movePlayer() // movement functionalities of player
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        checkItems(playerX + 3, playerY);
        if (getCharAtxy(playerX + 3, playerY) == ' ' && getCharAtxy(playerX + 3, playerY + 1) == ' ' && getCharAtxy(playerX + 3, playerY + 2) == ' ')
        {
            erasePlayer(playerX, playerY);
            playerX++;
            playerdirection = "right";
            printRightPlayer(playerX, playerY);
        }
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        checkItems(playerX - 1, playerY);
        if (getCharAtxy(playerX - 1, playerY) == ' ' && getCharAtxy(playerX - 1, playerY + 1) == ' ' && getCharAtxy(playerX - 1, playerY + 2) == ' ')
        {
            erasePlayer(playerX, playerY);
            playerX--;
            playerdirection = "left";
            printLeftPlayer(playerX, playerY);
        } 
    }
    else if (GetAsyncKeyState(VK_UP))
    {
        checkItems(playerX, playerY - 1);
        if (getCharAtxy(playerX, playerY - 1) == ' ' && getCharAtxy(playerX + 1, playerY - 1) == ' ' && getCharAtxy(playerX + 2, playerY - 1) == ' ')
        {
            erasePlayer(playerX, playerY);
            playerY--;
            playerDirection();
        }
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        checkItems(playerX, playerY + 3);
        if (getCharAtxy(playerX, playerY + 3) == ' ' && getCharAtxy(playerX + 1, playerY + 3) == ' ' && getCharAtxy(playerX + 2, playerY + 3) == ' ')
        {
            erasePlayer(playerX, playerY);
            playerY++;
            playerDirection();
        }
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (playerBulletCount > 0 && (getCharAtxy(playerX, playerY) == ' ' && getCharAtxy(playerX - 1, playerY + 1) == ' ' && getCharAtxy(playerX + 3, playerY + 1) == ' '))
        {
            bullet(playerX, playerY);// fire a bullet
            playerBulletCount--;// decrease the player's bullet count
            printRemainingBullets();// update display total bullrts on the top of screen
        }
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        Sleep(500);
        menu();
    }
}

void playerDirection()
{
    // Determines direction of player and calls the respective side face function
    if (playerdirection == "right")
    {
        printRightPlayer(playerX, playerY);
    }
    else if (playerdirection == "left")
    {
        printLeftPlayer(playerX, playerY);
    }
}

void printRightPlayer(int x, int y)
{
    // Prints player facing right side of the console
    string body[3][3] = {{" ", "0", " "}, {"(", "=", ">"}, {"/", "/", " "}};
    print3by3Grid(body, 3, "\33[32m", x, y);
}

void printLeftPlayer(int x, int y)
{
    // Prints player facing left side of the console
    string body[3][3] = {{" ", "0", " "}, {"<", "=", ")"}, {" ", "\\", "\\"}};
    print3by3Grid(body, 3, "\33[32m", x, y);
}

void erasePlayer(int x, int y)
{
    // Erases player sprite from console
    string body[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
    print3by3Grid(body, 3, "\33[36m", x, y);
}    

void print3by3Grid(string arr[][3], int size, string color, int x, int y)
{
    // Prints characters in a 3x3 grid
    int bx;
    for (int i = 0; i < size; i++)
    {
        bx = x;
        for (int j = 0; j < 3; j++)
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;//Increments the x-coordinate for the next character in the same row.
        }
        y++;//y-coordinate is incremented to move to the next row.
    }
}

void print4by4Grid(string arr[][4], int size, string color, int x, int y)
{
    // Prints characters in a 3x4 grid
    int bx;
    for (int i = 0; i < size; i++)
    {
        bx = x;
        for (int j = 0; j < 4; j++)
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;
        }
        y++;
    }
}

void print5by5Grid(string arr[][5], int size, string color, int x, int y)
{
    // Prints characters in a 3x5 grid
    int bx;
    for (int i = 0; i < size; i++)//rows
    {
        bx = x;
        for (int j = 0; j < 5; j++)//columns
        {
            gotoxy(bx, y);
            cout << color << arr[i][j] << "\33[0m";
            bx++;
        }
        y++;
    }
}

void printEnemy1(int x, int y) // printing enemy 1
{
    string body[4][4] = {{"(", "O", " ", " "}, {"\\", "=", "=", ">"}, {" ", "^", "'", " "}, {"/", " ", "|", " "}};
    print4by4Grid(body, 4, "\33[34m", x, y);
}

void eraseEnemy1(int x, int y) // erase enemy 1
{
    string body[4][4] = {{" ", " ", " ", " "}, {" ", " ", " ", " "}, {" ", " ", " ", " "}, {" ", " ", " ", " "}};
    print4by4Grid(body, 4, "\33[34m", x, y);
}

void deathOfEnemy1(int x, int y) // enemy 1 death
{
    string body[4][4] = {{"X", "X", "X", "X"}, {"X", "X", "X", "X"}, {"X", "X", "X", "X"}, {"X", "X", "X", "X"}};
    print4by4Grid(body, 4, "\33[34m", x, y);
}
void moveEnemy1() // movement functionality of enemy 1
{
    if (enemy1direction == "down") // To change enemy direction 
    {
        if (eY == 22)
        {
            enemy1direction = "up";
        }
        else if (eY == playerY)// fire iff player x and enemy x matches
        {
            enemyBullet(eX + 4, eY + 1, "right");
        }
        else
        {
            // simple enemy movent logiccs
            if (getCharAtxy(eX, eY + 5) == ' ' && getCharAtxy(eX + 2, eY + 5) == ' ' && getCharAtxy(eX + 3, eY + 5) == ' ' && getCharAtxy(eX + 4, eY + 5) == ' ')//?
            {
                eraseEnemy1(eX, eY);
                eY++;
                printEnemy1(eX, eY);
            }
        }
    }

    else if (enemy1direction == "up")
    {
        if (eY == 12)
        {
            enemy1direction = "down";
        }
        else if (eY == playerY)
        {
            enemyBullet(eX + 4, eY + 1, "right");
        }
        else
        {
            if (getCharAtxy(eX, eY - 1) == ' ' && getCharAtxy(eX + 2, eY - 1) == ' ' && getCharAtxy(eX + 3, eY - 1) == ' ' && getCharAtxy(eX + 4, eY - 1))
            {
                eraseEnemy1(eX, eY);
                eY--;
                printEnemy1(eX, eY);
            }
        }
    }
}

void printEnemy2(int x, int y) // printing enemy 2
{
    string body[3][5] = {{" ", "_", "_", "_", " "},
        {"<", "=", "@", "|", ")"},
        {" ", "O", "/", "\\", "O"}};
    print5by5Grid(body, 3, "\33[35m", x, y);
}

void eraseEnemy2(int x, int y) // erasing enemy 2
{
    string body[3][5] = {{" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}};
    print5by5Grid(body, 3, "\33[35m", x, y);
}
void deathOfEnemy2(int x, int y) //// enemy 2 death

{
    string body[3][5] = {{"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}};
    print5by5Grid(body, 3, "\33[35m", x, y);
}
void moveEnemy2() // movement functionality of enemy 2
{
    if (enemy2direction == "down")
    {
        if (eY2 == 47)
        {
            enemy2direction = "up";
        }
        else if (eY2 == playerY)
        {
            enemyBullet(eX2, eY2, "left");
        }
        else
        {
            if (getCharAtxy(eX2, eY2 + 4) == ' ' && getCharAtxy(eX2 + 2, eY2 + 4) == ' ' && getCharAtxy(eX2 + 4, eY2 + 4) == ' ')
            {
                eraseEnemy2(eX2, eY2);
                eY2++;
                printEnemy2(eX2, eY2);
            }
        }
    }
    else if (enemy2direction == "up")
    {
        if (eY2 == 19)
        {
            enemy2direction = "down";
        }
        else if (eY2 == playerY)
        {
            enemyBullet(eX2, eY2, "left");
        }
        else
        {
            if (getCharAtxy(eX2, eY2 - 1) == ' ' && getCharAtxy(eX2 + 3, eY2 - 1) == ' ' && getCharAtxy(eX2 + 4, eY2 - 1))
            {
                eraseEnemy2(eX2, eY2);
                eY2--;
                printEnemy2(eX2, eY2);
            }
        }
    }
}

void printEnemy3Right(int x, int y) // printing enemy 3 right face
{
    string body[3][5] = 
    {
        {" ", " ", "^", " ", " "},
        {"<", "=", "=", "=", ">"},
        {" ", " ", ",", " ", " "}
    };
    print5by5Grid(body, 3, "\33[31m", x, y);
}

void printEnemy3Left(int x, int y) // printing enemy 3 left face
{
    string body[3][5] = 
    {
        {" ", " ", "^", " ", " "},
        {"<", "=", "=", "=", ">"},
        {" ", " ", "'", " ", " "}
    };
    print5by5Grid(body, 3, "\33[31m", x, y);
}

void eraseEnemy3(int x, int y) // erase enemy 3
{
    string body[3][5] = {{" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}, {" ", " ", " ", " ", " "}};
    print5by5Grid(body, 3, "\33[31m", x, y);
}

void deathOfEnemy3(int x, int y) // enemy 3 death
{
    string body[3][5] = {{"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}, {"X", "X", "X", "X", "X"}};
    print5by5Grid(body, 3, "\33[31m", x, y);
}

void enemy3Direction() // control direction of enemy 3
{
    // for shooting player if their y coordinates match
    if ((eY3 == playerY || eY3 == playerY - 1 || eY3 == playerY - 2 || eY3 == playerY + 3 || eY3 == playerY + 1 || eY3 == playerY + 2) && enemy3Timer <= 60)
    {
        if (eX3 > playerX)
        {
            printEnemy3Left(eX3, eY3);
            enemyBullet(eX3 - 1, eY3, "left");
        }
        else if (eX3 < playerX)
        {
            printEnemy3Right(eX3, eY3);
            enemyBullet(eX3 + 5, eY3 + 1, "right");
        }
        if (enemy3Timer == 60)
        {
            enemy3Timer = 100;
        }
    }

    // for random movement of enemy 3 in case it is not shooting player
    else
    {
        if (randomValue == 0)
        {
            enemy3direction = "left";
        }
        else if (randomValue == 1)
        {
            enemy3direction = "right";
        }
        else if (randomValue == 2)
        {
            enemy3direction = "up";
        }
        else if (randomValue == 3)
        {
            enemy3direction = "down";
        }
        moveEnemy3();
    }
}

void moveEnemy3() // moves enemy 3
{
    if (enemy3direction == "right")
    {
        if (getCharAtxy(eX3 + 5, eY3) == ' ' && getCharAtxy(eX3 + 5, eY3 + 1) == ' ' && getCharAtxy(eX3 + 5, eY3 + 2) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eX3++;
            printEnemy3Right(eX3, eY3);
        }
        else
        {
            enemy3direction = "left";
        }
    }
    else if (enemy3direction == "left")
    {
        if (getCharAtxy(eX3 - 1, eY3) == ' ' && getCharAtxy(eX3 - 1, eY3 + 1) == ' ' && getCharAtxy(eX3 - 1, eY3 + 2) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eX3--;
            printEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "right";
        }
    }
    else if (enemy3direction == "up")
    {
        if (getCharAtxy(eX3, eY3 - 1) == ' ' && getCharAtxy(eX3 + 2, eY3 - 1) == ' ' && getCharAtxy(eX3 + 3, eY3 - 1) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eY3--;
            printEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "down";
        }
    }
    else if (enemy3direction == "down")
    {
        if (getCharAtxy(eX3, eY3 + 3) == ' ' && getCharAtxy(eX3 + 2, eY3 + 3) == ' ' && getCharAtxy(eX3 + 3, eY3 + 3) == ' ' && getCharAtxy(eX3 + 4, eY3 + 3) == ' ')
        {
            eraseEnemy3(eX3, eY3);
            eY3++;
            printEnemy3Left(eX3, eY3);
        }
        else
        {
            enemy3direction = "up";
        }
    }
}

void printEnemyBullets(int x, int y) // prints enemy bullets
{
    gotoxy(x, y);
    cout << "\33[31m"
         << "*"
         << "\33[0m";
}

void startEnemyBullet() // start enemy bullets
{
    for (int i = 0; i < 10000; i++)
    {
        activateEnemyRightBullet[i] = false;
        activateEnemyLeftBullet[i] = false;
    }
}

void enemyBullet(int x, int y, string direction) // generates an enemy bullet and add indeX in the array also activate the bullet
{
    // generating right side bullets of enemies
    if (direction == "right")
    {
        enemyRightBulletX[rightEnemyBulletCount] = x;
        enemyRightBulletY[rightEnemyBulletCount] = y;
        activateEnemyRightBullet[rightEnemyBulletCount] = true;
        rightEnemyBulletCount++;
        printEnemyBullets(x, y);//
    }

    // generating left side bullets of enemies
    else if (direction == "left")
    {
        enemyLeftBulletX[leftEnemyBulletCount] = x - 1;
        enemyLeftBulletY[leftEnemyBulletCount] = y + 1;
        activateEnemyLeftBullet[leftEnemyBulletCount] = true;
        leftEnemyBulletCount++;
        printEnemyBullets(x - 1, y + 1);
    }
}

void moveEnemyBullet() // move bullets of enemies
{
    // for right hand side bullet
    for (int i = 0; i < rightEnemyBulletCount; i++)
    {
        if (activateEnemyRightBullet[i])
        {
            erasePlayerBullet(enemyRightBulletX[i], enemyRightBulletY[i]);
            enemyRightBulletX[i] += 1;
            printEnemyBullets(enemyRightBulletX[i], enemyRightBulletY[i]);
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (activateEnemyLeftBullet[i])
        {
            erasePlayerBullet(enemyLeftBulletX[i], enemyLeftBulletY[i]);
            enemyLeftBulletX[i] -= 1;
            printEnemyBullets(enemyLeftBulletX[i], enemyLeftBulletY[i]);
        }
    }
}

void enemyBulletCollision() // enemy bullet collsion detection
{
    // for right hand side bullet
    for (int i = 0; i < rightEnemyBulletCount; i++)//
    {
        if (activateEnemyRightBullet[i])// Check if the right bullet is active
        {
            int x = enemyRightBulletX[i], y = enemyRightBulletY[i];
            char next = getCharAtxy(x + 1, y);
            if ((x + 1 == playerX + 1 && y == playerY) || (x + 1 == playerX && y == playerY + 1) || (x + 1 == playerX + 2 && y == playerY + 1) || (x + 1 == playerX && y == playerY + 2) || (x + 1 == playerX + 1 && y == playerY + 2) || (x + 1 == playerX + 2 && y == playerY + 2))
            {
                erasePlayerBullet(x, y);
                if (i)
                {
                    playerHealthDamage(2, 165, 4);
                }
                removeEnemyBulletsFromArray(i, "right");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removeEnemyBulletsFromArray(i, "right");
            }
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (activateEnemyLeftBullet[i])
        {
            int x = enemyLeftBulletX[i], y = enemyLeftBulletY[i];
            char next = getCharAtxy(x - 1, y);
            if ((x - 1 == playerX + 1 && y == playerY) || (x - 1 == playerX && y == playerY + 1) || (x - 1 == playerX + 2 && y == playerY + 1) || (x - 1 == playerX && y == playerY + 2) || (x - 1 == playerX + 1 && y == playerY + 2) || (x - 1 == playerX + 2 && y == playerY + 2))
            {
                erasePlayerBullet(x, y);
                if (maxPlayerHealth)
                {
                    playerHealthDamage(2,165, 4);
                }
                removeEnemyBulletsFromArray(i, "left");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removeEnemyBulletsFromArray(i, "left");
            }
        }
    }
}

void removeEnemyBulletsFromArray(int c, string direction) // removes enemy bullet from the arrays
{
    // for right hand side bullet
    if (direction == "right")
    {
        activateEnemyRightBullet[c] = false;
    }

    // for left hand side bullet
    else if (direction == "left")
    {
        activateEnemyLeftBullet[c] = false;
    }
}

void resetEnemyBullets()
{
    // for right bullets
    for (int i = 0; i < rightEnemyBulletCount; i++)
    {
        if (!activateEnemyRightBullet[i])
        {
            for (int j = i; j < rightEnemyBulletCount - 1; j++)
            {
                enemyRightBulletX[j] = enemyRightBulletX[j + 1];
                enemyRightBulletY[j] = enemyRightBulletY[j + 1];
                activateEnemyRightBullet[j] = activateEnemyRightBullet[j + 1];
            }
            rightEnemyBulletCount--;
        }
    }

    // for left bullets
    for (int i = 0; i < leftEnemyBulletCount; i++)
    {
        if (!activateEnemyLeftBullet[i])
        {
            for (int j = i; j < leftEnemyBulletCount - 1; j++)
            {
                enemyLeftBulletX[j] = enemyLeftBulletX[j + 1];
                enemyLeftBulletY[j] = enemyLeftBulletY[j + 1];
                activateEnemyLeftBullet[j] = activateEnemyLeftBullet[j + 1];
            }
            leftEnemyBulletCount--;
        }
    }
}

void erasePlayerBullet(int x, int y) // erases the bullet
{
    gotoxy(x, y);
    cout << " ";
}

void printbullet(int x, int y) // prints the bullet
{
    gotoxy(x, y);
    cout << "\33[32m"
         << "."
         << "\33[0m";
}

void bullet(int x, int y) // generates a player bullet and adds bullet indeX in the array
{
    // generating right hand side bullet
    if (playerdirection == "right")
    {
        playerRightBulletX[rightPlayerBulletCount] = x + 3;
        playerRightBulletY[rightPlayerBulletCount] = y + 1;
        activatePlayerRightBullet[rightPlayerBulletCount] = true;// to fore a bullet
        rightPlayerBulletCount++;
        printbullet(x + 3, y + 1);
    }

    // generating left hand side bullet
    else if (playerdirection == "left")
    {
        playerLeftBulletX[leftPlayerBulletCount] = x - 1;
        playerLeftBulletY[leftPlayerBulletCount] = y + 1;
        activatePlayerLeftBullet[leftPlayerBulletCount] = true;
        leftPlayerBulletCount++;
        printbullet(x - 1, y + 1);
    }
}

void movePlayerBullet() // moves all the bullets of player
{
    // for right hand side bullet
    for (int i = 0; i < rightPlayerBulletCount; i++)
    {
        if (activatePlayerRightBullet[i])
        {
            erasePlayerBullet(playerRightBulletX[i], playerRightBulletY[i]);
            playerRightBulletX[i] += 1;
            printbullet(playerRightBulletX[i], playerRightBulletY[i]);
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftPlayerBulletCount; i++)
    {
        if (activatePlayerLeftBullet[i])
        {
            erasePlayerBullet(playerLeftBulletX[i], playerLeftBulletY[i]);
            playerLeftBulletX[i] -= 1;
            printbullet(playerLeftBulletX[i], playerLeftBulletY[i]);
        }
    }
}

void playerBulletCollision() // Remove the bullet in case of collision with the enemy
{
    // for right hand side bullet
    for (int i = 0; i < rightPlayerBulletCount; i++)
    {
        if (activatePlayerRightBullet[i])
        {
            int x = playerRightBulletX[i], y = playerRightBulletY[i];
            char next = getCharAtxy(x + 1, y);
            if ((x + 1 == eX && y == eY) || (x + 1 == eX + 1 && y == eY) || (x + 1 == eX && y == eY + 1) || (x + 1 == eX + 4 && y == eY + 1) || (x + 1 == eX + 1 && y == eY + 2) || (x + 1 == eX + 2 && y == eY + 2) || (x + 1 == eX && y == eY + 3) || (x + 1 == eX + 1 && y == eY + 3) || (x + 1 == eX + 2 && y == eY + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy1IsLive)
                {
                    increaseScore();
                    healthEnemy1Damage(5);
                }
                removePlayerBulletsFromArray(i, "right");
            }
            else if ((x + 1 == eX2 && y == eY2) || (x + 1 == eX2 && y == eY2 + 1) || (x + 1 == eX2 && y == eY2 + 2) || (x + 1 == eX2 && y == eY2 + 3) || (x + 1 == eX2 + 2 && y == eY2) || (x + 1 == eX2 + 2 && y == eY2 + 1) || (x + 1 == eX2 + 2 && y == eY2 + 2) || (x + 1 == eX2 + 2 && y == eY2 + 3) || (x + 1 == eX2 + 1 && y == eY2) || (x + 1 == eX2 + 1 && y == eY2 + 1) || (x + 1 == eX2 + 1 && y == eY2 + 2) || (x + 1 == eX2 + 1 && y == eY2 + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy2IsLive)
                {
                    increaseScore();
                    healthEnemy2Damage(5);
                }
                removePlayerBulletsFromArray(i, "right");
            }
            else if ((x + 1 == eX3 && y == eY3) || (x + 1 == eX3 + 1 && y == eY3) || (x + 1 == eX3 + 2 && y == eY3) || (x + 1 == eX3 + 3 && y == eY3) || (x + 1 == eX3 && y == eY3 + 1) || (x + 1 == eX3 + 2 && y == eY3 + 1) || (x + 1 == eX3 + 3 && y == eY3 + 1) || (x + 1 == eX3 && y == eY3 + 2) || (x + 1 == eX3 + 3 && y == eY3 + 2) || (x + 1 == eX3 && y == eY3 + 3) || (x + 1 == eX3 + 3 && y == eY3 + 3) || (x + 1 == eX3 && y == eY3 + 4) || (x + 1 == eX3 + 3 && y == eY3 + 4))
            {
                erasePlayerBullet(x, y);
                if (enemy3IsLive)
                {
                    increaseScore();
                    healthEnemy3Damage(5);
                }
                removePlayerBulletsFromArray(i, "right");
            }
            else if (next != ' ')
            {
                erasePlayerBullet(x, y);
                removePlayerBulletsFromArray(i, "right");
            }
        }
    }

    // for left hand side bullet
    for (int i = 0; i < leftPlayerBulletCount; i++)
    {
        if (activatePlayerLeftBullet[i])
        {
            int x = playerLeftBulletX[i], y = playerLeftBulletY[i];
            char next = getCharAtxy(x - 1, y);
            if ((x - 1 == eX && y == eY) || (x - 1 == eX + 1 && y == eY) || (x - 1 == eX && y == eY + 1) || (x - 1 == eX + 4 && y == eY + 1) || (x - 1 == eX + 1 && y == eY + 2) || (x - 1 == eX + 2 && y == eY + 2) || (x - 1 == eX && y == eY + 3) || (x - 1 == eX + 1 && y == eY + 3) || (x - 1 == eX + 2 && y == eY + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy1IsLive)
                {
                    increaseScore();
                    healthEnemy1Damage(5);
                }
                removePlayerBulletsFromArray(i, "left");
            }
            else if ((x - 1 == eX3 && y == eY3) || (x - 1 == eX3 + 3 && y == eY3) || (x - 1 == eX3 && y == eY3 + 1) || (x - 1 == eX3 + 3 && y == eY3 + 1) || (x - 1 == eX3 && y == eY3 + 2) || (x - 1 == eX3 + 3 && y == eY3 + 2) || (x - 1 == eX3 && y == eY3 + 3) || (x - 1 == eX3 + 3 && y == eY3 + 3))
            {
                erasePlayerBullet(x, y);
                if (enemy3IsLive)
                {
