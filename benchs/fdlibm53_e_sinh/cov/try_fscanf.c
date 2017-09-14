#include <stdio.h>
int main()
{
    FILE* f = fopen("test.txt", "r");
    double n ;
    int i = 0;
    double numbers[5]; // assuming there are only 5 numbers in the file

    while( fscanf(f, "%lf,", &n) > 0 ) // parse %d followed by ','
    {
        numbers[i++] = n;
        printf ("%f\n",n);
    }

    fclose(f);
}
