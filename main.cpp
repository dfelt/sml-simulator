#include <iostream>
#include "SimpletronH.h"

// Take two numbers from stdin and print sum
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
// larger value.
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

int prog1[] = {
	// READ size (1)
	1018
	// LOAD size (2)
	2018
	// BRANCHNEG end (3)
	4115
	// BRANCHZERO end (4)
	4215
// next:
	// READ num (5)
	1020
	// LOAD num (6)
	2020
	// SUBTRACT max (7)
	3119
	// BRANCHNEG skip (8)
	4111
	// LOAD num (9)
	2020
	// STORE max (10)
	2119
// skip:
	// LOAD size (11)
	2018
	// SUBTRACT one (12)
	3117
	// STORE size (13)
	2118
	// BRANCHZERO next (14)
	4205
// end:
	// WRITE max (15)
	1119
	// HALT (16)
	4300
// memory:
	// one (17)
	0001,
	// size (18)
	0000,
	// max (19)
	0000,
	// num (20)
	0000
};

int main() {
	Simpletron cpu;
	cpu.setProgram(test2, 11);
	cpu.run();
}
