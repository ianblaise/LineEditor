#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Function Prototypes for menu.
void decisionHandler(int);
void showOptions();

//Function Prototypes for file editing.
void substitute(string, string);
void type(int);
void copy(int);
void paste(void);
void locate(string);
void insert();
void deleteLines(int);
void replace(int);
void moveCurrentLine(int);
void quit(void);

//Global Variables
int currentLine = 0;
ifstream fileIn;
ofstream fileOut;
vector<string> fileData;

int main()
{
	while (true) 
	{
		system("CLS");
		fileData.clear();
		int choice = 0;
		cout << "Line Editor\n1)Open Existing\n2)Create New\n3)Exit\nEnter your choice: ";
		cin >> choice;
		cin.ignore();
		while (choice > 3 || choice < 1)
		{
			cout << "invalid choice. try again.\nEnter your choice: ";
			cin >> choice;
			cin.ignore();
		}

		decisionHandler(choice);
	}
	return 0;
}

void openExisting()
{
	cout << "Enter the file's path: ";
	string filePath;
	getline(cin, filePath);
	fileIn.open(filePath);
	if (!fileIn.is_open())
	{
		cout << "Failed to open the file! (" << filePath << ")" << endl;
		return;
	}
	else
	{
		cout << "File opened successfully!" << endl;
		string line;
		while (getline(fileIn, line))
		{
			fileData.push_back(line);
		}
		showOptions();
	}
}

void createNew()
{
	cout << "Enter the name of the file to create: ";
	string fileName;
	getline(cin, fileName);
	if (ifstream(fileName))
	{
		cout << "that file already exists." << endl;
		return;
	}
	fileOut.open(fileName);
	if (fileOut.is_open())
	{
		cout << "created " << fileName << " successfully." << endl;
		fileOut.close();
		fileIn.open(fileName);
		if (!fileIn.is_open())
		{
			cout << "could not open the file.. " << fileName << endl;
			return;
		}

		showOptions();
	}
	else
	{
		cout << "failed to create " << fileName << ". " << endl;
	}
}

void showOptions()
{
	bool waiting = true;
	while (waiting)
	{
		char cmd = ' ';
		cout << "Enter a command (I <#>/T <#>/M <#>): ";
		cin >> cmd;
		tolower(cmd);

		switch (cmd)
		{
			case 'i':
				insert();
				break;
			case 't':
				type(1);
				break;
			case 'm':
				move(1);
				break;
			case 'q':
				waiting = false;
				fileIn.close();
				break;
			default:
				cout << "Unknown command!" << endl;
				break;
		}
	}
}

/* Determines what operation to perform next, based upon user's input. */
void decisionHandler(int choice)
{
	switch (choice)
	{
		case 1:
			openExisting(); //Opens existing file.. starts listening for cmd input.
			break;
		case 2:
			createNew(); //Creates new file.. starts listening for cmd input.
			break;
		case 3:
			quit();
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
	cout << "Substitute called!" << endl;
}

/* Print the contents of the next # lines, including the current one.
* Don�t print blank spaces at the end of a line.
* The current line should be the last typed. */
void type(int nextLines)
{
	cout << "Type called!" << endl;
}

/* Copy the next # lines, including the current one, to a temporary storage area.
* The current line should not change. */
void copy(int nextLines)
{
	cout << "Copy called!" << endl;
}

/* Copy the contents of the temporary storage area to a position between the
* current line and the line following the current line.
* The current line should become the last line pasted. */
void paste()
{
	cout << "Paste called!" << endl;
}

/* Find the next occurrence of the string and make the line containing it the
* current line. If string does not occur anywhere in the file after the current line,
* issue a message and don�t change the current line. Then print the current line. */
void locate(string searchString)
{
	cout << "Locate called!" << endl;
}

/* Insert # lines into the file following the current line.
* The current line should be the last line entered. */
void insert()
{
	cout << "Insert called!" << endl;
}

/* Delete the next # lines, including the current one.
* Make the first line follwoing the deleted section the current line. */
void deleteLines(int nextLines)
{
	cout << "Delete called!" << endl;
}

/* Replace the next # lines, beginning with the current one, with # lines.
* The current line should be the last line entered. */
void replace(int nextLines)
{
	cout << "Replace called!" << endl;
}

/* Locate & print the line # lines past the current line.
* Make that the current line. */
void moveCurrentLine(int line)
{
	cout << "Move called!" << endl;
}

/* Saves the file to disk and quits the editor. */
void quit()
{
	exit(0);
}
