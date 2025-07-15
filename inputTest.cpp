/*
 * Copyright 2020~2025 USBONG
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @company: USBONG
 * @author: SYSON, MICHAEL B.
 * @date created: 20200926
 * @date updated: 20250715; from 20210128
 * @website: http://www.usbong.ph
 *
 * Reference:
 * 1) https://docs.microsoft.com/en-us/windows/win32/inputdev/user-input3
 * last accessed: 20250715; from 20200424
 *
 */

/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <stdio.h>

//added by Mike, 20200928
//note: "static" in C/C++ = "final" in java
static int myWindowWidth=640; //320
static int myWindowHeight=640; //320

enum Keys
{
/*	//edited by Mike, 20210128
	KEY_UP = 0,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_SPACE,
	//edited by Mike, 20201013
	KEY_ENTER,
	//TO-DO: -verify: gamepad
	KEY_A,
	KEY_D,
	KEY_W,
	KEY_S,
*/
	//TO-DO: -verify: gamepad
/*	//edited by Mike, 20210129
	KEY_A = 0,
	KEY_D,
	KEY_W,
	KEY_S,
*/
	KEY_W = 0,
	KEY_S,
	KEY_D,
	KEY_A,
/* //removed by Mike, 20210130
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_SPACE,
	KEY_ENTER,
*/
	KEY_J,
	KEY_L,
	KEY_I,
	KEY_K,
	//added by Mike, 20210111
	KEY_H,
	//added by Mike, 20210121
	KEY_U,

	iNumOfKeyTypes
};

//added by Mike, 20201001
bool pause;

