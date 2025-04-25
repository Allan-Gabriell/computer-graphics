/*
1. Construa uma imagem 100 × 100 usando o formato PPM com fundo preto que tem apenas 1 pixel 
   vermelho no centro da imagem.
*/

#include <stdio.h>

int gerarImagem(int width, int height){
  FILE *img = fopen("questao1.ppm", "w");
  if(img == NULL){
    printf("Infelizmente houve um erro ao gerar a imagem!");
    return 1;
  }

  int y_center = width/2;
  int x_center = height/2;
 
  fprintf(img, "P3\n %d \t %d\n 255\n", width, height);

  for (int i = 0; i < height; i++){ 
    for (int j = 0; j < width; j++){
      fprintf(img, "%d \t %d \t %d \n", 255, 255, 255);
      if(i == y_center && j == x_center) {
        fprintf(img, "%d \t %d \t %d \n", 255, 0, 0);
      }
    }
  }
  return 0;
}

int main(){
  int width = 5;
  int height = 5;

  gerarImagem(width, height);

  return 0;
}