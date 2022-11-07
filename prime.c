// My program
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
unsigned int number_of_primes = 1;
unsigned int s(unsigned int number);
bool is_prime(unsigned int a);
unsigned int *primes;
unsigned int x;
unsigned int this;
/*
	Create a list of prime numbers under the sqrt(of number)
	Loop thourgh that list to find the prime numbers up to number
	If a number
*/
unsigned int s(unsigned int number)
{
	if (number < 5)
	{
		return 1;
	}
	unsigned int limit = s(sqrt(number));
	for (unsigned int odd = primes[number_of_primes - 1] + 2; odd < sqrt(number) + 1; odd = odd + 2)
	{
		for (unsigned int prime_index = 0; prime_index < limit; prime_index++)
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
				unsigned int *tmp;
				tmp = realloc(primes, sizeof(unsigned int) * (number_of_primes + 1));
				primes = tmp;
				primes[number_of_primes] = odd;
				number_of_primes++;
				tmp = NULL;
			}
		}
	}
	return number_of_primes;
}
unsigned int main(unsigned int argc, char *argv[])
{
	printf("%li\n", sizeof(unsigned int));
	if (argc != 2)
	{
		printf("You have to do './prime [positive unsigned integer]'\n");
		return 1;
	}
	x = atoi(argv[1]);
	if (x < 0)
	{
		printf("Use a positive unsigned integer\n");
		return 2;
	}
	primes = (unsigned int *)malloc(sizeof(unsigned int));
	primes[0] = 3;
	this = s(x);
	/* printf("Primes under the sqrt of %u:", x);
	 for (unsigned int i = 0; i < this; i++)
	 {
		printf(" %u", primes[i]);
	 } */
	printf("%u is ", x);
	if (!is_prime(x))
	{
		printf("not ");
	}
	printf("prime\n");
	free(primes);
}

bool is_prime(unsigned int a)
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
	unsigned int *tmp = malloc(sizeof(unsigned int) * (number_of_primes + 1));
	tmp[0] = 2;
	for (unsigned int i = 0; i < number_of_primes; i++)
	{
		tmp[i + 1] = primes[i];
	}
	primes = tmp;
	tmp = NULL;
	for (unsigned int i = 0; i < this; i++)
	{
		//	printf("%u ",primes[i]);
		if (a % primes[i] == 0)
		{
			printf("\n%u\n", primes[i]);
			return false;
		}
	}
	return true;
}
