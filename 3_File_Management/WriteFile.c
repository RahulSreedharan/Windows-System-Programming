
	// A Small program to illustrate the WriteFile() function

	#include <Windows.h>
	#include <string.h>
	#include <stdio.h>

	void main(void)
	{
		HANDLE hFile ;
		LPSTR  FileName   = "WindowsTextFile.txt";
		LPSTR  FileBuffer = "Hello this file is written using Windows WriteFile() function";
		DWORD  NoOfBytesWritten = 0;
		DWORD  NoOfBytesToWrite = 0;
		BOOL   Status;
		
		hFile = CreateFile( FileName,                        // Name of the file to be created 
							GENERIC_READ | GENERIC_WRITE,    // Read/Write Access
							0,                               // No Sharing
							NULL,                            // No Security
							CREATE_ALWAYS,                   // Create file,OverWrite if it exists
							FILE_ATTRIBUTE_NORMAL,           // Apply thee Normal attributes
							NULL                     
						  );
		printf("%s File created \n", FileName);

		if (hFile == INVALID_HANDLE_VALUE)                   // Error Checking for CreateFile() 
			printf("ERROR in opening %s", FileName);

		NoOfBytesToWrite = strlen(FileBuffer);               //Calculating the NoOfBytesToWrite

		Status = WriteFile( hFile,                           // Handle to the File(WindowsTextFile.txt) to write the data
							FileBuffer,                      // Pointer which points to the string to be written to the file
							NoOfBytesToWrite,                // No of Bytes to be written
							&NoOfBytesWritten,               // pointer to the varible NoOfBytesWritten
							NULL                             // Points to OVERLAPPED structure ,NULL for thetime being 
			               );

		if (Status == TRUE)                                  // WriteFile() returns TRUE if Successfull
		{
			printf("Data successfully written to File\n");
			printf("%d Bytes of data written to File\" %s\"\n", NoOfBytesWritten, FileName);
		}
		else if (Status == FALSE)
			printf("%x ERROR", GetLastError());

		CloseHandle(hFile);                                  //Close the handle to the file 

		getch();
	}