# Stack ADT 

Operations:
1.	void Push(element) – pushes an element on the top of stack
2.	element Pop() – removes and display the element on the top of stack
3.	boolisEmpty() – checks if the stack is empty or not
4.	void Clear() – release the memory allocated by stack
5.	void Peak() – display the contents of the top element of stack 

Task 2: 
The idea is rather simple: You keep a Stack of braces, and every time you encounter an open brace, you push it into your stack. Every time you encounter a close brace, you pop the top element from your stack. At the end, you check your stack for being empty. If so, indeed your input string contained balanced braces. Otherwise, it didn't. 
Expected Input 
1.	1 + 2 * (3 / 4)
2.	1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14
3.	1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14
Your program will determine whether the open brackets (the square brackets, curly braces and the parentheses) are closed in the correct order.
Expected Output 
1.	This expression is correct.
2.	This expression is NOT correct e.g. error at character # 10. ‘{‘- not closed.
3.	This expression is correct.
Your program should be able to take generic input expression from user.
 
 

 
Task 3 (Recursion):

Write a function(in Main Class) that takes input a stack and prints it, bottom up.
