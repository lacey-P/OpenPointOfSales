#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>


int main (int argc, char **argv){
	fprintf(stdout, "** Starting Open Point Of Sales ** \n");
	fprintf(stdout, "Starting SDL................")
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		fprintf(stdout, "[FAIL - FATAL]\n" );
		fprintf(stderr, "stopping init process - Error Occured\n");
		fprintf(stderr, "ERROR IS AS FOLLOWS: %s\n", SDL_GetError() );
		//attempt to destroy rest of SDL so it doesnt kill the computer
		SDL_Quit();
		return -1;
	}
}