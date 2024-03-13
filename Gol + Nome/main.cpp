#ifdef __APPLE__
#include <GLUT/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>

float alpha = 0;
float beta = 0;
float delta = 1;
int gols = 0;
int erros = 0;
const char *exe_open = "C://Users//natha//Documents//Faculdade//trabson2//nomeLinhas//bin//Debug//walterwhite.exe";

typedef struct{

    float x1;
    float y1 = -0.6f;
    float z1;
} Ponto;

Ponto bola;

void init(){

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4, 4, -4, 4, -4, 4);
}

void DesenhaTextoStroke(char *aux){

    char *p;
    p = aux;
    while(*p)
        glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}

void desenhaTextoGol(){

    char golsStr[3];

    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glColor3f(0,1,0);
    glTranslatef(-600,900,0);
    glScalef(1, 1, 0);
    glLineWidth(2);
    DesenhaTextoStroke("Gols:\n");
    sprintf(golsStr, "%d", gols);
    DesenhaTextoStroke(golsStr);
    glFlush();
}
void desenhaTextoErro(){

    char errosStr[3];

    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

    glColor3f(1,0,0);
    glTranslatef(-600,700,0);
    glScalef(1, 1, 0); // diminui o tamanho do fonte
    glLineWidth(2); // define a espessura da linha
    DesenhaTextoStroke("Erros:\n");
    sprintf(errosStr, "%d", erros);
    DesenhaTextoStroke(errosStr);
    glFlush();
}

void desenhaBola(){

    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(bola.x1, bola.y1, bola.z1);
    glutWireSphere(0.3f, 40, 20);
    glPopMatrix();
}

void desenhaTraves(){

    glColor3f(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINES);

    glVertex3f(2.5f, -1, 1.5f); // Trave Esquerda
    glVertex3f(2.5f, 1, 1.5f);

    glVertex3f(2.5f, 1, 1.5f); // Travessão
    glVertex3f(2.5f, 1, -1.5f);

    glVertex3f(2.5f, -1, -1.5f); // Trave Direita
    glVertex3f(2.5f, 1, -1.5f);

    glVertex3f(2.5f, -0.93, 1.5f); // Linha do Gol
    glVertex3f(2.5f, -0.93, -1.5f);

    glEnd();
}
void desenhaCampo(){

    glPushMatrix();
    glTranslatef(0, -1, 0);
    glScalef(6, 0.1f, 6);
    glColor3f(0, 1, 0);
    glutSolidCube(1.0f);
    glPopMatrix();
}

/*void golCheckBackup(){

    if (bola.x1 >= 2.3f) {
        if (bola.z1 >= -1.5f && bola.z1 <= 1.5f) {
            gols++;
            printf("Gol! Numero de gols: %d\n", gols);
        } else {
            erros++;
            printf("Fora! Numero de erros: %d\n", erros);
        }
        bola.x1 = 0;
        bola.z1 = 0;
    }
}*/

void golCheck(){

    if (bola.x1 >= 2.3f)
    {
        if (bola.z1 >= -1.5f && bola.z1 <= 1.5f)
        {
            gols++;

        }
        else
        {
            erros++;

        }
        bola.x1 = 0;
        bola.z1 = 0;
    }
}

void reiniciar(){

    printf("Reiniciando o placar...\n");
    gols = 0, erros = 0;

    bola.x1 = 0;
    bola.z1 = 0;
}

void animacao(int v){
    bola.x1 += 0.1f;
}

void display(){

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(beta, 0, 1, 0);
    glRotatef(alpha, 1, 0, 0);
    glScalef(delta, delta, delta);

    desenhaBola();
    desenhaTraves();
    desenhaCampo();
    desenhaTextoGol();
    desenhaTextoErro();

    glFlush();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    if (key == 27){
        exit(0);
    }
    switch(key)
    {
    case 'q':
        delta = delta * 1.1f;
        break;
    case 'w':
        delta = delta * 0.9f;
        break;
    case ' ':
        if(bola.x1 >= 2.3f)
        {
            bola.x1 = 2.3f;
        }
        golCheck();
        glutTimerFunc(100, animacao, 0);
        break;
    case 'a':
        if(bola.z1 <= -2.4f)
        {
            bola.z1 = -2.4f ;
        }
        bola.z1 -= 0.5;
        break;
    case 'd':
        if(bola.z1 >= 2.4f)
        {
            bola.z1 = 2.4f;
        }
        bola.z1 += 0.5;
        break;
    case 'r':
        reiniciar();
        break;
    case 'c':
        system(exe_open);
    }
    glutPostRedisplay();
}

void listeningSpKey(GLint tecla, GLint x, GLint y){

    switch(tecla)
    {
    case GLUT_KEY_UP:
        alpha = alpha - 1;
        break;
    case GLUT_KEY_DOWN:
        alpha = alpha + 1;
        break;
    case GLUT_KEY_LEFT:
        beta = beta + 1;
        break;
    case GLUT_KEY_RIGHT:
        beta = beta - 1;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Clube de Regatas Vasco da Gama");
    gluOrtho2D(-4, 4, -4, 4);
    init();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(listeningSpKey);
    glutDisplayFunc(display);
    glutTimerFunc(500, animacao, 0);
    glutMainLoop();
}
