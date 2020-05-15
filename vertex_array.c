#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat MyVertices[8][3] = { //육면체 정점의 좌표
    { -0.25, -0.25, 0.25 },
    { -0.25, 0.25, 0.25 },
    { 0.25, 0.25, 0.25 },
    { 0.25, -0.25, 0.25 },
    { -0.25, -0.25, -0.25 },
    { -0.25, 0.25, -0.25 },
    { 0.25, 0.25, -0.25 },
    { 0.25, -0.25, -0.25 }
};
GLfloat MyColors[8][3] = { //정점의 색
    { 0.2, 0.2, 0.2 },
    { 1.0, 0.0, 0.0 },
    { 1.0, 1.0, 0.0 },
    { 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    { 1.0, 0.0, 1.0 },
    { 1.0, 1.0, 1.0 },
    { 0.0, 1.0, 1.0 }
};
GLubyte MyVertexList[24] = { // 여섯 개의 면이 각각 어떤 정점들에 의해 이루어지는지
	// 사용된 숫자(정점의 아이디)는 MyVertices[8] 내부에 해당 정점이 들어가 있는 곳의 인덱스
    0, 3, 2, 1,
    2, 3, 7, 6,
    0, 4, 7, 3,
    1, 2, 6, 5,
    4, 5, 6, 7,
    0, 1, 5, 4
};

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
	//정점 배열 사용은 아니지만 정육면체를 그리기 위한
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_COLOR_ARRAY); //정점색
    glEnableClientState(GL_VERTEX_ARRAY); //정점좌표
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(30.0, 1.0, 1.0, 1.0);
    for(GLint i = 0; i < 6; i++)
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
