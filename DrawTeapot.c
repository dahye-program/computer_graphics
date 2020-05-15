#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#define _USE_MATH_DEFINES
#include<math.h>

int Width, Height;

void Init()
{
	glClearColor(1.0,1.0,1.0,1.0); //배경 흰색
	glMatrixMode(GL_PROJECTION); //투상변환을 위해 GL_PROJECTION
	glLoadIdentity(); //투상행렬초기화

	glOrtho(-2.0,2.0,-2.0,2.0,0.5,5.0); //가시 부피 설정(크게)
	glMatrixMode(GL_MODELVIEW); //모델 뷰 변환을 위해
	glLoadIdentity(); //변환행렬초기화
}

void DrawScene() { //2가지 물체를 그려내는 함수
    glColor3f(0.7, 0.7, 0.7); //회색으로 그리기
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

    glColor3f(0.3, 0.3, 0.7); //남색?
    glPushMatrix(); //복원된 모델 뷰 행렬을 다시 푸시하여 저장
        glTranslatef(0.0, 0.0, -0.5); //-z축 방향으로 0.5만큼 이동
        glutWireTeapot(1.0); //크기가 1인 주전자 그리기
    glPopMatrix(); //원래의 모델 뷰 행렬 복원
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT); //컬러 버퍼 초기화
	glColor3f(1.0,1.0,1.0); //흰색으로 그리도록 설정

	//glViewport(0,Height/2,Width/2,Height/2); //2사분면 영역에 그리기
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//	glLoadIdentity();
	//	gluPerspective(30,1.0,3.0,50.0); //원근 투상을 위해
	//	// 30도...(시야) 1.0은 종횡비(가로세로의 비를 1:1로) 3.0은 near 50.0은 far(3부터 50까지 밀리게)
	//	glMatrixMode(GL_MODELVIEW);
	//	glPushMatrix();
	//		gluLookAt(5.0,5.0,5.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //시선 (앞에서부터 카메라의 위치, 초점, 카메라의 상단 초점
	//		DrawScene();
	//	glPopMatrix();
	//	glMatrixMode(GL_PROJECTION);
	//glPopMatrix();

	//glPerspective -> glFrustum으로(책 참고)
	glViewport(Width/2,Height/2,Width/2,Height/2); //1사분면 영역에 그리기
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		//bottom = -near
		double bottom = -3.0*tan(30/2*M_PI/180);
		double top = -bottom;
		glFrustum( bottom*1.0, top*1.0,bottom, top,3.0 ,50.0 ); 
		
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(5.0,5.0,5.0, 0.0,0.0,0.0, 0.0,1.0,0.0); //시선 (앞에서부터 카메라의 위치, 초점, 카메라의 상단 초점) (원근 투상의 경우, 앞에 3개의 수가 커질수록 카메라의 위치가 멀어지는 것처럼 보임)
			DrawScene();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}