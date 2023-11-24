#include "funcs.h"
#include <iostream>
using namespace std;
#include "plotter.h"
std::vector<std::pair<double, double>> points;
std::vector<std::pair<double, double>> lines;
std::vector<std::pair<double, double>> polygons;
#include <vector>

int x = 0;
int y = 0;

int main()
{
    int x;
    x = 4;
    int y;
    y = 2;
    points.emplace_back(x, y);

    polygons.emplace_back(x, y);

    lines.emplace_back(x, y);

    x = 7;
    y = 3;
    polygons.emplace_back(x, y);

    lines.emplace_back(x, y);

    x = 12;
    y = 6;
    polygons.emplace_back(x, y);

    points.emplace_back(x, y);

    lines.emplace_back(x, y);

    while (3 >= x)
    {
        int j;
        for (j = 0; j < 3; j = j + 1)
        {
            int y;
            cout << (j);
            if (j == 1)
            {
            }
        }
        x = x + 1;
        if (x == 2)
        {
        }
    }
    generatePythonScript(points, lines, polygons);
    cout << "Enter any key for graph generation...";
    cin.get();
    points.clear();
    lines.clear();
    polygons.clear();

    system("python svas.py");

    x = 9;
    y = 2;
    polygons.emplace_back(x, y);

    x = 3;
    y = 4;
    polygons.emplace_back(x, y);

    x = 1;
    y = 0;
    polygons.emplace_back(x, y);

    x = -1;
    y = -2;
    polygons.emplace_back(x, y);

    generatePythonScript(points, lines, polygons);
    cout << "Enter any key for graph generation...";
    cin.get();
    points.clear();
    lines.clear();
    polygons.clear();

    system("python svas.py");

    return 0;
}