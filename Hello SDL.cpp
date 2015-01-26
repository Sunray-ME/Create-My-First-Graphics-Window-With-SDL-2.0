// SDL_test.cpp : �������̨Ӧ�ó������ڵ㡣

//SDL2.0����ѧϰ�����Surfaceȫ��ɫ��������Window��ʾ2���ӡ�

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

    //Initialize SDL ��ʼ��SDL��ǰ�����ܵ����κ�SDL����
	//�˴�����ʼ����Ƶ��ϵͳ������д���SDL_Init����-1
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		//SDL_GetError�᷵��SDL�������������µĴ���
    }
	else
    {
        //Create window ����д���SDL_CreateWindow ���� NULL
        window = SDL_CreateWindow( "SDL Tutorial", //���ڱ��� 
			                       SDL_WINDOWPOS_UNDEFINED, //��������Ļ������
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

			//�㻭��һЩ������screen surface�ϣ�����ζ������ܿ���������Ҫrender(��Ⱦ�����С�
			//��滭���Ժ���Ҫ����window������������ʾ�㻭�����ݡ�
			//Ҳ����Ҫ��������ĺ���SDL_UpdateWindowSurface
            
            //Update the surface
            SDL_UpdateWindowSurface( window ); //Copy the window surface to the screen

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

	//Destroy window �ͷ��ڴ�
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

