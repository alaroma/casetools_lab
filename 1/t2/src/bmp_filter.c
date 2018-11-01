#include "bmp.h"
#include <stdlib.h>
#include <stdio.h>

int filter[5][5] = {
    { 0,  0,  1,  0,  0 },
    { 0,  1,  1,  1,  0 },
    { 1,  1,  1,  1,  1 },
    { 0,  1,  1,  1,  0 },
    { 0,  0,  1,  0,  0 }
};

double min(double a, double b) {
    return (a > b) ? b : a;
}

double max(double a, double b) {
    return (a < b) ? b : a;
}

void bmp_filter(bmp_image image)
{
    int i, j, k, id, sum, dx, dy, nx, ny;

    /* Получаем линейные размеры изображения */
    int w = image.header.width;
    int h = image.header.height;
    int size = h * w;
    double new_color, color;

    bmp_pixel_array new_pixel_array = (double*) malloc(3 * size * sizeof(double));

    // number of color
    for (k = 0; k < 3; k++) {
        /* Для всех строк пикселей */
        for (i = 0; i < h; i++) {
            /* Для каждого пикселя */
            for(j = 0; j < w; j++) {
                
                /* Получаем компоненты цвета текущего пикселя*/
               
                sum = 0;
                new_color = 0;
                for (dx = -2; dx <= 2; dx++) {
                    for (dy = -2; dy <= 2; dy++) {
                        nx = min(h - 1, max(0, i + dx));
                        ny = min(w - 1, max(0, j + dy));

                        id = k * h * w + nx * w + ny;
                        
                        color = image.pixel_array[id];
                        sum += (filter[dx + 2][dy + 2] != 0);
                        new_color += color * filter[dx + 2][dy + 2];
                    }
                }
                new_pixel_array[k * h * w + i * w + j] = min(1., max(0., new_color / sum));
            }
        }
    }
    
    for (i = 0; i < 3 * size; i++) {
    
        image.pixel_array[i] = new_pixel_array[i];
    }
    free(new_pixel_array);
}