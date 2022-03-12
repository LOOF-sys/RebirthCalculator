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
	0, // level 20 [[ its actually 25000 but for math reasons it is 0 ]]
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
	237500
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
	0
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
	313500
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

		// check for anomalies
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (Xp + 10 == AccurateGlitchingNumbers[i]) {
				FlagOutput = FlagOutput + "\n[XP ANOMALY DETECTED]\n";
				SetConsoleTextAttribute(Console, 12);
				std::cout << "[D] POTENTIAL CALCULATION ANOMALY OCCURED." << std::endl;
				SetConsoleTextAttribute(Console, 7);
				DistortionCount = DistortionCount + 1;
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

		// check for anomalies
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (Xp + 10 == AccurateMuscleKingGlitchingNumbers[i]) {
				FlagOutput = FlagOutput + "\n[XP ANOMALY DETECTED]\n";
				SetConsoleTextAttribute(Console, 12);
				std::cout << "[M] POTENTIAL CALCULATION ANOMALY OCCURED." << std::endl;
				SetConsoleTextAttribute(Console, 7);
				DistortionCount = DistortionCount + 1;
			}
		}
	}
	Levels = Levels + 1;
	Output = Output + std::to_string(Levels) + ", Xp " + std::to_string(Xp) + FlagOutput;
	return Output;
}

// same as GetFormattedXp but instead it returns the raw number
int GetNumberFormattedXp(std::string _Name, int Xp) {
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

int GetAccurateLevel(float Xp, int Multiplier, std::string petType) {
	Xp = Xp / Multiplier;
	Xp = Xp * (Multiplier - 1);
	int level = 1;
	if (petType == "Darkstar") {
		for (int i = 0; i <= sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateGlitchingNumbers[i] && AccurateGlitchingNumbers[i] != 0 && level != 19) {
				level = level + 1;
			}
		}
	}
	if (petType == "MuscleKing") {
		for (int i = 0; i <= sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (Xp >= AccurateMuscleKingGlitchingNumbers[i] && AccurateMuscleKingGlitchingNumbers[i] != 0 && level != 19) {
				level = level + 1;
			}
		}
	}
	return level;
}

int Dark = 0;
int Muscle = 0;

int StatsSystem(int Level, int LEVEL, float Xp, int XpAdded, std::string _PetType) {
	int PetsLevel = GetAccurateLevel(Xp, LEVEL, _PetType);
	int PetsGlitchingLevel = (Level + 1);

	int TotalLevels = PetsLevel + 0;
	if (TotalLevels == 1) {
		return (Level + 1) * 5;
	}
	if ((Level + 1) > TotalLevels) {
		int Answer = (Level + 1) - TotalLevels;
		if (Answer < 1) {
			Answer = 1;
		}
		return Answer * 5;
	}
	else {
		int Answer = TotalLevels - (Level + 1);
		if (Answer < 1) {
			Answer = 1;
		}
		return Answer * 5;
	}
}

