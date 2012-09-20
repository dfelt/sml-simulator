
class Simpletron {
public:
	Simpletron();
	void setProgram(int instructions[], int numInstructions);
	void setProgramFromStdin();
	void run();

private:
	static const int MEM_SIZE = 100;
	int memory[MEM_SIZE];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
	bool halt;
	bool fatal;
	
	void tick();
	void dump();
};
