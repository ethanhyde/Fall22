# Tuesday 09/27 Week 1
## Lecture 1: Course Overview & Introduction to Unix
Do reading for 2.1 - 2.5 and 2.6.1
What is Unix?
- Operating system
	- Multi tasking
	- Multi user
- Started at AT&T Bell Labs in late 60’s, first released in 1973
- 80’s and 90s Competing versions of Unix
- 1990s Linux takes off
- 2000s commercial Unixes abandoned, companies use Linux, back Linux
- OS X used on Macs since 2002
Shells
- Shells are accessed through a terminal program
- Typically exposed on all Linux
- Shells are interpreters like python, carries out a command
- Many types of shells
	- Sh (=bash and ksh)
	- csh(=tcsh)
- They differ in syntax for environment variables and iteration / loops
Files
- Unix maintains a file system
	- File system controls how data is stored and retrieved
- Abstractions
	- Directories and files
	- Files within directories
- Directories are hierarchical
	- Directories can be placed within other directories
	- / = root. First thing on a line in terminal
Anatomy of shell formatting

![](https://lh3.googleusercontent.com/ftVWwwEN6oibhiJUYGnFoUsjiWzfFO2nBc0UTb-8HpVrEjM042dpYU4F9ESe1Qri0foovCuCHzpRC6ONziXWIOU9_eGT5z7LzalQ2jE-e-wD3VTmsRe6EVNECjyoH1zIxdKHT0clwuknNAP4l9oyT94oS84eBKLjS5T3C_BljzYSgpOnGf0WOYPaAQ)

File editors
- Vi
- Emacs
- Sublime
# Thursday 09/27 Week 1
## Conventions surrounding binary numbers
- 01000001 is 65 in decimal
- 65 represents ‘A’, ASCII value
Terminology
- Computer operates in “cycles”
- Goal during a cycle is to compute one thing
- At end of cycle, computer starts a new cycle
- Every cycle gets one “instruction” - bytes that explain what to do

# Tuesday 10/4 Week 2
## More unix, What is data? Beginning on memory
### Quiz answer
int main ()
{
	int x = 0;
	while (x < 10)
	x += 6;
	x += 4;
return x;
}
//Returns 16

Permissions
- Properties associated with files and directories
	- System calls have built in checks to permissions and only succeed if they are in place
- 3 Classes of permissions
	- User: Access for everyone with file
- Group: allow unix group
- Other: anyone with granted access to file
- 3 Types of permissions
	- Read, write, execute
- Executable files are able to be run from command line
	- Scripts, binary programs
- If file is executable is linked to file permissions

Chmod
- Change file mode
- Edits permissions for a file

ls -l
- Long listing of files
- Shows the permissions of files in a directory
- Owner, group, file size....

Permissions and directories
- Can only edit a directory if you have permissions

[[Project 1B]]

# Thursday 10/6 Week 2
Types in C
 - char 1 byte
 - unassigned char - 1 byte
 - int - 4 bytes
 - float - 4 bytes
 - double - 8 bytes

Types in C: char and unsigned char
- char: ASCII character, 1 byte
	- Values: -128 to 127
- unsigned char: 1 byte
	- Values: 0 to 255

Overflow
- int x = 2^31 - 1
- x += 1;
- Answer is x = -2^31
- Beyond largest integer
- Wraps around

# Tuesday 10/11 Week 3
### Memory
Automatic vs dynamic memory
- In C, 2 types of variables
	- Ignoring static memory
- Automatic
	- Taken care of automatically
- Dynamic
	- Programmer manages it

Main ideas for memory are automatic and dynamic memory
Support struct for implementing them uses diff data structs
- Auto memory is managed w/ stack
- Dynamic is managed w/ heap

- Programmer allocates memory, stays around until you dealocate or program ends
- Need a way to keep track of memory
	- Memory leaks are an error from not keeping track 

Pointers
- Pointer points to memory address
- Denoted with *
	- int * p
		- Pointer to an int

Hexacedimal Addresses
- Memory addresses are in hexadecimal
	- 16 options for each digit
		- 01345679 ABCDEF
- Print pointers with "%p"
	- Shows the hexadecimal addresses

```C
printf("%p", &A)
//Where A is the name of a variable, array index
//Prints the memory address of the variable
```

Dynamic mem allocation
Both of these in .h file
- Malloc
	- Allocates the needed memory
- Free
	- Deallocates memory

```C
#include <stdio.h>
#include <stdlib.h> //Think its for pointers
//Allocates mem
int *ptr = malloc(2*sizeof(int));
//sizeof returns number of bytes for a type. 4 bytes for int

//Deallocates mem
free(ptr);
```


NULL ptr
 - int * p = NULL;
	 - Initializes pointers

Pointers size
- Pointers are 8 bytes
- sizeof( int * ) == 8
- sizeof( char * ) == 8

Dereferencing
- Dereference
	- Gets value at memory location
- Uses * which is the dereference operator
```C
int * p = malloc(sizeof(int)* 1);
```

- & for the variable, tells you address
- * for the address, tell you its value
```C
int y = 2
int * x = &y
int z = * x
//If printed, would be the addresses and values of the pointers
```

# Week 3 Thursday 10/13
Pointer arithmetic
- int * p = malloc(sizeof(int)* 5);
- c allows you to modify pointers using pointer arithmetic

Dereferencing
- * is the dereference operator
- Another one is []
```C
int * p = malloc(sizeof(int)* 1);
* p = 2; //Sets memory p to have value 2
p[0] = 2; //Sets memory p points to have value 2
```
Pointers to pointers
```C
int ** p = malloc(sizeof(int *)* 5);
p[0] = malloc(sizeof(int)* 50);
```
- Sizeof tells you number of bytes associated w/ type
	- Not the actual size of the array

Memory segments
- Program is divided into 4 segments
	1. Code segments
		- where machine instructions are
	2. Data segments
		- Where global variables live and other things
	3. "Stack"
		- Where automatic mem lives
	4. "Heap"
		- Where dynamic mem lives 

Stack overflow
- When stack goes into the heap

Character strings
- Array of type "char"
- Terminated by null char

# Week 4 Tuesday 10/18
Tuesday 10/25 mega quiz
Thursday 10/27 megaquiz feedback and midterm format discussion
Tuesday 11/1 Midterm

Enums
- Make your own type
	- Type is "list of key words"
- Enums are useful for code clarity
	- Always possible to do same thing with int
- Basically a struct in C

Structs
- Simple data types
	- Float, int, char, etc ...
- Structs are complex data type
- Mechanicism provided by C to define group of variables
	- Variables must be grouped together
- Can have structs within structs
```C
struct Origin
{
	//Stuff
};

struct Direction
{
	//Stuff
};

struct Ray
{
	struct Origin ori;
	struct Direction dir;
};
```

File IO: streams and file descriptors
- Two ways to access files 
- File descriptors
	- Lower lever interface to files and devices
	- Type: small ints 
- Streams
	- Higher lever interface to files and devices
	- Type FILE *
- Processs for reading or writing
	- Open file
		- Tell unix you intend to do file IO
		- Function returns a file *
			- Used to identifyu from this point
		- Checks permissions are valid
	- Write to file
	- Close file

Opening a file 
```C
FILE *handle = fopen(filename, mode);

//Example
FILE *h = fopen("/tmp/212", "wb");
```

```C
int main(int argc, char *argv[])
{
	char *hello = "hello world: file edition\n";
	FILE *f = fopen("330", "w");
	fwrite(hello, sizeof(char), strlen(hello),f);
	fclose(f);
}

//If we see contents of file from command line this is returned:
cat 330
hello world: file edition`
```

# Week 4 Thursday 10/20
File position indicator 
```C
fseek(FILE *stream, long offset, int whence);
//Function sets the file position indicator for the stream pointed to by stream
ftell(FILE *stream)
//Helps figure out the size of the file
```

Printing to terminal, reading from terminal
- In unix, printing to terminal and reading from is done with file I/O

Standard streams
- Preconnected input and output channels between computer program and environment
- Three standard streams
	- stdin (standard input)
	- stdout (standard output)
	- stderr (standard error)
- printf() goes to stdout

Buffering and printf
- printf is buffered
- printf puts string in buffer
- other things happen
- Buffer eventually is printed
- Solutions
	- fflush()
	- fprintf(stdder)
	- Always flushed

Unix shell maipulation
- ">" redirect output of program to file
- Ex
	- Is > output
	- echo "this is a file " > output
	- cat file1 file2 > file3

Fork and pipe c funcitons
- Fork 
	- Duplicates current program into a separate instance
		- Two running programs
		- Only differentiated by return value of fork (which is original and which is new)
- Pipe
	- Mechanism for connecting file descriptors between two forked programs
- Pipes in unix shells
	- Represented with "|"
	- Output of one program becomes input to another

Useful unix commands
- grep
	- Keep lines that match pattern, discard other's that don't match
- sed
	- Replace pattern 1 with pattern 2
- Wildcards
	- **

