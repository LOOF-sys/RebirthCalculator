#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <thread>

float DarkStarLevels[21] = {
	1250, // level 1
	2500, // level 2
	3750, // level 3
	5000, // level 4
	6250, // level 5
	7500, // level 6
	8750, // level 7
	10000, // level 8
	11250, // level 9
	12500, // level 10
	13750, // level 11
	15000, // level 12
	16250, // level 13
	17500, // level 14
	18750, // level 15
	20000, // level 16
	21250, // level 17
	22500, // level 18
	23750, // level 19
	25000, // level 20 [[ its actually 25000 but for math reasons it is 0 ]]
};
float AccurateGlitchingNumbers[20] = {
	1250,
	3750,
	7500,
	12500,
	18750,
	26250,
	35000,
	45000,
	56250,
	68750,
	82500,
	97500,
	113750,
	131250,
	150000,
	170000,
	191250,
	213750,
	237500,
	262500
};

float MuscleKingLevels[20] = {
	3000,
	4500,
	6000,
	7500,
	9000,
	10500,
	12000,
	13500,
	15000,
	16500,
	18000,
	19500,
	21000,
	22500,
	24000,
	25500,
	27000,
	28500,
	30000,
	31500
};
float AccurateMuscleKingGlitchingNumbers[20] = {
	3000,
	7500,
	13500,
	21000,
	30000,
	40500,
	52500,
	66000,
	81000,
	97500,
	115500,
	135000,
	156000,
	178500,
	202500,
	228000,
	255000,
	283500,
	313500,
	345000
};

void Pause(std::string option) {
	std::system("pause");
	if (option == "clear") {
		std::system("CLS");
	}
}

int LeftOverXpFrom_GetNumberFormattedXp = 0;
int CorruptXp = 0;

HWND ConsoleWindow = GetConsoleWindow();
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // -11
#define ILLEGAL_REBIRTH_NUMBER(rebirth) rebirth == 31
#define ILLEGAL_EXP_NUMBER(exp) exp == 10

int DistortionCount = 0;

// returns string format
std::string GetFormattedXp(std::string _Name, int Xp) {
	std::string Output = "Level ";
	std::string FlagOutput = "";
	int ElevatedXp = 0;
	int Levels = 0;
	if (_Name == "Darkstar") {
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateGlitchingNumbers[i]) {
				ElevatedXp = AccurateGlitchingNumbers[i];
				Levels = Levels + 1;
			}
			else {
				Xp = Xp - ElevatedXp;
				break;
			}
		}
	}
	if (_Name == "Aura") {
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateMuscleKingGlitchingNumbers[i]) {
				ElevatedXp = AccurateMuscleKingGlitchingNumbers[i];
				Levels = Levels + 1;
			}
			else {
				Xp = Xp - ElevatedXp;
				break;
			}
		}
	}
	Levels = Levels + 1;
	Output = Output + std::to_string(Levels) + ", Xp " + std::to_string(Xp) + FlagOutput;
	return Output;
}

// same as GetFormattedXp but instead it returns the raw number
int GetCurrentLevelAndXp(std::string _Name, int Xp) {
	int ElevatedXp = 0;
	int Levels = 0;
	if (_Name == "Darkstar") {
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateGlitchingNumbers[i]) {
				ElevatedXp = AccurateGlitchingNumbers[i];
				Levels = Levels + 1;
			}
			else {
				Xp = Xp - ElevatedXp;
				break;
			}
		}
	}
	if (_Name == "Aura" || _Name == "MuscleKing") {
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateMuscleKingGlitchingNumbers[i]) {
				ElevatedXp = AccurateMuscleKingGlitchingNumbers[i];
				Levels = Levels + 1;
			}
			else {
				Xp = Xp - ElevatedXp;
				break;
			}
		}
	}
	LeftOverXpFrom_GetNumberFormattedXp = Xp;
	return Levels;
}

#define XP_LEFT LeftOverXpFrom_GetNumberFormattedXp

