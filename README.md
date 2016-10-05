# LineEditor
Line Editor Project for CSCI-40. 

Directions...
Write a simple word processor that will accept text and commands as input. The commands it should respond to are:
Substitute/oldstring/newstring/
Copy #
Locate/string/
Delete #
Move #

Type #
Pastes
Insert #
Replace #
Quit
The file will consist of up to 100 lines. The program should be able to open an existing file or create a new one. It should keep track of where the user is in the file at any time. Each command is followed by a number which indicates the number of line (the current line & those following) upon which the command should act. Each command should operate on the specified line or lines of the file. A detailed explanation of each command follows:
Substitute/oldstring/newstring
Substitute newstring for every occurrence of oldstring in the current line. Issue a message if oldstring does not appear in the current line. Print the changed line.
Type #
Print the contents of the next # lines, including the current one. Don’t print blank spaces at the end of a line. The current line should be the last typed.
Copy #
Copy the next # lines, including the current one, to a temporary storage area. The current line should not change.
Paste 
Copy the contents of the temporary storage area to a position between the current line and the line following the current line. The current line should become the last line pasted.
Locate/string/
Find the next occurrence of the string and make the line containing it the current line. If string does not occur anywhere in the file after the current line, issue a message and don’t change the current line. Then print the current line.
Insert #
Insert # lines into the file following the current line. The current line should be the last line entered.
Delete #
Delete the next # lines, including the current one. Make the first line follwoing the deleted section the current line.
Replace #
Replace the next # lines, beginning with the current one, with # lines. The current line should be the last line entered.
Move #
Locate & print the line # lines past the current line. Make that the current line. 
Quit
Saves the file to disk and quits the editor.

