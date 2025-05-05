# Projeto de Computação Gráfica: Desenho de uma Casa Rotacionada e Escalável

Este projeto em C demonstra os conceitos básicos de computação gráfica para desenhar uma casa simples, com funcionalidades de rotação e escalonamento. A imagem gerada é salva no formato PPM (Portable Pixmap).

## Conteúdo do Código

O código `casaRotacionada.c` implementa as seguintes funcionalidades:

-   **`setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)`:** Define a cor de um pixel específico nas coordenadas (x, y) da imagem. A coordenada y é invertida para corresponder ao sistema de coordenadas da imagem (origem no canto superior esquerdo).
-   **`clearImg()`:** Preenche toda a imagem com a cor branca (RGB: 255, 255, 255), limpando o conteúdo anterior.
-   **`saveIMg()`:** Salva o conteúdo do array `img` em um arquivo chamado `casaRotacionada.ppm`. O formato PPM é um formato de imagem simples baseado em texto.
-   **`rotatePoint(int x, int y, int cx, int cy, float angle, int* rx, int* ry)`:** Rotaciona um ponto (x, y) em torno de um centro (cx, cy) por um determinado ângulo (em graus). As novas coordenadas rotacionadas são armazenadas em `rx` e `ry`. A conversão de graus para radianos é realizada internamente.
-   **`drawLineRotated(int x1, int y1, int x2, int y2, int cx, int cy, int escalar, float angle, unsigned char r, unsigned char g, unsigned char b)`:** Desenha uma linha entre dois pontos (x1, y1) e (x2, y2) após aplicar uma rotação em torno de um centro (cx, cy) e um fator de escala. A rotação é aplicada a cada ponto antes de desenhar a linha. A linha é desenhada utilizando interpolação linear entre os pontos rotacionados e escalados.
-   **`main()`:** Função principal que:
    -   Limpa a imagem.
    -   Define a cor azul e preta.
    -   Define o centro de rotação da casa (`cx`, `cy`), o ângulo de rotação (inicialmente 360 graus) e o fator de escala.
    -   Utiliza a função `drawLineRotated` para desenhar as diferentes partes da casa: o cubo principal, a porta, o telhado e uma janela. Cada parte é definida por suas coordenadas relativas e desenhada com a rotação e escala aplicadas.
    -   Salva a imagem gerada.

## Como Compilar e Executar

Para compilar e executar o código, você precisará de um compilador C (como GCC) instalado em seu sistema.

1.  **Salvar o código:** Salve o código em um arquivo chamado `casaRotacionada.c`.
2.  **Compilar:** Abra um terminal ou prompt de comando e navegue até o diretório onde você salvou o arquivo. Execute o seguinte comando para compilar o código:

    ```bash
    gcc -o casaRotacionada casaRotacionada.c -lm
    ```

    O flag `-lm` é necessário para linkar a biblioteca matemática (`math.h`), que contém as funções `cos` e `sin`.
3.  **Executar e Salvar a Imagem:** Após a compilação bem-sucedida, execute o programa e redirecione a saída para um arquivo PPM com o seguinte comando:

    ```bash
    ./casaRotacionada > casaRotacionada.ppm
    ```

    Isso criará um arquivo chamado `casaRotacionada.ppm` no mesmo diretório.

## Observações

-   O centro de rotação (`cx`, `cy`) define o ponto em torno do qual a casa será rotacionada.
-   O ângulo de rotação (`angle`) está em graus. No código, ele está definido como 360 graus, o que significa que a casa será desenhada em sua orientação original após uma rotação completa. Você pode alterar esse valor para visualizar a casa em diferentes ângulos.
-   O fator de escala (`escalar`) permite aumentar ou diminuir o tamanho da casa proporcionalmente.
-   A função `drawLineRotated` interpola entre os pontos para desenhar a linha, resultando em uma representação visual da linha rotacionada e escalada.
-   O formato PPM é um formato simples, o que facilita a geração da imagem diretamente a partir dos dados dos pixels.

Este projeto serve como uma introdução prática aos conceitos de transformação geométrica (rotação e escala) em computação gráfica, utilizando uma abordagem de rasterização simples para desenhar primitivas (linhas) em uma imagem.