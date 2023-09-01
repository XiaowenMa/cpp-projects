# cpp-projects

# Overview

This folder contains the projects from course Object-Oriented Software Laboratory. It is composed of 5 projects, Lab1 - Lab3 are individual projects, Lab4 - Lab5 are group projects (group of 3). The projects are designed and constructed to learn C++ programming in developing a C++ game step by step and a simulation software of file system. All codes are written in C++.

# Lab1 - Basic C++ Program Structure and Data Movement

In this project, I implement a simple C++ program that can:
  (1) read in and parse command line arguments,
  (2) open a file and read in strings from it,
  (3) differentiate numeric values from other input strings,
  (4) produce output based on the strings that it read in, to the standard output stream.

# Lab2 - Building Up the Game Board

This project extends Lab1's functionality by:
  (1) reading in and parsing files defining the settings of a board game, including game board dimensions, game piece locations, and the symbols used to display the pieces on a game board,
  (2) recognizing badly formatted inputs that the program can handle and then still proceed, but have the program exit gracefully if it encounters a case it cannot handle (such as not being able to
open the input file),
  (3) if information gathering from the file succeeded, print out a representation of the game board and the pieces on it.

# Lab3 - TicTacToe

In this project, I develop a C++ TicTacToe game on a 5*5 game board; the program can:
  (1) repeatedly display the current state of a game,
  (2) prompt the user and receive input for the next move in the game,
  (3) check whether or not each input move is valid,
  (4) detect if the game is successfully completed, if the game has reached a point where no further valid moves are possible, or if there are still remaining valid moves available.

# Lab 4 - Multiple Games -  Gomoku(Group of 3)

In this project, we first refactor the previous individual TicTacToe game into a general game class, and then develop a Gomoku game on a 19*19 game board; the program can:
  (1) handle valid and invalid move inputs from the user and keep on playing,
  (2) allow the user to quit when they choose,
  (3) identify successful completion or unsuccessful completion of the game.

# Lab 5 - Simple File System(Group of 3)

In this project, we build a software simulation of a file system, which supports some basic, simple file types that can be stored in a file system; we also provide a user interface similar to a command prompt or terminal that allows a user to interact with the file system and files it contains.
The supporting commands inlude ls, rm, cat, cp, ds, sym, etc. The detailed documentation can be found at lab5->Readme.txt.
