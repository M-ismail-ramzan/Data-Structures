# 1. Algorithm Optimization

## Q1:
Print all positive integer solutions to the equation a 3 + b 3 =c 3 + d 3 where a, b, c, and d are integers between 1 and 1000.
A brute force solution will just have four nested for loops. Something like:
n = 1000
for a from 1 to n
for b from 1 to n
for c from 1 to n
for d from 1 to n
if a 3 + b 3 == c 3 + d 3
print a, b, c, d

This algorithm iterates through all possible values of a, b, c, and d and checks if that
combination happens to work. The time complexity of the algorithm is O(n 4 ), reduce the
runtime from O(n 4 ) to O(n 3 ).
Hint:

## Q2: Reverse the contents of an integer array in-place i.e., without using any other data
structure in O(n) runtime.
void reverse (int array[], int arr_length){
//Your code here
}

## 2. SNAKES AND LADDERS GAME

Snakes and ladders is an ancient south Asian board game. It consists of 10X10 grid board
which contains some snakes and ladders at specific boxes/indexes. One hundred is the
maximum and a must to win score for each player. First player reaching 100 gets to win the
game and is immediately declared as first Winner.
You are required to do the following:
 Create a snake board of 10 rows and 10 columns.
 Randomly generate 09 snakes on the board. In order to generate snake, you only
need to know head and tail of the snake. Make sure that both head and tail are on
the board. Moreover, if head is on row (Mi) and tail is on row (Mj) then i will

always be less than j.
 Similarly, generate 09 ladders on the board.
 Print the snake board along with snakes and ladders on the screen.
 Once the game is started display the output of the dice and move the first player.
Then wait for key press (you can use getch()) before second player’s turn.
 Game will go on until one player wins the game.
 In case player lands on a snake’s head, it will come down to its tail, here you need
to display a message “oops, snake got you!!!”
 In case player lands on the bottom of the leader it will climb the ladder, here you
need to display a message “you got lucky”
Note: Input validation is mandatory when reading taking input size of the board.