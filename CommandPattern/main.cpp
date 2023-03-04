// Command pattern

#include <iostream>

// Command Interface
class Command
{
public:
	virtual void execute() = 0;
};

// Receiver Class
class DMM
{
public:
	void GetVoltage() {
		std::cout << "Voltage measurement\n";
		std::cout << "12V\n";
	}
	void GetCurrent() {
		std::cout << "Current measurement\n";
		std::cout << "3A\n";
	}
};

// Concrete command
class DmmGetVoltageCommand :public Command {
public:
	DmmGetVoltageCommand(DMM *dmm) {
		mdmm = dmm;
	}

	void execute() {
		mdmm->GetVoltage();
		
	}
private:
	DMM* mdmm;
};

class DmmGetCurrentCommand :public Command {
public:
	DmmGetCurrentCommand(DMM* dmm) {
		mdmm = dmm;
	}

	void execute() {
		mdmm->GetCurrent();
	}
private:
	DMM* mdmm;
};

class RemoteControl
{


public:
	// init
	RemoteControl() {
		CmdNumber = 0;
		mCmd[0] = nullptr;
	}

	void setCommand(Command* cmd) {
		mCmd[CmdNumber] = cmd;
		CmdNumber++;
	}

	void runCommand() {
		for(int i=0; i< CmdNumber; i++)
			mCmd[i]->execute();					

		CmdNumber = 0;
	}
private:
	int CmdNumber;
	Command* mCmd[256];
};


int main(void)
{
	// receiver object
	DMM* dmm = new DMM;
	
	// command object
	DmmGetVoltageCommand* GetVoltage = new DmmGetVoltageCommand(dmm);
	DmmGetCurrentCommand* GetCurrent = new DmmGetCurrentCommand(dmm);

	// control object
	RemoteControl* control = new RemoteControl;

	// control command
	control->setCommand(GetVoltage);
	control->setCommand(GetVoltage);
	control->setCommand(GetCurrent);
	control->setCommand(GetVoltage);
	control->setCommand(GetCurrent);

	control->runCommand();

	return 0;
}