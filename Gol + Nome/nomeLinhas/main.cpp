#include<GL/freeglut.h>
#include<iostream>

GLfloat escala = 1, deslocax = 0, deslocay = 0, rotacaoy = 0;
GLfloat escalaMinima = 0.5f;

void inicializacao(void);

void listeningkey(unsigned char tecla, GLint x, GLint y)
{

    switch(tecla)
    {
    case '+':
        escala += 0.5f;
        break;
    case '-':
        escala -= 0.5f;
        if (escala < escalaMinima){
            escala = escalaMinima;
        }
        break;
    case 'a':
        deslocax -= 0.2f;
        break;
    case 'd':
        deslocax += 0.2f;
        break;
    case 's':
        deslocay -= 0.2f;
        break;
    case 'w':
        deslocay += 0.2f;
        break;
    case 'q':
        rotacaoy += 4;
        break;
    case 'e':
        rotacaoy -= 4;
        break;
    }
    inicializacao();
}

void desenhaLinha(void)
{

    glLineWidth(8);
    glBegin (GL_LINES);

    glVertex2f(-2,2);
    glVertex2f(-2,-2);

    glVertex2f(-2,2);
    glVertex2f(-1,-2);

    glVertex2f(-1,-2);
    glVertex2f(-1,2); // Letra N

    glVertex2f(1,2);
    glVertex2f(0,-2);

    glVertex2f(1,2);
    glVertex2f(2,-2);

    glVertex2f(0,0);
    glVertex2f(2,0); // Letra A

    glVertex2f(3,2);
    glVertex2f(3,-2);

    glVertex2f(2,2);
    glVertex2f(4,2); // Letra T

    glVertex2f(5,2);
    glVertex2f(5,-2);

    glVertex2f(5,2);
    glVertex2f(6,2);

    glVertex2f(5,0);
    glVertex2f(6,0);

    glVertex2f(5,-2);
    glVertex2f(6,-2); // Letra E



    glEnd();
}
void desenhaTriangulo(void)
{

    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);
    glVertex2f(-2.5f, -2.5f);
    glVertex2f(2.5f, -2.5f);
    glColor3f(1,0,0);
    glVertex2f(0.0f, 2.5f);
    glEnd();


    glFlush();
}
void inicializacao(void)
{

    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-7, 7,-7, 7);

    glScalef(escala, escala, 0); // quando n�o for utilizar a escala, utilizar 1 (1, escala, 1): a escala � atribu�da apenas para o Y.
    glTranslatef(deslocax, 0, 0);
    glTranslatef(0, deslocay, 0);
    glRotatef(rotacaoy, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenhaLinha();
    //desenhaTriangulo();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("Ola Glut");
    glutDisplayFunc(inicializacao);
    glutKeyboardFunc(listeningkey);
    glClearColor(1, 0, 1, 0);
    glutMainLoop();

    return 0;
}
