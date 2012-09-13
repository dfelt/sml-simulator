
class Simpletron {
public:
	Simpletron();
	void printWelcome();

private:
	int memory[100];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
	
	void executeNextOp();
};
