#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <cstdio>

void draw_arc()
{
    glClearColor(.0, .0, .0, .0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);

    for (int i = 0; i < 5; i++)
    {
        float theta = 15.0f * 3.01415926f;
        float x = tan(theta) * sin(theta);
        float y = cos(theta);

        glColor3f  (0.20, 0.60, 0.20); glVertex3f(x + 100, y + 105, x + y);
    }
    glEnd();
}

int main(int argc, char **argv)
{
    try {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("i suck");
        glutDisplayFunc(draw_arc);
        glutMainLoop();
        return 0;
    } catch (int) {
        return 1; /// if failed, unnessary thing, as I'm dumb I just put it there
    }
}
