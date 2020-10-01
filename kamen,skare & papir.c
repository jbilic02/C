//    -KAMEN, ŠKARE & PAPIR-
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


int generateRandomNumber(int n)
{
	srand((unsigned)time(NULL));
	return rand() % n;
}

int greater(char c1, char c2)
{
	if (c1 == c2)
	{
		return -1;
	}
	else if (c1 == 'k' && c2 == 's')
	{
		return 1;
	}
	else if (c2 == 'k' && c1 == 's')
	{
		return 0;
	}
	else if (c1 == 'p' && c2 == 'k')
	{
		return 1;
	}
	else if (c2 == 'p' && c1 == 'k')
	{
		return 0;
	}

	else if (c1 == 's' && c2 == 'p')
	{
		return 1;
	}
	else if (c2 == 's' && c1 == 'p')
	{
		return 0;
	}
}
int main()
{
	int playerScore = 0, compScore = 0, temp;
	char playerChar, compChar;
	char dict[] = { 'k', 'p', 's' };
	printf("\tDobrodosli u igru:  KAMEN, SKARE & PAPIR\n");
	printf("\t----------------------------------\n\n");

	for (int i = 0; i < 3; i++)
	{
		// korisnikov odabir
		printf("Pritisnite 1 za Kamen, Pritisnite 2 za Papir, Pritisnite 3 za Skare\n\n");
		printf("\tIgrac odabire: ");
		scanf_s("%d", &temp);
		getchar();
		playerChar = dict[temp - 1];
		printf(" -----------------\n");
		printf("| Odabrali ste: %c   |\n", playerChar);
		printf(" -----------------\n\n");

		//kompjutor
		printf("Pritisnite 1 za Kamen, Pritisnite 2 za Papir, Pritisnite 3 za Skare\n\n");
		printf("\tRacunalo odabire\n");
		temp = generateRandomNumber(3) + 1;
		compChar = dict[temp - 1];
		printf(" --------------------\n");
		printf("| Racunalo odabir: %c |\n", compChar);
		printf(" --------------------\n\n");

		// komparator karaktera i povecanje bodova
		if (greater(compChar, playerChar) == 1)
		{
			compScore++;
			printf("\t\tRacunalo win!\n\n");
		}
		else if (greater(compChar, playerChar) == -1)
		{
			compScore++;
			playerScore++;
			printf("\t\tNerjeseno. Svatko po 1 poen!\n\n");
		}
		else
		{
			playerScore++;
			printf("\t\tBravo! Pobjedili ste!\n\n");
		}

		printf(" -------------\n");
		printf("| Igrac: %d      |\n", playerScore);
		printf("| Racunalo: %d |\n", compScore);
		printf(" -------------\n\n");

		printf("===========================================================\n\n");
	}

	printf(" -----------------\n");
	printf("|   Rezultati   |\n");
	printf(" -----------------\n");
	printf("|  Igrac | Racunalo |\n");
	printf("|------|----------|\n");
	printf("|     %d  |   %d     |\n", playerScore, compScore);
	printf(" -----------------\n\n");

	// usporedba score
	if (playerScore > compScore)
	{
		printf("\n\t -------------------\n");
		printf("\t| Pobjedili ste |\n");
		printf("\t -------------------\n");
	}
	else if (playerScore < compScore)
	{
		printf("\n\t ------------------------\n");
		printf("\t| Racunalo je pobjedilo |\n");
		printf("\t ------------------------\n");
	}
	else
	{
		printf("\n\t -------------\n");
		printf("\t| Nerjeseno |\n");
		printf("\t -------------\n");
	}

	return 0;
}