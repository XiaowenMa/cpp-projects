Test Cases:
1.tic-tac-toe:
XXX
 X
X
since blue  is inValid, the game pieces at those locations are by default.
2.gomoku
 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X

the empty position are occupied by default game pieces
I also tried to insert blank lines into the file and space between strings/ints. The output doesn't change.
3.my own test:jingziqi(4*4)
OXOO
XOXO
XOXO
OXOX
I also tried to write color in capital letters, and it can still recognize it because of the call of lowercase(string s) before calling enum color aString(string s), which transforms string to a enum color.
And i tried to have a piece at loc(4,0)(black circle O 4 0) which is invalid since my board is 4*4, and it skip that line and move to the next valid lines.
4. And i make my "jingziqi2" on a 5(width)*4(height)  board.
OXOOX
XOXOO
XOXOO
OXOXX
