#include <stdio.h>
//#include <glut.h>
#include <GL/freeglut.h>
#include "chip8_interactive.h"
#include "proccessor_controller.h"

// Display size
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32

chip8_interactive myChip8_interactive;
int modifier_interactive = 10;

// Window size
int display_width_interactive = SCREEN_WIDTH * modifier_interactive;
int display_height_interactive = SCREEN_HEIGHT * modifier_interactive;

void display_interactive();
void reshape_window_interactive(GLsizei w, GLsizei h);
void keyboardUp_interactive(unsigned char key, int x, int y);
void keyboardDown_interactive(unsigned char key, int x, int y);

// Use new drawing method
#define DRAWWITHTEXTURE
typedef unsigned __int8 u8;
u8 screenData_interactive[SCREEN_HEIGHT][SCREEN_WIDTH][3];
void setupTexture_interactive();

int chip8_main(int argc, char **argv)
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
    myChip8_interactive.loadApplication("tetris.c8");
	// Setup OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(display_width_interactive, display_height_interactive);
    glutInitWindowPosition(320, 320);
	glutCreateWindow("myChip8 by Laurence Muller");

	glutDisplayFunc(display_interactive);
	glutIdleFunc(display_interactive);
    glutReshapeFunc(reshape_window_interactive);
	glutKeyboardFunc(keyboardDown_interactive);
	glutKeyboardUpFunc(keyboardUp_interactive);

#ifdef DRAWWITHTEXTURE
	setupTexture_interactive();
#endif

	glutMainLoop();

	return 0;
}

// Setup Texture
void setupTexture_interactive()
{
	// Clear screen
	for(int y = 0; y < SCREEN_HEIGHT; ++y)
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			screenData_interactive[y][x][0] = screenData_interactive[y][x][1] = screenData_interactive[y][x][2] = 0;

	// Create a texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData_interactive);

	// Set up the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// Enable textures
	glEnable(GL_TEXTURE_2D);
}

void updateTexture_interactive(const chip8_interactive& c8)
{
	// Update pixels
	for(int y = 0; y < 32; ++y)
		for(int x = 0; x < 64; ++x)
			if(c8.gfx[(y * 64) + x] == 0)
				screenData_interactive[y][x][0] = screenData_interactive[y][x][1] = screenData_interactive[y][x][2] = 0;	// Disabled
			else
				screenData_interactive[y][x][0] = screenData_interactive[y][x][1] = screenData_interactive[y][x][2] = 255;  // Enabled

	// Update Texture
	glTexSubImage2D(GL_TEXTURE_2D, 0 ,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData_interactive);

	glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0);		glVertex2d(0.0,			  0.0);
		glTexCoord2d(1.0, 0.0); 	glVertex2d(display_width_interactive, 0.0);
		glTexCoord2d(1.0, 1.0); 	glVertex2d(display_width_interactive, display_height_interactive);
		glTexCoord2d(0.0, 1.0); 	glVertex2d(0.0,			  display_height_interactive);
	glEnd();
}

// Old gfx code
void drawPixel_interactive(int x, int y)
{
	glBegin(GL_QUADS);
		glVertex3f((x * modifier_interactive) + 0.0f,     (y * modifier_interactive) + 0.0f,	 0.0f);
		glVertex3f((x * modifier_interactive) + 0.0f,     (y * modifier_interactive) + modifier_interactive, 0.0f);
		glVertex3f((x * modifier_interactive) + modifier_interactive, (y * modifier_interactive) + modifier_interactive, 0.0f);
		glVertex3f((x * modifier_interactive) + modifier_interactive, (y * modifier_interactive) + 0.0f,	 0.0f);
	glEnd();
}

void updateQuads_interactive(const chip8_interactive& c8)
{
	// Draw
	for(int y = 0; y < 32; ++y)
		for(int x = 0; x < 64; ++x)
		{
			if(c8.gfx[(y*64) + x] == 0)
				glColor3f(0.0f,0.0f,0.0f);
			else
				glColor3f(1.0f,1.0f,1.0f);

			drawPixel_interactive(x, y);
		}
}