std::string GetGlitchingSpeed(int Level, int LEVEL, float Xp, int XpAdded, std::string _PetType) {
	int RawLevel = GetAccurateLevel(Xp, LEVEL, _PetType);
	int NextRawLevel = GetNumberFormattedXp(_PetType, XpAdded);

	NextRawLevel = NextRawLevel - (RawLevel - 2);
	int RawAdd = 5 * RawLevel;
	int Answer = 100 - RawAdd;

	int Subtract = 0;
	int NewCount = Level + 1;
	while (NewCount < 19) {
		NewCount++;
		Subtract = Subtract + 5;
	}
	while (NextRawLevel > 1) {
		NextRawLevel--;
		Subtract = Subtract + 5;
	}
	Answer = Answer - Subtract;
	if (_PetType == "MuscleKing") {
		return "+" + std::to_string(StatsSystem(Level,LEVEL,Xp,XpAdded,_PetType)) + " Stats per punch,";
	}
	return "+" + std::to_string(Answer) + " Stats per punch,";
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

	bool Corrupt = false;

	if(ILLEGAL_REBIRTH_NUMBER(rebirth)) {
		SetConsoleTextAttribute(Console, 12);
		char Answer;
		std::cout << "[CAUTION]: THIS REBIRTH HAS BEEN MARKED AS HAZARDOUS AND SHOULD BE AVOIDED DUE TO THE UNEXPECTED BEHAVIOUR IS HAS ON THE CALCULATORS CALCULATIONS, ARE YOU SURE YOU WISH TO\nCONTINUE? Y/N" << std::endl;
		SetConsoleTextAttribute(Console, 7);
		std::cin >> Answer;
		if (Answer != 'Y' && Answer != 'y') {
			std::system("CLS");
			return 0;
		}
		Corrupt = true;
	}

	std::cout << "Calculating..." << std::endl;

	// DARKSTAR CALCULATIONS
	std::ofstream WriteTo(std::to_string(rebirth) + "_Rebirth_Calculations_Output" + std::to_string(FileAmount) + ".txt");
	if (Corrupt == true) {
		WriteTo << "CALCULATIONS FLAGGED AS HAZARDOUS, SOME THINGS MAY BE WRONG.\n" << std::endl;
	}
	std::system("color 0A");
	while (xpAdded < 237500) {
		for (int index = 1; index < 100; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Muscle King Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 100 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Legends Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 45 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Eternal Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 30 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Mythical Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 15 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Frost Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 8 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 5K Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 3 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 100 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 2 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the 10 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 1 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Tiny Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "] [" << index << " punches required" << "]" << std::endl;
					check = true;
				}
			};
		}
		xpAdded = xpAdded + 5;
	}
	// MUSCLE KING CALCULATIONS
	std::system("color 0B");
	WriteTo << "\n[Muscle King Calculations]: A new experimental +Stats Module has been added to replace the old one specifically for Muscle King Auras to \"Attempt\" to fix the problem and further eliminate it, This new module will further update and eventually fix the problem entirely, As of now, the module is not 100% accurate, infact it is only about 60% accurate but the previous one was about 22%. To report any bugs report it to the Discord Server.\n" << std::endl;
	while (MuscleKingXpAdded < 313500) {
		for (float index = 1; index < 100; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Muscle King Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Legends Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Eternal Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Mythical Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Frost Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 5K Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 100 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the 10 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
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
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Tiny Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, MuscleKingXpAdded, "MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index, "MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "] [" << index << " punches required]" << std::endl;
					MuscleKingCheck = true;
				}
			};

		}
		MuscleKingXpAdded = MuscleKingXpAdded + 5;
	}

	switch (check) {
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
		if (DistortionCount > 30) {
			MessageBox(ConsoleWindow, L"Exceeded WMAX{NULL,0,30--LLMT (error, cannot deciper the expected max value), Unknown behaviour.", L"KMODULE|XP", MB_ICONWARNING);
		}
		if (DistortionCount > 20) {
			MessageBox(ConsoleWindow, L"Overload at chunck \"WMAX Max = new WMAX{NULL,0,20};Max.MaxWarn[false];--error (value is NULL0)\", Count exceeded", L"KMODULE|XP", MB_ICONWARNING);
		}
		if (DistortionCount > 10) {
			MessageBox(ConsoleWindow, L"Your rebirth has been flagged by our automatic anomaly detector, if a calculation is inaccurate, then report it to Cypher#2763", L"KMODULE|XP",MB_ICONINFORMATION);
		}
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

int ListCalculate(int rebirth) {
	// DARKSTARS 
	for (float index = 1; index < 50; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Muscle King] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [5K Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [100 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [10 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
			}
		};
	}
	// MUSCLE KING AURAS [TEMPORARILY DISABLED]
	/*
	for (float index = 1; index < 20; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Muscle King] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Golden Rock (5K Durability Rock)] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Large Rock (100 Durability Rock)] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Punching Rock (10 Durability Rock)] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index) << "]" << std::endl;
			}
		};
	}
	*/
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
		CalculatedXp = CalculatedXp * 500 / 2;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Muscle King] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [5K Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [100 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [10 Durability Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
				WriteToString_S << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i, index, CalculatedXp, NULL, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "]" << "\n";
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
std::string PreviousVersion = "1.44";
std::string Version = "1.45";
int main() {
	HMODULE WindowsCheck = LoadLibrary(L"C:\\Windows\\SysWOW64\\BitLockerCsp.dll");
	if (WindowsCheck == 0) {
		std::exit(0);
	}
	FreeLibrary(WindowsCheck);
	SetConsoleTitle(L"RebirthCalculator - Muscle Legends");
	SetupChars();

	std::thread EnableRandom(Timer);
	std::thread NewSpoof(SpoofConsole);
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 100, 100, 1450, 600, TRUE); }
	int rebirth = 0;
	while (true) {
		int Lines = 0;
		std::system("color 07");
		std::ifstream File;
		File.open("Credits.txt");
		std::string Line;
		SetConsoleTextAttribute(Console, 12);
		if (File.is_open()) {
			while (std::getline(File, Line)) {
				Lines = Lines + 1;
				std::cout << Line << std::endl;
				int CharFoundAtPos = Line.find("_", 1);
				if(CharFoundAtPos<0 && CharFoundAtPos>19){
					std::exit(0);
				}
			}
			if (Lines != 6) {
				std::exit(0);
			}
		}
		else {
			//SetConsoleTextAttribute(Console, 7);
			SetConsoleTextAttribute(Console, 12);
			std::cout << "Failed to load .txt resource" << std::endl;
			SetConsoleTextAttribute(Console, 7);
			MessageBox(ConsoleWindow, L"\"Credits.txt\" is missing",L"Calculate Loader | MLOAD", MB_ICONERROR);
			std::exit(0);
		}
		SetConsoleTextAttribute(Console, 7);
		File.close();
		std::system("attrib +R Credits.txt");

		/* version magik */
		std::string RecentUpdates = "Major miscalculations fixed with all rocks, the bad news is that this fix may decrease some of the output per rebirth.";
		std::cout << "\nPrevious Version " << PreviousVersion << std::endl;
		std::cout << "\nVersion " + Version + ", Keep the window at the automatic set size to ensure correct formatting." << std::endl;
		/* ============= */

		SetConsoleTextAttribute(Console, 14);
		std::cout << "Recent Updates: " << "[" << Version << "] " << RecentUpdates << "\n" << std::endl;
		SetConsoleTextAttribute(Console, 11);
		std::cout << "Software Developed By Cypher#2763, SiZzY™#9158 & ÇðÐê§ ? §ðµñÐz#6288 | Roblox Users are CypherV5, Codes_SoundzYT and sizzys mainly contain \"sizzy\"\n" << std::endl;
		SetConsoleTextAttribute(Console, 10);
		std::cout << "Commands: (-4) is to print ALL POSSIBLE glitchable rebirths, (-5) is to open the cmd line for debugging, (-6) is for help/documentation.\n" << std::endl;
		SetConsoleTextAttribute(Console, 7);
		std::cout << "Type rebirth here: ";
		std::cin >> rebirth;
		if (rebirth == 0) {
			std::system("CLS");
			std::cout << "Process error.";
			MessageBox(hwnd, L"Cannot cast LPCWSTR(lpText) to type \"int\", Do not do that again", L"RebirthCalculator.exe", MB_ICONERROR);
			std::exit(0);
		}
		if (rebirth >= INT_MAX || rebirth <= INT_MIN) {
			std::system("CLS");
			std::cout << "Process error.";
			MessageBox(hwnd, L"Type int exceeded", L"RebirthCalculator.exe", MB_ICONERROR);
			std::exit(0);
		}
		if (rebirth == -3) {
			std::string Code;
			std::system("CLS");
			std::cout << "Verification code: ";
			std::cin >> Code;
			if (Code != "Verification_Code_1485023_4830038_oPC29__+==+-_-@@33%%^3#_Cypher0F_TRebCalculator__Encryption+KEy__)0") {
				std::exit(0);
			}
			WriteToString_S = "";
			std::ofstream WriteTo("Strict_All_Rebirths_Output" + std::to_string(FileAmount) + ".txt");
			std::cout << "Calculating... This should only take a few seconds..." << std::endl;
			StrictListCalculate(0);
			std::cout << "Finished Calculating, Check your desktop for an open notepad window." << std::endl;
			WriteTo << WriteToString_S;
			WriteTo.close();
			std::string OpenFile = "notepad \"Strict_All_Rebirths_Output" + std::to_string(FileAmount) + ".txt" + "\"";
			std::system(OpenFile.c_str());
			std::system("pause");
			std::system("CLS");
			continue;
		}
		if (rebirth == -4) {
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
		if (rebirth == -5) {
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
		if (rebirth == -6) {
			std::system("CLS");
			std::cout << "Documentation: " << std::endl;
			std::cout << "General usage: With this calculator you can calculate all/any rebirth that can glitch in muscle legends with darkstars(unique pets) & muscle king auras (unique auras), to start off type in any number to calculate, Example: type in 30 and it will print every single possible glitchable method and if that rebirth can glitch, what rock is glitches on, the speed it glitches and the xp it needs to glitch." << std::endl;
			std::system("pause");
		}
		std::cout << "Calculating..." << std::endl;
		if (rebirth > 0 && rebirth < 30) {
			std::cout << "\nYou need atleast 30 rebirths to use a darkstar/muscle king aura so calculating below 30 is useless.\n\n";
			std::system("pause");
			std::system("CLS");
			continue;
		}
		if (rebirth != -6 && rebirth != -5 && rebirth != -4 && rebirth != -3) {
			Calculate(rebirth);
		}
		else {
			std::system("CLS");
		}
		//std::system("pause");
	};
	return 0;
}