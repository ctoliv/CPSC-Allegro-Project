# CPSC Allegro Project

This repository is for my CPSC 440 Game Programming work using Visual Studio and Allegro.

## Lab 1

Lab 1 is a simple Allegro program that draws a still night scene using primitive shapes.

The scene includes:
- A house
- A moon
- Stars
- Windows
- A door
- A tree
- Grass

The program does not use a game loop. It creates the display, draws the scene, shows it for 20 seconds, and then closes.

## Lab 2

Lab 2 draws a movable object in the center of the screen. The object has a pointer that changes direction depending on the key pressed.

Controls:
- Up Arrow: move up
- Down Arrow: move down
- Right Arrow: move right
- Left Arrow: move left
- U: move diagonally upper-left
- D: move diagonally lower-right
- R: move diagonally upper-right
- L: move diagonally lower-left
- Escape: close the program

The old object is erased by redrawing the background before drawing the object in its new position.

## How to Run

1. Open the solution in Visual Studio.
2. Select the project you want to run.
   - `Project1` for Lab 1
   - `Project2` for Lab 2
3. Make sure the selected project is set as the Startup Project.
4. Make sure Allegro is installed through NuGet for that project.
5. Make sure the Primitives Addon is enabled.
6. Click Local Windows Debugger to run.

## Author

Christian Toliver
