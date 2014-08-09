#ifndef CHIP8_WITH_DEBUG_H_INCLUDED
#define CHIP8_WITH_DEBUG_H_INCLUDED
class chip8_debug{
    public:
        unsigned char  gfx[64 * 32];	// Total amount of pixels: 2048
		unsigned char  key[16];
		unsigned short pc;				// Program counter
		unsigned short opcode;			// Current opcode
		unsigned short I;				// Index register
		unsigned short sp;				// Stack pointer
		unsigned char  V[16];			// V-regs (V0-VF)
		unsigned short stack[16];		// Stack (16 levels)
		unsigned char  memory[4096];
		unsigned char  delay_timer;
		unsigned char  sound_timer;
    public:
        chip8_debug();
		~chip8_debug();
		bool drawFlag;
		void emulateCycle();
		void debugRender();
		bool loadApplication(const char * filename);
		void init();
};
#endif // CHIP8_WITH_DEBUG_H_INCLUDED