int GetPreviousLevel(float Xp, int Multiplier, std::string petType) {
	Xp = Xp / Multiplier;
	Xp = Xp * (Multiplier - 1); // revert 1 level back
	int level = 0;
	if (petType == "Darkstar") {
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++)
		{
			if (Xp >= AccurateGlitchingNumbers[i] && level < 19) // previous level cant be the max level (19)
			{
				level = level + 1;
			}
		}
	}
	if (petType == "MuscleKing") {
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++)
		{
			if (Xp >= AccurateMuscleKingGlitchingNumbers[i] && level < 19) // level 19 = max level which can't glitch
			{
				level = level + 1;
			}
		}
	}
	return level;
}

// LEVEL is the amount of hits
std::string GetGlitchingSpeed(int Level, int LEVEL, float Xp, int XpAdded, std::string _PetType)
{
	int PreviousLevel = GetPreviousLevel(Xp, LEVEL, _PetType);
	int CurrentLevel = GetCurrentLevelAndXp(_PetType, Xp);
	return "+" + std::to_string((CurrentLevel - PreviousLevel) * 5) + " Stats per punch,";
}
int FileAmount = 0;

std::string WriteToString_S = "";

std::string operator<<(std::string main, std::string add) {
	WriteToString_S = WriteToString_S + add;
	return WriteToString_S;
}
std::string operator<<(std::string main, int add) {
	WriteToString_S = WriteToString_S + std::to_string(add);
	return WriteToString_S;
}

int Calculate(int rebirth) {
	DistortionCount = 0;
	bool check = false;
	bool MuscleKingCheck = false;
	float xpAdded = 0;
	int MuscleKingXpAdded = 0;
	std::cout << "\n";
	std::cout << "Calculating..." << std::endl;

	// DARKSTAR CALCULATIONS
	std::ofstream WriteTo(std::to_string(rebirth) + "_Rebirth_Calculations_Output" + std::to_string(FileAmount) + ".txt");
	std::system("color 0A");
	while (xpAdded < 237500)
	{
		for (int index = 1; index < 100; index++)
		{
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 1000 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i])
				{
					WriteTo << "Your rebirth can glitch Darkstars on the Ancient Jungle Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i])
				{
					WriteTo << "Your rebirth can glitch Darkstars on the Muscle King Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 100 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Legends Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 45 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Eternal Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 30 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Mythical Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 15 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Frost Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 8 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 5K Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 3 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 100 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 2 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 10 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 1 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Tiny Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
		}
		xpAdded = xpAdded + 5;
	}

	// MUSCLE KING CALCULATIONS
	std::system("color 0B");
	WriteTo << "\n[Muscle King Calculations]: A new experimental +Stats Module has been added to replace the old one specifically for Muscle King Auras to \"Attempt\" to fix the problem and further eliminate it, This new module will further update and eventually fix the problem entirely, As of now, the module is not 100% accurate, infact it is only about 60% accurate but the previous one was about 22%. To report any bugs report it to the Discord Server.\n" << std::endl;
	while (MuscleKingXpAdded < 313500)
	{
		for (float index = 1; index < 100; index++)
		{
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Muscle King Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};
			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 100 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Legends Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 45 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Eternal Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 30 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Mythical Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 15 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Frost Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 8 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 5K Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 3 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 100 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 2 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 10 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

			//if (MuscleKingCheck == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 1 / 2;

			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Tiny Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << (GetCurrentLevelAndXp("MuscleKing", CalculatedXp) + 1) << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

		}
		MuscleKingXpAdded = MuscleKingXpAdded + 5;
	}

	switch (check)
	{
	case false:
		if (MuscleKingCheck == false) {
			std::cout << "Your rebirth sadly cannot glitch Darkstar Hunters nor Muscle King Auras on any Rock :(\n" << std::endl;
			Pause("clear");
			break;
		}
		else {
			std::cout << "Your rebirth sadly cannot glitch Darkstar Hunters on any Rock :(\n" << std::endl; Pause("clear");
			Pause("clear");
			break;
		}
	case true:
		std::string OpenFile = "notepad \"" + std::to_string(rebirth) + "_Rebirth_Calculations_Output" + std::to_string(FileAmount) + ".txt" + "\"";
		std::system(OpenFile.c_str());
		WriteTo.close();
		FileAmount = FileAmount + 1;
		std::cout << "\n";
		std::system("pause");
		std::system("CLS");
	}
	return 0;
}

