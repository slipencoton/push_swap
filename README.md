*This project has been created as part of the 42 curriculum by <qbourine>[, <rstrcic>].*

Description :

	The main goal of the project is to sort a stack of numbers in crescent order in the most efficient way. We must follow the rules of 1.0 version of Push_swap (https://cdn.intra.42.fr/pdf/pdf/190342/en.subject.pdf).

	The allowed actions are :
	
		sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one element or none.(qbourine)

		sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one element or none.(qbourine)

		ss : sa and sb at the same time.(qbourine)
	
		pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.(qbourine)

		pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.(qbourine)

		ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.(rstrcic)

		rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.(rstrcic)

		rr : ra and rb at the same time.(rstrcic)

		rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.(rstrcic)

		rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.(rstrcic)

		rrr : rra and rrb at the same time.	(rstrcic)

	The program must mesure the disorder and use the best algorithm accordingly :

		Simple algorithm (O(n^2)) :		Insertion sort (adapted for the subject)
										We rotate the stack A until the lowest number is in first position.
										Then we push it in the stack B.
										We repeat until the stack A has one element (the highest number).
										Then we empty the stack B by pushing it in A.
										This algorithm is easy to implement and don't make to much moves.
		
		Medium algorithm (O(n√n)) :		Block-based partitionning
										We separate the stack in quartiles.
										We rotate the stack A until we found a number of the current quartile.
										Then we push it in the stack B.
										We repeat until there is no numbers of the current quartile, then we pass to the next one.
										When the stack A is empty, we rotate B until the highest number is in first position and push it in the stack A.
										We repeat this step until the stack B is empty.
										This algorithm is adapted to any size of input and offer good enought performances.

		Complex algorithm (O(n log n)):	Radix sort (adapted for the subject)
										The main objective is to sort numbers based on their units, then their tens etc...
										When we pass from the stack A to B we make it crescent and in descending order in the other way.
										This method is pretty efficient and easy to build. However, it can make more useless moves as the range of number increase.
										In order to solve this problem, we used index instead of the input numbers.
								
 Instruction :

	-Compilation :  Just write "make" in the terminal and the Makefile will do the work for you.
				    You can type "make fclean" or "make clean" to delete all the object and execution file.
				    Or type "make re" if you want to redo a compilation from the start wich will clean all the object and execution file and compile after that.

	-Usage :	After the compilation you will have an execution file called "push_swap", to use it you will need to put some instructions like bellow :

															./push_swap <FLAG> < FLAG> <STACK>

				FLAG : 5 FLAGS exist for thic project, there is the "--simple" flag, the "--medium", the "--complex", the "--adaptive" and finally the "--bench" one.
					Flags must be put before the stack.
					"--simple"   = Forces the use of your O(n^2) algorithm.
					"--medium"   = Forces the use of your O(n√n) algorithm.
					"--complex"  = Forces the use of your O(n log n) algorithm.
					"--adaptive" = Forces the use of your adaptive algorithm based on disorder. This is the default behavior if no selector is given.
						
					"--bench"    = display :
										 - The computed disorder (% with two decimals).
				    					 - The name of the strategy used and its theoretical complexity class.
										 - The total number of operations.
										 - The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
								
				Caution : To work properly the STACK must not include :
								- consecutive Signs ("--", "++") or signs like ("=", "/", "√", ...).
								- two same numbers ("0 1 2 3 2") or even ("0 1 2 3 02).
								- letters ("a, b, c, d, ..., z) CAPS OR NOT !
								- numbers that is strictely inferior to INT_MIN and strictely superior to INT_MAX.
									all the numbers should be between -2147483648 and 2147483647.
						 
						  The program can be run by using string or int, it's fine in both cases but it must not contain a mix of both.
						  If you are using string, it MUST start with a number.
															
 Nb :		The correct application of bench marks, the calculations of disorder have been handled by rstrcic. The main function (verification of input values and flags)
 			have been handled by qbourine. For the algorithms, both worked simultaneously.

 Ressources :
	
	Source : 
		- WIKIPEDIA     : 	Explanations about algorithm:
							https://en.wikipedia.org/wiki/Sorting_algorithm
		
		- GeeksforGeeks : 	Explanations about complexity:
							https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/
		
						  	Description of selection-sort strategy:
						  	https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
		
						  	Description of block-sort strategy:
						  	https://www.geeksforgeeks.org/dsa/introduction-to-block-sort/
						  
						    Description of radix-sort strategy:
						  	https://www.geeksforgeeks.org/dsa/radix-sort/
