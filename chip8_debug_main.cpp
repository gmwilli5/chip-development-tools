#include <stdio.h>
//#include <glut.h>
#include <GL/freeglut.h>
#include "chip8.h"

// Display size
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

chip8 myChip8_debug;
int modifier_debug = 10;

// Window size
int display_width_debug = SCREEN_WIDTH * modifier_debug;
int display_height_debug = SCREEN_HEIGHT * modifier_debug;

void display();
void reshape_window(GLsizei w, GLsizei h);
void keyboardUp_debug(unsigned char key, int x, int y);
void keyboardDown_debug(unsigned char key, int x, int y);

// Use new drawing method
#define DRAWWITHTEXTURE
typedef unsigned __int8 u8;
u8 screenData_debug[SCREEN_HEIGHT][SCREEN_WIDTH][3];
void setupTexture();

int chip8_debug_main(int argc, char **argv)
{
	/*if(argc < 2)
	{
		printf("Usage: myChip8.exe chip8application\n\n");
		return 1;
	}

	// Load game
	if(!myChip8.loadApplication(argv[1]))
		return 1;
    */
    myChip8_debug.loadApplication("test_program.c8");
	// Setup OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(display_width_debug, display_height_debug);
    glutInitWindowPosition(320, 320);
	glutCreateWindow("myChip8 by Laurence Muller");

	glutDisplayFunc(display);
	glutIdleFunc(display);
    glutReshapeFunc(reshape_window);
	glutKeyboardFunc(keyboardDown_debug);
	glutKeyboardUpFunc(keyboardUp_debug);

#ifdef DRAWWITHTEXTURE
	setupTexture();
#endif

	glutMainLoop();

	return 0;
}
void keyboardDown_debug(unsigned char key, int x, int y)
{
	if(key == 27)    // esc
		exit(0);

	if(key == '1')		myChip8_debug.key[0x1] = 1;
	else if(key == '2')	myChip8_debug.key[0x2] = 1;
	else if(key == '3')	myChip8_debug.key[0x3] = 1;
	else if(key == '4')	myChip8_debug.key[0xC] = 1;

	else if(key == 'q')	myChip8_debug.key[0x4] = 1;
	else if(key == 'w')	myChip8_debug.key[0x5] = 1;
	else if(key == 'e')	myChip8_debug.key[0x6] = 1;
	else if(key == 'r')	myChip8_debug.key[0xD] = 1;

	else if(key == 'a')	myChip8_debug.key[0x7] = 1;
	else if(key == 's')	myChip8_debug.key[0x8] = 1;
	else if(key == 'd')	myChip8_debug.key[0x9] = 1;
	else if(key == 'f')	myChip8_debug.key[0xE] = 1;

	else if(key == 'z')	myChip8_debug.key[0xA] = 1;
	else if(key == 'x')	myChip8_debug.key[0x0] = 1;
	else if(key == 'c')	myChip8_debug.key[0xB] = 1;
	else if(key == 'v')	myChip8_debug.key[0xF] = 1;

	/*else if(key == GLUT_KEY_UP) myChip8.clock.rate+=1;
	else if(key == GLUT_KEY_DOWN) myChip8.clock.rate+=-1;*/


	//printf("Press key %c\n", key);
}

void keyboardUp_debug(unsigned char key, int x, int y)
{
	if(key == '1')		myChip8_debug.key[0x1] = 0;
	else if(key == '2')	myChip8_debug.key[0x2] = 0;
	else if(key == '3')	myChip8_debug.key[0x3] = 0;
	else if(key == '4')	myChip8_debug.key[0xC] = 0;

	else if(key == 'q')	myChip8_debug.key[0x4] = 0;
	else if(key == 'w')	myChip8_debug.key[0x5] = 0;
	else if(key == 'e')	myChip8_debug.key[0x6] = 0;
	else if(key == 'r')	myChip8_debug.key[0xD] = 0;

	else if(key == 'a')	myChip8_debug.key[0x7] = 0;
	else if(key == 's')	myChip8_debug.key[0x8] = 0;
	else if(key == 'd')	myChip8_debug.key[0x9] = 0;
	else if(key == 'f')	myChip8_debug.key[0xE] = 0;

	else if(key == 'z')	myChip8_debug.key[0xA] = 0;
	else if(key == 'x')	myChip8_debug.key[0x0] = 0;
	else if(key == 'c')	myChip8_debug.key[0xB] = 0;
	else if(key == 'v')	myChip8_debug.key[0xF] = 0;

	/*else if(key == GLUT_KEY_UP) myChip8.clock.rate+=1;
	else if(key == GLUT_KEY_DOWN) myChip8.clock.rate+=-1;*/
}
