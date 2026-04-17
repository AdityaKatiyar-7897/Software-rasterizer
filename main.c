#include <stdio.h>
#include <SDL2/SDL.h>

void set_pixel(Uint32 *pixels, int x , int y , Uint32 color)
{
	
	int index = y * 800 + x ;
	pixels[index] = color;
	
}

int main()
{
	 SDL_Init(SDL_INIT_VIDEO);
	 Uint32 pixels[480000] = {0};

	SDL_Window * window = SDL_CreateWindow("Software rasteriser", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 800 , 600 , 0 );

	int running = 1;
	SDL_Event event;

	while(running)
	{

	set_pixel(pixels, 400, 300, 0xFFFFFFFF);
	set_pixel(pixels, 450, 300, 0xFFFFFFFF);
	set_pixel(pixels, 400, 350, 0xFFFFFFFF);
	set_pixel(pixels, 500, 400, 0xFFFFFFFF);
	set_pixel(pixels, 600, 500, 0xFFFFFFFF);

	for (int i = 0 ; i < 100 ; i++){
		set_pixel(pixels, i, 300, 0xFFFFFFFF);
	}
	
	
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(pixels, 800, 600, 32, 3200, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	SDL_Surface* window_surface = SDL_GetWindowSurface(window);
	SDL_BlitSurface(surface, NULL, window_surface, NULL);
	SDL_UpdateWindowSurface(window);

	
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = 0;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

//

