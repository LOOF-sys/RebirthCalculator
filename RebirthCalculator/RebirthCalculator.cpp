#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

#include "Mapping.h"

HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
HWND ConsoleWindow = GetConsoleWindow();

#define Console ConsoleWindow

bool SetConsoleTextColorDefault() {
	return SetConsoleTextAttribute(ConsoleOutput, 7);
}

std::string CurrentVersion = "2.00";
std::string CurrentVersionInfo = "FULL RE-WRITE/REMAKE OF REBIRTH CALCULATOR ALLOWING FOR THE FASTEST CALCULATIONS EVER POSSIBLE AND CROSS COMPATABLE WITH ALL SCRIPTBLOXIAN GAMES!!!";

std::string LastVersion = "1.48";

const char* Developers[20] = {
	"Cypher#6678"
};

// pre definitions
bool ResetThread();
void LegendsOfSpeedMode();
void MuscleLegendsMode();
void NinjaLegendsMode();

int main() {
	MoveWindow(Console, 200, 200, 1500, 600, true);
	SetConsoleTitleA("Rebirth Calculator V2 [CYPHER SOFTWARE]");
	std::ifstream File("Credits.txt", std::ios::in);
	if (File.is_open() == false) {
		MessageBoxA(ConsoleWindow, "Couldn't locate \"Credits.txt\" lol", "Rebirth Calculator Security", MB_ICONERROR);
		return false;
	}

	// Display drippy intro
	short LineIndex = 0;
	SetConsoleTextAttribute(ConsoleOutput, 12);
	std::string Line;
	while (std::getline(File, Line)) {
		if (LineIndex > 5) {
			break;
		}
		LineIndex++;
		std::cout << Line << std::endl;
	}
	SetConsoleTextColorDefault();

	// Credits and version shit
	SetConsoleTextAttribute(ConsoleOutput, 14);
	std::cout << "\nRebirth Calculator was Developed By: Cypher#6678\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 11);
	std::cout << "Last Version: " << LastVersion << std::endl;
	std::cout << "Current Version: " << CurrentVersion << "\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 10);
	std::cout << "Patch notes: " << CurrentVersionInfo << "\n" << std::endl;

	SetConsoleTextColorDefault();

	std::string Option = "";
	std::cout << "What game do you want to do? \nOptions: LOS = Legends Of Speed,\nML = Muscle Legends,\nNL = Ninja Legends\n\nYour Answer: ";
	std::cin >> Option;

	if (Option == "LOS") {
		std::cout << "Reloading into Legends Of Speed Mode..." << std::endl;
		ResetThread();
		LegendsOfSpeedMode();
	}
}

#pragma region Definitions

void LegendsOfSpeedMode() {
	short Answer;
	std::cout << "Loading into Legends Of Shit Mode..." << std::endl;
	while (true) {
		ResetThread();
		std::cout << "What would you like to calculate?\nOptions are: 1 = Glitchable Rebirths\n2 = Output All Glitchable Rebirths\n3 = Rebirth Time\n4 = Time needed to make a glitch pet at a certain rebirth\n\nYour Answer: ";
		std::cin >> Answer;
		switch(Answer)
	}
}

void MuscleLegendsMode() {

}

void NinjaLegendsMode() {

}

bool ResetThread() {
	std::system("CLS");
	std::ifstream File("Credits.txt", std::ios::in);
	if (File.is_open() == false) {
		MessageBoxA(ConsoleWindow, "Couldn't locate \"Credits.txt\" lol", "Rebirth Calculator Security", MB_ICONERROR);
		return false;
	}

	SetConsoleTextAttribute(ConsoleOutput, 12);
	short LineIndex = 0;
	std::string Line;
	while (std::getline(File, Line)) {
		if (LineIndex > 5) {
			break;
		}
		LineIndex++;
		std::cout << Line << std::endl;
	}
	File.close();

	SetConsoleTextColorDefault();

	// Credits and version shit
	SetConsoleTextAttribute(ConsoleOutput, 14);
	std::cout << "\nRebirth Calculator was Developed By: Cypher#6678\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 11);
	std::cout << "Last Version: " << LastVersion << std::endl;
	std::cout << "Current Version: " << CurrentVersion << "\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 10);
	std::cout << "Patch notes: " << CurrentVersionInfo << "\n" << std::endl;

	SetConsoleTextColorDefault();

	return true;
}

#pragma endregion Definitions