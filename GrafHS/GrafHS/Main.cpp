
#include <iostream>
#include "GL/glut.h"

void draw() {
	glFlush();

}

int main(int argc, char * args[]) {

	glutInit(&argc, args);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Highscore Display");
	glutDisplayFunc(draw);

	glutMainLoop();


	return 0;
}