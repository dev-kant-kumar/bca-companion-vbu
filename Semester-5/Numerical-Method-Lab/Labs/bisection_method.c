// find the root of x^3 - x - 1 = 0

// f(a) * f(b) < 0 = root lies between a and b

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - x - 1);
}

int main()
{

    float a, b, c;
    int i = 1;

    a = 1.0;
    b = 2.0;

    if (f(a) * f(b) >= 0)
    {
        printf("Bisection Method fails : wrong initial interval");
    }

    printf("%-16s %-25s %-25s %-25s %s\n", "i", "a", "b", "c", "f(c)");

    do
    {

        c = (a + b) / 2;
        printf("%d\t\t %.6f\t\t %.6f\t\t %.6f\t\t %.6f\n", i, a, b, c, f(c));

        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        i++;

    } while (fabs(f(c)) > 0.001);

    printf("\nRoot is = %.3f\n", c);

    return 0;
}
