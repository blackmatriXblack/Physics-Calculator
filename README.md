# Physics-Calculator
Physics Calculator Suite v1.0 is a comprehensive, terminal-based computational tool designed for students, educators, and engineers. Developed in standard C, this application provides a unified interface for solving problems across ten major domains of classical physics, including Kinematics, Dynamics, Thermodynamics, and Electromagnetism.
# Physics Calculator Suite v1.0 – Technical Documentation

## 1. Project Overview

**Physics Calculator Suite v1.0** is a comprehensive, terminal-based computational tool designed for students, educators, and engineers. Developed in standard C, this application provides a unified interface for solving problems across ten major domains of classical physics, including Kinematics, Dynamics, Thermodynamics, and Electromagnetism.

The program features a modular architecture, robust input validation, and an interactive menu system that guides users through complex calculations. It also includes specialized features such as multi-planetary gravity support and ideal gas law verification, making it a versatile utility for both academic learning and quick professional reference.

### 1.1 Core Objectives
*   **Educational Aid:** Provide immediate feedback on physics problems, helping users understand the relationship between variables (e.g., how mass affects gravitational force on different planets).
*   **Computational Accuracy:** Utilize double-precision floating-point arithmetic to ensure high-accuracy results for scientific calculations.
*   **User-Centric Design:** Implement a clear, step-by-step input process with error handling to prevent common user mistakes (such as division by zero).
*   **Cross-Platform Portability:** Written in ANSI C with minimal dependencies, ensuring compatibility across Windows, Linux, and macOS environments.

### 1.2 Key Features
*   **10 Specialized Modules:** Covering Kinematics, Dynamics, Energy, Waves, Electricity, Thermodynamics, Forces, Projectile Motion, Work-Energy Theorem, and Simple Harmonic Motion (SHM).
*   **Multi-Planetary Gravity Engine:** A built-in database of 10 celestial bodies (Mercury to Pluto) allows users to calculate gravitational force in various extraterrestrial environments.
*   **Ideal Gas Law Validator:** Unlike simple calculators, this module checks if provided Pressure, Volume, Moles, and Temperature values satisfy the equation $PV = nRT$.
*   **Robust Input Validation:** Every input field is checked for validity. The program handles non-numeric inputs gracefully and prevents mathematical errors like division by zero.

---

## 2. System Architecture

### 2.1 Data Structures

The application uses a simple but effective `struct` to manage planetary data:

```c
typedef struct {
    const char* name;   // Name of the celestial body
    double gravity;     // Surface gravity in m/s^2
} Planet;
```

*   **Global Array:** `Planet planets[]` stores constants for 10 bodies, allowing $O(1)$ access time during gravity calculations.
*   **Constants:** Defined at the top level for precision:
    *   `PI`: 3.14159265358979323846
    *   `G`: 6.67430e-11 (Universal Gravitational Constant, reserved for future expansion).

### 2.2 Module Structure

The program follows a **Modular Procedural Design**. Each physics domain is encapsulated in its own function, promoting code readability and maintainability.

| Module | Function Name | Key Calculations |
| :--- | :--- | :--- |
| **Kinematics** | `kinematicsCalculator()` | Displacement ($s=ut+0.5at^2$), Final Velocity ($v=u+at$), Acceleration |
| **Dynamics** | `dynamicsCalculator()` | Force ($F=ma$), Momentum ($p=mv$), Impulse ($J=Ft$) |
| **Energy** | `energyCalculator()` | Kinetic Energy, Potential Energy, Work |
| **Waves** | `waveCalculator()` | Wave Speed, Frequency, Wavelength |
| **Electricity** | `electricityCalculator()` | Ohm’s Law ($V=IR$), Power ($P=VI$) |
| **Thermodynamics**| `thermodynamicsCalculator()` | Ideal Gas Law Check, Heat Capacity ($Q=mc\Delta T$) |
| **Forces** | `forceCalculator()` | Gravity (Multi-planet), Friction, Centripetal Force |
| **Projectile** | `projectileCalculator()` | Range Calculation ($R = \frac{u^2 \sin 2\theta}{g}$) |
| **Work-Energy** | `workEnergyCalculator()` | Work-Energy Theorem ($W = \Delta KE$) |
| **SHM** | `shmCalculator()` | Mass-Spring Period, Pendulum Period |

---

## 3. Detailed Module Analysis

### 3.1 The Main Control Loop (`main`)

The entry point of the application features a `while(1)` infinite loop that serves as the main menu dispatcher.

*   **Input Sanitization:**
    ```c
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // Clear buffer
        continue;
    }
    ```
    This block ensures that if a user enters a character instead of an integer, the program does not crash or enter an infinite loop. It clears the input buffer and re-prompts the user.

*   **Pause Mechanism:**
    After each calculation, the program waits for the user to press Enter (`getchar()` twice) before returning to the main menu. This prevents the screen from flashing too quickly and allows users to review results.

### 3.2 Force Calculator & Planetary Database (`forceCalculator`)

This is one of the most sophisticated modules. It demonstrates the use of the `Planet` struct.

1.  **Selection Interface:** It iterates through the `planets` array to display a numbered list of celestial bodies.
2.  **Validation:** It checks if the selected planet index `p` is within bounds (`1 <= p <= planetCount`).
3.  **Calculation:**
    $$ F_g = m \times g_{planet} $$
    Where $g_{planet}$ is retrieved directly from the struct array.

