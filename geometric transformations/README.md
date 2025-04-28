# Projeto de Transformações Geométricas 2D e 3D

Este projeto implementa funções em C para realizar diversas transformações geométricas em espaços bidimensionais (2D) e tridimensionais (3D). O objetivo é fornecer uma biblioteca simples e reutilizável para manipulação de pontos e vetores, incluindo operações básicas como cálculo de vetores, norma (magnitude), deslocamento de pontos, soma e subtração de vetores, multiplicação por escalar, normalização (vetor unitário) e o conceito de produto vetorial.

## Funcionalidades Implementadas

### Vetores
- **Cálculo de Vetor:** Determina o vetor entre dois pontos em 2D e 3D.
- **Norma (Magnitude):** Calcula a magnitude de um vetor em 2D e 3D.
- **Soma de Vetores:** Soma dois vetores em 2D e 3D.
- **Subtração de Vetores:** Subtrai um vetor de outro em 2D e 3D.
- **Multiplicação por Escalar:** Multiplica um vetor por um valor escalar em 2D e 3D.
- **Vetor Unitário (Normalização):** Calcula o vetor unitário (com magnitude 1) a partir de um vetor em 2D e 3D.

### Pontos
- **Deslocamento de Ponto:** Desloca um ponto 2D ou 3D por um determinado vetor (adição ou subtração).

### Produto Vetorial
- **Produto Vetorial 2D (Escalar):** Calcula um valor escalar que representa a área orientada do paralelogramo formado por dois vetores 2D. Um resultado zero indica que os vetores são paralelos.
- **Produto Vetorial 2D (Vetor 3D):** Calcula o produto vetorial de dois vetores 2D elevando-os ao plano 3D (componente Z = 0). O resultado é um vetor 3D com componentes X e Y nulos, e o componente Z sendo o valor escalar do "produto vetorial" 2D. Um vetor nulo resultante indica paralelismo.
- **Produto Vetorial 3D:** Calcula o produto vetorial de dois vetores 3D, resultando em um terceiro vetor ortogonal aos dois primeiros. Um vetor nulo resultante indica paralelismo.

## Organização do Projeto

O projeto segue uma estrutura básica para organização de código em C:

- **`include/`**: Contém os arquivos de cabeçalho (`.h`) que declaram as estruturas de dados (`Point2D`, `Point3D`) e as funções implementadas.
- **`src/`**: Contém os arquivos de código fonte (`.c`) que implementam as funções declaradas nos arquivos de cabeçalho.

## Como Compilar

Para compilar o projeto (assumindo que você tenha o GCC instalado), navegue até a raiz do projeto no seu terminal e execute o seguinte comando:

```bash
gcc -c src/functions.c -o functions.o
gcc -c src/main.c -o main.o
gcc functions.o main.o -o geometric_transformation -lm
./geometric_transformation