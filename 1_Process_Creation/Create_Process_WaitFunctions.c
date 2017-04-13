	
	//-----------------------------------------------------------------------------------------------------------------//
	// Creates a new process notepad.exe using CreateProcess() function call                                           //
	// Shows the behaviour of the WaitForSingleObject()  function                                                      //
	//                                                                                                                 //
	//-----------------------------------------------------------------------------------------------------------------//

	#include<stdio.h>
	#include<Windows.h>
	void main(int argc, char *argv[])
	{
		STARTUPINFO			StartUpInfo;		       // A structure governing the window appearence,handles
		PROCESS_INFORMATION ProcInfo;		           // A structure containing the returning Process handles/ID ,Thread handles/ID
		BOOL				bCreateProcStatus;		   // Status of the CreateProcess() call	

		DWORD				dwCurrentProcessID;        // Process ID of the Main Program (Parent Process)
		HANDLE              hCurrentProcessHANDLE;     // Handle to the Main Program (Parent Process)

		

		//------------------- Setting Up STARTUPINFO structure using GetStartupInfo()  ----------------------------------------------------------//

		/*ZeroMemory(&StartUpInfo, sizeof(StartUpInfo));						// Filling the STARTUPINFO with Zero 
		StartUpInfo.cb = sizeof(StartUpInfo);								// .cb represents The size of the structure, in bytes.
		*/
		ZeroMemory(&ProcInfo, sizeof(ProcInfo));							// Clearing up the PROCESS_INFORMATION structure(all zero's)
		

		GetStartupInfo(&StartUpInfo);        


		//------------------- Create a child process using CreateProcess() call --------------------------------------------------------------//

		bCreateProcStatus = CreateProcess(	NULL,	                            // Name of the executable here NULL or can be given as "C:\\Windows\\System32\\cmd.exe",
										    argv[1],							// Command Line Arguments (Name of the program to be run here notepad or cmd.exe
										    NULL,								// Security of the Process (NULL = default security)
										    NULL,								// Security of the Thread  (NULL = default security)
											FALSE,								// New Process will not inherit the calling process (inheritable) open handles
											0,									// No creation Flags
											NULL,								// New Process uses Parents Environment
											NULL,								// New Process uses Parents Directory
											&StartUpInfo,						// Pointer to STARTUPINFO	structure
											&ProcInfo							// Pointer to PROCESS_INFORMATION struture
									);

		if (bCreateProcStatus == TRUE)
			{
				printf(" Create Process sucessfull \n Process %s Created", argv[1]);
				
			}
			
		else
			{
				printf(" CreateProcess failed \n Error Number %d", GetLastError());
				getch();
			}
			
		

		printf("\n\n WaitForSingleObject(ProcInfo.hProcess, 3000) called ");
		WaitForSingleObject(ProcInfo.hProcess, 3000);  
		printf("\n\n Control will reach here after 3 Seconds ");
		
		CloseHandle(ProcInfo.hProcess);		// Close the Process
		CloseHandle(ProcInfo.hThread);      // Close the thread
		printf("\n\n Process and thread handle of %s closed ", argv[1]);
		printf("\n\n %s still running after the handles are closed", argv[1]);

		
		getch();

	}