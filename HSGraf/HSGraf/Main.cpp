#include <iostream>
#include <GL/glut.h>
#include "HighScore.h"
using namespace HighScoreListLT;

HighScore* HSlist = new HighScore(false, 5);

void drawText(const char* text, int length, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);

	for (int i = 0; i < length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);

	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);

}

void Display_cb() {
	string title;
	title = "Ranking:";

	drawText(title.data(), title.size(), 100, 530);
	for (int i = 0; i < HSlist->GetSizeListHighScore(); i++){
		string text1 = HSlist->GetNodeScore(i).name.c_str();
		string text2 = "........ ";

		string text3;
		text3 = to_string(HSlist->GetNodeScore(i).score);
		title = text1 + text2 + text3;
		drawText(title.data(), title.size(), 100, 530 - ((i + 1) * 25));

	}
}


void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0, 0, -10, 0, 0, 3, 0, 1, 0);

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	Display_cb();

	glutSwapBuffers();
}


int main(int argc, char* args[]) {

	HSlist->InsertScore(200, "Matias");
	HSlist->InsertScore(170, "Theo");
	HSlist->InsertScore(210, "Sofia");
	HSlist->InsertScore(125, "Ivan");
	HSlist->InsertScore(305, "Tyler");



	glutInit(&argc, args);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Highscore Display");
	glutDisplayFunc(draw);

	glutMainLoop();
	delete HSlist;

	return 0;
}