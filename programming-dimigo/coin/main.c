#include<stdio.h>

int main()
{
	int w = 0, rw = 0;
	int result = 0;
	int flag = 0;

	int coinN[6] = { 0, };
	int coinRN[6] = { 0, };
	int coin[6] = { 500, 100, 50, 10, 5, 1 };

	int n = 0;
	int i = 0;

	scanf("%d", &w);
	scanf("%d %d %d %d %d %d", &coinN[0], &coinN[1], &coinN[2], &coinN[3], &coinN[4], &coinN[5]);

	for (i = 0; i<6; i++)
	{
		coinRN[i] = w / coin[i];
		if (coinRN[i] > coinN[i])
			coinRN[i] = coinN[i];
	}

	for (i = 5; i >= 0; i--)
	{
		if (flag == 1)
			coinRN[i] = 0;
		else
		{
			rw += coinRN[i] * coin[i];

			if (w <= rw)
				flag = 1;
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (coinRN[i] != 0 && i != 5)
		{
			if (((coin[i + 1] * coinRN[i + 1]) / coin[i]) > 0)
				coinRN[i] -= ((coin[i + 1] * coinRN[i + 1]) / coin[i]);
		}
	}

	rw = 0;

	for (i = 0; i < 6; i++)
	{
		if (coinRN[i] != 0)
		{
			if (i != 5)
			{
				if ((w / coin[i]) < coinRN[i])
					coinRN[i] = w / coin[i];
			}
			else
				coinRN[i] = w - rw;

			rw += (coinRN[i]*coin[i]);
		}

		n += coinRN[i];

		if (rw == w)
			break;
	}

	printf("%d\n", n);
	for (i = 0; i < 6; i++)
	{
		printf("%d ", coinRN[i]);
	}
	printf("\n");

	return 0;
}
