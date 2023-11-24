#include <iostream>
#include <fstream>
#include <vector>
#include "plotter.h"

void generatePythonScript(const std::vector<std::pair<double, double>> &points,
                          const std::vector<std::pair<double, double>> &lines,
                          const std::vector<std::pair<double, double>> &polygons)
{
    std::ofstream outFile("svas.py");

    outFile << "import sys\n";
    outFile << "import matplotlib.pyplot as plt\n\n";
    outFile << "from polygons import plot_polygons\n\n";
    outFile << "from polygons import plot_points\n\n";
    outFile << "from polygons import plot_lines\n\n";

    outFile << "plt.figure()\n";

    outFile << "if __name__ == \"__main__\":\n";
    outFile << "    points = [\n";

    for (int i = 0; i < points.size(); i++)
    {
        outFile << "        (" << points[i].first << ", " << points[i].second << "),\n";
    }

    outFile << "    ]\n";
    outFile << "    lines = [\n";
    for (int i = 0; i < (lines.size() - 1); i++)
    {
        outFile << "        ((" << lines[i].first << ", " << lines[i].second << "), ("
                << lines[i + 1].first << ", " << lines[i + 1].second << ")),\n";
    }
    outFile << "    ]\n";

    outFile << "    polygons = [\n";

    for (int i = 0; i < polygons.size(); i++)
    {
        outFile << "        (" << polygons[i].first << ", " << polygons[i].second << "),\n";
    }

    outFile << "    ]\n";

    outFile << "    plot_points(points)\n";
    outFile << "    plot_lines(lines)\n";
    outFile << "    plot_polygons(polygons)\n";
    outFile << "    plt.xlabel('X-axis')\n";
    outFile << "    plt.ylabel('Y-axis')\n";
    outFile << "    plt.title('All Plots')\n";
    outFile << "    plt.show()\n";

    outFile.close();
}