### 3.3 Thermodynamics Validator (`thermodynamicsCalculator`)

This module goes beyond simple calculation by performing a **consistency check** for the Ideal Gas Law.

*   **Logic:** It calculates both sides of the equation $PV = nRT$.
*   **Floating Point Comparison:**
    ```c
    if (fabs(P*V - n*R*T) < 1e-9)
    ```
    It uses `fabs` (floating-point absolute value) and a small epsilon ($1e-9$) to determine if the values are approximately equal. This accounts for minor floating-point precision errors inherent in computer arithmetic.

### 3.4 Simple Harmonic Motion (`shmCalculator`)

Added in v1.0, this module handles oscillatory systems.

*   **Mass-Spring System:**
    $$ T = 2\pi \sqrt{\frac{m}{k}} $$
*   **Simple Pendulum:**
    $$ T = 2\pi \sqrt{\frac{L}{g}} $$
*   **Safety Checks:** It explicitly checks if mass, spring constant, or length are positive numbers, returning an error if they are zero or negative, as these physical quantities cannot be non-positive in this context.

### 3.5 Projectile Motion (`projectileCalculator`)

*   **Angle Conversion:** The user inputs angles in degrees, which are converted to radians for the `sin()` function:
    ```c
    double rad = theta * PI / 180.0;
    ```
*   **Range Formula:** Implements the standard range equation for projectile motion on a flat plane, assuming Earth's gravity ($9.81 m/s^2$).

---

## 4. User Interface & Experience

### 4.1 Menu System
The interface is text-based but structured for clarity.
*   **Header:** Clearly identifies the program as "Physics Calculator".
*   **Numbered Options:** Users select modules by entering integers (0-11).
*   **Help Section:** Option 11 provides a quick summary of all available functions, acting as a built-in manual.

### 4.2 Output Formatting
Results are printed with 4 decimal places (`%.4f`), providing sufficient precision for most academic purposes without cluttering the screen with excessive digits.

**Example Output:**
```text
--- Kinematics Calculator ---
1. Displacement (s = ut + 0.5at^2)
...
Initial velocity (u) [m/s]: 10
Time (t) [s]: 5
Acceleration (a) [m/s^2]: 2
Displacement: 75.0000 m
```

---

## 5. Compilation and Deployment

### 5.1 Prerequisites
*   **Compiler:** GCC, Clang, or MSVC.
*   **Standard Library:** Requires `<stdio.h>`, `<stdlib.h>`, `<math.h>`, `<string.h>`, `<ctype.h>`.
*   **Linking:** On Linux/macOS, you must link the math library using `-lm`.

### 5.2 Build Instructions

**On Linux/macOS:**
```bash
gcc main.c -o physics_calc -lm
./physics_calc
```

**On Windows (MinGW/GCC):**
```cmd
gcc main.c -o physics_calc.exe -lm
physics_calc.exe
```

**On Windows (MSVC):**
```cmd
cl main.c
physics_calc.exe
```
*(Note: MSVC usually links math functions by default, so `-lm` is not required.)*

---

## 6. Code Quality & Best Practices

### 6.1 Strengths
1.  **Input Validation:** Extensive use of `scanf` return value checks prevents crashes from unexpected input types.
2.  **Division by Zero Protection:** Explicit checks for zero denominators in Acceleration, Frequency, Wavelength, and Centripetal Force calculations.
3.  **Modularity:** Each calculator is a separate function, making it easy to debug or extend specific physics domains without affecting others.
4.  **Memory Safety:** The program uses stack-allocated variables and fixed-size arrays, avoiding dynamic memory allocation issues like leaks or fragmentation.

### 6.2 Areas for Improvement
1.  **Variable Naming in Dynamics:** In `dynamicsCalculator`, case 1 uses variable `v` to store acceleration input (`scanf("%lf", &v)`). While functional, this is confusing. It should be renamed to `a` for clarity.
2.  **Hardcoded Gravity:** The `energyCalculator` and `projectileCalculator` hardcode Earth's gravity ($9.81$). Integrating the `Planet` struct into these modules would allow users to calculate potential energy or projectile range on Mars or the Moon.
3.  **Buffer Clearing:** The `main` loop uses `getchar()` twice to pause. A more robust approach would be a dedicated `wait_for_enter()` function that clears the entire buffer until a newline is found.

---

## 7. Future Roadmap

### 7.1 Short-Term Enhancements
*   **Unit Conversion:** Add a module for converting between units (e.g., Joules to Calories, Meters to Feet).
*   **Graphing Output:** Integrate with a lightweight library (like `gnuplot`) to visualize projectile paths or wave functions.
*   **History Log:** Save the last 10 calculations to a file for review.

### 7.2 Long-Term Vision
*   **Symbolic Calculation:** Integrate a symbolic math library to solve for variables algebraically rather than just numerically.
*   **GUI Frontend:** Port the logic to a graphical interface using Qt or GTK for a more modern user experience.
*   **Advanced Physics:** Add modules for Relativity (Time Dilation) and Quantum Mechanics (Photon Energy).

---

## 8. Conclusion

**Physics Calculator Suite v1.0** is a robust, well-structured educational tool that effectively bridges the gap between theoretical physics formulas and practical computation. Its emphasis on input validation and modular design makes it a reliable resource for students and professionals alike. By combining classic mechanics with thermodynamic validation and multi-planetary support, it offers a depth of functionality rarely found in simple command-line utilities.
