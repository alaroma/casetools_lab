#include "bmp.h"

/*
 * Преобразует цвета пикселей в черно-белую гамму
 * (30% красного + 59% зеленого + 11% синего)
*/
void bmp_gray(bmp_image image)
{
    unsigned int i, j;
    
    /* Получаем линейные размеры изображения */
    unsigned int w = image.header.width;
    unsigned int h = image.header.height;

    /* Для всех строк пикселей */
    for (i = 0; i < h; i++) {
        /* Для каждого пикселя */
        for(j = 0; j < w; j++) {
            
            /* Получаем компоненты цвета текущего пикселя*/
            double blue = image.pixel_array[0 * h * w + i * w + j];
            double green = image.pixel_array[1 * h * w + i * w + j];
            double red = image.pixel_array[2 * h * w + i * w + j];
            
            /* Преобразуем в черно-белое */
            image.pixel_array[0 * h * w + i * w + j] =
            image.pixel_array[1 * h * w + i * w + j] =
            image.pixel_array[2 * h * w + i * w + j] =
                0.11 * blue + 0.59 * green + 0.30 * red;
        }
    }
}