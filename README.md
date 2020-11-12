# WanderersQuest
README

Wanderer's Quest - IN DEVELOPMENT 
Built in Visual Studio, Currently updating only the solution
by Sinan Unan

Wanderer's Quest is designed to be a stragetic turn-based game. 
Also, every 10 turns, a card-based battle games are initiated.


Current Build Features:
The current build has gameplay features that are initiated by keys in the board. 
Some of these features are not designed to be initiated by keys. (Ex: New Unit)

Current Key Bindings:
Move (all speeds different)
w: Move up
a: Move left
s: Move down
d: Move right

n: next turn (can also press placeholder on right bottom)
u: use settlement (currently, only adds new unit)

Keys that are not designed for initation
g: Center active unit 
c: Create new unit
k: Kill unit

Mouse bindings:
Can end turn with placeholder on right bottom
Can initialize path for active unit by moving mouse 
Can set path by clicking on a valid hexagon  







How to Win:
The game lasts for 30 turns, or 3 card-based battles; it can go to overtime for another 10 turn.
There are 4 ways to win.
Peace: If a player wins 3 card battles by only defending, they are the winner automatically.
Mixed: If a player wins 3 card battles by different styles (attack only, defend only, mixed attack and defense),
       then they win the game if there is no peace winner.
Attack: If a player wins 3 card battles by only attacking
        then they win the game if there is no peace or mixed winner.
Overtime: If no player has won the game by the above constraints, another 10 turns are played with one last battle.
          After that, the constraints are checked again, to see if anyone has won the game.
          If not, the winner will be decided by the point system.

Point System
Win with Defense only   : +5 points
Win with Attack  only   : +3 points
Win by any other means  : +2 points
Lost battle             : +0 points
Won at least two games  : +2 points
Won at least three games: +3 points 
Won all games           : +5 points