int ListCalculate(int rebirth)
{
	// DARKSTARS 
	for (float index = 1; index < 50; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Muscle King] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [5K Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [100 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [10 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;

		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
	}

	for (float index = 1; index < 20; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Muscle King] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Golden Rock (5K Durability Rock)] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Large Rock (100 Durability Rock)] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Punching Rock (10 Durability Rock)] " << GetGlitchingSpeed(i, index, CalculatedXp, 0, "MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,0,"MuscleKing") << " [Muscle King Aura Level " << (GetPreviousLevel(CalculatedXp, index, "MuscleKing") + 1) << "]" << std::endl;
			}
		};
	}
	return 0;
}

int StrictListCalculate(int rebirth) {
	rebirth = 1;
	// DARKSTARS 
	int index = 1;
	float CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 500 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1000 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Jungle Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 500 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Muscle King] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 100 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 45 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 30 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 15 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 8 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [5K Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 3 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [100 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 2 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [10 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	rebirth = 1;
	WriteToString_S << "\n";
	CalculatedXp = 5 * (float)rebirth / 100 + 1;
	CalculatedXp = CalculatedXp * 1 / 2;

	while (CalculatedXp < (AccurateGlitchingNumbers[18] + 1)) {
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << (GetCurrentLevelAndXp("Darkstar", CalculatedXp) + 1) << "]" << "\n";
			}
		};
		rebirth = rebirth + 1;
	}
	return 0;
}
char Characters[140] = {};
bool YesOrNo;
bool MoreRandom;

int Timer() {
	int Times = 0;
	while (true) {
		YesOrNo = true;
		Sleep(5);
		YesOrNo = false;
		Sleep(6);
	}
}

std::string SetupChars() {
	for (int i = 0; i < sizeof(Characters) / sizeof(Characters[0]); i++) {
		Characters[i] = i;
	}
	return "\0";
}

int Blacklisted(int number) {
	switch (number) {
	case 0:
		return 0;
	case 7:
		return 0;
	case 8:
		return 0;
	case 9:
		return 0;
	case 10:
		return 0;
	case 13:
		return 0;
	default:
		return 1;
	}
}

std::string GetChars() {
	int NextSpace = 0;
	std::string Default = "___________________________________________________________________________________________________________________________________";
	for (int i = 0; i < sizeof(Characters) / sizeof(Characters[0]); i++) {
		if (YesOrNo == true && Blacklisted(i) != 0) {
			Default[NextSpace] = Characters[i];
			NextSpace = NextSpace + 1;
		}
		if (YesOrNo == true) {
			Sleep(7);
		}
		else {
			Sleep(9);
		}
	}

	for (int i = 0; i <= Default.length(); i++) {
		if (Default[i] == '_') {
			Default[i] = '\0';
		}
	}
	return Default;
}
int SpoofConsole() {
	while (true) {
		SetConsoleTitleA(GetChars().c_str());
	}
	return 0;
}
std::string RunClock = "start bin\\clock.exe ";
std::string RunClockHelp = "notepad bin\\help.txt";

