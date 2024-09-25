// =====================================================================================
// ZinsberechnungMitArray.c
// =====================================================================================

#include <stdio.h>

#include "GlobalDefinitions.h"

int doubleInterestRateWithWithAccumulation(
    double capital, double rate, double accumulation[], int length, int* success)
{
    *success = 0;  // not succeeded

    double newCapital = capital;

    int year = 0;

    while (newCapital < 2 * capital) {

        double interest = (newCapital / 100.0) * rate;

        newCapital = newCapital + interest;

        if (year < length) {

            accumulation[year] = newCapital;
        }

        year++;
    }

    if (year < length) {
        *success = 1;
    }

    return year;
}

#define Length  10

void exercise_zinsberechnung_mit_array()
{
    double capital = 1000.0;

    double rate = 5.0;

    double accumulatedCapital[Length] = { 0.0 };

    int succeeded = 0;  // 0 == not succeeded, 1 == succeeded

    int years = doubleInterestRateWithWithAccumulation(
        capital, rate, accumulatedCapital, Length, &succeeded
    );

    printf("After %d years, a capital of %lf with interest rate %.2lf is doubled!\n",
        years, capital, rate);

    for (int i = 0; i < Length; i++)
    {
        printf("%2d. years: capital = %.2lf\n", (i + 1), accumulatedCapital[i]);
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================