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