std::string Version = "2.0.0b";
int main()
{
	SetConsoleTitle("Rebirth Calculator - Muscle Legends");
	SetupChars();
	std::thread EnableRandom(Timer);
	std::thread NewSpoof(SpoofConsole);

	HWND hwnd = GetConsoleWindow();
	if (hwnd) MoveWindow(hwnd, 100, 100, 1450, 600, TRUE);

	int rebirth = 0;
	while (true)
	{
		int Lines = 0;
		std::system("color 07");
		std::ifstream File;
		File.open("Credits.txt");
		std::string Line;
		SetConsoleTextAttribute(Console, 12);
		if (File.is_open())
		{
			while (std::getline(File, Line))
			{
				Lines = Lines + 1;
				std::cout << Line << std::endl;
				int CharFoundAtPos = Line.find("_", 1);
				if (CharFoundAtPos < 0 && CharFoundAtPos > 19) std::exit(0);
			}
			if (Lines != 6) std::exit(0);
		}
		else
		{
			SetConsoleTextAttribute(Console, 12);
			std::cout << "Failed to load .txt resource" << std::endl;
			SetConsoleTextAttribute(Console, 7);
			MessageBox(ConsoleWindow, "\"Credits.txt\" is missing", "Rebirth Calculator | LOADER", MB_ICONERROR);
			std::exit(0);
		}
		SetConsoleTextAttribute(Console, 7);
		File.close();
		std::system("attrib +R Credits.txt");

		/* version magik */
		std::string RecentUpdates = "contribute to the project @https://github.com/LOOF-sys/RebirthCalculator";
		std::cout << "\nVersion " + Version + ", Keep the window at the automatic set size to ensure correct formatting." << std::endl;
		/* ============= */

		SetConsoleTextAttribute(Console, 14);
		std::cout << "Recent Updates: " << "[" << Version << "] " << RecentUpdates << "\n" << std::endl;
		SetConsoleTextAttribute(Console, 11);
		std::cout << "Software created by Cypher (discord: wcypher) | https://github.com/LOOF-sys" << std::endl;
		SetConsoleTextAttribute(Console, 10);
		std::cout << "Commands: (-4) shows all Glitchable Rebirths, (-5) open's the cmd line for debugging, (-6) is for help/documentation. (-7) For extra features\n" << std::endl;
		SetConsoleTextAttribute(Console, 7);
		std::cout << "Type rebirth here: ";
		std::cin >> rebirth;

		if (rebirth == 0)
		{
			system("cls");
			std::cout << "Process error.";
			continue;
		}

		if (rebirth >= INT_MAX || rebirth <= INT_MIN)
		{
			system("cls");
			std::cout << "Process error.";
			continue;
		}

		if (rebirth == -3)
		{
			system("cls");
			WriteToString_S = "";
			std::ofstream WriteTo("Strict_All_Rebirths_Output" + std::to_string(FileAmount) + ".txt");
			std::cout << "Strict calculating rebirths... (find hidden ones unpublic feature made public)" << std::endl;
			StrictListCalculate(0);
			std::cout << "Finished Calculating, Check your desktop for an open notepad window." << std::endl;
			WriteTo << WriteToString_S;
			WriteTo.close();
			std::string OpenFile = "notepad \"Strict_All_Rebirths_Output" + std::to_string(FileAmount) + ".txt" + "\"";
			system(OpenFile.c_str());
			system("pause");
			system("CLS");
			continue;
		}

		if (rebirth == -4)
		{
			WriteToString_S = "";
			std::ofstream WriteTo("All_Rebirths_Output" + std::to_string(FileAmount) + ".txt");
			std::cout << "Calculating... This should only take 1/2 minutes..." << std::endl;
			for (int i = 0; i < 12600000; i++) {
				ListCalculate(i);
			};
			std::cout << "Finished Calculating, Check your desktop for an open notepad window." << std::endl;
			WriteTo << WriteToString_S;
			WriteTo.close();
			std::string OpenFile = "notepad \"All_Rebirths_Output" + std::to_string(FileAmount) + ".txt" + "\"";
			std::system(OpenFile.c_str());
			std::system("pause");
			std::system("CLS");
		}

		if (rebirth == -5)
		{
			std::system("CLS");
			std::string NewLine;
			std::cout << "Command: ";
			std::cin >> NewLine;
			std::cout << std::endl;
			if (NewLine[0] == 'C' && NewLine[1] == 'M' && NewLine[2] == 'D') {
				switch (NewLine[4]) {
				case 'M':
					if (NewLine[3] == '-') {
						std::cout << "Rebirth Number: ";
						std::cin >> rebirth;
						std::cout << "Manual Calculating..." << std::endl;
						Calculate(rebirth);
					}
					break;
				case 'B':
					if (NewLine[3] == '-') {
						std::exit(0);
					}
					break;
				case 'T':
					if (NewLine[3] == '-') {
						std::terminate();
					}
					break;
				case 'C':
					if (NewLine[3] == '=') {
						std::cout << "Mapping..." << std::endl;
						WriteToString_S = "";
						std::cout << "Calculating... This should only take 1/2 minutes..." << std::endl;
						for (int i = 0; i < 12600000; i++) {
							ListCalculate(i);
						};
						std::cout << WriteToString_S << std::endl;
						std::system("pause");
						std::system("CLS");
					}
					break;
				default:
					break;
				}
			}
		}
		if (rebirth == -6)
		{
			std::system("CLS");
			std::cout << "Documentation: " << std::endl;
			std::cout << "General usage: With this calculator you can calculate all/any rebirth that can glitch in muscle legends with darkstars(unique pets) & muscle king auras (unique auras), to start off type in any number to calculate, Example: type in 30 and it will print every single possible glitchable method and if that rebirth can glitch, what rock is glitches on, the speed it glitches and the xp it needs to glitch." << std::endl;
			std::system("pause");
		}
		if (rebirth == -7)
		{
			char yes_or_no = 0;
			int WaitTime = 0;
			long long int total_health = 0;
			long long int hits = 0;
			long long int rebirths_value1 = 0;
			long double damage_value1 = 0;
			long double strength_value1 = 0;
			long double strength_value2 = 0;
			long double durability_value1 = 0;
			int response = 0;
			std::cout << "\nWhat else do you want to calculate?\n[1] Damage to Strength\n[2] Strength to Damage\n[3] How many hits until death (durability test)\n[4] Seconds to accurate time (new)\n[5] Credits (in depth)" << std::endl;
			std::cin >> response;
			switch (response) {
			case 1:
				std::cout << "What is the damage? " << std::endl;
				std::cin >> damage_value1;
				std::cout << "Processing..." << std::endl; // 14.79289940828403
				std::cout << "The damage converts to " << std::to_string(damage_value1 * 14.79289940828403) << " Strength." << std::endl;
				std::system("pause");
				std::system("CLS");
				break;
			case 2:
				std::cout << "What is the strength? " << std::endl;
				std::cin >> strength_value1;
				std::cout << "Processing..." << std::endl;
				std::cout << "The strength converts to " << std::to_string(strength_value1 * 0.0676) << " Damage." << std::endl;
				std::system("pause");
				std::system("CLS");
				break;
			case 3:
				std::cout << "What is the defenders durability? ";
				std::cin >> durability_value1;
				std::cout << "What is your strength? ";
				std::cin >> strength_value1;
				damage_value1 = strength_value1 * 0.0676;
				total_health = 100 + durability_value1;
				hits = 0;
				while (hits < 300) {
					hits++;
					total_health = total_health - damage_value1;
					if (hits > 299) {
						std::cout << "You cannot kill this player, get better." << std::endl;
						break;
					}
					if (total_health <= 0) {
						std::cout << "To kill this player you need to punch them " << hits << " times." << std::endl;
						break;
					}
				}
				std::system("pause");
				std::system("CLS");
				break;
			case 4:
				std::cout << "do you need help on using this cmd? Y/N ";
				std::cin >> yes_or_no;
				if (yes_or_no == 'Y' || yes_or_no == 'y') {
					std::system(RunClockHelp.c_str());
				}
				std::cout << "What is the amount of seconds you want to wait? ";
				std::cin >> WaitTime;
				RunClock = RunClock + std::to_string(WaitTime);
				std::system(RunClock.c_str());
				break;
			case 5:
				std::cout << "Rebirth Calculator was Developed by the following people:" << std::endl;
				std::cout << "wcypher on discord | developer of Rebirth Calculator Software\nimpicklerick83#8484 / impicklerick83 | Backend mathmatics and played a huge role in verifiying it was accurate\nSiZzY#9158 / ErisaSilvan | Muscle King Aura mathmatics & designing in Rebirth Calculator's Equations, tested and verified it." << std::endl;
				std::system("pause");
				break;
			default:
				std::cout << "not valid" << std::endl; break;
			}
		}
		std::cout << "Calculating..." << std::endl;
		if (rebirth > 0 && rebirth < 30)
		{
			std::cout << "\nYou need atleast 30 rebirths to use a darkstar/muscle king aura so calculating below 30 is useless.\n\n";
			std::system("pause");
			std::system("CLS");
			continue;
		}
		if (rebirth != -7 && rebirth != -6 && rebirth != -5 && rebirth != -4 && rebirth != -3) Calculate(rebirth);
		else std::system("CLS");
		//std::system("pause");
	};
	return 0;
}
