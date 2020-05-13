#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void Init() //창에 대한 설정, 투영 방식 등 기본 설정
{
	glClearColor(0.0,0.0,0.0,0.0); //검정색으로 배경 설정
	//투상 변환을 하려면...
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity(); //투상행렬 초기화를 위해 항등행렬 곱함
	//가시 부피 설정
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0); //원점 기준으로 x축 0부터 1까지, y축 0부터 1까지.. z축은 노상관이니 -1부터 1 다 .... 
	//원래 glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0); 랑 같았네..
}

void display() //그리기 함수g
{
	// 창이 이동하거나, 크기가 바뀌거나, 사라졌다 나타날때.. 다시 그려줘야하기 때문에 이전의 색상 버퍼 지우고 새로운 색상으로 그리기를 실행할 수 있도록
	glClear(GL_COLOR_BUFFER_BIT); //색상버퍼 지우기
	glColor3f(1.0,1.0,1.0); //흰색
	glBegin(GL_POLYGON); //사각형 그리는 GL_POLYGON..
		glVertex3f(0.25,0.25,0.0);
		glVertex3f(0.75,0.25,0.0);
		glVertex3f(0.75,0.75,0.0);
		glVertex3f(0.25,0.75,0.0);
	glEnd(); //glBegin함수와 짝.
	glFlush(); //화면에 사각형 그려라

}

int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //디스플레이 모드 설정 -> 더블 버퍼 필요 없, 싱글 버퍼.. and RGB
	glutInitWindowSize(250,250); //윈도우 사이즈(창 크기) 설정
	glutInitWindowPosition(500,500); //윈도우(창)의 위치!! 
	glutCreateWindow("사각형을 그릴거에요"); //윈도우 생성
	Init(); //초기화 함수
	//콜백함수 등록
	glutDisplayFunc(display);
	glutMainLoop(); //이벤트가 처리되기 시작하면서 반복될 수 있도록
	return 0;
}