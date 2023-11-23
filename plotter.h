#ifndef PLOTTER_H
#define PLOTTER_H

#include <vector>
#include <utility>

void generatePythonScript(const std::vector<std::pair<double, double>> &points, const std::vector<std::pair<double, double>> &lines, const std::vector<std::pair<double, double>> &polygons);

#endif
