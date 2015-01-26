// SDL_test.cpp : 定义控制台应用程序的入口点。

//SDL2.0基础学习。填充Surface全白色，并弹出Window显示2秒钟。

#include "stdafx.h"

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int _tmain(int argc, _TCHAR* argv[])
{
	//The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL 初始化SDL以前，不能调用任何SDL函数
	//此处，初始化视频子系统。如果有错误，SDL_Init返回-1
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		//SDL_GetError会返回SDL函数产生的最新的错误
    }
	else
    {
        //Create window 如果有错误，SDL_CreateWindow 返回 NULL
        window = SDL_CreateWindow( "SDL Tutorial", //窗口标题 
			                       SDL_WINDOWPOS_UNDEFINED, //窗口在屏幕正中央
								   SDL_WINDOWPOS_UNDEFINED, 
								   SCREEN_WIDTH, 
								   SCREEN_HEIGHT, 
								   SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
		else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

			//你画了一些东西在screen surface上，不意味着你就能看到，还须要render(渲染）才行。
			//你绘画完以后，须要更新window，这样才能显示你画的内容。
			//也就是要调用下面的函数SDL_UpdateWindowSurface
            
            //Update the surface
            SDL_UpdateWindowSurface( window ); //Copy the window surface to the screen

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

	//Destroy window 释放内存
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

