import sys
import matplotlib.pyplot as plt

def plot_points(points):
    if len(points) >= 1:
        x_values = [point[0] for point in points]
        y_values = [point[1] for point in points]
        plt.scatter(x_values, y_values, color='red', marker='o')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.title('Points Plot')
        plt.show()

def plot_lines(lines):
    if len(lines) > 1:
        for line in lines:
            plt.plot([line[0][0], line[1][0]], [line[0][1], line[1][1]], color='blue')
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.title('Lines Plot')
        plt.show()

def plot_polygons(polygons):
    if len(polygons) > 2:
        for polygon in polygons:
            x_polygon = [point[0] for point in polygon]
            y_polygon = [point[1] for point in polygon]
            plt.plot(x_polygon + [x_polygon[0]], y_polygon + [y_polygon[0]], color='green')
            plt.plot(polygon[0][0], polygon[0][1], 'go')  # Mark the starting point
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.title('Polygons Plot')
        plt.show()

if __name__ == "__main__":
    points = [
        (4, 0),
        (12, 0),
    ]
    lines = [
        ((4, 0), (7, 0)),
        ((7, 0), (12, 0)),
    ]
    polygons = [
            (4, 0),
            (7, 0),
            (12, 0),
    ]
    plot_points(points)
    plot_lines(lines)
    plot_polygons(polygons)
