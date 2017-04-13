
	//-----------------------------------------------------------------//	
	// Program to create new threads usung CreateThread() functions    //
	// The newly created threads wait for getch() to exit              //
	// The threads can  be viewed on "Windows Task Manager"            //
	// Total 4 threads - CreateThread.exe(1) + 3 new threads           //
    //-----------------------------------------------------------------//

	#include<Windows.h>

	#define NO_OF_THREADS 3       //No of threads created by the program 

	DWORD WINAPI MyThreadFunction(LPVOID lparameter); //Thread Function Declaration

	// Structure to pass variables to a thread  
	typedef struct
	{
		int val1;
		int val2;
		int val3;

	}ThreadParamStruct;

	void main(void)
		{
			ThreadParamStruct *ThreadParam[NO_OF_THREADS];		// Arrays of structure to pass the parameter to newly created Threads
			DWORD             dwThreadId[NO_OF_THREADS];		// Arrays for storing the ID's of newly created Threads
			HANDLE            hThreadHandle[NO_OF_THREADS];		// Arrays for storing the Handles of newly created Threads

			//-------------------- Loop To Create 3 Threads ----------------------------//

			for (int i = 0; i < NO_OF_THREADS; i++)
				{
					//--------------------------------------------------------------//
					// CreateThread() returns both Thread Handle and Thread ID      //
					// hThreadHandle[i] Contains the Handle of the 'i'th thread     //
					// dwThreadId[i]    Contains the ID of the 'i'th thread         //
				    //--------------------------------------------------------------//

					hThreadHandle[i] = CreateThread( NULL,				// Use default Security Attributes
						                             0,                 // Use defult stacksize usually 1MB
													 MyThreadFunction,	// Pointer to the Thread function()
													 ThreadParam[i],    // Argument passed to the thread function
													 0,                 // Creation Flags - 0 -Thread Runs immediately
													 &dwThreadId[i]     // ID of the created  thread returned by CreateThread() function
												   );
				}
	
			//------------------ Wait for all the threads to exits -----------------------//

			WaitForMultipleObjects( NO_OF_THREADS,		// The total number of threads to wait for
									hThreadHandle,      // Pointer to the array containing the handles of all the threads
									TRUE,               // Return only after all the threads are in signaled state
									INFINITE            // Wait infinitly,no time out
								  );
	
			//---------- Close all the Handles belonging to the created threads ----------//

			for (int i = 0; i < NO_OF_THREADS; i++)
				{
					CloseHandle(hThreadHandle[i]);

				}

		}//End of main() function


	DWORD WINAPI MyThreadFunction(LPVOID lparameter)
		{
			getch();
			return 0;
		}