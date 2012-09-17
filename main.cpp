#include <iostream>
#include "SimpletronH.h"

// Take 2 numbers from stdin and print sum
int test1[] = {
	1007, // Read A
	1008, // Read B
	2007, // Load A
	3008, // Add B
	2109, // Store C
	1109, // Write C
	4300, // Halt
	0000, // Variable A
	0000, // Variable B
	0000  // Variable C
};

// Reads two numbers from the keyboard, then determines and prints the
// larger value. THIS DOES NOT WORK YET

int test2[] = {
	1009, // Read A
	1010, // Read B
	2009, // Load A
	3110, // Subtract B
	4107, // Branch negative to 07
	1109, // Write A
	4300, // Halt
	1110, // Write B
	4300, // Halt
	0000, // Variable A
	0000  // Variable B
};

int main() {
	Simpletron cpu;
	cpu.setProgram(test1, 10);
	cpu.run();
}
