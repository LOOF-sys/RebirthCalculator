#pragma once

namespace MuscleLegends {
	// Unique Pet Mappings
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

	// Unique Pet Mappings Without subtracting the Xp Every Level (the xp adds up to the next levels xp)
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
		0 // level 20 [[ its actually 25000 but for math reasons it is 0 ]]
	};

	// Unique Aura Mappings
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

	// Unique Aura Mappings Without subtracting the Xp Every Level (the xp adds up to the next levels xp)
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


}
