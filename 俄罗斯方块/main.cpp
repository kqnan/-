#include "cube.h"
#include <glut.h>
#include <iostream>
#include <cmath>
using std::cout;
int SIZE = 25;

int ** map;


// openGL设置
void InitGLScene()
{
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("TERIS BEGIN!");

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, SIZE, SIZE, 0);
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(800 / SIZE);
	glBegin(GL_POINTS);
	/*double * tempcubecolor = cube.paintcolor();
	glColor3f(tempcubecolor[0], tempcubecolor[1], tempcubecolor[2]);
	int ** temp = cube.usecube();
	for (int i = 0; i < 4; i++) {
		// 游戏中
		if (temp[i][1] > 2)
			glVertex2f(temp[i][0], temp[i][1]);
	}
	*/
	// 提示框
	glColor3ub(255, 0, 0);
	glVertex2f(1.0, 1.0);

	/*for (int i = 0; i < 4; i++) {
		
		glVertex2f(abs(tempremind[i][0] - tempremind[0][0] + 3), abs(tempremind[i][1] - tempremind[0][1] + 2));
		cout << abs(tempremind[i][0] - tempremind[0][0] + 3) << abs(tempremind[i][1] - tempremind[0][1] + 2)<<std::endl;
	}*/

	glEnd();
	glFlush();
}



void keypress(unsigned char key, int x, int y)
{/*
	int ** temp = cube.usecube();
	int flag = 0;
	if (key == 'g' && !cube.isstatestart()) {
		cube.setstatestart();
		cuberemind.setstatestart();
		glutTimerFunc(TimerInterval, timer, 1);
	}
	cube.movecube(key);
	if (key == 'q') {
		cout << "GAME END\n";
		exit(EXIT_FAILURE);
	}*/
}


int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	InitGLScene();
	glutDisplayFunc(display);
	glutKeyboardFunc(keypress);
	glutMainLoop();
}