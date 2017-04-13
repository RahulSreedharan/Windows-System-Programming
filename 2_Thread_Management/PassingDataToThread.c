   
	//----------------------------------------------------------------------------------------//
	// Program to pass Arguments to the Thread handling function                              //
	//  DWORD WINAPI MyThreadFunction(LPVOID lpram)                                           //
	//----------------------------------------------------------------------------------------//
	
	#include <Windows.h>

	//----------- Structure to pass the parameters to the Thread Function ----------------------//

	typedef struct 
	{
		int Value1;
		int Value2;
	}THREAD_PARAM;

	//-----------------------------------------------------------------------------------------//

	DWORD WINAPI MyThreadFunction(LPVOID lpram);          // Declaration of the ThreadFunction

	void main()
	{

		THREAD_PARAM ThreadParameter;         // Create  structure  "ThreadParameter" of type THREAD_PARAM
		THREAD_PARAM *ptrThreadParameter;	  // Creating a pointer to point to "THREAD_PARAM" structure
		DWORD        dChildThreadID;          // Variable to hold the Child thread's ID
		HANDLE       hChildThreadHandle;      // Variable to hold the Child thread's Handle

		// Filling the Varibles in the ThreadParameter Structure
		ThreadParameter.Value1 = 10;
		ThreadParameter.Value2 = 20;

		ptrThreadParameter = &ThreadParameter; // Making "ptrThreadParameter"  points to "ThreadParameter Structure"
		
		printf("Before Calling Thread Function  MyThreadFunction() ");
		printf("\nThreadParameter.Value1 = %d", ThreadParameter.Value1);
		printf("\nThreadParameter.Value2 = %d", ThreadParameter.Value2);

		//-------------------------------- Create a Child Thread ---------------------------------------------//
		hChildThreadHandle = CreateThread( NULL,				// Default security
										   0,                   // Default stack size
										   MyThreadFunction,    // Pointer to thread function 
										   ptrThreadParameter,  // Pointer to pass the arguments to the thread function 
			                               0,                   // Thread Runs immediately
			                               &dChildThreadID      // Child Thread ID returned by CreateThread() function
										  );

		//--------------------------- Wait for the Child thread to complete execution --------------------------//
		WaitForSingleObject(hChildThreadHandle, INFINITE);

		CloseHandle(hChildThreadHandle);  //Close the handle of the child thread

		//---------------------- Print Results -----------------------//
		printf("\n\nAfter Calling Thread Function  MyThreadFunction() ");
		printf("\nThreadParameter.Value1 = %d", ThreadParameter.Value1);
		printf("\nThreadParameter.Value2 = %d", ThreadParameter.Value2);
		getch();

	}//End of main()

	//----------------------------- Thread Handling Function ------------------------------------//

	DWORD WINAPI MyThreadFunction(LPVOID lThreadParameters)
	{
		Sleep(5000);	//Suspends the thread for 5 seconds
		THREAD_PARAM *localThreadParam;
		Sleep(5000);	//Suspends the thread for 5 seconds
		localThreadParam = lThreadParameters;
		Sleep(5000);	//Suspends the thread for 5 seconds
		localThreadParam->Value1 = 100;
		localThreadParam->Value2 = 200;
		Sleep(5000);	//Suspends the thread for 5 seconds
	}	