#include "TXLib.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

void element_pillar (int number);
void graph();
double basisPolynom(int x, int j, vector <double> &vec, int size);
int check(int x, vector <double> &vec, int size);

const int X = GetSystemMetrics(SM_CXSCREEN);
const int Y = GetSystemMetrics(SM_CYSCREEN);
const int SCALEX = 11;
const double SCALEY = 2.7;

double element_mass[] = {1.0, 4.0, 6.94, 9.0, 10.8, 12.0, 14.0, 16.0, 19.0, 20.18, 23.0, 24.3, 27.0, 28.0, 30.97, 32.0, 35.45, 39.94, 39.0, 40.0, 44.95, 47.8, 50.94,
 52.0, 54.93, 55.85, 58.93, 58.69, 63.55, 65.38, 69.72, 72.63, 74.92, 78.97, 79.9, 83.8, 85.47, 87.6, 88.9, 91.2, 92.9, 95.95, 98, 101.0, 102.9, 106.4, 107.87, 112.4,
 114.8, 118.7, 121.76, 127.6, 126.9, 131.29, 132.9, 137.33, 138.9, 140.1, 140.9, 144.24, 145, 150.36, 151.96, 157.25, 158.93, 162.5, 164.93, 167.26, 168.93,
 173.0, 174.97, 178.49, 180.95, 183.84, 186.2, 190.2, 192.2, 195.0, 196.97, 200.6, 204.38, 207.2, 208.98, 209, 210, 222, 223, 226, 227, 232.0, 231.0, 238.0, 237,
 244.0, 243.0, 247.0, 247.0, 251.0, 252.0, 257.0, 258.0, 259.0, 266.0, 267.0, 268.0, 269.0, 270.0, 277.0, 278.0, 281.0, 282.0, 285.0, 286.0, 289.0, 290.0, 293.0, 294.0, 294.0, 1};
const char* element_massstring[] = {"1.0", "4.0", "6.94", "9.0", "10.8", "12.0", "14.0", "16.0", "19.0",
 "20.18", "23.0", "24.3", "27.0", "28.0", "30.97", "32.0", "35.45", "39.94", "39.0", "40.0", "44.95", "47.8", "50.94",
 "52.0", "54.93", "55.85", "58.93", "58.69", "63.55", "65.38", "69.72", "72.63", "74.92", "78.97", "79.9", "83.8", "85.47", "87.6", "88.9", "91.2", "92.9", "95.95", "98", "101.0", "102.9", "106.4", "107.87", "112.4",
 "114.8", "118.7", "121.76", "127.6", "126.9", "131.29", "132.9", "137.33", "138.9", "140.1", "140.9", "144.24", "145", "150.36", "151.96", "157.25", "158.93", "162.5", "164.93", "167.26", "168.93",
 "173.0", "174.97", "178.49", "180.95", "183.84", "186.2", "190.2", "192.2", "195.0", "196.97", "200.6", "204.38", "207.2", "208.98", "209.0", "210.0", "222.0", "223.0", "226.0", "227.0", "232.0", "231.0", "238.0", "237.0",
 "244.0", "243.0", "247.0", "247.0", "251.0", "252.0", "257.0", "258.0", "259.0", "266.0", "267.0", "268.0", "269.0", "270.0", "277.0", "278.0", "281.0", "282.0", "285.0", "286.0", "289.0", "290.0", "293.0", "294.0", "294.0", "1"};
const char*  element_name [] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K",
"Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mb", "Tc", "Ru", "Rh", "Pd", "Ar", "Cd",
"In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt",
"Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs",
"Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og", "Fil"} ;
int element_type [] = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


