#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int Width, Height;

void Init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);//투상행렬 설정
    glLoadIdentity( ); //항등행렬로 초기화

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0); //물체크기 2배 정도의 가시 부피 설정
    glMatrixMode(GL_MODELVIEW);//뷰행렬 설정
    glLoadIdentity( );//항등행렬로 초기화
}

void DrawScene() { //2가지 물체를 그려내는 함수
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix(); //현 모델 뷰 행렬 저장
        glTranslatef(0.0, -1.0, 0.0); //y축 방향으로 -1만큼 이동
        glBegin(GL_QUADS); //그리기 시작
			// 가로 세로의 크기가 4인 회색 사각형을 그린다.
            glVertex3f(2.0, 0.0, 2.0);
            glVertex3f(2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, 2.0);
        glEnd();
    glPopMatrix(); //원래의 모델 뷰 행렬 복원

    glColor3f(0.3, 0.3, 0.7);
    glPushMatrix(); //복원된 모델 뷰 행렬을 다시 푸시하여 저장
        glTranslatef(0.0, 0.0, -0.5); //-z축 방향으로 0.5만큼 이동
        glutWireTeapot(1.0);
    glPopMatrix(); //원래의 모델 뷰 행렬 복원
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glViewport(0, 0, Width/2, Height/2); //좌하단에 뷰 포트 생성
	// 행렬 모드를 명시하지 않았을 때 기본적으로 불려오는 것은 모델 뷰 행렬
    glPushMatrix();
        gluLookAt(0.0, 0.0, 1.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0);
        DrawScene();
    glPopMatrix();
    glViewport(Width/2, 0, Width/2, Height/2);
    glPushMatrix();
        gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
        DrawScene();
    glPopMatrix();
    glViewport(0, Height/2, Width/2, Height/2);
    glPushMatrix();
        gluLookAt(0.0, 1.0, 0.0,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0);
        DrawScene();
    glPopMatrix();
    glViewport(Width/2, Height/2, Width/2, Height/2);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluPerspective(30, 1.0, 3.0, 50.0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            gluLookAt(5.0, 5.0, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
            DrawScene();
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h) {
    Width = w;
    Height = h;
}

int main(int argc, char** argv) {
    Width = 500;
    Height = 500;
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Sample Drawing");
    Init();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}
