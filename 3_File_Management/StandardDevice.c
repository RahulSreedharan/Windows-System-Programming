
	// Program to write into the standard output

	#include <windows.h>
	#include <stdio.h>
	#include <string.h>
	void main(void)
	{
		HANDLE hStdOut;                                        // Handle for Standard output
		LPSTR  Text = "Hello this is from Standard Output";    // Text to write to Standard output
		DWORD  nNumberOfBytesToWrite = 0;                      
		DWORD  nNumberOfBytesWritten = 0;
		BOOL   Status;

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);              //Get the handle for Standard output
		 
		nNumberOfBytesToWrite = strlen(Text);                   // Find the number of bytes to write 

		Status = WriteFile( hStdOut,
							Text, 
							nNumberOfBytesToWrite, 
							nNumberOfBytesWritten,
							NULL
						   );
		getch();
	}