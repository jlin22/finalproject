
Chess 
--------------------------
Members
--------------------------
John Lin and Michael Lee from Period 5

Project Overview
--------------------------
This is Chess that can be played in three ways. 

1-Single Player against an AI.(but currently gives a segfault that we can't figure out)

2-Loading a game state or playing a game in a single terminal(without ai, so controlling both players)

3-Against another player

Topics Covered
--------------------------
Networking to connect two players through a similar server

Files through reading and writing in order to load game states

Forking for the select server

Allocating Memory through the use of malloc

Instructions
--------------------------
Running make will compile several files

Calling ./load will initially ask for command
call 'play' to start a fresh game and call 'load' to load a file.
If 'play' is called, a file to write into will be called for and then the board will appear. Insert commands to move the pieces
If the game state is in the file, then it will load. Insert commands to move the pieces

Calling ./ai will create a new game in which you can play against an AI, but doesn't work.

Calling ./server will set up the server that can have multiple clients. When two clients connect, then the game can begin. Insert commands in the client to move accordingly.

Commands will be entered in the format 6040, where the first two numbers is the inital position in (R)(C) and the last two numbers is the final position in (R)(C). 6040 would move the piece from row 6, col 0 to row 4, col 0 if it is a valid move

  0 1 2 3 4 5 6 7 (C)
		
0

1

2

3

4

5

6

7

(R)

Known Bugs
--------------------------

Sometimes, after client connects, there is an infinite loop printing enter command and an errno in server

Sometimes, turns do not properly function in a player vs player game; for example, a player's command going through even though it isn't their turn, or the turns not switching
