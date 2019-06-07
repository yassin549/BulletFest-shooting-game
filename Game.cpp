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
