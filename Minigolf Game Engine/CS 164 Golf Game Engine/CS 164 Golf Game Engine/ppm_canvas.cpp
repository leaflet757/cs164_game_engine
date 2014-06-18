/********
*
*  ppm_canvas.cpp
*
*  Author: Adam Smith
*  Some revisions by John Murray
*  Date of Version: October 8, 2011
*
*********/

#include <stdlib.h>
#include <stdio.h>
#include "ppm_canvas.h"

int ppmLoadCanvas(const char *filename, struct canvas_t *canvas)
{
    FILE *fp;
    int width, height, size,  i;
		pixel_t *buf;

    if ((fopen_s(&fp,filename, "rb")) != 0) {
		 return -1;
    }

    fscanf_s(fp, "P6\n");
    fscanf_s(fp, "#%*[^\n]\n");
    fscanf_s(fp, "%d", &width);
    fscanf_s(fp, "%d", &height);
    fscanf_s(fp, "%*d\n");

    size = width * height;
    canvas->width = width;
    canvas->height = height;
    canvas->pixels = (pixel_t *) malloc(size * sizeof(pixel_t));

    buf = canvas->pixels;
    for (i = 0; i < size; i++, buf++) {
			fread(buf, 1, 3, fp);
    }

    return 0;
}


int ppmSaveCanvas(char *filename, struct canvas_t *canvas)
{
    FILE *fp;
    int width, height, size,  i;
		pixel_t *buf;
    char data[1];

    if ((fopen_s(&fp, filename, "w")) == 0) {
		 return -1;
    }
    
    width = canvas->width;
    height = canvas->height;
    size = width*height;
    fprintf(fp, "P6\n");
    fprintf(fp, "# Comment Line\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    buf = canvas->pixels;
    for (i = 0; i < size; i++, buf++) {
	data[0] = (*buf) & 0xff;
	fwrite(data, 1, 1, fp);
	data[0] = ((*buf) >> 8) & 0xff;
	fwrite(data, 1, 1, fp);
	data[0] = ((*buf) >> 16) & 0xff;
	fwrite(data, 1, 1, fp);
    }

    fclose(fp);
    return 0;
}