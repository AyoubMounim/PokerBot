
# PokerBot

The basic idea behind this project is to buld a simple program to help a poker
player make better decisions during a poker game.

The main function of the program is computing some form of quantitative rating
of the player's hand in any given moment of play, in order to suggest the
best course of action (statistically speaking).

The final version of the program is intented to have two modes: *play mode* and
*assist mode*.  
In play mode, the player can play a poker game against a number of computer-controlled players.  
In assist mode, the player can simulate any real-time game scenario by manually
inputting his hand and table cards, and see how the program's advice is effective
in playing the hand.

In the current version of the program, the play mode is barely functional and will
be properly implemented in the future.  
This current version also supports one sigle method of hand ranking, namely by 
computing the *effective hand strength*, and that is the only output of the program
when suggesting what the player should do. The successive vertion will have more
choices of hand ranking and will have a more extensive and useful output.

