#include <stdio.h>
//#include <glut.h>
#include <GL/freeglut.h>
#include "chip8_with_debug.h"

// Display size
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

chip8_debug myChip8_debug;
int modifier_debug = 10;

// Window size
int display_width_debug = SCREEN_WIDTH * modifier_debug;
int display_height_debug = SCREEN_HEIGHT * modifier_debug;

void display_debug();
void reshape_window_debug(GLsizei w, GLsizei h);
void keyboardUp_debug(unsigned char key, int x, int y);
void keyboardDown_debug(unsigned char key, int x, int y);

// Use new drawing method
#define DRAWWITHTEXTURE
typedef unsigned __int8 u8;
u8 screenData_debug[SCREEN_HEIGHT][SCREEN_WIDTH][3];
void setupTexture_debug();

int chip8_debug_main(int argc, char **argv)
{
    myChip8_debug.loadApplication("tetris.c8");
	// Setup OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(display_width_debug, display_height_debug);
    glutInitWindowPosition(320, 320);
	glutCreateWindow("chip 8");

	glutDisplayFunc(display_debug);
	glutIdleFunc(display_debug);
    glutReshapeFunc(reshape_window_debug);
	glutKeyboardFunc(keyboardDown_debug);
	glutKeyboardUpFunc(keyboardUp_debug);

#ifdef DRAWWITHTEXTURE
	setupTexture_debug();
#endif

	glutMainLoop();

	return 0;
}

// Setup Texture
void setupTexture_debug()
{
	// Clear screen
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			screenData_debug[y][x][0] = screenData_debug[y][x][1] = screenData_debug[y][x][2] = 0;

	// Create a texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData_debug);

	// Set up the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// Enable textures
	glEnable(GL_TEXTURE_2D);
}

void updateTexture_debug(const chip8_debug& c8)
{
	// Update pixels
	for(int y = 0; y < 32; ++y)
		for(int x = 0; x < 64; ++x)
			if(c8.gfx[(y * 64) + x] == 0)
				screenData_debug[y][x][0] = screenData_debug[y][x][1] = screenData_debug[y][x][2] = 0;	// Disabled
			else
				screenData_debug[y][x][0] = screenData_debug[y][x][1] = screenData_debug[y][x][2] = 255;  // Enabled

	// Update Texture
	glTexSubImage2D(GL_TEXTURE_2D, 0 ,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData_debug);

	glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0);		glVertex2d(0.0,			  0.0);
		glTexCoord2d(1.0, 0.0); 	glVertex2d(display_width_debug, 0.0);
		glTexCoord2d(1.0, 1.0); 	glVertex2d(display_width_debug, display_height_debug);
		glTexCoord2d(0.0, 1.0); 	glVertex2d(0.0,			  display_height_debug);
	glEnd();
}

// Old gfx code
void drawPixel_debug(int x, int y)
{
	glBegin(GL_QUADS);
		glVertex3f((x * modifier_debug) + 0.0f,     (y * modifier_debug) + 0.0f,	 0.0f);
		glVertex3f((x * modifier_debug) + 0.0f,     (y * modifier_debug) + modifier_debug, 0.0f);
		glVertex3f((x * modifier_debug) + modifier_debug, (y * modifier_debug) + modifier_debug, 0.0f);
		glVertex3f((x * modifier_debug) + modifier_debug, (y * modifier_debug) + 0.0f,	 0.0f);
	glEnd();
}

void updateQuads_debug(const chip8_debug& c8)
{
	// Draw
	for(int y = 0; y < 32; ++y)
		for(int x = 0; x < 64; ++x)
		{
			if(c8.gfx[(y*64) + x] == 0)
				glColor3f(0.0f,0.0f,0.0f);
			else
				glColor3f(1.0f,1.0f,1.0f);

			drawPixel_debug(x, y);
		}
}

void display_debug()
{
	myChip8_debug.emulateCycle();
	if(myChip8_debug.drawFlag)
	{
		// Clear framebuffer
		glClear(GL_COLOR_BUFFER_BIT);

#ifdef DRAWWITHTEXTURE
		updateTexture_debug(myChip8_debug);
#else
		updateQuads(myChip8);
#endif

		// Swap buffers!
		glutSwapBuffers();

		// Processed frame
		myChip8_debug.drawFlag = false;
	}
}

void reshape_window_debug(GLsizei w, GLsizei h)
{
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);

	// Resize quad
	display_width_debug = w;
	display_height_debug = h;
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
