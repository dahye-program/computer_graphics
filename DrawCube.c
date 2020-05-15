#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

void display() //그리기 함수
{
	// 창이 이동하거나, 크기가 바뀌거나, 사라졌다 나타날때.. 다시 그려줘야하기 때문에 이전의 색상 버퍼 지우고 새로운 색상으로 그리기를 실행할 수 있도록
	glClear(GL_COLOR_BUFFER_BIT); //색상버퍼 지우기
	glViewport(0,0,300,300);
	glColor3f(1,1,1); //흰색
	glRotatef(30,1,1,1);
	glutWireCube(1.0);
	glFlush(); //화면에 사각형 그려라
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500); //윈도우 사이즈(창 크기) 설정
	glutInitWindowPosition(0,0); //윈도우(창)의 위치!! 
	glutCreateWindow("사각형을 그릴거에요"); //윈도우 생성
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	//콜백함수 등록
	glutDisplayFunc(display);
	glutMainLoop(); //이벤트가 처리되기 시작하면서 반복될 수 있도록
	return 0;
}