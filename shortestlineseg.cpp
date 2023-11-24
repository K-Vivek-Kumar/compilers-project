#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <future>
#include <algorithm>
#include <limits>

struct Point
{
    double x;
    double y;
};

double calculateDistance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::pair<Point, Point> findShortestLineSegment(const std::vector<Point> &points, int start, int end)
{
    double shortestDistance = std::numeric_limits<double>::max();
    std::pair<Point, Point> shortestSegment;

    for (int i = start; i < end; ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            double distance = calculateDistance(points[i], points[j]);
            if (distance < shortestDistance)
            {
                shortestDistance = distance;
                shortestSegment = {points[i], points[j]};
            }
        }
    }

    return shortestSegment;
}

std::pair<Point, Point> findShortestLineSegmentMultithread(const std::vector<Point> &points)
{
    int numThreads = 2;
    int numPoints = points.size();
    std::vector<std::thread> threads;
    std::vector<std::pair<Point, Point>> results(numThreads);

    int chunkSize = numPoints / numThreads;
    for (int i = 0; i < numThreads; ++i)
    {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? numPoints : (i + 1) * chunkSize;
        threads.emplace_back([start, end, &results, i, &points]
                             { results[i] = findShortestLineSegment(points, start, end); });
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    double shortestDistance = std::numeric_limits<double>::max();
    std::pair<Point, Point> shortestSegment;
    for (const auto &result : results)
    {
        double distance = calculateDistance(result.first, result.second);
        if (distance < shortestDistance)
        {
            shortestDistance = distance;
            shortestSegment = result;
        }
    }

    return shortestSegment;
}

double calculateLineSegmentLength(const Point &p1, const Point &p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}
