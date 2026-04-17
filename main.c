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

	// answer is linear interpolation , we will move 1 step on x and with every point the y shifts by (250/300) rise over run
    float y = 100.0f;
    
	for (int i = 100; i <=400; i++){
		set_pixel(pixels, i, (int)y, 0xFFFFFFFF);

		y = y + (250.0/300.0);
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

