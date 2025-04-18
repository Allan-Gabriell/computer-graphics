/*
4. Construa uma imagem 100 × 100 usando o formato PPM com fundo preto e escreva o 
   caractere ' T ' no centro da imagem com alto contraste em relação ao fundo da imagem.
*/

#include <stdio.h>

int gerarImagem(int height, int width){
    FILE *img = fopen("questao4.ppm", "w");
    if(img == NULL){
        printf("Houve um erro ao gerar a imagem!");
        return 1;
    }

    int y_center = height / 2;
    int x_center = width / 2;

    int y_top = y_center + 25;
    int y_low = y_center - 25;

    int x_top = x_center + 25;
    int x_low = x_center - 25;

    fprintf(img, "P3\n%d %d\n255\n", width, height);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // Nesse primeiro if eu faço o topo da letra "T"
            if((i == y_low || i == y_low + 1) && j >= x_low && j <= x_top){
                fprintf(img, "102 255 255\n");
                // Nesse segundo if eu faço a parte horizontal da letra "T"
            } else if(i > y_low + 1 && i < y_top && (j == x_center || j == x_center + 1)) {
                fprintf(img, "102 255 255\n");
            } else {
                fprintf(img, "0 0 0\n");
            }
        }
    }
    fclose(img);
    return 0;
}

int main (){
    int width = 100;
    int height = 100;

    gerarImagem(height, width);

    return 0;
}