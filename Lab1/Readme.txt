Test Cases:
  a.space/tab: they are ignored and not printed out
  b.normal strings such as "name", "hahaha" etc: each of them are printed out in a single line
  c.a string of symbols such as "//" and "^&*": print out as "^&*"
  d.a mixed string with letters, number and symbols in it "workhard2!": print out in a line as "workhard2!"
  e.multiple strings in a line such as "nihao	huanying" and "hello world": each of the single string is printed out in a single line and the spaces are ingnored. As following:
   nihao
   huanying
   hahaha
   hello
   world
  f.numbers 2 and 56, 2 is in the same line with "^&*" and right before it, as "2 ^&*", and 56 is in a single line: these 2 numbers are printed out after all the strings are printed out and each number is in a single line.

  Extra Credit:
 Desktop     Music           Pictures   Templates   WINDOWS               'Xiaowen Ma CSE332S'   perl5
 Downloads  'My Documents'   Public     Videos     'Xiaowen Ma 332S new'   cse332