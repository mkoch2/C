/* Arrays

 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "arrays.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], int n)
{
    double list_total = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        list_total += fabs(x[i]);
    }

    return list_total / n;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], int n)
{
    double power_total = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        // power_total += pow(x[i], 2);
        power_total += x[i] * x[i];
    }
    return power_total / n;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double maxi(double arr[], int n)
{
    double max_num = arr[0];
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] > max_num)
        {
            max_num = arr[i];
        }
    }
    return max_num;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[].
 * This function assumes that parameter n is >= 1.
 */
double mini(double arr[], int n)
{
    double min_num = arr[0];
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] < min_num)
        {
            min_num = arr[i];
        }
    }
    return min_num;
}

/* Exercise 5. */

/* Normalize the n doubles in x[].
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
    double min_num = mini(x, n);
    double max_num = maxi(x, n);

    for (int i = 0; i <= n - 1; i++)
    {
        x[i] = (x[i] - min_num) / (max_num - min_num);
    }
}
