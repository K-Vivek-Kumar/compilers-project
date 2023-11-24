import sys
import matplotlib.pyplot as plt

plt.figure()
def plot_points(points):
    if len(points) >= 1:
        x_values = [point[0] for point in points]
        y_values = [point[1] for point in points]
        plt.scatter(x_values, y_values, color='red', marker='o')
def plot_lines(lines):
    if len(lines) > 1:
        for line in lines:
            plt.plot([line[0][0], line[1][0]], [line[0][1], line[1][1]], color='blue')
def plot_polygons(polygons):
    if len(polygons) > 2:
        x_polygon = [point[0] for point in polygons]
        y_polygon = [point[1] for point in polygons]
        plt.plot(x_polygon + [x_polygon[0]], y_polygon + [y_polygon[0]], color='green')
        plt.plot(polygons[0][0], polygons[0][1], 'go')  # Mark the starting point
if __name__ == "__main__":
    points = [
    ]
    lines = [
        ((0, 0), (1, 1)),
        ((1, 1), (4, 2)),
        ((4, 2), (9, 3)),
        ((9, 3), (16, 4)),
        ((16, 4), (25, 5)),
        ((25, 5), (36, 6)),
        ((36, 6), (49, 7)),
        ((49, 7), (64, 8)),
        ((64, 8), (81, 9)),
    ]
    polygons = [
    ]
    plot_points(points)
    plot_lines(lines)
    plot_polygons(polygons)
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('All Plots')
    plt.show()
