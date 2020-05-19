#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
 
void drawBox(){
    glColor3f(1, 0, 0); //빨간 네모
    glBegin(GL_POLYGON);
        glVertex3f(-1, -1, -1);
        glVertex3f(1, -1, -1);
        glVertex3f(1, 1, -1);
        glVertex3f(-1, 1, -1);
    glEnd();
 
    glColor3f(0, 1, 0); //초록 네모
    glBegin(GL_POLYGON);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glEnd();
 
    glColor3f(0, 0, 1); //파란 네모
    glBegin(GL_POLYGON);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	 
	// 아래 사각형부터는 옆면
	glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);

	glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);

	glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, 1, -1);
    glEnd();
}

void InitVisual(){  //후면 제거
	glEnable(GL_CULL_FACE); //후면 제거 모드 활성화
	glFrontFace(GL_CW);
	// 실제 후면 제거 작업은 glCullFace()함수에 의해 이루어짐
	glCullFace(GL_BACK); //(BACK은 후면, FRONT는 전면을 제거한다.)
	// 추가로 GL_FRONT_AND_BACK은 전면과 후면 모두를 제거한다.
}

void display(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(100, 100, 250, 250);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, 0.1, 50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        glTranslatef(0, 0, -2);//정점의 이동
        glRotatef(180, 1, 1, 1);//회전 변환
        glScalef(0.5, 0.5, 0.5);//크기 변환 : 벡터의 크기를 늘리고 줄이는 것.
        drawBox();
    glPopMatrix();
    glutSwapBuffers();
    glFinish();
}
 
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("후면제거해보자!");
	InitVisual();
    glutDisplayFunc(display);
    glutMainLoop();
}