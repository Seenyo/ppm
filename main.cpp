#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//フィルムの大きさ
const int g_FilmWidth = 640;
const int g_FilmHeight = 480;
const int pic_size = g_FilmWidth * g_FilmHeight;
const int px_num = pic_size * 3;
//ピクセル毎の情報を入れておく変数
unsigned char image[480][640][3];

int ppm_read(char *filename, unsigned char *pimage) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("ERROR:%s\n", filename);
        exit(-1);
    }
    fscanf(fp, "P3\n640 480\n255\n");
    fread(pimage, sizeof(char), px_num, fp);
    for (int i = 0; i < 30; i++) {
        std::cout << pimage[i];
    }
    fclose(fp);
    return 0;
}


/* 描画 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(g_FilmWidth, g_FilmHeight, GL_RGB, GL_UNSIGNED_BYTE, &image[0][0][0]);
    glFlush();
}

void init() {
    glClearColor(0.0, 1.0, 0.0, 1.0);
    ppm_read("C:/Users/narus/ppm/method2.ppm", &image[0][0][0]);
}


int main(int argc, char **argv) {
    /* 初期化 */
    glutInit(&argc, argv);

    /* ウィンドウの生成 */
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("ppm");

    /* 描画ルーチンの設定 */
    glutDisplayFunc(display);

    /* OpenGL 初期化ルーチンの呼び出し*/
    init();

    /* 無限ループ */
    glutMainLoop();
    return 0;
}


