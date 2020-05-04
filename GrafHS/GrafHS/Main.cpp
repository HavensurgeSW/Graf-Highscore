
#include <iostream>
#include <GL/glut.h>
#include "HighScore.h"
using namespace HighScoreListLT;

void drawText(const char *text, int length, int x, int y) {
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
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
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(0,0,-10,0,0,3,0,1,0);

	glColor3f(1,0,0);
	glBegin(GL_LINES);
	glVertex3f(0,0,0);
	glVertex3f(1, 0, 0);
	glEnd();

	std::string text;
	text = "Hello world";
	drawText(text.data(), text.size(), 5, 570);


	/*for (int i = 0; i < 5; i++){
		drawText(HSlist->GetNodeScore(i).name.c_str(),200, 1,1);
	}*/

	glutSwapBuffers();
}


int main(int argc, char * args[]) {

	HighScore* HSlist = new HighScore(false, 5);
	/*HSlist->InsertScore(200, "Matias");
	HSlist->InsertScore(170, "Theo");
	HSlist->InsertScore(210, "Sofia");
	HSlist->InsertScore(125, "Ivan");
	HSlist->InsertScore(305, "Tyler");*/
	


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