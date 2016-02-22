## Coding Problems 

### Boolean Parenthesation Problem 

Given a boolean expression with following symbols.

	Symbols
	    'T' ---> true 
	    'F' ---> false 

And following operators filled between symbols

	Operators
	    &   ---> boolean AND
	    |   ---> boolean OR
	    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Examples:

	Input: symbol[]    = {T, F, T}
	       operator[]  = {^, &}
	Output: 2
	The given expression is "T ^ F & T", it evaluates true
	in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
	
	Input: symbol[]    = {T, F, F}
	       operator[]  = {^, |}
	Output: 2
	The given expression is "T ^ F | F", it evaluates true
	in two ways "( (T ^ F) | F )" and "( T ^ (F | F) )". 
	
	Input: symbol[]    = {T, T, F, T}
	       operator[]  = {|, &, ^}
	Output: 4
	The given expression is "T | T & F ^ T", it evaluates true
	in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) 
	and (T|((T&F)^T)). 
	
Solution:
Let T(i, j) represents the number of ways to parenthesize the symbols between i and j (both inclusive) such that the subexpression between i and j evaluates to true.

![DPEquTrue](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/trueeq.png)

Let F(i, j) represents the number of ways to parenthesize the symbols between i and j (both inclusive) such that the subexpression between i and j evaluates to false.

![DPEquFalse](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/falseeq.png)

Base Cases:

	T(i, i) = 1 if symbol[i] = 'T' 
	T(i, i) = 0 if symbol[i] = 'F' 
	
	F(i, i) = 1 if symbol[i] = 'F' 
	F(i, i) = 0 if symbol[i] = 'T'
If we draw recursion tree of above recursive solution, we can observe that it many overlapping subproblems. Like other dynamic programming problems, it can be solved by filling a table in bottom up manner. 

The C++ implementation is under the directory. 

