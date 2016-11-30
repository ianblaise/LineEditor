#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
void insert(int);
void deleteLines(int);
void replace(int);
void moveCurrentLine(int);
void quit(void);

//Global Variables
int currentLine = 0;
string filesPath = "";
ifstream fileIn;
ofstream fileOut;
vector<string> fileData;
vector<string> copyData;

int main()
{
	while (true)
	{
		system("CLS");
		fileData.clear();
		cin.clear();
		int choice = 0;
		cout << "Line Editor\n1)Open Existing\n2)Create New\n3)Exit\nEnter your choice: ";
		if (cin >> choice && choice <= 3 && choice >= 1)
		{
			cin.ignore();
			decisionHandler(choice);
		}
		else
		{
			cout << "error." << endl;
			cin.clear();
			cin.ignore();
		}
	}
	return 0;
}

void writeFile()
{
	fileIn.close();
	fileOut.open(filesPath);
	for (unsigned int i = 0; i < fileData.size(); i++)
	{
		fileOut << fileData[i] << "\n";
	}
	fileOut.close();
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
		cin.get();
		return;
	}
	else
	{
		cout << "File opened successfully!" << endl;
		string line;
		cout << "Would you like to see the file's contents? (Y/N): ";
		char ans;
		bool displayContent = false;
		cin >> ans;
		if (isalpha(ans))
		{
			tolower(ans);
			if (ans == 'y')
				displayContent = true;
		}

		while (getline(fileIn, line))
		{
			if (displayContent)
				cout << line << endl;
			fileData.push_back(line);
			currentLine++;
		}
		filesPath = filePath;
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
		filesPath = fileName;
		showOptions();
	}
	else
	{
		cout << "failed to create " << fileName << ". " << endl;
	}
}

void getNumParam(int &numParam)
{
	cout << "Enter a #: ";
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "Invalid num param. Num Param set to 0." << endl;
		numParam = 0;
	}
	else
	{
		numParam = num;
	}
}

void getStrParam(string &strParam)
{
	cin.ignore();
	cin.clear();

	cout << "enter a string: ";
	string str;
	getline(cin, str);
	strParam = str;
}

void showHelp()
{
	cout << "Help Menu\n\nCommands: Move (m <#>) - This command changes the current line. Where # is the new current line.\n"
		<< "\t\t Insert (i <#>) - This command prompts the user to input text into the file. # represents the number of new lines to insert.\n"
		<< "\t\t Type (t <#>) - This command will display the next # of lines text to the user.\n";
}

void showOptions()
{
	bool waiting = true;
	while (waiting)
	{
		char cmd = ' ';
		int numParam;
		string strParam;
		cout << "(CL: " << currentLine << ") Enter a command (I <#>/T <#>/M <#>): ";
		cin >> cmd;
		tolower(cmd);

		switch (cmd)
		{
		case 'i':
			getNumParam(numParam);
			insert(numParam);
			break;
		case 't':
			getNumParam(numParam);
			type(numParam);
			break;
		case 'm':
			getNumParam(numParam);
			moveCurrentLine(numParam);
			break;
		case 'p':
			paste();
			break;
		case 'l':
			getStrParam(strParam);
			locate(strParam);
			break;
		case 'q':
			waiting = false;
			currentLine = 0;
			writeFile();
			break;
		case 's':
			writeFile();
			break;
		case 'r':
			getNumParam(numParam);
			replace(numParam);
			break;
		case 'd':
			getNumParam(numParam);
			deleteLines(numParam);
			break;
		case 'c':
			getNumParam(numParam);
			copy(numParam);
			break;
		case 'z':
			system("cls");
			break;
		case '?':
			showHelp();
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

// Due 11/15
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
	int counter = 0;
	for (int i = currentLine; i < currentLine + nextLines; i++)
	{
		if (i < static_cast<int>(fileData.size()))
		{
			cout << fileData[i] << endl;
			counter++;
		}
		else
		{
			cout << "end of file." << endl;
			break;
		}
	}
	currentLine += counter;
}

// Due 11/15
/* Find the next occurrence of the string and make the line containing it the
* current line. If string does not occur anywhere in the file after the current line,
* issue a message and don�t change the current line. Then print the current line. */
void locate(string searchString)
{
	auto it = std::find(fileData.begin(), fileData.end(), searchString);
	if (it == fileData.end())
	{
		cout << "Does not exist." << endl;
	} 
	else
	{
		auto index = distance(fileData.begin(), it);
		cout << "Found string at index: " << index << endl;
		currentLine = index;
	}
}

/* Insert # lines into the file following the current line.
* The current line should be the last line entered. */
void insert(int numLines)
{
	cin.clear();
	cin.ignore();

	for (int i = 0; i < numLines; i++)
	{
		string insertLine;
		cout << "Insert a line: ";
		getline(cin, insertLine);
		fileData.insert(fileData.begin() + currentLine, insertLine);
		currentLine++;
	}
}

// Due 11/15
/* Delete the next # lines, including the current one.
* Make the first line follwoing the deleted section the current line. */
void deleteLines(int nextLines)
{
	int counter = 0;
	for (int i = currentLine; i < currentLine + nextLines; i++)
	{
		if (i < static_cast<int>(fileData.size()))
		{
			fileData.erase(fileData.begin() + currentLine + counter);
			counter++;
		}
		else
		{
			cout << "End of file." << endl;
			break;
		}
	}
	currentLine += counter;
	cout << "Delete called!" << endl;
}

// Due 11/15
/* Replace the next # lines, beginning with the current one, with # lines.
* The current line should be the last line entered. */
void replace(int nextLines)
{
	cin.ignore();
	cin.clear();

	int counter = 0;
	for (int i = currentLine; i < currentLine + nextLines; i++)
	{
		if (i < static_cast<int>(fileData.size()))
		{
			string replacementLine;
			fileData.erase(fileData.begin() + currentLine + counter);
			cout << "Replace with: ";
			getline(cin, replacementLine);
			fileData.insert(fileData.begin() + currentLine + counter, replacementLine);
			counter++;
		}
		else
		{
			cout << "End of file." << endl;
			break;
		}
	}
	currentLine += counter;
	cout << "Replace called!" << endl;
}

/* Locate & print the line # lines past the current line.
* Make that the current line. */
void moveCurrentLine(int lineNum)
{
	currentLine = lineNum;
	cout << "Changed current line to " << lineNum << endl;
}

/* Saves the file to disk and quits the editor. */
void quit()
{
	exit(0);
}

/* Copy the next # lines, including the current one, to a temporary storage area.
* The current line should not change. */
void copy(int nextLines)
{
	int counter = 0;
	for(int i = currentLine; i < currentLine + nextLines; i++)
	{
		if (i < static_cast<int>(fileData.size()))
		{
			copyData.insert(copyData.end(), fileData[i]);
			counter++;
		}
		else
		{
			cout << "End of file" << endl;
		}
	}
	for(int a = 0; a < static_cast<int>(copyData.size()); a++)
	{
		cout << "copy data: " << copyData[a] << endl;
	}
	cout << "copied " << nextLines << " lines." << endl;
}

/* Copy the contents of the temporary storage area to a position between the
* current line and the line following the current line.
* The current line should become the last line pasted. */
void paste()
{
	int counter = 0;
	for(string val : copyData)
	{
		fileData.insert(fileData.begin() + counter, val);
		counter++;
	}
	currentLine += counter;
}
