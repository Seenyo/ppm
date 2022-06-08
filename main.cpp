#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

//フィルムの大きさ
const int g_FilmWidth = 640;
const int g_FilmHeight = 480;
const int pic_size = g_FilmWidth * g_FilmHeight;
const int px_num = pic_size * 12;
//ピクセル毎の情報を入れておく変数 [height][width][1pixel]
float* g_FilmBuffer;
unsigned char image[480][640][12];

int ppm_read(char *filename, unsigned char *pimage) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("ERROR:%s\n", filename);
        exit(-1);
    }
    fscanf(fp, "P3\n640 480\n255\n");
    fread(pimage, sizeof(char), px_num, fp);
    fclose(fp);

    /* 読み込みが正しく行われているかの確認 */
    std::ofstream writing_file;
    std::string op_name;

    op_name = "C:/Users/narus/cg_ppm/re_method2.ppm";

    writing_file.open(op_name, std::ios::out);
    std::string header = "P3\n" + std::to_string(g_FilmWidth) + " " + std::to_string(g_FilmHeight) + "\n" + "255\n";
    writing_file << header << std::endl;

    for (int i = 0; i < px_num; i++) {
        unsigned char pixel = pimage[i];
        writing_file << pixel;
        if(px_num-i==1){
            std::cout << "written";
        }
    }
    writing_file.close();

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
    ppm_read("C:/Users/narus/cg_ppm/method2.ppm", &image[0][0][0]);
}


int main(int argc, char **argv) {
    /* 初期化 */
    glutInit(&argc, argv);

    /* ウィンドウサイズの指定 */
    glutInitWindowSize(g_FilmWidth,g_FilmHeight);

    /* ウィンドウの生成 */
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("PPM Viewer");

    /* 描画ルーチンの設定 */
    glutDisplayFunc(display);

    /* OpenGL 初期化ルーチンの呼び出し*/
    init();

    /* 無限ループ */
    glutMainLoop();
    return 0;
}


