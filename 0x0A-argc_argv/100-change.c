#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_coins(int balance, int num, int *count);

/**
 * main - converts money into number of coins of change
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int money;
	int i, balance, count = 0;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		money = atoi(argv[1]);

		if (money < 0)
		{
			printf("0\n");
			return (0);
		}

		balance = get_coins(money, 25, &count);

		for (i = 1; coins[i] != '\0'; i++)
		{
			if (balance == 0)
				break;
			balance = get_coins(balance, coins[i], &count);
		}
	}
	printf("%d\n", count);
	return (0);
}

/**
 * get_coins - helper function
 * @balance: money to convert into coin change
 * @num: coin
 * @count: pointer to global count variable
 *
 * Return: balance left
 */
int get_coins(int balance, int num, int *count)
{
	int b = balance % num;

	*count += balance / num;
	return (b);
}

