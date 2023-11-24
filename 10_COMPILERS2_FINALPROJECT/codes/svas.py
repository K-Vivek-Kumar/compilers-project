import sys
import matplotlib.pyplot as plt

from polygons import plot_polygons

from polygons import plot_points

from polygons import plot_lines

plt.figure()
if __name__ == "__main__":
    points = [
        (5, 8),
        (9, 0),
    ]
    lines = [
        ((5, 8), (9, 0)),
    ]
    polygons = [
        (5, 5),
        (10, 10),
        (10, 5),
        (5, 0),
        (5, 5),
    ]
    plot_points(points)
    plot_lines(lines)
    plot_polygons(polygons)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('All Plots')
    plt.show()
