#include <stdio.h>
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00
#define MONTHS_PER_YEAR 12  

int main(void)
{
    int i, low_rate, num_years, year, month;
    double value[5];
    double monthly_rate;  

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;  
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        for (month = 0; month < MONTHS_PER_YEAR; month++) {
            for (i = 0; i < NUM_RATES; i++) {
                monthly_rate = (low_rate + i) / 100.0 / MONTHS_PER_YEAR;
                value[i] += monthly_rate * value[i];  
            }
        }
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}
