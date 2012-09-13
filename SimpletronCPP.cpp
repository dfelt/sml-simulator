#include "SimpletronH.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int main() {
	Simpletron cpu;
	cpu.printWelcome();
}

// This isn't strictly necessary, but I have a strange attachment to enums...
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

Simpletron::Simpletron() {
	memset(memory, 0, sizeof(int) * 100); // Zero out array
	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
}

void Simpletron::printWelcome() {
	cout << "          *** Welcome to Simpletron! ***         " << endl
		 << "*** Please enter your program one instruction ***" << endl
		 << "*** (or data word) at a time. I will type the ***" << endl
		 << "*** location number and a question mark (?).  ***" << endl
		 << "*** You then type the word for that location. ***" << endl
		 << "*** Type the sentinel -99999 to stop entering ***" << endl
		 << "*** your program. ***" << endl;
}

void Simpletron::executeNextOp() {
	switch (operationCode) {
		case READ:
			break;
		case WRITE:
			break;
	
		case LOAD:
			break;
		case STORE:
			break;
		
		case ADD:
			break;
		case SUBTRACT:
			break;
		case DIVIDE:
			break;
		case MULTIPLY:
			break;
		
		case BRANCH:
			break;
		case BRANCHNEG:
			break;
		case BRANCHZERO:
			break;
		case HALT:
			break;
		default:
			cout << "Unrecogniced opcode: " << operationCode;
	}
}
