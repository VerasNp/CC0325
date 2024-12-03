import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import sympy as sp

def plot_polynomial_fit(df):
    # Fit a polynomial to the data
    coefficients = np.polyfit(df['NROWS'], df['Time'], 2)
    poly = np.poly1d(coefficients)

    # Show the polynomial fit equation
    x = sp.Symbol('x')
    poly_equation = sp.Poly(poly(x), x)
    print(f"Polynomial Fit Equation: {poly_equation}")

    # Plot the data points
    plt.plot(df['NROWS'], df['Time'], marker='o', label='Data Points')

    # Plot the polynomial fit, dashed line
    plt.plot(df['NROWS'], poly(df['NROWS']), label='Poly Fit', linestyle='--')

    plt.legend()
    plt.show()


df_cpp = pd.read_csv('./out/output_12022024_234640.csv')
df_cpp.head()

plot_polynomial_fit(df_cpp)