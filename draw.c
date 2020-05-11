#include <stdio.h>
#include <math.h>
#include "constants.h"
#include "pgm.h"
#include "draw.h"



int drawLine(pgm_t *image, int x1, int y1, int x2, int y2, int color){
		if(!image) return ERROR;	
		if(color > MAX_COLOR_VALUE) return ERROR;


int tan, deltax, deltay, j;

		if(x1 > x2)
			deltax = x1 - x2;
		else 
			deltax = x2 - x1;

		if(y1 > y2)
			deltay = y1 - y2;
		else 
			deltay = y2 - y1;

		if(deltax > deltay){
			tan = (float) deltay/deltax;
			if(x1 > x2){
				if(y2 > y1){
					for(j = x2; j < x1; j++)
						pgmSetPixel(image, j, y1 + (int) tan*j, color);
				}
				else 	
					for(j = x2; j < x1; j++)
						pgmSetPixel(image, j, y2 + (int) tan*j, color);
				}
			else {
				if(y2 > y1){
					for(j = x1; j < x2; j++)
						pgmSetPixel(image, j, y1 + (int) tan*j, color);
				}
				else 	
					for(j = x1; j < x2; j++)
						pgmSetPixel(image, j, y2 + (int) tan*j, color);
				}
			}
		

		else if(deltay > deltax){
			tan = (float) deltax/deltay;
			if(y1 > y2){
				if(x2 > x1){
					for(j = y2; j < y1; j++)
						pgmSetPixel(image, j, x1 + (int) tan*j, color);
				}
				else 	
					for(j = y2; j < y1; j++)
						pgmSetPixel(image, j, x2 + (int) tan*j, color);
				}
			else {
				if(x2 > x1){
					for(j = y1; j < y2; j++)
						pgmSetPixel(image, j, x1 + (int) tan*j, color);
				}
				else 	
					for(j = y1; j < y2; j++)
						pgmSetPixel(image, j, x2 + (int) tan*j, color);
				}
		}
		
	

		return SUCCESS;
	};
	


	int drawCircle(pgm_t *image, int x, int y, int radius, int color){ 
		if(!image) return ERROR;
		if(radius < 0) return ERROR;

		int j;

		for(j = x - radius; j < x + radius; j++){
		pgmSetPixel(image, j, y + sqrt(pow(radius, 2) - pow((j - x), 2)), color);
		pgmSetPixel(image, j, y - sqrt(pow(radius, 2) - pow((j - x), 2)), color);
	}
		for(j = y - radius; j < y + radius; j++){
		pgmSetPixel(image, x + sqrt(pow(radius, 2) - pow((j - y), 2)), j, color);
		pgmSetPixel(image, x - sqrt(pow(radius, 2) - pow((j - y), 2)), j, color);
	}

		return SUCCESS;
	};



	int drawDisk(pgm_t *image, int x, int y, int radius, int color){
	if(!image) return ERROR;
 	if(radius < 0) return ERROR;


 	int i, j;

	for(i = x - radius; i < x + radius; i++){
		for(j = y - radius; j < y + radius; j++){
			if((pow(x - i, 2) + pow(y - j, 2)) <= pow(radius, 2))
				pgmSetPixel(image, i, j, color);
		}
	}

	 return SUCCESS;
 };

 




