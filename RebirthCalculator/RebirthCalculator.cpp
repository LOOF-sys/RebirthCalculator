#include <iostream>
#include <windows.h>
#include <string>
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

int Calculate(int rebirth) {
	bool check = false;
	bool MuscleKingCheck = false;
	int xpAdded = 0;
	int MuscleKingXpAdded = 0;
	std::cout << "\n";
	std::cout << "[DARKSTAR CALCULATIONS BELOW]" << std::endl;

	// DARKSTAR CALCULATIONS
	std::system("color 0A");
	while (xpAdded < 237500) {
		for (int index = 1; index < 20; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + xpAdded;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Muscle King Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
					check = true;
				}
			};
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 100 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Legends Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 45 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Eternal Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 30 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Mythical Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 15 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Frost Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 8 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Golden Rock (5K Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 3 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Large Rock (100 Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 2 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Punching Rock (10 Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 1 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + xpAdded;
				for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Darkstars on the Tiny Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "] [" << GetFormattedXp("Darkstar",xpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
		}
		xpAdded = xpAdded + 5;
	}
	// MUSCLE KING CALCULATIONS
	std::system("color 0B");
	std::cout << "\n[MUSCLE KING AURA CALCULATIONS BELOW]" << std::endl;
	while (MuscleKingXpAdded < 313500) {
		for (int index = 1; index < 20; index++) {
			float CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 500 / 2;
			CalculatedXp = CalculatedXp * index;
			CalculatedXp = CalculatedXp + MuscleKingXpAdded;
			for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Muscle King Auras on the Muscle King Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
					check = true;
				}
			};
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 100 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Legends Gym Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 45 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Eternal Gym Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 30 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Mythical Gym Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 15 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Frost Gym Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 8 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Golden Rock (5K Durability Rock)! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 3 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Large Rock (100 Durability Rock)! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 2 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Punching Rock (10 Durability Rock)! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
			if (check == false) {
				CalculatedXp = 5 * (float)rebirth / 100 + 1;
				CalculatedXp = CalculatedXp * 1 / 2;
				CalculatedXp = CalculatedXp * index;
				CalculatedXp = CalculatedXp + MuscleKingXpAdded;
				for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
					if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
						std::cout << "Your rebirth can glitch Muscle King Auras on the Tiny Gym Rock! Glitches at Level " << i + 1 << " [MUSCLE KING LEVEL " << index << "] [" << GetFormattedXp("Aura",MuscleKingXpAdded) << "]" << std::endl;
						check = true;
					}
				};
			}
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
		std::cout << "\n";
		std::system("pause");
		std::system("CLS");
	}
	return 0;
}

int ListCalculate(int rebirth) {

	// DARKSTARS 
	for (int index = 1; index < 20; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Muscle King] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Legends Gym] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Eternal Gym] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Mythical Gym] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Frost Gym] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Golden Rock (5K Durability Rock)] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Large Rock (100 Durability Rock)] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Punching Rock (10 Durability Rock)] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << rebirth << " [Tiny Gym Rock] Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
			}
		};
	}

	// MUSCLE KING AURAS
	for (int index = 1; index < 20; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Muscle King] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 100 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Legends Gym] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 45 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Eternal Gym] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 30 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Mythical Gym] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 15 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Frost Gym] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 8 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Golden Rock (5K Durability Rock)] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 3 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Large Rock (100 Durability Rock)] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 2 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Punching Rock (10 Durability Rock)] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
		CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 1 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateMuscleKingGlitchingNumbers) / sizeof(AccurateMuscleKingGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateMuscleKingGlitchingNumbers[i]) {
				std::cout << rebirth << " [Tiny Gym Rock] Glitches at Level " << i + 1 << " [MUSCLE KING AURA LEVEL " << index << "]" << std::endl;
			}
		};
	}
	return 0;
}

int main() {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 100, 100, 1200, 600, TRUE); }
	/*
	std::cout << "Made By Cypher#2763 | https://discord.gg/3WJnU7tCGv\nRoblox User | SamTerraria10" << std::endl;
	std::cout << "Type in -4 to list all Glitchable Rebirths,"<< std::endl;
	std::cout << "Otherwise Type in the specific rebirth you wish to calculate," << std::endl;
	std::cout << "\"[XP ADDED (number)]\" defines how much treadmill xp is added to it for it to work (shows 0 if it works without treadmill modification)\n" << std::endl;
	*/
	int rebirth = 0;
	while (true) {
		std::cout << "Version 1.12, Keep the window at the automatic set size to ensure correct formatting.\n" << std::endl;
		std::cout << "This Program was Developed By: Cypher#2763 (Programmer), SiZzY#9158 and Codes_SoundzYT#6288" << std::endl;
		std::cout << "Roblox Users | SamTerraria10 (Cypher), S1ZzYChEeKs and Codes_SoundzYT\n" << std::endl;
		std::cout << "Type rebirth here: ";
		std::cin >> rebirth;
		if (rebirth == -4) {
			std::cout << "\nYou may experience lag at the last calculating Rebirths..." << std::endl;
			for (int i = 0; i < 12600000; i++) {
				ListCalculate(i);
			};
			std::system("pause");
			std::system("CLS");
			std::cout << "Made By Cypher#2763 | https://discord.gg/3WJnU7tCGv\nRoblox User | SamTerraria10" << std::endl;
		}
		std::cout << "Calculating..." << std::endl;
		Calculate(rebirth);
		//std::system("pause");
	};
	return 0;
}