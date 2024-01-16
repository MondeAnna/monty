### [ALX](https://www.alxafrica.com/) System Engineering Plus

Studies carried out in the **[ALX Software Engineering Plus](https://www.alxafrica.com/software-engineering-plus/)** course

<br />

#### Technologies

* Bash:     5.1-6ubuntu1
* Docker:   24.0.5
* GCC:      9.4.0
* Ubuntu:   20.04 LTS

<br />

#### Requirements: C

* Allowed editors:
    * _[vi](https://www.geeksforgeeks.org/vi-editor-unix/)_
    * _[vim](https://www.geeksforgeeks.org/getting-started-with-vim-editor-in-linux/)_
    * _[emacs](https://www.geeksforgeeks.org/emacs-command-in-linux-with-examples/)_

* All source code:
	* Will be compiled on `Ubuntu 20.04 LTS` using `gcc`, using the options
		* `-Wall -Werror -Wextra -pedantic -std=gnu89`
	* Not to use `stdlib's` _[system](https://www.geeksforgeeks.org/system-call-in-c/)_
	* To end with a new line
	* To have no errors and no warnings during compilation
	* To use the _[Betty](https://github.com/alx-tools/Betty)_ style.
	* To have it's best practices checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)

* A README.md file at the root of:
	* The repo, containing a description of the repository
	* The folder of each project, containing a description of the project

* Code
	* You allowed to use a maximum of one global variable
	* No more than 5 functions per file
	* You are allowed to use the C standard library
	* The prototypes of all your functions should be included in your header file called `monty.h`
	* Don't forget to push your header file
	* All your header files should be include guarded
	* You are expected to do the tasks in the order shown in the project
	* Any output must be printed on `stdout`
	* Any error message must be printed on `stderr`
		* Here is a link to a _[GitHub repository](https://github.com/ku1ik/stderred)_ that could help you making sure your errors are printed on `stderr`

<br />

#### Learning Objectives

The ability to explain, without external resources:
	* What do LIFO and FIFO mean
	* What is a stack, and when to use it
	* What is a queue, and when to use it
	* What are the common implementations of stacks and queues
	* What are the most common use cases of stacks and queues
	* What is the proper way to use global variables

#### Resources

* _[How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)_
* _[Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)_
* _[Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)_
* _[Queue operations](https://www.edureka.co/blog/queue-in-c/)_

<br />

#### Low Level Programming Concepts

* _[Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)_
* _[Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)_

<br />

#### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

* Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language
* There is not more than one instruction per line
* There can be any number of spaces before or after the opcode and its argument
* Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account

<br />

#### The monty program

* Usage: `monty file`
    * where `file` is the path to the file containing Monty byte code
* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
    * where `<file>` is the name of the file
* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
    * where is the line number where the instruction appears
    * Line numbers always start at 1
* The monty program runs the bytecodes line by line and stop if either:
    * it executed properly every line of the file
    * it finds an error in the file
    * an error occured
* If you can't malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`
* You have to use `malloc` and `free` and are not allowed to use any other function from man `malloc` (`realloc`, `calloc`, ...)

<br />
