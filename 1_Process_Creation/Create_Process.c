
	//----------------------------------------------------------------------------------------------------------------//
	// A simple Program to create a new process using CreateProcess API                                               //
	// Name of the new process can be given using command line or as the first argument of the CreateProcess()        //
	// Usage                                                                                                          //
    // C:\Create_Process.exe notepad                                                                                  //
    // C:\Create_Process.exe cmd                                                                                      //
    //----------------------------------------------------------------------------------------------------------------//
	#include<stdio.h>
	#include<Windows.h>
	void main(int argc,char *argv[])
	{
		STARTUPINFO			StartUpInfo;		       // A structure governing the window appearence,handles
		PROCESS_INFORMATION ProcInfo;		           // A structure containing the returning Process handles/ID ,Thread handles/ID
		

		//  Setting Up STARTUPINFO structure manually,you can also use GetStartupInfo() 

		ZeroMemory(&StartUpInfo, sizeof(StartUpInfo)); // Filling the STARTUPINFO with Zero 
		StartUpInfo.cb = sizeof(StartUpInfo);          // .cb represents The size of the structure, in bytes.

		ZeroMemory(&ProcInfo, sizeof(ProcInfo));       // Clearing up the PROCESS_INFORMATION structure(all zero's)
		
		
			CreateProcess( NULL,	                            // Name of the executable here NULL or can be given as "C:\\Windows\\System32\\cmd.exe",
				           argv[1],								// Command Line Arguments (Name of the program to be run here notepad or cmd.exe
						   NULL,								// Security of the Process (NULL = default security)
						   NULL,								// Security of the Thread  (NULL = default security)
						   FALSE,								// New Process will not inherit the calling process (inheritable) open handles
						   0,									// No creation Flags
						   NULL,								// New Proess uses Parents Environment
						   NULL,								// New Proess uses Parents Directory
						   &StartUpInfo,						// Pointer to STARTUPINFO	structure
						   &ProcInfo							// Pointer to PROCESS_INFORMATION struture
					     );
		
		
		
		//Wait until the child process exits
		WaitForSingleObject(ProcInfo.hProcess, INFINITE);

		CloseHandle(ProcInfo.hProcess);		// Close the Process
		CloseHandle(ProcInfo.hThread);      // Close the thread




	}