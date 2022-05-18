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
bool ResetThread(short setting);
bool LegendsOfSpeedMode();
bool MuscleLegendsMode();
bool NinjaLegendsMode();

int main() {
	MoveWindow(Console, 200, 200, 1500, 600, true);
	SetConsoleTitleA("Rebirth Calculator V2 [Evolved]");
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
	SetConsoleTextAttribute(ConsoleOutput, 11);
	std::cout << "Rebirth Calculator was Developed By: Cypher#6678, SiZzY#9158 & impicklerick83#8484\nRoblox Users: CypherV5, impicklerick83 & Sizzys always contain \"Sizzy\" lol\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 10);
	std::cout << "Last Version: " << LastVersion << std::endl;
	std::cout << "Current Version: " << CurrentVersion << "\n" << std::endl;

	SetConsoleTextAttribute(ConsoleOutput, 14);
	std::cout << "Patch notes: " << CurrentVersionInfo << "\n" << std::endl;

	SetConsoleTextColorDefault();

	std::string Option = "";
	std::cout << "What game do you want to do? \nOptions: LOS = Legends Of Speed,\nML = Muscle Legends,\nNL = Ninja Legends\n\nYour Answer: ";
	std::cin >> Option;

	if (Option == "LOS") {
		std::cout << "Reloading into Legends Of Speed Mode..." << std::endl;
		ResetThread(1);
		LegendsOfSpeedMode();
	}
	if (Option == "ML") {
		std::cout << "Reloading into Muscle Legends Mode..." << std::endl;
		ResetThread(1);
		MuscleLegendsMode();
	}
}

#pragma region Definitions

bool LegendsOfSpeedMode() {
	long long Rebirth;
	short Answer;
	std::cout << "Loading into Legends Of Shit Mode..." << std::endl;
	while (true) {
		ResetThread(1);
		std::cout << "What would you like to calculate?\nOptions are: 1 = Glitchable Rebirths\n2 = Output All Glitchable Rebirths\n3 = Rebirth Time\n4 = Time needed to make a glitch pet at a certain rebirth\n\nYour Answer: ";
		std::cin >> Answer;
		switch (Answer) {
		case 1:
			ResetThread(1);
			std::cout << "Type your rebirth here: ";
			std::cin >> Rebirth;
			std::cout << "Calculating..." << std::endl;
		}
	}
}

bool CalculateRebirth(long Rebirth) {
	std::ofstream output("MuscleLegendsOutput.txt", std::ios::out);
	if (output.is_open() == false) {
		MessageBoxA(ConsoleWindow, "Critical Error: 0x0F", "Rebirth Calculator Error Handler", MB_ICONERROR);
		return false;
	}

	std::cout << "Running..." << std::endl;

	float RebirthXp = 5 * (static_cast<float>(Rebirth) / 100 + 1);

	short Rocks = 1;

	float XpMultiplier = 0.0f;
	const char* Rock = "";

	long TempLevel = 1;
	float TempRXP = RebirthXp;
	long XpModification = 0;
	while (XpModification < 262500) {
		while (Rocks < 9) {
			switch (Rocks) {
			case 1:
				XpMultiplier = 250.0f;
				Rock = "Muscle King Rock";
				break;
			case 2:
				XpMultiplier = 50.0f;
				Rock = "Legends Gym Rock";
				break;
			case 3:
				XpMultiplier = 22.5f;
				Rock = "Eternal Gym Rock";
				break;
			case 4:
				XpMultiplier = 15.0f;
				Rock = "Mythical Gym Rock";
				break;
			case 5:
				XpMultiplier = 7.5f;
				Rock = "Frost Gym Rock";
				break;
			case 6:
				XpMultiplier = 4.0f;
				Rock = "Golden Rock";
				break;
			case 7:
				XpMultiplier = 1.5f;
				Rock = "100 Rock";
				break;
			case 8:
				XpMultiplier = 1.0f;
				Rock = "10 Rock";
				break;
			case 9:
				XpMultiplier = 0.5f;
				Rock = "Tiny Gym Rock";
				break;
			default:
				break;
			}
			while (TempLevel < 20) {
				for (short i = 0; i < sizeof(MuscleLegends::AccurateGlitchingNumbers) / sizeof(MuscleLegends::AccurateGlitchingNumbers[0]); i++) {
					TempRXP = RebirthXp;
					TempRXP = TempRXP * XpMultiplier;

					TempRXP = TempRXP * TempLevel;
					TempRXP = TempRXP + XpModification;

					if (TempRXP == MuscleLegends::AccurateGlitchingNumbers[i]) {
						std::string Output = std::to_string(Rebirth) + " Rebirths can glitch on " + Rock + ", Pet Glitches at Level " + std::to_string(MuscleLegends::GetUniquePetActualLevel(TempRXP,TempLevel)) + ", Xp " + std::to_string(MuscleLegends::LEFT_OVER_XP) + " | Xp Modification Required: Level " + std::to_string(MuscleLegends::GetUniquePetLevel(XpModification, 0)) + ", Xp " + std::to_string(MuscleLegends::LEFT_OVER_XP) + "\n";
						output.write(Output.c_str(), Output.size());
					}
				}
				TempLevel++;
			}
			XpMultiplier++;
			Rocks++;
			TempLevel = 0;
		}
		XpMultiplier = 0;
		Rocks = 1;
		TempLevel = 0;
		XpModification = XpModification + 5;
	}
	TempRXP = RebirthXp;
	return true;
}
bool MuscleLegendsMode() {
	long long Rebirth;
	short Answer;
	std::cout << "Loading into Muscle Legends Mode..." << std::endl;
	while (true) {
		ResetThread(1);
		std::cout << "What would you like to calculate?\nOptions are: 1 = Glitchable Rebirths\n2 = Output All Glitchable Rebirths\n3 = Rebirth Time\n4 = Time needed to make a glitch pet at a certain rebirth\n\nYour Answer: ";
		std::cin >> Answer;
		switch (Answer) {
		case 1:
			ResetThread(1);
			std::cout << "Type your rebirth here: ";
			std::cin >> Rebirth;
			std::cout << "Calculating..." << std::endl;
			CalculateRebirth(Rebirth);
			std::system("pause");
		case 2:
			break;
		default:
			break;
		}
	}
	return true;
}

bool NinjaLegendsMode() {

}

bool ResetThread(short setting) {
	std::system("CLS");
	std::ifstream File("Credits.txt", std::ios::in);
	if (File.is_open() == false) {
		MessageBoxA(ConsoleWindow, "Couldn't locate \"Credits.txt\" lol", "Rebirth Calculator Security", MB_ICONERROR);
		return false;
	}

	SetConsoleTextAttribute(ConsoleOutput, 12);

	short LineIndex = 0;
	short MaxIndex;
	short MinIndex;

	switch (setting) {
	case 0:
		MinIndex = 0;
		MaxIndex = 6;
		break;
	case 1:
		MinIndex = 7;
		MaxIndex = 12;
		break;
	default:
		MinIndex = 0;
		MaxIndex = 5;
		break;
	}
	std::string Line;
	while (std::getline(File, Line)) {
		if (LineIndex > MaxIndex) {
			break;
		}
		LineIndex++;
		if (LineIndex > MinIndex) {
			std::cout << Line << std::endl;
		}
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