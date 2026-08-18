# Scientific Calculator in C

A comprehensive, interactive, menu-driven CLI Scientific Calculator developed in C as a **1st Semester Academic Project**. This calculator provides an extensive suite of mathematical tools ranging from standard arithmetic to linear algebra (matrices & vectors), trigonometry, base conversions, unit conversions, combinatorics, and polynomial root solving.

---

## 👥 Contributors & Module Breakdown

This project was built collaboratively by a team of 4 members, each designing and implementing specific mathematical modules:

| Contributor | Assigned Modules & Features |
| :--- | :--- |
| **Prithu** | Matrix Operations, Vector Operations, Powers & Roots |
| **Tahmid** | Arithmetic Operations, Logarithms, Number Base Conversions |
| **Rumi** | Trigonometric Functions (Normal & Inverse), Unit Conversions |
| **Arif** | Factorials, Permutations ($nPr$), Combinations ($nCr$), Polynomial Root Solving |

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
  - Dot Product (u · v)
  - Cross Product (u × v)

### 3. 📐 Trigonometry (Normal & Inverse)
- **Direct Functions:** sin(x), cos(x), tan(x), sec(x), csc(x), cot(x) (accepts input in degrees)
- **Inverse Functions:** arcsin(x), arccos(x), arctan(x), arcsec(x), arccsc(x), arccot(x) (returns angles in degrees)

### 4. 📈 Logarithms
- Natural Logarithm (ln x)
- Common Logarithm (log₁₀ x)
- Logarithm with arbitrary base (log_b x)

### 5. 🔄 Number Base Conversions
- Decimal to Binary & Binary to Decimal
- Decimal to Hexadecimal & Hexadecimal to Decimal

### 6. 📏 Unit Conversions
- **Distance:** Km ↔ Miles, Meters ↔ Feet, Cm ↔ Inches, Meters ↔ Yards, Km ↔ Nautical Miles
- **Weight:** Kg ↔ Pounds, Grams ↔ Ounces
- **Liquid Volume:** Liters ↔ Gallons
- **Temperature:** Celsius ↔ Fahrenheit ↔ Kelvin

### 7. 🎲 Combinatorics & Polynomials
- **Factorials:** n!
- **Permutations:** P(n, r) = n! / (n - r)!
- **Combinations:** C(n, r) = n! / (r! * (n - r)!)
- **Polynomial Roots:** Solve quadratic equations ax² + bx + c = 0

---

## 🛠️ Project Structure

```text
scientific-calculator-c/
├── main.c              # Source code containing all modules & function definitions
└── README.md           # Project documentation
