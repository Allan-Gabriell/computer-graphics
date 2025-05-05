#include <stdio.h>
#include <math.h>

#define h 500
#define w 500
#define M_PI 3.14159265358979323846

unsigned char img[h][w][3];

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    int newY = h - 1 - y;
    if (x >= 0 && x < w && newY >= 0 && newY < h){
        img[newY][x][0] = r;
        img[newY][x][1] = g;
        img[newY][x][2] = b;
    }
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
    FILE *imagem = fopen("casaRotacionada.ppm", "w");
    if(imagem == NULL){
        printf("Infelizmente houve um erro ao gerar a imagem!");
        return;
    }

    fprintf(imagem, "P3\n%d %d\n255\n", h, w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int c = 0; c < 3; c++){
                fprintf(imagem, "%d ", img[i][j][c]);
            }
            fprintf(imagem, "\n");
        }
    }

    fclose(imagem);
}

void rotatePoint(int x, int y, int cx, int cy, float angle, int* rx, int* ry) {
    float rad = angle * M_PI / 180.0;

    float dx = x - cx;
    float dy = y - cy;

    *rx = (int)(cx + dx * cos(rad) - dy * sin(rad));
    *ry = (int)(cy + dx * sin(rad) + dy * cos(rad));
}

// Minha ideia para fazer com que a casa possa expandir de forma proporcional é fazer a multiplicação de vetor por
// escalar, modificando a função drawLineRotated

void drawLineRotated(int x1, int y1, int x2, int y2, int cx, int cy, int escalar, float angle, unsigned char r, unsigned char g, unsigned char b){
    int rx1, ry1, rx2, ry2;
    rotatePoint((x1 * escalar), (y1 * escalar), cx, cy, angle, &rx1, &ry1);
    rotatePoint((x2 * escalar), (y2 * escalar), cx, cy, angle, &rx2, &ry2);

    for(float t = 0.0; t <= 1.0; t += 0.0001){
        int x = (int)((rx2 - rx1) * t + rx1);
        int y = (int)((ry2 - ry1) * t + ry1);

        setPixel(x, y, r, g, b);
    }
}

int main(){
    clearImg();

    unsigned char blue = 255;
    unsigned char black = 0;
    int cx = 75, cy = 75; // centro da casa
    float angle = 360.0;
    int escalar = 3;

    // cubo da casa
    drawLineRotated(0, 0, 150, 0, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(0, 0, 0, 90, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(150, 0, 150, 90, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(0, 90, 150, 90, cx, cy, escalar, angle, black, black, blue);

    // porta da casa
    drawLineRotated(20, 0, 20, 60, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(60, 0, 60, 60, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(20, 60, 60, 60, cx, cy, escalar, angle, black, black, blue);

    // telhado da casa
    drawLineRotated(0, 90, 75, 150, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(150, 90, 75, 150, cx, cy, escalar, angle, black, black, blue);

    // janela
    drawLineRotated(90, 20, 130, 20, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(90, 20, 90, 60, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(130, 20, 130, 60, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(90, 60, 130, 60, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(90, 40, 130, 40, cx, cy, escalar, angle, black, black, blue);
    drawLineRotated(110, 20, 110, 60, cx, cy, escalar, angle, black, black, blue);

    saveIMg();

    return 0;
}
