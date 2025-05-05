#include <stdio.h>
#include <math.h>

#define h 500
#define w 500

unsigned char img[h][w][3];

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    img[x][y][0] = r;
    img[x][y][1] = g;
    img[x][y][2] = b;
}

void clearImg(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int c = 0; c < 3; c++){
                img[i][j][c] = 255;
            }
        }
    }
}

void saveIMg(){
    FILE *imagem = fopen("casa.ppm", "w");
    if(img == NULL){
        printf("Infelizmente houve um erro ao gerar a imagem!");
        return 1;
    }

    fprintf(imagem, "P3\n %d \t %d\n 255\n",h , w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int c = 0; c < 3; c++){
                fprintf(imagem, "%d \t", img[i][j][c]);
            }
            fprintf(imagem, "\n");
        }
    }

    fclose(imagem);
}

void drawLine(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    //t é u valor entre 0 e 1
    for(float t = 0.0; t < 1; t =  t + 0.00001){
        setPixel((int)(x2 - x1)*t + x1, (int)(y2-y1)*t +y1, r, g, b);
    }
}

int main(){
    clearImg();

    // setPixel( (int) h/2, (int) w/2, 255, 0, 0); //faz um ponto no centro
    // drawLine((int) h/2, (int) w/2, h-1, w-1, 255, 0, 0); //gera uma reta

    unsigned char blue = 255;
    unsigned char black = 0;

    // int left = w / 8;
    // int right = w * 7 / 8;
    // int top = h * 3 / 8;
    // int bottom = h * 5 / 8;
    // int roof_peak_y = h * 7 / 8;
    // int roof_peak_x = w / 2;

    // int door_left = w * 2 / 8;
    // int door_right = w * 3 / 8;
    // int door_top = h * 3 / 8;
    // int door_bottom = h * 4 / 8;

    // drawLine(left, top, right, top, black, black, blue);  
    // drawLine(left, bottom, right, bottom, black, black, blue); 
    // drawLine(left, top, left, bottom, black, black, blue);  
    // drawLine(right, top, right, bottom, black, black, blue);

    // drawLine(left, bottom, roof_peak_x, roof_peak_y, black, black, blue);
    // drawLine(right, bottom, roof_peak_x, roof_peak_y, black, black, blue);

    // drawLine(door_left, door_top, door_left, door_bottom, black, black, blue);
    // drawLine(door_right, door_top, door_right, door_bottom, black, black, blue); 
    // drawLine(door_left, door_top, door_right, door_top, black, black, blue);
    // drawLine(door_left, door_bottom, door_right, door_bottom, black, black, blue);

    //cubo da casa
    drawLine(0, 0, 150, 0, black, black, blue);
    drawLine(0, 0, 0, 90, black, black, blue);
    drawLine(150, 0, 150, 90, black, black, blue);
    drawLine(0, 90, 150, 90, black, black, blue);

    //porta da casa
    drawLine(20, 0, 20, 60, black, black, blue);
    drawLine(60, 0, 60, 60, black, black, blue);
    drawLine(20, 60, 60, 60, black, black, blue);

    //telhado da casa
    drawLine(0, 90, 75, 150, black, black, blue);
    drawLine(150, 90, 75, 150, black, black, blue);

    //janela 
    drawLine(90, 20, 130, 20, black, black, blue);
    drawLine(90, 20, 90, 60, black, black, blue);
    drawLine(130, 20, 130, 60, black, black, blue);
    drawLine(90, 60, 130, 60, black, black, blue);
    drawLine(90, 40, 130, 40, black, black, blue);
    drawLine(110, 20, 110, 60, black, black, blue);

    saveIMg();

    return 0;
}