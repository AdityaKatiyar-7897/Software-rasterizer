#include <stdio.h>
#include <SDL2/SDL.h>

void set_pixel(Uint32 *pixels, int x , int y , Uint32 color)
{
	
	int index = y * 800 + x ;
	pixels[index] = color;
	
}

void draw_line(Uint32 *pixels , int x0 , int y0 , int x1 , int y1 , Uint32 color)
{
	    float y = y0;
	    
		for (int i = x0; i <=x1; i++){
	    	set_pixel(pixels, i, (int)y, color);
			y = y + ((float)(y1-y0)/(float)(x1-x0));
			}
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

	draw_line(pixels, 400, 100, 700, 500, 0xFFFFFFFF);
	draw_line(pixels, 700, 500, 100, 500, 0xFFFFFFFF);
	draw_line(pixels, 100, 500, 400, 100, 0xFFFFFFFF);
	
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



