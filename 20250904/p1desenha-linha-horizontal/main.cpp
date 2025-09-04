/*
 * by: Rafael
 * proj. p1desenha-linha-horizontal
 */


#include <GL/glut.h>
#include <stdlib.h>

static void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    //definir a matrix de transformação que quer mudar, define a matriz de transformação da camera
    glMatrixMode(GL_PROJECTION);
    // seta a matriz identidade para a camera
    glLoadIdentity();

    gluOrtho2D(-3, 3, -3, 3); //define a Area de enquadramento da cena

    // define a matriz de transformação dos modelos (triangulo, esferas)
    glMatrixMode(GL_MODELVIEW);
    //seta a matriz de identidade para os modelos'
    glLoadIdentity();


    glLineWidth(2);//mudar o tamanho da linha
    glBegin(GL_LINES);
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glEnd();


    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2f(-2.0f, -2.0f);
        glVertex2f(2.0f, -2.0f);
        glColor3f(0.4,0,0);
        glVertex2f(0.0f, 2.0f);
    glEnd();

    glFlush();
}

int main (int argc, char *argv[])

{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode (GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    glClearColor(0.4, 0, 4, 0);
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
