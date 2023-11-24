#include <iostream>
#include <fstream>
#include <vector>

void generatePythonScript(const std::vector<std::pair<double, double>> &points,
                          const std::vector<std::pair<double, double>> &lines,
                          const std::vector<std::pair<double, double>> &polygons)
{
    std::ofstream outFile("svas.py");

    outFile << "import sys\n";
    outFile << "import matplotlib.pyplot as plt\n\n";

    // Create one figure for all plots
    outFile << "plt.figure()\n";

    outFile << "def plot_points(points):\n";
    outFile << "    if len(points) >= 1:\n";
    outFile << "        x_values = [point[0] for point in points]\n";
    outFile << "        y_values = [point[1] for point in points]\n";
    outFile << "        plt.scatter(x_values, y_values, color='red', marker='o')\n";

    outFile << "def plot_lines(lines):\n";
    outFile << "    if len(lines) > 1:\n";
    outFile << "        for line in lines:\n";
    outFile << "            plt.plot([line[0][0], line[1][0]], [line[0][1], line[1][1]], color='blue')\n";

    outFile << "def plot_polygons(polygons):\n";
    outFile << "    if len(polygons) > 2:\n";
    outFile << "        x_polygon = [point[0] for point in polygons]\n";
    outFile << "        y_polygon = [point[1] for point in polygons]\n";

    // Connect all adjacent points in the polygon
    outFile << "        plt.plot(x_polygon + [x_polygon[0]], y_polygon + [y_polygon[0]], color='green')\n";
    outFile << "        plt.plot(polygons[0][0], polygons[0][1], 'go')  # Mark the starting point\n";

    outFile << "if __name__ == \"__main__\":\n";
    outFile << "    points = [\n";

    for (const auto &point : points)
    {
        outFile << "        (" << point.first << ", " << point.second << "),\n";
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

    for (const auto &point : polygons)
    {
        outFile << "        (" << point.first << ", " << point.second << "),\n";
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