int main()
    {
     //setlocale(LC_ALL, "Russian");
     txCreateWindow(X, Y);
     txSetFillColour(TX_WHITE);
     txRectangle(0, 0, X, Y);
     txSetFillColour(TX_BLACK);

     txSetColor (TX_BLACK, 4);
     txSelectFont ("Times New Roman", 30);
     txTextOut(45 , 20, "M (g / mol)");
     txTextOut(X-140 , Y-45, "Number");

     txLine(100, 50, 100, Y-50);
     txLine(100, Y-50, X-100, Y-50);

     for (int i = 0; i < 118; i++) element_pillar(i);

    //graph(); прорисовка моего графа

    vector <double> coordsX;
    vector <double> coordsY;
    int sizeOfArray = 0;

    cout << "\n" << endl;
    while (!GetAsyncKeyState(VK_ESCAPE))
        {
        int xpos = txMouseX();
        int n = (xpos-120)/SCALEX;
        if (xpos < 119 + 118 * SCALEX && xpos > 120)
            {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_WHITE);
            txRectangle(130, 50, 250, 200);

            txSetColor(TX_RED);
            txSelectFont ("Times New Roman", 55);
            txTextOut(130, 70, element_name[n]);

            txSelectFont ("Times New Roman", 30);
            txTextOut(130, 120, element_massstring[n]);

            txSelectFont ("Times New Roman", 20);
            stringstream strs;
            strs << n+1;
            string temp_str = strs.str();
            char* char_type = (char*) temp_str.c_str();
            txTextOut(195, 96, char_type);

            if (GetAsyncKeyState(VK_RBUTTON))
                {
                int res = check(xpos - xpos%11 + 5, coordsX,sizeOfArray);
                if (res == -1)
                    {
                    coordsX.push_back(xpos - xpos%11 + 5);
                    coordsY.push_back(Y - element_mass[n]*SCALEY - 50);
                    }
                else
                    {
                    coordsX.erase(coordsX.begin()+res);
                    coordsY.erase(coordsY.begin()+res);
                    }

                sizeOfArray = coordsX.size();
                cout << sizeOfArray << " [" << n+1 << "]"<< endl;

                txSetColor(TX_WHITE);
                txSetFillColor(TX_WHITE);
                txRectangle(0, 0, X, Y);
                txSetColor (TX_BLACK, 4);
                txSelectFont ("Times New Roman", 30);
                txTextOut(45 , 20, "M (g / mol)");
                txTextOut(X-140 , Y-45, "Number");
                txLine(100, 50, 100, Y-50);
                txLine(100, Y-50, X-100, Y-50);
                for (int i = 0; i < 118; i++) element_pillar(i);

                for (double x = 0; x < X; x += 0.1)
                    {
                    double y = 0;
                    for (int j = 0; j < sizeOfArray; j++)
                        {
                        y += coordsY[j]*basisPolynom(x, j, coordsX, sizeOfArray);
                        }

                    if (check(x, coordsX, sizeOfArray) != -1)
                        {
                        txSetColour    (RGB(0, 0, 255));
                        txSetFillColour(RGB(0, 0, 255));
                        txCircle(x, y, 5);
                        }

                    else
                        {
                        txSetColour    (RGB(255, 0, 0));
                        txSetFillColour(RGB(255, 0, 0));
                        txCircle(x, y, 1.5);
                        }
                    }
                }
            }

        txSleep(70);
        }
    }


void element_pillar (int number)
    {
    txSetColor (TX_BLACK, 2);
    if (element_type[number] == 0) txSetFillColor (RGB(80, 80, 80));
    else txSetFillColor (RGB(40, 40, 40));

    txRectangle(120 + number*SCALEX, Y-52,
                                     120 + (number+1)*SCALEX, Y-52 - element_mass[number]*SCALEY);
    }

void graph()
    {
    for (double xcord = 120; xcord < X; xcord += 0.5)
        {
        double xnew = xcord-120;
        //double y = GetSystemMetrics(SM_CYSCREEN) - 53 - 2*xnew*2.7/11;
        double y = GetSystemMetrics(SM_CYSCREEN) - 53 - pow(xnew, 1.08)*0.36;
        txSetColor     (RGB(255, 0, 0));
        txSetFillColor (RGB(255, 0, 0));
        txCircle (xcord, y, 2);
        }
    }

double basisPolynom(int x, int j, vector <double> &vec, int size)
    {
    double result = 1;
    for (int i = 0; i < size; i++)
        {
        if (i != j) result *= (x-vec[i])/(vec[j]-vec[i]);
        }

    return result;
    }

int check(int x, vector <double> &vec, int size)
    {
    for (int i = 0; i < size; i++)
        {
        if (x == vec[i]) return i;
        }

    return -1;
    }

