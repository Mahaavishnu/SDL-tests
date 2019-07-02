#include <stdio.h>
#include <stdlib.h>
#include "SDL2/include/SDL.h"

int			main(int argc, char *argv[])
{
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Surface *screen = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "SDL_Init Error : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	win = SDL_CreateWindow("Hellow World", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error : %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	screen = SDL_FillRect(ren, NULL, "black");

	SDL_Delay(8000);

	SDL_Quit();

	return EXIT_SUCCESS;
}