#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

//Function Prototypes for menu.
void decisionHandler(int);

//Function Prototypes for initilization
void openFile(string);
void createFile(string);
void readFile();
void getFileName();

//Function Prototypes for file editing.
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
string FileName = "";
ifstream FileStream;

int main()
{
	int choice = 0;
	cout << "Line Editor\n1)Open Existing\n2)Create New\n3)Exit\nEnter your choice: ";
	cin >> choice;
	if(!isdigit(choice))
	{
		cout << "Invalid choice. Not a number. " << endl;
		return -1;
	}
	while(choice > 3 || choice < 1)
	{
		cout << "invalid choice. try again.\nEnter your choice: ";
		cin >> choice;
	}

	decisionHandler(choice);

	return 0;
}

/* Sets the variable FileName to a user specified value. */
void getFileName()
{
	string fileName = "";
	cout << "Enter the file name: ";
	cin >> fileName;
	
	FileName = fileName;
}
/* Creates a new file with a name specified by the user in the default directory. */
void createFile(string fileName)
{

}

/* Opens a file specified by the user. */
void openFile(string fileName)
{
	FileStream.open(fileName);
	if(!FileStream.is_open())
		cout << "Failed to open the file, does it exist? (" << fileName << ")" << endl;
	FileName = fileName;
	readFile();
}

/* Reads the file data, stores all lines into an array. */
void readFile()
{
	string line = "";
	if(!FileStream.is_open())
		cout << "The file stream is closed, no data to read." << endl;
	while(getline(FileStream,line))
	{
		cout << line << endl;
	}
}

/* Determines what operation to perform next, based upon user's input. */
void decisionHandler(int choice)
{
	switch(choice)
	{
		case 1:
			cout << "Case 1." << endl; // This will open existing file.
			getFileName();
			openFile(FileName);
			readFile();
			break;
		case 2:
			cout << "Case 2." << endl; // This will create a new file.
			break;
		case 3:
			cout << "Case 3." << endl; // This will exit.
			break;
		default:
			cout << "Unexpected choice. (" << choice << ")." << endl; // This should never be executed but jst in case.
			break;
	}
}

/* Substitute newstring for every occurrence of oldstring in the current line. 
 * Issue a message if oldstring does not appear in the current line. Print the changed line. */
void substitute(string oldString, string newString)
{
}

/* Print the contents of the next # lines, including the current one.
 * Don�t print blank spaces at the end of a line. 
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
 * issue a message and don�t change the current line. Then print the current line. */
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
