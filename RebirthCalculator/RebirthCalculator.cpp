#include <iostream>
#include <stdio.h>

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
	237500,
};

/*
	5 * rebirths / 100 + 1 (gets the total amount of xp)
	Above Equasion Answer * 500 / 2 (gets the total amount of muscle king xp)
*/
int Calculate(int rebirth) {
	bool check = false;
	std::cout << "\n";
	for (int index = 1; index < 21; index++) {
		float CalculatedXp = 5 * (float)rebirth / 100 + 1;
		CalculatedXp = CalculatedXp * 500 / 2;
		CalculatedXp = CalculatedXp * index;
		for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
			if (CalculatedXp == AccurateGlitchingNumbers[i]) {
				std::cout << "Your rebirth can glitch Darkstars on the Muscle King Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
				check = true;
			}
		};
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 100 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Legends Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 45 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Eternal Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 30 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Mythical Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 15 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Frost Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 8 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Golden Rock (5K Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 3 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Large Rock (100 Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 2 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Punching Rock (10 Durability Rock)! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
		if (check == false) {
			CalculatedXp = 5 * (float)rebirth / 100 + 1;
			CalculatedXp = CalculatedXp * 1 / 2;
			CalculatedXp = CalculatedXp * index;
			for (int i = 0; i < sizeof(AccurateGlitchingNumbers) / sizeof(AccurateGlitchingNumbers[0]); i++) {
				if (CalculatedXp == AccurateGlitchingNumbers[i]) {
					std::cout << "Your rebirth can glitch Darkstars on the Tiny Gym Rock! Glitches at Level " << i + 1 << " [DARKSTAR LEVEL " << index << "]" << std::endl;
					check = true;
				}
			};
		}
	}
	if (check == false) {
		std::cout << "This rebirth sadly cannot glitch a Darkstar on any Rock :(\n" << std::endl;
	}
	if (check == true) {
		std::cout << "\n";
	}
	return 0;
}
int ListCalculate(int rebirth) {
	for (int index = 1; index < 21; index++) {
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
	return 0;
}

int main() {
	std::cout << "Made By Cypher#2763 | https://discord.gg/3WJnU7tCGv\nRoblox User | SamTerraria10" << std::endl;
	std::cout << "Type in -4 to list all Glitchable Rebirths,"<< std::endl;
	std::cout << "Otherwise Type in the specific rebirth you wish to calculate.\n" << std::endl;

	int rebirth = 0;
	while (true) {
		std::cout << "Type rebirth here: ";
		std::cin >> rebirth;
		if (rebirth == -4) {
			std::cout << "\nYou may experience lag at the last calculating Rebirths..." << std::endl;
			for (int i = 0; i < 10000000; i++) {
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