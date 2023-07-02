#ifndef FACTORS_H
#define FACTORS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
 * struct Factors - Structure to hold the factors of a number
 * @factor1: First factor
 * @factor2: Second factor
 */
struct Factors
{
    int factor1;
    int factor2;
};

/**
 * factorize - Find factors of a number
 * @num: Input number
 *
 * Return: Pointer to struct Factors containing factors or NULL if prime
 */
struct Factors *factorize(int num);

#endif /* FACTORS_H */