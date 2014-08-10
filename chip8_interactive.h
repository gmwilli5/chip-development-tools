#ifndef CHIP8_INTERACTIVE_H_INCLUDED
#define CHIP8_INTERACTIVE_H_INCLUDED
class chip8_interactive{
    public:
        unsigned short pc;				// Program counter
		unsigned short opcode;			// Current opcode
		unsigned short I;				// Index register
		unsigned short sp;				// Stack pointer

		unsigned char  V[16];			// V-regs (V0-VF)
		unsigned short stack[16];		// Stack (16 levels)
		unsigned char  memory[4096];	// Memory (size = 4k)

		unsigned char  delay_timer;		// Delay timer
		unsigned char  sound_timer;		// Sound timer
        unsigned char  gfx[64 * 32];	// Total amount of pixels: 2048
		unsigned char  key[16];
    public:
		bool drawFlag;
		void emulateCycle();
		void debugRender();
		bool loadApplication(const char * filename);
		void init();
};
#endif // CHIP8_INTERACTIVE_H_INCLUDED
