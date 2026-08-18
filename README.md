# Scientific Calculator in C

A comprehensive, interactive, menu-driven CLI Scientific Calculator developed in C as a **1st Semester Academic Project**. This calculator provides an extensive suite of mathematical tools ranging from standard arithmetic to linear algebra, trigonometry, base conversions, unit conversions, combinatorics, and polynomial root solving.

---

## 👥 Contributors & Module Breakdown

This project was built collaboratively by a team of 4 members, each designing and implementing specific mathematical modules:

| Contributor | Assigned Modules & Features |
| :--- | :--- |
| **Prithu** | Matrix Operations, Vector Operations, Powers & Roots |
| **Tahmid** | Arithmetic Operations, Logarithms, Number Base Conversions |
| **Rumi** | Trigonometric Functions (Normal & Inverse), Unit Conversions |
| **Arif** | Factorials, Permutations, Combinations, Polynomial Roots Solving |

---

## ✨ Features & Functionalities

### 1. 🧮 Basic & Advanced Arithmetic
- Standard arithmetic: Addition, Subtraction, Multiplication, Division, Modulus
- Powers & N-th Roots

### 2. 📊 Linear Algebra
- **Matrix Operations** (Supports dimensions up to 10 × 10):
  - Matrix Addition & Subtraction
  - Matrix Multiplication (with dimensional validation)
  - Determinant Calculation (using recursive cofactor expansion)
  - Matrix Inversion
- **Vector Operations** (3D Space: i, j, k):
  - Vector Addition & Subtraction
  - Dot Product & Cross Product

### 3. 📐 Trigonometry (Normal & Inverse)
- **Direct Functions:** sin(x), cos(x), tan(x), sec(x), csc(x), cot(x) (accepts input in degrees)
- **Inverse Functions:** arcsin(x), arccos(x), arctan(x), arcsec(x), arccsc(x), arccot(x)

### 4. 📈 Logarithms & Base Conversions
- Natural Logarithm (ln x), Common Logarithm (log₁₀ x), Arbitrary Base Logarithm (log_b x)
- Decimal ↔ Binary and Decimal ↔ Hexadecimal conversions

### 5. 📏 Unit Conversions
- **Distance:** Km ↔ Miles, Meters ↔ Feet, Cm ↔ Inches, Meters ↔ Yards, Km ↔ Nautical Miles
- **Weight:** Kg ↔ Pounds, Grams ↔ Ounces
- **Liquid Volume:** Liters ↔ Gallons
- **Temperature:** Celsius ↔ Fahrenheit ↔ Kelvin

### 6. 🎲 Combinatorics & Polynomial Roots (Arif's Module)
- **Factorials (`factorial`):**
  - Calculates $n!$ for non-negative integers.
  - Includes error handling for negative inputs ($n < 0$ returns `-1`).
  - Returns `1` for boundary cases $0!$ and $1!$.
- **Permutations (`permutation`):**
  - Computes $P(n, r) = \frac{n!}{(n-r)!}$ using the `long long` data type to handle larger integer values.
  - Validates inputs ($r \le n$ and $n, r \ge 0$).
- **Combinations (`combination`):**
  - Computes $C(n, r) = \frac{n!}{r!(n-r)!}$ using the `long long` data type.
  - Includes validation check ($r \le n$ and $n, r \ge 0$).
- **Polynomial Roots Solving (`polynomiyal_roots`):**
  - Solves quadratic equations of the form $ax^2 + bx + c = 0$.
  - Validates that $a \neq 0$ to ensure the equation is quadratic.

---

## 🛠️ Project Structure

```text
scientific-calculator-c/
├── main.c              # Source code containing all modules & function definitions
└── README.md           # Project documentation
