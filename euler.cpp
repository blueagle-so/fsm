#include <stdio.h>

double func(double x, double y)
{
	return x*x-y; // функция первой производной
}

int main(int argc, char** argv)
{
    int i, n; 
    int x, y, h;

    h = 1; // шаг
    n = 10; // количество итераций
    x = 1; // x0
    y = 1; // y0

    for (i = 0; i < n; i++)
    {
	printf("x=%i, y=%i\n",x,y);
        y += h * func(x, y); // вычисление yi
        x += h;
	//printf("x=%i, y=%i\n",x,y);
    }

    return 0;
}
