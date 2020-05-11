#include "pgm.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int pgmCreate(pgm_t **image, int width, int height){
	if(!image) return ERROR;
	if(width < 0 || width > MAX_IMAGE_SIZE) return ERROR;
	if(height < 0 || height > MAX_IMAGE_SIZE) return ERROR;

	int i, j;

	*image = (pgm_t *)calloc(1, sizeof(pgm_t));
	(*image)->magicNumber[0] = 'P';
	(*image)->magicNumber[1] = '2';
	(*image)->magicNumber[2] = '\0';
	(*image)->width = width;
	(*image)->height = height;
	(*image)->tones = 255;
	(*image)->pixels = (int **)calloc(height, sizeof(int *));
	for(j = 0; j < height; j++)
		(*image)->pixels[j] = (int *)calloc(width, sizeof(int ));
	

	return SUCCESS;
}

int pgmFree(pgm_t *image){
	if(!image) return ERROR;

	int i;

	for(i = 0; i < image->height; i++)
		free(image->pixels[i]);
	free(image->pixels);
	free(image);

	return SUCCESS;
}

int pgmSave(pgm_t *image, char *name){

	if(!image) return ERROR;
	if(!name) return ERROR;
 
	int i, j;
	FILE *file;

	file = fopen(name, "w");
	fprintf(file, "%s\n", image->magicNumber);
	fprintf(file, "%d %d\n", image->width, image->height);
	fprintf(file, "%d\n", image->tones);
	for(i = 0; i < image->height; i++)
		for(j = 0; j < (image->width - 1); j++){
			fprintf(file, "%d ", image->pixels[i][j]);
		}
		if(i == (image->height - 1))
			fprintf(file, "%d", image->pixels[i][j]);
		
		else
			fprintf(file, "%d\n", image->pixels[i][j]);

fclose(file);

	return SUCCESS;
}

int pgmSetPixel(pgm_t *image, int x, int y, int color){
	if(!image) return ERROR;
	if(x < 0 || x > image->width) return ERROR;
	if(y < 0 || y > image->height) return ERROR;
	if(color < 0 || color > MAX_COLOR_VALUE) return ERROR;

	image->pixels[y][x] = color;

	return SUCCESS;
}


	



	