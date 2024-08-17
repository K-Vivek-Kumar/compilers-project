import matplotlib.pyplot as plt


def plot_polygons(polygons):
    if len(polygons) >= 3:
        x_polygon = [point[0] for point in polygons]
        y_polygon = [point[1] for point in polygons]
        for i in range(len(polygons) - 1):
            plt.plot(
                [x_polygon[i], x_polygon[i + 1]],
                [y_polygon[i], y_polygon[i + 1]],
                color="green",
            )
        plt.plot(
            [x_polygon[-1], x_polygon[0]], [y_polygon[-1], y_polygon[0]], color="green"
        )
        plt.scatter(x_polygon, y_polygon, color="blue", marker="o")
        plt.plot(polygons[0][0], polygons[0][1], "go")

def plot_points(points):
    if len(points) >= 1:
        x_values = [point[0] for point in points]
        y_values = [point[1] for point in points]
        plt.scatter(x_values, y_values, color='red', marker='o')

def plot_lines(lines):
    if len(lines) > 1:
        for line in lines:
            plt.plot([line[0][0], line[1][0]], [line[0][1], line[1][1]], color='blue')