void display_interactive()
{
    myChip8_interactive.Controller->get_opcode();
	myChip8_interactive.emulateCycle();
	if(myChip8_interactive.drawFlag)
	{
		// Clear framebuffer
		glClear(GL_COLOR_BUFFER_BIT);

#ifdef DRAWWITHTEXTURE
		updateTexture_interactive(myChip8_interactive);
#else
		updateQuads(myChip8);
#endif

		// Swap buffers!
		glutSwapBuffers();

		// Processed frame
		myChip8_interactive.drawFlag = false;
	}
}

void reshape_window_interactive(GLsizei w, GLsizei h)
{
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);

	// Resize quad
	display_width_interactive = w;
	display_height_interactive = h;
}

void keyboardDown_interactive(unsigned char key, int x, int y)
{
	if(key == 27)    // esc
		exit(0);

	if(key == '1')		myChip8_interactive.key[0x1] = 1;
	else if(key == '2')	myChip8_interactive.key[0x2] = 1;
	else if(key == '3')	myChip8_interactive.key[0x3] = 1;
	else if(key == '4')	myChip8_interactive.key[0xC] = 1;

	else if(key == 'q')	myChip8_interactive.key[0x4] = 1;
	else if(key == 'w')	myChip8_interactive.key[0x5] = 1;
	else if(key == 'e')	myChip8_interactive.key[0x6] = 1;
	else if(key == 'r')	myChip8_interactive.key[0xD] = 1;

	else if(key == 'a')	myChip8_interactive.key[0x7] = 1;
	else if(key == 's')	myChip8_interactive.key[0x8] = 1;
	else if(key == 'd')	myChip8_interactive.key[0x9] = 1;
	else if(key == 'f')	myChip8_interactive.key[0xE] = 1;

	else if(key == 'z')	myChip8_interactive.key[0xA] = 1;
	else if(key == 'x')	myChip8_interactive.key[0x0] = 1;
	else if(key == 'c')	myChip8_interactive.key[0xB] = 1;
	else if(key == 'v')	myChip8_interactive.key[0xF] = 1;

	/*else if(key == GLUT_KEY_UP) myChip8.clock.rate+=1;
	else if(key == GLUT_KEY_DOWN) myChip8.clock.rate+=-1;*/


	//printf("Press key %c\n", key);
}

void keyboardUp_interactive(unsigned char key, int x, int y)
{
	if(key == '1')		myChip8_interactive.key[0x1] = 0;
	else if(key == '2')	myChip8_interactive.key[0x2] = 0;
	else if(key == '3')	myChip8_interactive.key[0x3] = 0;
	else if(key == '4')	myChip8_interactive.key[0xC] = 0;

	else if(key == 'q')	myChip8_interactive.key[0x4] = 0;
	else if(key == 'w')	myChip8_interactive.key[0x5] = 0;
	else if(key == 'e')	myChip8_interactive.key[0x6] = 0;
	else if(key == 'r')	myChip8_interactive.key[0xD] = 0;

	else if(key == 'a')	myChip8_interactive.key[0x7] = 0;
	else if(key == 's')	myChip8_interactive.key[0x8] = 0;
	else if(key == 'd')	myChip8_interactive.key[0x9] = 0;
	else if(key == 'f')	myChip8_interactive.key[0xE] = 0;

	else if(key == 'z')	myChip8_interactive.key[0xA] = 0;
	else if(key == 'x')	myChip8_interactive.key[0x0] = 0;
	else if(key == 'c')	myChip8_interactive.key[0xB] = 0;
	else if(key == 'v')	myChip8_interactive.key[0xF] = 0;

	/*else if(key == GLUT_KEY_UP) myChip8.clock.rate+=1;
	else if(key == GLUT_KEY_DOWN) myChip8.clock.rate+=-1;*/
}
