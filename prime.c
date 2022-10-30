// My program
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
int number_of_primes = 1;
int s(int number);
bool is_prime(int a);
int *primes;
int x;
int this;
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("You have to do './prime [positive integer]'\n");
		return 1;
	}
	x = atoi(argv[1]);
	if (x < 0)
	{
		printf("Use a positive integer\n");
		return 2;
	}
	primes = (int *)malloc(sizeof(int));
	primes[0] = 3;
	printf("Primes under the sqrt of %i:", x);
	this = s(x);

	for (int i = 0; i < this; i++)
	{
		printf(" %i", primes[i]);
	}
	printf("\nNumber of primes checked: %i\n%i is ", this, x);
	if (is_prime(x) == false)
	{
		printf("not ");
	}
	printf("prime\n");
	free(primes);
}

int s(int number)
{
	if (number < 5)
	{
		return 1;
	}
	int limit = s((int)sqrt(number));
	for (int odd = primes[number_of_primes - 1] + 2; odd < sqrt(number) + 1; odd = odd + 2)
	{
		for (int prime_index = 0; prime_index < limit; prime_index++)
		{
			if (primes[prime_index])
			{
				if (odd % primes[prime_index] == 0)
				{
					break;
				}
			}
			if (prime_index == limit - 1)
			{
				int *tmp;
				tmp = realloc(primes, sizeof(int) * (number_of_primes + 1));
				primes = tmp;
				primes[number_of_primes] = odd;
				number_of_primes++;
				tmp = NULL;
			}
		}
	}
	return number_of_primes;
}

bool is_prime(int a)
{
	if (a == 2)
	{
		return true;
	}
	if (a == 1)
	{
		return false;
	}
	// Make 2 the first element in the primes list
	int *tmp = malloc(sizeof(int) * (number_of_primes + 1));
	tmp[0] = 2;
	for (int i = 0; i < number_of_primes; i++)
	{
		tmp[i + 1] = primes[i];
	}
	primes = tmp;
	tmp = NULL;
	for (int i = 0; i < this; i++)
	{
		if (a % primes[i] == 0)
		{
			return false;
		}
	}
	return true;
}
