#include "factors.h"

/**
 * factorize - Find factors of a number
 * @num: Input number
 *
 * Return: Pointer to struct Factors containing factors or NULL if prime
 */
struct Factors *factorize(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			struct Factors *factors = (struct Factors *)malloc(sizeof(struct Factors));

			factors->factor1 = i;
			factors->factor2 = num / i;
			return (factors);
		}
	}
	return (NULL);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		exit(1);
	}

	char *input_file = argv[1];
	FILE *file = fopen(input_file, "r");

	if (file == NULL)
	{
		printf("File not found\n");
		exit(1);
	}

	int num;
	struct Factors *factors;
	clock_t start_time = clock();

	while (fscanf(file, "%d", &num) != EOF)
	{
		factors = factorize(num);
		if (factors != NULL)
		{
			printf("%d=%d*%d\n", num, factors->factor1, factors->factor2);
		}

		if ((double)(clock() - start_time) / CLOCKS_PER_SEC > 5)
		{
			printf("Time limit exceeded\n");
			exit(1);
		}
	}

	fclose(file);
	free(factors);
	return (0);
}
