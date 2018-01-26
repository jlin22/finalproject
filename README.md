
Chess 
--------------------------
Members

John Lin and Michael Lee from Period 5
-------------
Project Overview

This is Chess that can be played in three ways. 

1-Single Player against an AI.

2-Loading a game state against an AI.

3-Against another player
-----------------------
Topics Covered

Networking to connect two players through a similar server

Files through reading and writing in order to load game states

Forking for the select server

Allocating Memory through the use of malloc
------------------------
Instructions

Running make will compile several files

Calling ./load will initially as for a file to load
If the game state is in the file, then it will load and play out like a normal game

Calling ./ai will create a new game in which you can play against an AI

Calling ./server will set up the server that can have multiple clients. When two clients connect, then the game can begin
----------------------
Known Bugs

Sometimes, after client connects, there is an infinite loop printing enter command and an errno in server

Sometimes, turns do not properly function in a player vs player game; for example, a player's command going through even though it isn't their turn, or the turns not switching
