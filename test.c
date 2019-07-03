#include <stdio.h>
#include <stdlib.h>
#include "SDL2/include/SDL.h"

int			main(int argc, char *argv[])
{
	SDL_Window *win;
	SDL_Renderer *ren;
	SDL_Surface *screen;
	SDL_Surface *drawing[256][700];
	SDL_Rect position;
	int x, y;

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "SDL_Init Error : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	win = SDL_CreateWindow("Hellow World", 100, 100, 700, 256, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error : %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	/*ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}*/


	screen = SDL_GetWindowSurface(win);
	//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 250, 0, 0));

	for (x = 0; x < 256; x++)
	{
		for (y = 0; y < 700; y++)
		{
			position.x = y;
			position.y = x;
			drawing[x][y] = SDL_CreateRGBSurface(SDL_SWSURFACE, 1, 1, 32, 0, 0, 0, 0);
			SDL_FillRect(drawing[x][y], NULL, SDL_MapRGB(screen->format, x, x, x));
			SDL_BlitSurface(drawing[x][y], NULL, screen, &position);
			SDL_FreeSurface(drawing[x][y]);
		}
		y = 0;
	}
	//position.x = 50;
	//position.y = 50;

	//drawing = SDL_CreateRGBSurface(SDL_SWSURFACE, 100, 100, 32, 0, 0, 0, 0);
	//SDL_FillRect(drawing, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
	//SDL_BlitSurface(drawing, NULL, screen, &position);

	if (SDL_UpdateWindowSurface(win) != 0)
	{
		fprintf(stderr, "SDL_UpdateWindowSurface Error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_Delay(8000);

	SDL_Quit();

	return EXIT_SUCCESS;
}