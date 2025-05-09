#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "model.h"

unsigned char image[HEIGHT][WIDTH][3];

// Essa função serve para pintar um píxel na minha imagem em uma dada posição (X, Y),
// usando uma das cores RGB
void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    //A linha acima me garante que o píxel vai estar dentro do límite da minha imagem
    image[y][x][0] = r;
    image[y][x][1] = g;
    image[y][x][2] = b;
  }
}

// Essa função serve para desenhar uma linha preta entre dois pontos (x0, y0) e (x1, y1)
// faz isso usando interpolação linear
void draw_line(int x0, int y0, int x1, int y1) {
  for (float t = 0.0; t < 1.0; t = t + 0.0001)
    set_pixel((int)x0+(x1-x0)*t, (int)y0+(y1-y0)*t, 0, 0, 0);
}

// Essa função para limpar a minha imagem ou seja ela preenche todos os canais RGB como branco
void clr(){
  for(int i = 0; i < WIDTH; i++)
    for(int j = 0; j < HEIGHT; j++)
      for(int c = 0; c < 3; c++)  // Percorre os 3 canais de cor: R (0), G (1), B (2)
        image[i][j][c] = 255;
}

// Essa é a função responsável por salvare a imagem no formato PPm
void save(){
  printf("P3\n %d \t %d\n 255\n", WIDTH, HEIGHT); // Imprime o cabeçalho
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      for(int c = 0; c < 3; c++){
        printf("%d \t", image[i][j][c]); // Imprime o valor de cada pixel
      }
      printf("\n");
    }
  }
}

// Essa função é responsável por carregar um arquivo do tipo .obj (formato padrão de modelos 3D)
// e carrega os vértices e faces do modelo nas estruturas vertices e faces
int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces,
             int *fcount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char line[512];
    *vcount = 0; //Inicializa os contadores dos vetices e das faces 
    *fcount = 0;

    // fgets - é usada para ler uma linha de texto de um fluxo (como um arquivo ou a entrada padrão) 
    // e armazená-la em um array de caracteres (string)
    while (fgets(line, sizeof(line), file)) { //ler linha por linha 
        // strncmp - é utilizada para comparar, no máximo, um determinado número de caracteres de duas string
        if (strncmp(line, "v ", 2) == 0) { // verifica se começa com v, caso sim é um vértice
            // A função sscanf() lê dados do buffer nos locais que são fornecidos por argument-list. 
            // Cada argumento deve ser um ponteiro para uma variável com um tipo que corresponde a 
            // um especificador de tipo no format-string.
            if (sscanf(line + 2, "%f %f %f", &vertices[*vcount].x, //armazena as três posições do vértice x, y e z
                       &vertices[*vcount].y, &vertices[*vcount].z) == 3) {
                (*vcount)++;
            }
        } else if (strncmp(line, "f ", 2) == 0) { // se começa com f é uma face  (conjunto de índices que formam um polígono)
            Face face = {.n = 0}; // n = 0 quantidade de vertices da face é inicializada
            char *token = strtok(line + 2, " \n"); // Usa strtok para separar os índices de vértices
            while (token && face.n < MAX_FACE_VERTS) {
                int index;
                if (sscanf(token, "%d", &index) == 1) {
                    face.verts[face.n++] = index;
                }
                token = strtok(NULL, " \n");
            }
            faces[(*fcount)++] = face;
        }
    }

    fclose(file);
    return 1;
}

void point_cloud(Vertex *vertices, int *vcount){
    for(int i = 0; i < *vcount; i++){
        Vertex v = vertices[i];
        int x = (int)((v.x + 1.0f) * WIDTH / 2.0f);
        int y = (int)((1.0f - v.y) * HEIGHT / 2.0f );
        set_pixel(x, y, 0, 0, 0);
    }
}

// Essa função é reposnsável converter coordenadas de vértices 3D normalizadas (de -1 a 1) 
// para coordenadas de tela (em pixels) e desenhar uma linha entre eles usando a função draw_line
void resizing( Vertex v0, Vertex v1 ){
  int x0 = (int)((v0.x + 1.0f) * WIDTH / 2.0f); // normalização das minhas coordenadas
  int y0 = (int)((1.0f - v0.y) * HEIGHT / 2.0f);
  int x1 = (int)((v1.x + 1.0f) * WIDTH / 2.0f);
  int y1 = (int)((1.0f - v1.y) * HEIGHT / 2.0f);

  draw_line(x0, y0, x1, y1);
}

// Éssa função é reponsável por desenhar todas as faces de um modelo 3D, 
// conectando seus vértices com linhas na tela — ou seja, renderizando a 
// estrutura do objeto em forma de malha (wireframe).
void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount) {
    for (int i = 0; i < fcount; i++) { // percorre todas as faces
        Face face = faces[i]; // copia a face atual
        for (int j = 0; j < face.n; j++) { // percorre todos os vertices da face
            Vertex v0 = vertices[face.verts[j] - 1];
            Vertex v1 = vertices[face.verts[(j + 1) % face.n] - 1]; 
            // (j + 1) % face.n faz com que, no último vértice, ele conecte de volta ao primeiro (fechando a face).
            resizing(v0, v1); // Converte os vértices para coordenadas de tela e desenha a linha entre eles.
        }
    }
}
