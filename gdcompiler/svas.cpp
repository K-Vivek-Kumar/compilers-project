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

int vivek(int i){
 return 0;
}

int main(){
 int i;  int j;  i = 0;
 j = 0;
 while(i < 10){
 y = i;
 x = j;
 lines.emplace_back(x, y);

 i = i + 1;
 j = i * i;
 }
 generatePythonScript(points, lines, polygons);
points.clear();
lines.clear();
polygons.clear();

  vivek(1);
 return 0;
}