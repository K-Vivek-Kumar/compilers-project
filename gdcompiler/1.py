import sys
import matplotlib.pyplot as plt


def plot_point(x, y):
    plt.scatter(float(x), float(y), color="red", marker="o")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.title("Point Plot")
    plt.show()


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <x> <y>")
        sys.exit(1)

    x_arg = sys.argv[1]
    y_arg = sys.argv[2]

    plot_point(x_arg, y_arg)
