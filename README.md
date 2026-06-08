# Program Assignment 3 - Cannon Drop Game

This repository contains my Program Assignment 3 project for CPSC 440 Game Programming.

## Description

This project is based on the Penguin Drop assignment, but uses a custom cannon and UFO theme. The player controls a cannon at the bottom of the screen and shoots cannonballs at falling enemies. The goal is to stop enemies from landing on the base.

If five enemies land on the base, the game ends and displays a final Game Over screen with the final stats.

## Features

- Custom background image
- Custom cannon image
- Custom enemy image
- Custom cannonball image
- Custom base image
- Cannon rotates left and right using the arrow keys
- Spacebar fires cannonballs
- Multiple cannonballs can be active at the same time
- Enemies randomly spawn at the top of the screen
- Enemies fall downward toward the base
- Cannonballs collide with enemies
- Enemies disappear when hit by a cannonball
- Score increases when an enemy is hit
- Enemies landing on the base increase the landed count
- Game ends when five enemies land
- Game Over screen displays final stats
- Uses separate class files for cannonballs and enemies
- Includes image loading error checks
- Destroys loaded bitmaps before the program closes

## Controls

- Left Arrow: Rotate cannon left
- Right Arrow: Rotate cannon right
- Spacebar: Fire cannonball
- Escape: Close the game

## Project Files

- `main.cpp` - Main game loop, input handling, drawing, status display, and game over screen
- `cannonball.h` - Cannonball class definition
- `cannonball.cpp` - Cannonball image loading, firing, movement, drawing, and collision
- `enemy.h` - Enemy class definition
- `enemy.cpp` - Enemy image loading, spawning, falling movement, drawing, and base collision
- `background.png` - Background image
- `base.png` - Base image
- `cannon.png` - Cannon image
- `cannonball.png` - Cannonball image
- `enemy.png` - Falling enemy image

## How to Run

1. Open the project in Visual Studio.
2. Make sure Allegro is installed.
3. Make sure the Allegro Image, Primitives, and Font add-ons are available.
4. Make sure all PNG image files are in the project folder.
5. Build and run the project.
6. Use the left and right arrow keys to aim the cannon.
7. Press Spacebar to fire cannonballs at the enemies.

## Author

Christian Toliver
