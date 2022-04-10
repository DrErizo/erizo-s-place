#include <iostream>
#include <SDL2/SDL.h>
#include <cstdio>

#define WIN_HEIGHT 1000
#define WIN_WIDTH 1000
struct cell_t{
        SDL_Color color;
        int x,y;
        int width,height;
};

SDL_Window* m_window;
SDL_Event m_event;
SDL_Renderer* m_renderer;
bool isRunning = true;
int main(int argc, const char **argv) {
	std::cout << "Initializing...\n" << std::endl;
        if((m_window = SDL_CreateWindow("Erizo's place", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN))){
                printf("Window Initialized\n");
        }
        if((m_renderer = SDL_CreateRenderer(m_window, -1 ,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))){
                printf("Renderer Initialized\n");
        }  

        while(isRunning){
                while(SDL_PollEvent(&m_event)){
                        switch(m_event.type){
                        
                                case SDL_QUIT:
                                        printf("Quitting SDL...\n");
                                        SDL_Quit();
                                        break;
                                case SDL_KEYDOWN:
                                        if(m_event.key.keysym.sym == SDLK_ESCAPE){
                                                printf("Quitting SDL...\n");
                                                SDL_Quit();
                                        }
                                        break; 
                        }
                }
                SDL_RenderPresent(m_renderer);
                SDL_RenderClear(m_renderer);
        }
        return 0;
}
void SDL_Quit(){
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        isRunning = false;
}
