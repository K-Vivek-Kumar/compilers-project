#include "funcs.h"
#include <iostream>
#include <vector>
using namespace std;
#include "plotter.h"
std::vector<std::pair<double, double>> points;
std::vector<std::pair<double, double>> lines;
std::vector<std::pair<double, double>> polygons;

int x = 0;
int y = 0;

int main(){
 int x;  int y; 
 int   i;
 i = 5;
 x = i;
 y = 5;

 polygons.push_back(std::make_pair(x, y));


 x = 10;
 y = 10;

 
 polygons.push_back(std::make_pair(x, y));


 x = 10;
 y = 5;

 polygons.push_back(std::make_pair(x, y));

 x = 5;
 y = 0;

 polygons.push_back(std::make_pair(x, y));


 x = 5;
 y = 5;

 polygons.push_back(std::make_pair(x, y));


 x = 5;
 y = 8;
 points.push_back(std::make_pair(x, y));

 lines.push_back(std::make_pair(x, y));


 x = 9;
 y = 0;
 points.push_back(std::make_pair(x, y));

 lines.push_back(std::make_pair(x, y));




 generatePythonScript(points, lines, polygons);
points.clear();
lines.clear();
polygons.clear();

 cout << "Press `Enter` key for graph generation...";
cin.get();
system("python svas.py");

 return 0;
}