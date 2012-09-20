#include "SimpletronH.h"
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

Simpletron::Simpletron() {
	memset(memory, 0, sizeof(int) * MEM_SIZE); // Zero out array
	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
	halt = false;
}

// Initialize with program from array (for testing purposes)
void Simpletron::setProgram(int instructions[], int numInstructions) {
	// Avoid buffer overflow
	if (numInstructions > MEM_SIZE) numInstructions = MEM_SIZE;
	// Write instructions starting at address 0
	for (int i = 0; i < numInstructions; i++) {
		memory[i] = instructions[i];
	}
}

// Initialize with program from stdin
void Simpletron::setProgramFromStdin() {
	cout << "          *** Welcome to Simpletron! ***         " << endl
		 << "*** Please enter your program one instruction ***" << endl
		 << "*** (or data word) at a time. I will type the ***" << endl
		 << "*** location number and a question mark (?).  ***" << endl
		 << "*** You then type the word for that location. ***" << endl
		 << "*** Type the sentinel -99999 to stop entering ***" << endl
		 << "*** your program. ***" << endl;
	
	int address = 0;
	while (true) {
		cout << address << "? ";
		int input;
		cin >> input;
		if (input == -99999) return;
		memory[address] = input;
		address++;
	}
}

// Run simpletron until halt instruction encountered
void Simpletron::run() {
	while (!halt) tick();
	cout << "Simpletron execution terminated." << endl;
	dump();
}

// All valid opcodes
enum op {
	READ       = 10,
	WRITE      = 11,
	
	LOAD       = 20,
	STORE      = 21,
	
	ADD        = 30,
	SUBTRACT   = 31,
	DIVIDE     = 32,
	MULTIPLY   = 33,
	
	BRANCH     = 40,
	BRANCHNEG  = 41,
	BRANCHZERO = 42,
	HALT       = 43
};

// Execute a single instruction
void Simpletron::tick() {
	// Get next instruction, incrementing the instructionCounter
	instructionRegister = memory[instructionCounter++];
	// Extract opcode
	operationCode = instructionRegister / 100;
	// Extract operand
	operand = instructionRegister % 100;
	
	// Choose operation based on operationCode
	switch (operationCode) {
		// IO
		case READ:
			cin >> memory[operand];
			break;
		case WRITE:
			cout << memory[operand] << endl;
			break;
		// Memory
		case LOAD:
			accumulator = memory[operand];
			break;
		case STORE:
			memory[operand] = accumulator;
			break;
		// Math
		case ADD:
			accumulator += memory[operand];
			break;
		case SUBTRACT:
			accumulator -= memory[operand];
			break;
		case DIVIDE:
			accumulator /= memory[operand];
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			break;
		// Control flow
		case BRANCH:
			instructionCounter = accumulator;
			break;
		case BRANCHNEG:
			if (accumulator < 0) instructionCounter = operand;
			break;
		case BRANCHZERO:
			if (accumulator == 0) instructionCounter = operand;
			break;
		case HALT:
			halt = true;
			break;
		default:
			cout << "Unrecogniced opcode: " << operationCode << endl;
			halt = true;
	}
}

void Simpletron::dump() {
	cout << "REGISTERS:" << endl;
	cout << "accumulator         "    << showpos   << setw(5) << setfill('0') << internal << accumulator << endl;
	cout << "instructionCounter     " << noshowpos << setw(2) << setfill('0') << instructionCounter << endl;
	cout << "instructionRegister "    << showpos   << setw(5) << setfill('0') << internal << instructionRegister << endl;
	cout << "operationCode          " << noshowpos << setw(2) << setfill('0') << operationCode << endl;
	cout << "operand                " << noshowpos << setw(2) << setfill('0') << operand << endl;

	cout << "MEMORY:" << endl;
	cout << "       0     1     2     3     4     5     6     7     8     9";
	
	for (int i = 0; i < 100; i++) {
		if ((i % 10) == 0) {
			cout << endl << noshowpos << setw(2) << i;
		}
		cout << ' ' << showpos << setw(5) << setfill('0') << internal << memory[i];
	}
	cout << endl;

};
