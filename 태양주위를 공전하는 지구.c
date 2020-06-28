//지구가 태양 주위를 돌아
#include<iostream>
#include<GL/glut.h>

float g_fAngle = 0; //얼만큼씩 회전할건지 설정하는 전역변수

void SetupRC();
void RenderScene();
void ReshapeScene(int width, int height);
void OnTimer(int id);

int main(){
	//초기화 함수들(암기하고 사용할 수 있,,,)
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH); //디스플레이 모드 설정 GLUT_DEPTH -> 깊이버퍼사용할거야(은면제거할거야)
	glutInitWindowPosition(100,100); //윈도우의 위치 지정
	glutInitWindowSize(500,500); //윈도우의 크기 지정
	glutCreateWindow("SUN"); //윈도우 생성(이름)
	glutDisplayFunc(RenderScene); //출력 함수의 지정
	glutReshapeFunc(ReshapeScene); //윈도우 크기 변경 함수의 지정

	SetupRC();
	glutMainLoop();
	return 0;
}

void OnTimer(int id){
	g_fAngle += 1.0f; //매 타이머 실행마다 1도씩 증가
	glutPostRedisplay(); //화면을 다시그림
}

void ReshapeScene(int width, int height){
	float fRange=10.0f;

	glViewport(0, 0, width, height); //뷰포트는 창의 크기와 동일하게
	glMatrixMode(GL_PROJECTION); //투상변환 설정
	glLoadIdentity();

	if(width<=height){
		glOrtho( -fRange, fRange, -fRange*height/width, fRange*height/width, -fRange, fRange);
	}else{
		glOrtho(-fRange*width/height, fRange*width/height, -fRange, fRange, -fRange, fRange);
	}
	//평행 투상 방법
}

void SetupRC(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //바탕 검은색
	glShadeModel(GL_FLAT); //물체 색깔이 한가지 단색으로 설정 or 혼합,,된 색상 쉐이딩
	glFrontFace(GL_CCW); //후면제거할때 ..
	glEnable(GL_CULL_FACE); //후면제거 동작 활성화
	glEnable(GL_DEPTH_TEST); //은면제거 동작 활성화
}

void RenderScene(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //컬러버퍼 초기화, 깊이버퍼 초기화 -> 은면제거 위해서
	glutTimerFunc(50, OnTimer, 1); //0.05초마다 OnTimer 함수 호출 (타이머함수를 호출하는 콜백함수) + 세번째 1값은 큰 의미X
	glMatrixMode(GL_MODELVIEW); //모델변환을 위한
	glLoadIdentity(); //항등행렬로 초기화
	glTranslatef(0.0f, 0.0f, -1.0f); //이동 함수 실행 (z축으로 -1만큼 이동)

	glPushMatrix(); 
		glColor3ub(255,0,0); //레드 컬러
		glutSolidSphere(2.0f, 24, 24); //태양 그리기 //24경선, 24위선
	glPopMatrix();

	glPushMatrix();
		glColor3ub(0,0,200); //블루 컬러
		glRotatef(g_fAngle, 0.0f, 1.0f, 0.0f);
		glTranslatef(6.0f, 0.0f, 0.0f);
		glutSolidSphere(0.5f, 24, 24); //지구 그리기
	glPopMatrix();

	glFlush(); //화면에 출력하기
}
