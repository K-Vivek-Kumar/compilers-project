#include <iostream>
#include <fstream>
#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void plot_points(const std::vector<std::pair<double, double>> &points) {
    if (points.size() >= 1) {
        std::vector<double> x_values, y_values;
        for (const auto &point : points) {
            x_values.push_back(point.first);
            y_values.push_back(point.second);
        }
        plt::scatter(x_values, y_values, "red", "o");
    }
}

void plot_lines(const std::vector<std::pair<double, double>> &lines) {
    if (lines.size() > 1) {
        for (const auto &line : lines) {
            plt::plot({line.first, line.second}, {line.first, line.second}, "blue");
        }
    }
}

void plot_polygons(const std::vector<std::pair<double, double>> &polygons) {
    if (polygons.size() > 2) {
        std::vector<double> x_polygon, y_polygon;
        for (const auto &point : polygons) {
            x_polygon.push_back(point.first);
            y_polygon.push_back(point.second);
        }
        plt::plot(x_polygon, y_polygon, "green");
        plt::plot(polygons[0].first, polygons[0].second, "go");
    }
}

void generate(const std::vector<std::pair<double, double>> &points,
                          const std::vector<std::pair<double, double>> &lines,
                          const std::vector<std::pair<double, double>> &polygons) {
    plt::figure();
    plot_points(points);
    plot_lines(lines);
    plot_polygons(polygons);
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    plt::title("All Plots");
    plt::show();
}
