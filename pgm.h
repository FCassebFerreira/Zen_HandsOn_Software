#ifndef PGM_H_
#define PGM_H_

struct pgmStruct
{
	char magicNumber[3];
	int width;
	int height;
	int tones;
	int **pixels;
};

typedef struct pgmStruct pgm_t;

int pgmCreate(pgm_t **, int, int);
int pgmFree(pgm_t *);
int pgmSave(pgm_t *, char *);

int pgmSetPixel(pgm_t *, int, int, int);

#endif