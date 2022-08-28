#include "TXLib.h"
using namespace std;

double basisPolynom(int x, int j, double array[], int size);
int check(int x, double array[], int size);

int main()
    {
    int X_Screen = GetSystemMetrics(SM_CXSCREEN), Y_Screen = GetSystemMetrics(SM_CYSCREEN);
    txCreateWindow(X_Screen, Y_Screen);
    txSetFillColour(RGB(255, 255, 255));
    txRectangle(0, 0,X_Screen, Y_Screen);

    double coordsX[] = {300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200};
    double coordsY[] = {100, 50, 600, 700, 400, 200, 800, 300, 400, 600};
    int sizeOfArray = sizeof(coordsX)/sizeof(double);

    for (int x = 0; x < X_Screen; x++)
        {
        double y = 0;
        for (int j = 0; j < sizeOfArray; j++)
            {
            y += coordsY[j]*basisPolynom(x, j, coordsX, sizeOfArray);
            }

        if (check(x, coordsX, sizeOfArray) == 1)
            {
            txSetColour    (RGB(0, 0, 255));
            txSetFillColour(RGB(0, 0, 255));
            txCircle(x, Y_Screen-y, 5);
            }

        else
            {
            txSetColour    (RGB(255, 0, 0));
            txSetFillColour(RGB(255, 0, 0));
            txCircle(x, Y_Screen-y, 2);
            }
        }

    }

double basisPolynom(int x, int j, double array[], int size)
    {
    double result = 1;
    for (int i = 0; i < size; i++)
        {
        if (i != j) result *= (x-array[i])/(array[j]-array[i]);
        }

    return result;
    }

int check(int x, double array[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        if (x == array[i]) return 1;
        }

    return 0;
    }
