#include <iostream>
#include <GL/freeglut.h>

float x = 0.0f;
float y = 0.0f;
float delta_x = 0.4f;
float delta_y = 0.2f;
float x2 = 0.0f;
float y2 = 0.0f;
float delta_x2 = 0.5f;
float delta_y2 = 0.4f;
bool kanan = true;
bool naik = true;
bool kanan2 = true;
bool naik2 = true;
bool pause = false;

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	if (x < 32.0f && kanan == true)
		x += delta_x;
	else kanan = false;
	if (x > -32.0f && kanan == false)
		x -= delta_x;
	else kanan = true;


	if (y < 23.0f && naik == true)
		y += delta_y;
	else naik = false;
	if (y > -25.0f && naik == false)
		y -= delta_y;
	else naik = true;

	if (x2 < 32.0f && kanan2 == true)
		x2 += delta_x2;
	else kanan2 = false;
	if (x2 > -32.0f && kanan2 == false)
		x2 -= delta_x2;
	else kanan2 = true;

	if (y2 < 23.0f && naik2 == true)
		y2 += delta_y2;
	else naik2 = false;
	if (y2 > -25.0f && naik2 == false)
		y2 -= delta_y2;
	else naik2 = true;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(32.0f + x, 25.0f);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(32.0f, 25.0f + y);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(32.0f + x2, 25.0f + y2);
	glEnd();

	if (pause == true) {
		glBegin(GL_TRIANGLES);
		glColor3f(0.2, 0.3, 0.5);
		glVertex2f(32.0f + x, 25.0f);
		glVertex2f(32.0f, 25.0f + y);
		glVertex2f(32.0f + x2, 25.0f + y2);
		glEnd();
	}
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == ' ' && pause == false) {
		pause = true;
	}
	else if (key == ' ' && pause == true) {
		pause = false;
	}
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(8.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 64.0f, 0.0f, 48.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TGS 3");
	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}