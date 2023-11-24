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

int main(){
 int x;
 x = 4;
  polygons.emplace_back(x, y);

 points.emplace_back(x, y);

 lines.emplace_back(x, y);

 x = 7;
 polygons.emplace_back(x, y);

 lines.emplace_back(x, y);

 x = 12;
 polygons.emplace_back(x, y);

 points.emplace_back(x, y);

 lines.emplace_back(x, y);

 switch (x)
 {
 case 1:
 cout << (1);
 case  2:
 cout << (2)  ;cout << endl;cout << endl;
 case 3:
 cout << (3);
 default:
 cout << (5);
 }
 if(x < 3){
 
 }
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
points.clear();
lines.clear();
polygons.clear();

 system("python svas.py");

 x = 9;
 return 0;
}