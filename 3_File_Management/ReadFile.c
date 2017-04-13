	
	//--------------------------------------------------------------------------------------//
	// A simple program to read a file and write its contents to standard output (Console)  //
	//--------------------------------------------------------------------------------------//
	
	#include <windows.h>
	#include <stdio.h>
	#include <string.h>
	void main(void)
	{
		HANDLE hFile;                       // Handle to the File 
		HANDLE hStdDev;                     // Handle to Standard Device
		LPSTR  FileName = "ReadFile.txt";   // Name of the file to open
		char   FileBuffer[1];               // Buffer to store the characters ReadFile() stores
		
		DWORD  nNumberOfBytesRead    = 0;     
		DWORD  nNumberOfBytesWritten = 0;

		// Using CreateFile(); to get the handle of the file to read
		hFile = CreateFile( FileName,					// Name of the File to be opened 
			                GENERIC_READ,			    // Open for reading only
							0,							// No Sharing
 							NULL,						// No security
							OPEN_EXISTING,				// open the existing file do not create new one 
							FILE_ATTRIBUTE_READONLY,    // Open file as readonly
							NULL);

		if (hFile == INVALID_HANDLE_VALUE)              // Check for ERROR's
			printf("ERROR %x in opening File -> \" %s \" \n", GetLastError(), FileName);
		else
			printf("File \" %s\" Successfully Opened \n\n",FileName);

		// Using GetStdHandle(DWORD nStdHandle) to get the handle of the standard output device (Windows Console)
		hStdDev = GetStdHandle(STD_OUTPUT_HANDLE);
		
		//On reaching EOF, ReadFile() = True &&  nNumberOfBytesRead = 0
		while ((ReadFile( hFile,                     // Handle to the file to read 
			              FileBuffer,                // used to store the bytes read
			              1,                         // Size of the buffer,1 byte will be read in a single ReadFile() operation
			              &nNumberOfBytesRead,       // Pointer to the number of bytes read
			              NULL)                      // pointer to overlapped structure,here NULL(synchronous I/O)
						  && nNumberOfBytesRead) > 0)
		       {   //Write to STDOUT till EOF is reached
		          	WriteFile( hStdDev,                 // Handle to the standard output (console)
				               FileBuffer,              // Data in the file buffer will be written to staandard output
				               1,                       // 1 byte will be written at a time 
				               &nNumberOfBytesWritten,  // Pointer to the number of bytes written to standard out
				               NULL);                   // pointer to overlapped structure,here NULL(synchronous I/O)

					if (nNumberOfBytesRead != nNumberOfBytesWritten) //Check for errors if dataread != datawritten
						printf("Error in Writing/Reading Data");
		       }

			 

		

		CloseHandle(hFile);   // Close the file handle hFile
		CloseHandle(hStdDev); // Close the handle to the Standard Device 

		getch();
	}

