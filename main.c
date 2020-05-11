#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "pgm.h"
#include "draw.h"

int main(){

	pgm_t *image;

	printf("Criando a imagem...\n");
	pgmCreate(&image, 600, 400);

	printf("Desenhando uma linha...\n");
	drawLine(image, 0, 200, 600, 200, 250);

	printf("Desenhando um circulo...\n");
	drawCircle(image, 300, 200, 150 ,120);

	printf("Desenhando um disco...\n");
	drawDisk(image, 300, 200, 60, 200);

	printf("Salvando a imagem...\n");
	pgmSave(image, "my_pgm.pgm");

	printf("Liberando a memoria...\n");
	pgmFree(image);
	
	printf("Funcionou!!!!\n");



	return 0;
}
