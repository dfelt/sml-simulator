
class Simpletron {
public:
	Simpletron();
	void setProgram(int instructions[], int numInstructions);
	void setProgramFromStdin();
	void run();

private:
	int memory[100];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
	bool halt;
	
	void tick();
};