/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Windows Input Test"; 
    RegisterClass (&wc);

    hWnd = CreateWindow (
      "Windows Input Test", "Windows Input Test", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, myWindowWidth, myWindowHeight,
      NULL, NULL, hInstance, NULL);

	//added by Mike, 20201001
    //init stuff for delay
    int skip=0, currSysTime=0,
        timeElapsed,
        idealFrameTime=30;

    pause=0;

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            if (!pause) {
                currSysTime=GetTickCount();
    
                /* OpenGL animation code goes here */
                //myOpenGLCanvas->update();
    
                if (skip > 0)
                   skip = skip-1;
                else {
                	
                	//printf("HALLO!!!");
/*                	
                     //do rendering here 
                     myOpenGLCanvas->render();
                     SwapBuffers (hDC);
*/                    
                     timeElapsed=GetTickCount()-currSysTime;
                     if (timeElapsed>idealFrameTime)
                       skip = (timeElapsed/idealFrameTime) - 1;
                     else 
                       Sleep(idealFrameTime - timeElapsed);
                }
            }
        }
    }

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{
/*
if (wParam!=0) {
printf("wParam: %f",wParam);
}
*/



    switch (message)
    {
	    case WM_CREATE:
	        return 0;
	    case WM_CLOSE:
	        PostQuitMessage (0);
	        return 0;
	
	    case WM_DESTROY:
	        return 0;
/*
	//added by Mike, 20201014
    case WM_CHAR:
        switch (wParam)
        {
           //added by Mike, 20201013
           //reference: 
           //https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
           //last accessed: 20201013
   	       case 0x41: //A key
		        myOpenGLCanvas->keyDown(KEY_A);
                return 0;
		}
		return 0;
*/
	    case WM_KEYDOWN:
	    	//TODO: -test with actual controller
	    	
	    	printf("wParam: %i\n",wParam);

	        switch (wParam)
	        {
		        case VK_ESCAPE:
		            PostQuitMessage(0);
		            return 0;
		        //added by Mike, 20201001
	   	       case VK_LEFT:
			        //printf("DITO!!!");
	                return 0;
	/*	//removed by Mike, 20210130

	   	       case VK_RIGHT:
			        myOpenGLCanvas->keyDown(KEY_RIGHT);
	                return 0;
	   	       case VK_UP:
			        myOpenGLCanvas->keyDown(KEY_UP);
	                return 0;                
	   	       case VK_DOWN:
			        myOpenGLCanvas->keyDown(KEY_DOWN);
	                return 0;     
	   	       case VK_SPACE:
	                myOpenGLCanvas->keyDown(KEY_SPACE);
	                return 0;
	                
	           //added by Mike, 20201013
	           //reference: 
	           //https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	           //last accessed: 20201013
	   	       case 0x41: //A key   	       
	////		        myOpenGLCanvas->keyDown(KEY_A);	        
	                return 0;     
	   	       case 0x44: //D key
	////		        myOpenGLCanvas->keyDown(KEY_D);
	                return 0;
	   	       case 0x57: //W key
	//   	       case 0x41: //W key
	//			case VK_UP:
					//edited by Mike, 20210128
	////		        myOpenGLCanvas->keyDown(KEY_W);
	                return 0;
	   	       case 0x53: //S key
	////		        myOpenGLCanvas->keyDown(KEY_S);
	                return 0;     
	   	       case 0x4A: //J key
			        myOpenGLCanvas->keyDown(KEY_J);
	                return 0;     
	   	       case 0x4C: //L key
			        myOpenGLCanvas->keyDown(KEY_L);
	                return 0;     
	   	       case 0x49: //I key
			        myOpenGLCanvas->keyDown(KEY_I);
	                return 0;     
	   	       case 0x4B: //K key
			        myOpenGLCanvas->keyDown(KEY_K);
	                return 0;     
	   	       case 0x48: //H key
			        myOpenGLCanvas->keyDown(KEY_H);
	                return 0;
			   //added by Mike, 20210121
	   	       case 0x55: //U key
			        myOpenGLCanvas->keyDown(KEY_U);
	                return 0;
	*/
				//removed by Mike, 20201001 
	/*			               
	   	       case 13: //ENTER
	                myOpenGLCanvas->keyDown(KEY_ENTER);
	                return 0;     
	   	       case 80: //P
	   	            if (myOpenGLCanvas->currentState!=TITLE_SCREEN) {
				        if (pause==0) //false
				          pause=1; //make it true
	                    else pause=0;
	                }
	                return 0;     	        
	*/                
	        }
	        return 0;
			//added by Mike, 20201001
	    case WM_KEYUP:
	        switch (wParam)
	        {
	/*	//removed by Mike, 20210130
	       	       case VK_LEFT:
				        myOpenGLCanvas->keyUp(KEY_LEFT);
	                    return 0;
	       	       case VK_RIGHT:
				        myOpenGLCanvas->keyUp(KEY_RIGHT);
	                    return 0;
	       	       case VK_UP:
				        myOpenGLCanvas->keyUp(KEY_UP);
	                    return 0;
	       	       case VK_DOWN:
				        myOpenGLCanvas->keyUp(KEY_DOWN);
	                    return 0;                        
	       	       case VK_SPACE:
				        myOpenGLCanvas->keyUp(KEY_SPACE);
	                    return 0;     
	
		           //added by Mike, 20201013
		           //reference: 
		           //https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		           //last accessed: 20201013
		   	       case 0x41: //A key
				        myOpenGLCanvas->keyUp(KEY_A);
	                    return 0;
		   	       case 0x44: //D key
		   	       		//edited by Mike, 20210128
				        myOpenGLCanvas->keyUp(KEY_D);
	//			        myOpenGLCanvas->keyUp(KEY_RIGHT);
		                return 0;     
		   	       case 0x57: //W key
		   	       		//edited by Mike, 20210128
				        myOpenGLCanvas->keyUp(KEY_W);
	//			        myOpenGLCanvas->keyUp(KEY_UP);
		                return 0;     
		   	       case 0x53: //S key
				        myOpenGLCanvas->keyUp(KEY_S);
	//			        myOpenGLCanvas->keyUp(KEY_DOWN);
		                return 0;     	
		   	       case 0x4A: //J key
				        myOpenGLCanvas->keyUp(KEY_J);
		                return 0;     
		   	       case 0x4C: //L key
				        myOpenGLCanvas->keyUp(KEY_L);
		                return 0;     
		   	       case 0x49: //I key
				        myOpenGLCanvas->keyUp(KEY_I);
		                return 0;     
		   	       case 0x4B: //K key
				        myOpenGLCanvas->keyUp(KEY_K);
		                return 0;
					//added by Mike, 20210111     
		   	       case 0x48: //H key
				        myOpenGLCanvas->keyUp(KEY_H);
		                return 0;
				   //added by Mike, 20210121
		   	       case 0x55: //U key
				        myOpenGLCanvas->keyUp(KEY_U);
		                return 0;
	*/	                
	/*	//removed by Mike, 20210130
	       	       case 13: //ENTER
	                    myOpenGLCanvas->keyUp(KEY_ENTER);
	                    return 0;
	*/                    
	        }
	        return 0;
	    default:
	        return DefWindowProc (hWnd, message, wParam, lParam);
	}
}
