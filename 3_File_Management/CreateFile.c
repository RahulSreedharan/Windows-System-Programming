// Program to demonstrate the CreateFile() function

#include<windows.h>
#include<stdio.h>
void main()
{
	LPSTR   *FileName = "MyFirstWindowsFile.c";
	HANDLE   hFile;
	BOOL     Status;
	
	printf("Creating a file of the name %s \n", FileName);
	 
	hFile = CreateFile(FileName,                     // Name of the file to be created
		               GENERIC_READ | GENERIC_WRITE, // Read / Write
		               0,                            // No Sharing
		               NULL,                         // No Security
		               CREATE_ALWAYS,                // Create the file,Overwrite if it exists
		               FILE_ATTRIBUTE_NORMAL,        // Normal Attributes
		               NULL); 

	if (hFile == INVALID_HANDLE_VALUE)                // Checking for any ERROR's
		printf("ERROR in CreateFile() function %x\n", GetLastError());
	

	Status = CloseHandle(hFile);  //Close the file handle

	if (Status == TRUE)
		printf("File %s Successfully Closed", FileName);

	getch();
}