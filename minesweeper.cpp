#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void tiparire(char cuv[][20])
{
	int i, j;
	for (i = 1; i <= 13; i++)
	{
		for (j = 0; j <= 13; j++)
			cout << cuv[i][j] << " ";
		cout << endl;
	}
}
int verificare(char aux[][20], char aux2[][20])
{
	int i, j, x = 1;
	for (i = 1; i <= 13; i++)
		for (j = 0; j <= 13; j++)
			if (aux[i][j] != aux2[i][j])
				x = 0;
	return x;
}
int main()
{
	char cuv[20][20], aux[20][20], aux2[20][20];
	int i, j, m, n, x, y, k = 0;
	strcpy_s(aux[1], "    012345678 ");
	strcpy_s(aux[2], "              ");
	strcpy_s(aux[3], "              ");
	strcpy_s(aux[4], "0   --------- ");
	strcpy_s(aux[5], "1   --------- ");
	strcpy_s(aux[6], "2   --------- ");
	strcpy_s(aux[7], "3   --------- ");
	strcpy_s(aux[8], "4   --------- ");
	strcpy_s(aux[9], "5   --------- ");
	strcpy_s(aux[10], "6   --------- ");
	strcpy_s(aux[11], "7   --------- ");
	strcpy_s(aux[12], "8   --------- ");
	strcpy_s(aux[13], "              ");

	strcpy_s(cuv[1], "    012345678 ");
	strcpy_s(cuv[2], "              ");
	strcpy_s(cuv[3], "              ");
	strcpy_s(cuv[4], "0   --------- ");
	strcpy_s(cuv[5], "1   --------- ");
	strcpy_s(cuv[6], "2   --------- ");
	strcpy_s(cuv[7], "3   --------- ");
	strcpy_s(cuv[8], "4   --------- ");
	strcpy_s(cuv[9], "5   --------- ");
	strcpy_s(cuv[10], "6   --------- ");
	strcpy_s(cuv[11], "7   --------- ");
	strcpy_s(cuv[12], "8   --------- ");
	strcpy_s(cuv[13], "              ");
	tiparire(aux);
	srand(time(NULL));
	for (i = 1; i <= 20; i++)
	{//srand(time(NULL));
		n = (rand() % 9) + 1;
		//srand(time(NULL));
		m = (rand() % 9) + 1;
		cuv[m + 3][n + 3] = '*';
	}

	for (i = 4; i <= 12; i++)
	{
		for (j = 4; j <= 12; j++)
		{
			if (cuv[i][j] != '*')
			{
				x = 0;
				if (cuv[i - 1][j - 1] == '*')
					x = x + 1;
				if (cuv[i - 1][j] == '*')
					x = x + 1;
				if (cuv[i - 1][j + 1] == '*')
					x = x + 1;
				if (cuv[i][j - 1] == '*')
					x = x + 1;
				if (cuv[i][j + 1] == '*')
					x = x + 1;
				if (cuv[i + 1][j] == '*')
					x = x + 1;
				if (cuv[i + 1][j - 1] == '*')
					x = x + 1;
				if (cuv[i + 1][j + 1] == '*')
					x = x + 1;
				x = x + 48;
				cuv[i][j] = char(x);
			}
		}
	}
	//tiparire(cuv);
	system("color b2");
	for (i = 1; i <= 13; i++)
		for (j = 0; j <= 13; j++)
		{
			if (cuv[i][j] != '*')
				aux2[i][j] = cuv[i][j];
			else
				aux2[i][j] = aux[i][j];
		}
	//tiparire(aux2);
	while (verificare(aux, aux2) == 0 && k == 0)
	{
		cin >> x;
		cin >> y;
		if (cuv[x + 4][y + 4] == '*')
		{
			tiparire(cuv);
			cout << "ai pierdut" << endl;
			k = 1;
		}
		else
		{
			system("cls");
			system("color b2");
			aux[x + 4][y + 4] = cuv[x + 4][y + 4];
			tiparire(aux);
		}
	}
	if (verificare(aux, aux2) == 1)
		cout << "ai castigat" << endl;
	//getche();
}
