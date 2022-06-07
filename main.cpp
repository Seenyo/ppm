#include <GL/glut.h>

/* 描画 */
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 1.0, 0.0, 0.0);
}


int main(int argc, char **argv) {
    /* 初期化 */
    glutInit(&argc, argv);

    /* ウィンドウの生成 */
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);

    /* OpenGL 初期化ルーチンの呼び出し*/
    init();

    /* 描画ルーチンの設定 */
    glutDisplayFunc(display);

    /* 無限ループ */
    glutMainLoop();
    return 0;
}


