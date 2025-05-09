#ifndef MODEL_H
#define MODEL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_VERTICES 50000 // Número máximo que pode ser lido de um arquivo .obj
#define MAX_FACES 50000 // Define o número máximo de faces (polígonos) que o modelo pode ter.
#define MAX_FACE_VERTS 32 // Define o número máximo de vértices por face

typedef struct {
  float x, y, z;
} Vertex;

typedef struct {
  int verts[MAX_FACE_VERTS]; //Indices dos vértices que formam a face
  int n; // número de vertices da face
} Face;

extern unsigned char image[HEIGHT][WIDTH][3];

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);

void clr();

void save();

void draw_line(int x0, int y0, int x1, int y1);

int load_obj(const char *filename, Vertex *vertices, int *vcount, Face *faces, int *fcount);

void point_cloud(Vertex *vertices, int *vcount);

void resizing( Vertex v0, Vertex v1 );

void render_faces(Vertex *vertices, Face *faces, int vcount, int fcount);


#endif