#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function Prototypes
void substitute(string, string);
void type(int);
void copy(int);
void paste(void);
void locate(string);
void insert(int);
void deleteLines(int);
void replace(int);
void move(int);
void quit(void);

//Global Variables
int CurrentLine = 0;
string CopiedString = "";

int main()
{
	return 0;
}

/* Substitute newstring for every occurrence of oldstring in the current line. 
 * Issue a message if oldstring does not appear in the current line. Print the changed line. */
void substitute(string oldString, string newString)
{
}

/* Print the contents of the next # lines, including the current one.
 * Don’t print blank spaces at the end of a line. 
 * The current line should be the last typed. */
void type(int nextLines)
{
}

/* Copy the next # lines, including the current one, to a temporary storage area. 
 * The current line should not change. */
void copy(int nextLines)
{
}

/* Copy the contents of the temporary storage area to a position between the 
 * current line and the line following the current line. 
 * The current line should become the last line pasted. */
void paste()
{
}

/* Find the next occurrence of the string and make the line containing it the 
 * current line. If string does not occur anywhere in the file after the current line, 
 * issue a message and don’t change the current line. Then print the current line. */
void locate(string searchString)
{
}

/* Insert # lines into the file following the current line. 
 * The current line should be the last line entered. */
void insert(int nextLines)
{
}

/* Delete the next # lines, including the current one. 
 * Make the first line follwoing the deleted section the current line. */
void deleteLines(int nextLines)
{
}

/* Replace the next # lines, beginning with the current one, with # lines. 
 * The current line should be the last line entered. */
void replace(int nextLines)
{
}

/* Locate & print the line # lines past the current line.
 * Make that the current line. */
void move(int line)
{
}

/* Saves the file to disk and quits the editor. */
void quit()
{
	exit(0);
}