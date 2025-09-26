#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <cmath>

// Variáveis de transformação
float scale = 1.0f;
float angle = 0.0f;
float posX = 0.0f;
float posY = 0.0f;

// Limites para não sair da tela
const float LIMIT = 2.5f;

// ----- DESENHO DAS LETRAS -----
void drawLetterR(float x, float y);
void drawLetterA(float x, float y);
void drawLetterF(float x, float y);
void drawLetterE(float x, float y);
void drawLetterL(float x, float y);

// Desenha o nome "RAFAEL"
void drawName() {
    float spacing = 0.8f;
    drawLetterR(-2.0f * spacing, 0.0f);
    drawLetterA(-1.2f * spacing, 0.0f);
    drawLetterF(-0.4f * spacing, 0.0f);
    drawLetterA( 0.4f * spacing, 0.0f);
    drawLetterE( 1.2f * spacing, 0.0f);
    drawLetterL( 2.0f * spacing, 0.0f);
}

// ----- DEFINIÇÃO DAS LETRAS -----

void drawLetterR(float x, float y) {
    glBegin(GL_LINES);
        glVertex2f(x, y - 0.5f); glVertex2f(x, y + 0.5f);     // linha vertical esquerda
        glVertex2f(x, y + 0.5f); glVertex2f(x + 0.2f, y + 0.5f); // topo horizontal
        glVertex2f(x + 0.2f, y + 0.5f); glVertex2f(x + 0.2f, y); // linha vertical meio
        glVertex2f(x + 0.2f, y); glVertex2f(x, y);             // meio horizontal
        glVertex2f(x, y); glVertex2f(x + 0.25f, y - 0.5f);     // perna diagonal
    glEnd();
}

void drawLetterA(float x, float y) {
    glBegin(GL_LINES);
        glVertex2f(x - 0.2f, y - 0.5f); glVertex2f(x, y + 0.5f);
        glVertex2f(x, y + 0.5f); glVertex2f(x + 0.2f, y - 0.5f);
        glVertex2f(x - 0.1f, y); glVertex2f(x + 0.1f, y);
    glEnd();
}

void drawLetterF(float x, float y) {
    glBegin(GL_LINES);
        glVertex2f(x, y - 0.5f); glVertex2f(x, y + 0.5f);     // linha vertical
        glVertex2f(x, y + 0.5f); glVertex2f(x + 0.25f, y + 0.5f); // topo
        glVertex2f(x, y); glVertex2f(x + 0.2f, y);           // meio
    glEnd();
}

void drawLetterE(float x, float y) {
    glBegin(GL_LINES);
        glVertex2f(x + 0.2f, y + 0.5f); glVertex2f(x - 0.2f, y + 0.5f); // topo
        glVertex2f(x - 0.2f, y + 0.5f); glVertex2f(x - 0.2f, y - 0.5f); // vertical
        glVertex2f(x - 0.2f, y); glVertex2f(x + 0.15f, y);             // meio
        glVertex2f(x - 0.2f, y - 0.5f); glVertex2f(x + 0.2f, y - 0.5f); // base
    glEnd();
}

void drawLetterL(float x, float y) {
    glBegin(GL_LINES);
        glVertex2f(x, y + 0.5f); glVertex2f(x, y - 0.5f);       // vertical
        glVertex2f(x, y - 0.5f); glVertex2f(x + 0.25f, y - 0.5f); // base
    glEnd();
}

// ----- OPENGL FUNÇÕES -----

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Aplica transformações
    glTranslatef(posX, posY, 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(scale, scale, 1);

    glColor3f(0.2f, 0.2f, 1.0f); // Azul escuro
    drawName();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (aspect >= 1.0f)
        glOrtho(-LIMIT * aspect, LIMIT * aspect, -LIMIT, LIMIT, -1.0, 1.0);
    else
        glOrtho(-LIMIT, LIMIT, -LIMIT / aspect, LIMIT / aspect, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
        case 'q':
            exit(0);
            break;
        case '+':
            scale += 0.1f;
            break;
        case '-':
            if (scale > 0.2f) scale -= 0.1f;
            break;
        case 'a':
            if (posX - 0.2f > -LIMIT) posX -= 0.1f;
            break;
        case 'd':
            if (posX + 0.2f < LIMIT) posX += 0.1f;
            break;
        case 'w':
            if (posY + 0.2f < LIMIT) posY += 0.1f;
            break;
        case 's':
            if (posY - 0.2f > -LIMIT) posY -= 0.1f;
            break;
        case 'e':
            angle -= 5.0f;
            break;
        case 'g':
            angle += 5.0f;
            break;
    }

    glutPostRedisplay();
}

void init() {
    glClearColor(0.47, 0.53,0.42, 0.42);  // fundo branco
    glColor3f(0, 0, 0);        // cor padrão
    glLineWidth(3.0f);         // espessura
    glEnable(GL_LINE_SMOOTH);  // suavizar linhas
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Transformacoes Afins - Rafael");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
