#include <stdio.h>
#include <math.h>
#include <Windows.h>

// Declaration of functions
int function(int lvl);

// Code
int function(int lvl) {
	double exp = (32.8739*pow(lvl,2)) + (19.3492*lvl);
	return (int)exp;
}

int enterLevel() {
	int lvl;
	L2:
	scanf_s("%d", &lvl);
	if (lvl < 0) {
		printf("Levels can't be below 0!\n");
		goto L2;
	}
	return lvl;
}

void lvlExpReq(int lvl) {
	char ch;
	L1: 
	printf("The EXP needed to reach that lvl would be: %d!\n", function(lvl));
	Sleep(1000);
	printf("Want to check another lvl? (y/n)\n");
	ch = getch();
	if (ch == 'y') {
		system("cls");
		goto L1;
	}
}

void explvlUp(int lvl) {
	int nextlvl = lvl + 1;
	int expLvlUp = function(nextlvl) - function(lvl);
	printf("Exp needed to Level-Up would be %d!\n",expLvlUp);
}

void Menu() {
	char key;
	int exp;
	printf(	"1 - Level Experience Calculator\n"
			"2 - Exp needed for Level-Up\n"
			"3 - Exit\n");
L1: key = getch();
	switch (key)
	{
	case '1':
		system("cls");
		printf("Level you want to know the exp value of: ");
		lvlExpReq(enterLevel());
		break;
	case '2':
		system("cls");
		printf("Enter your Level!\n");
		explvlUp(enterLevel());
		Sleep(1000);
		break;
	case '3':
		exit(0);
	default:
		goto L1;
		break;
	}
}

void main() {
	Menu();
	exit(0);
}