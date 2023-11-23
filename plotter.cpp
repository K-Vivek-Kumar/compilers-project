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

    outFile << "def plot_points(points):\n";
    outFile << "    if len(points) >= 1:\n";
    outFile << "        x_values = [point[0] for point in points]\n";
    outFile << "        y_values = [point[1] for point in points]\n";
    outFile << "        plt.scatter(x_values, y_values, color='red', marker='o')\n";
    outFile << "        plt.xlabel('X-axis')\n";
    outFile << "        plt.ylabel('Y-axis')\n";
    outFile << "        plt.title('Points Plot')\n";
    outFile << "        plt.show()\n\n";

    outFile << "def plot_lines(lines):\n";
    outFile << "    if len(lines) > 1:\n";
    outFile << "        for line in lines:\n";
    outFile << "            plt.plot([line[0][0], line[1][0]], [line[0][1], line[1][1]], color='blue')\n";
    outFile << "        plt.xlabel('X-axis')\n";
    outFile << "        plt.ylabel('Y-axis')\n";
    outFile << "        plt.title('Lines Plot')\n";
    outFile << "        plt.show()\n\n";

    outFile << "def plot_polygons(polygons):\n";
    outFile << "    if len(polygons) > 2:\n";
    outFile << "        for polygon in polygons:\n";
    outFile << "            plt.plot([point[0] for point in polygon], [point[1] for point in polygon], color='green')\n";
    outFile << "            plt.plot(polygon[0][0], polygon[0][1], 'go')  # Mark the starting point\n";
    outFile << "        plt.xlabel('X-axis')\n";
    outFile << "        plt.ylabel('Y-axis')\n";
    outFile << "        plt.title('Polygons Plot')\n";
    outFile << "        plt.show()\n\n";

    outFile << "if _name_ == \"_main_\":\n";
    outFile << "    points = [\n";

    for (const auto &point : points)
    {
        outFile << "        (" << point.first << ", " << point.second << "),\n";
    }

    outFile << "    ]\n";

    outFile << "    lines = [\n";

    outFile << "    lines = [\n";

    for (int i = 0; i < lines.size() - 1; i++)
    {
        outFile << "        ((" << lines[i].first << ", " << lines[i].second << "), ("
                << lines[i + 1].first << ", " << lines[i + 1].second << ")),\n";
    }

    outFile << "    ]\n";

    outFile << "    ]\n";

    outFile << "    polygons = [\n";

    for (const auto &polygon : polygons)
    {
        outFile << "        (\n";
        for (const auto &point : polygons)
        {
            outFile << "            (" << point.first << ", " << point.second << "),\n";
        }
        outFile << "        ),\n";
    }

    outFile << "    ]\n";

    outFile << "    plot_points(points)\n";
    outFile << "    plot_lines(lines)\n";
    outFile << "    plot_polygons(polygons)\n";

    outFile.close();
}
