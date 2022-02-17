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

// returns string format
std::string GetFormattedXp(std::string _Name, int Xp) {
	std::string Output = "Level ";
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
	Output = Output + std::to_string(Levels) + ", Xp " + std::to_string(Xp);
	return Output;
}

// same as GetFormattedXp but instead it returns the raw number
int GetNumberFormattedXp(std::string _Name, int Xp) {
	std::string Output = "Level ";
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
	if (_Name == "Aura" || _Name=="MuscleKing") {
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
	return Levels;
}

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

std::string GetGlitchingSpeed(int Level,int LEVEL,float Xp,int XpAdded,std::string _PetType) {
	int RawLevel = GetAccurateLevel(Xp, LEVEL, _PetType);
	int NextRawLevel = GetNumberFormattedXp(_PetType, XpAdded);
	NextRawLevel = NextRawLevel - (RawLevel-2);
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
		return "+" + std::to_string(Answer) + " Stats per punch [NOT ACCURATE],";
	}
	return "+" + std::to_string(Answer) + " Stats per punch,";
}

int FileAmount = 0;

std::string WriteToString_S = "";

std::string operator<<(std::string main,std::string add) {
	WriteToString_S = WriteToString_S + add;
	return WriteToString_S;
}
std::string operator<<(std::string main, int add) {
	WriteToString_S = WriteToString_S + std::to_string(add);
	return WriteToString_S;
}

int Calculate(int rebirth) {
	bool check = false;
	bool MuscleKingCheck = false;
	float xpAdded = 0;
	int MuscleKingXpAdded = 0;
	std::cout << "\n";
	std::cout << "[DARKSTAR CALCULATIONS BELOW]" << std::endl;

	// DARKSTAR CALCULATIONS
	std::ofstream WriteTo(std::to_string(rebirth) + "_Rebirth_Calculations_Output" + std::to_string(FileAmount) + ".txt");
	std::system("color 0A");
	while (xpAdded < 237500) {
		for (int index = 1; index < 100; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Darkstars on the Muscle King Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
					check = true;
				}
			};
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 100 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the Legends Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 45 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the Eternal Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 30 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the Mythical Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 15 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the Frost Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 8 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the 5K Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 3 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						
						WriteTo << "Your rebirth can glitch Darkstars on the 100 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 2 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						
						WriteTo << "Your rebirth can glitch Darkstars on the 10 Durability Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
			//if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 1 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Darkstars on the Tiny Gym Rock! " << GetGlitchingSpeed(i, index, CalculatedXp, xpAdded, "Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index, "Darkstar") << "] [" << GetFormattedXp("Darkstar", xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			//}
		}
		xpAdded = xpAdded + 5;
	}
	// MUSCLE KING CALCULATIONS
	std::system("color 0B");
	WriteTo << "\n[MUSCLE KING AURA CALCULATIONS BELOW]\n\n[WARNING]: MUSCLE KING AURAS CURRENTLY HAVE A SMALL MISCALCULATION FOR +Stats, IT ONLY SHOWS LEVEL 1 MUSCLE KING AURAS ACCURATELY.\n" << std::endl;
	while (MuscleKingXpAdded < 313500) {
		for (float index = 1; index < 100; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					WriteTo << "Your rebirth can glitch Muscle King Auras on the Muscle King Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura", MuscleKingXpAdded) << "]" << std::endl;
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
						WriteTo << "Your rebirth can glitch Muscle King Auras on the Legends Gym Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 45 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the Eternal Gym Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 30 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the Mythical Gym Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 15 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the Frost Gym Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 8 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the 5K Durability Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 3 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the 100 Durability Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 2 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the 10 Durability Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
			//if (MuscleKingCheck == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 1 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						WriteTo << "Your rebirth can glitch Muscle King Auras on the Tiny Gym Rock! " << GetGlitchingSpeed(i,index,CalculatedXp,MuscleKingXpAdded,"MuscleKing") << " [Muscle King Aura Level " << GetAccurateLevel(CalculatedXp, index,"MuscleKing") << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						MuscleKingCheck = true;
					}
				};
			//}
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

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // -11

int ListCalculate(int rebirth) {
	// DARKSTARS 
	for (float index = 1; index < 50; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Muscle King] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Legends Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Eternal Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Mythical Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Frost Gym] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [5K Durability Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [100 Durability Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [10 Durability Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				WriteToString_S << rebirth << " [Tiny Gym Rock] " << GetGlitchingSpeed(i,index,CalculatedXp,NULL,"Darkstar") << " [Darkstar Level " << GetAccurateLevel(CalculatedXp, index,"Darkstar") << "]" << "\n";
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
		if (YesOrNo == true && Blacklisted(i)!=0) {
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

std::string Version = "1.31";
int main() {

	SetConsoleTitle(L"RebirthCalculator - Muscle Legends");
	SetupChars();

	std::thread EnableRandom(Timer);
	std::thread NewSpoof(SpoofConsole);
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 100, 100, 1450, 600, TRUE); }
	int rebirth = 0;
	while (true) {
		std::system("color 07");
		std::ifstream File;
		File.open("Credits.txt");
		std::string Line;
		SetConsoleTextAttribute(Console, 12);
		if (File.is_open()) {
			while (std::getline(File, Line)) {
				std::cout << Line << std::endl;
			}
		}
		else {
			SetConsoleTextAttribute(Console, 7);
			std::cout << "failed to load .txt" << std::endl;
		}
		SetConsoleTextAttribute(Console, 7);
		File.close();
		std::system("attrib +R Credits.txt");
		std::string RecentUpdates = "The print all feature now writes to file, fix some miscalculations with the +Add Xp before glitch system & +stats system, [Skipping 1.30 because that version was broken].";
		std::cout << "\nVersion " + Version + ", Keep the window at the automatic set size to ensure correct formatting." << std::endl;
		SetConsoleTextAttribute(Console, 14);
		std::cout << "Recent Updates: " << "[" << Version << "] " << RecentUpdates << "\n" << std::endl;
		SetConsoleTextAttribute(Console, 11);
		std::cout << "Developed By: Cypher#2763, ÇðÐê§ ? §ðµñÐz#6288 and SiZzY#9158 / Roblox Users: CypherV5, Codes_Soundz and [Her users almost always contain \"sizzy\"]\n" << std::endl;
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
		if (rebirth == -4) {
			WriteToString_S = "";
			std::ofstream WriteTo("All_Rebirths_Output" + std::to_string(FileAmount) + ".txt");
			std::cout << "Calculating... This should only take 1/2 minutes..." << std::endl;
			for (int i = 0; i < 12600000; i++) {
				ListCalculate(i);
			};
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
				switch(NewLine[4]){
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
		if (rebirth != -6 && rebirth != -5 && rebirth != -4) {
			Calculate(rebirth);
		}
		else {
			std::system("CLS");
		}
		//std::system("pause");
	};
	return 0;
}