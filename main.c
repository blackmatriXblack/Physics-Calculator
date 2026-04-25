#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.67430e-11  // Universal gravitational constant

// Planet data for surface gravity (m/s^2)
typedef struct {
    const char* name;
    double gravity;
} Planet;

Planet planets[] = {
    {"Mercury", 3.7}, {"Venus", 8.87}, {"Earth", 9.81},
    {"Mars", 3.71},   {"Jupiter", 24.79}, {"Saturn", 10.44},
    {"Uranus", 8.87}, {"Neptune", 11.15}, {"Moon", 1.62},
    {"Pluto", 0.62}
};
const int planetCount = sizeof(planets) / sizeof(planets[0]);

// Function prototypes
void displayMenu();
void kinematicsCalculator();
void dynamicsCalculator();
void energyCalculator();
void waveCalculator();
void electricityCalculator();
void thermodynamicsCalculator();
void forceCalculator();
void projectileCalculator();
void workEnergyCalculator(); // New: Work-Energy Theorem Calculator
void shmCalculator();        // New: Simple Harmonic Motion Calculator
void help();

int main() {
    int choice;
    while (1) {
        displayMenu();
        // Check if scanf successfully read an integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Go back to the beginning of the loop
        }

        switch (choice) {
            case 1: kinematicsCalculator(); break;
            case 2: dynamicsCalculator(); break;
            case 3: energyCalculator(); break;
            case 4: waveCalculator(); break;
            case 5: electricityCalculator(); break;
            case 6: thermodynamicsCalculator(); break;
            case 7: forceCalculator(); break;
            case 8: projectileCalculator(); break;
            case 9: workEnergyCalculator(); break; // New case
            case 10: shmCalculator(); break;       // New case
            case 11: help(); break;
            case 0: printf("Exiting program. Goodbye!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
        printf("\nPress Enter to continue...");
        // Consume the newline character left by scanf
        getchar();
        // Wait for another newline character (Enter key)
        getchar();
    }
    return 0;
}

// Displays the main menu
void displayMenu() {
    printf("\n===== Physics Calculator =====\n");
    printf("1. Kinematics\n");
    printf("2. Dynamics\n");
    printf("3. Energy\n");
    printf("4. Wave\n");
    printf("5. Electricity\n");
    printf("6. Thermodynamics\n");
    printf("7. Force\n");
    printf("8. Projectile Motion\n");
    printf("9. Work-Energy Theorem\n"); // New menu item
    printf("10. Simple Harmonic Motion (SHM)\n"); // New menu item
    printf("11. Help\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

// Kinematics calculations (unchanged)
void kinematicsCalculator() {
    printf("\n--- Kinematics Calculator ---\n");
    printf("1. Displacement (s = ut + 0.5at^2)\n");
    printf("2. Final Velocity (v = u + at)\n");
    printf("3. Acceleration (a = (v - u)/t)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double u, v, t, a, s;
    switch (choice) {
        case 1:
            printf("Initial velocity (u) [m/s]: "); if (scanf("%lf", &u) != 1) { printf("Invalid input.\n"); return; }
            printf("Time (t) [s]: "); if (scanf("%lf", &t) != 1) { printf("Invalid input.\n"); return; }
            printf("Acceleration (a) [m/s^2]: "); if (scanf("%lf", &a) != 1) { printf("Invalid input.\n"); return; }
            s = u*t + 0.5*a*t*t;
            printf("Displacement: %.4f m\n", s);
            break;
        case 2:
            printf("Initial velocity (u) [m/s]: "); if (scanf("%lf", &u) != 1) { printf("Invalid input.\n"); return; }
            printf("Acceleration (a) [m/s^2]: "); if (scanf("%lf", &a) != 1) { printf("Invalid input.\n"); return; }
            printf("Time (t) [s]: "); if (scanf("%lf", &t) != 1) { printf("Invalid input.\n"); return; }
            v = u + a*t;
            printf("Final velocity: %.4f m/s\n", v);
            break;
        case 3:
            printf("Initial velocity (u) [m/s]: "); if (scanf("%lf", &u) != 1) { printf("Invalid input.\n"); return; }
            printf("Final velocity (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Time (t) [s]: "); if (scanf("%lf", &t) != 1) { printf("Invalid input.\n"); return; }
            if (t == 0) { printf("Error: Time cannot be zero.\n"); return; }
            a = (v - u) / t;
            printf("Acceleration: %.4f m/s^2\n", a);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Dynamics calculations (unchanged)
void dynamicsCalculator() {
    printf("\n--- Dynamics Calculator ---\n");
    printf("1. Force (F = m * a)\n");
    printf("2. Momentum (p = m * v)\n");
    printf("3. Impulse (J = F * t)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double m, v, F, t;
    switch (choice) {
        case 1:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Acceleration (a) [m/s^2]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; } // Note: 'v' is used for 'a' here, might be a typo in original code
            F = m * v;
            printf("Force: %.4f N\n", F);
            break;
        case 2:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Velocity (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Momentum: %.4f kg·m/s\n", m * v);
            break;
        case 3:
            printf("Force (F) [N]: "); if (scanf("%lf", &F) != 1) { printf("Invalid input.\n"); return; }
            printf("Time interval (t) [s]: "); if (scanf("%lf", &t) != 1) { printf("Invalid input.\n"); return; }
            printf("Impulse: %.4f N·s\n", F * t);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Energy calculations (Potential Energy calculation corrected)
void energyCalculator() {
    printf("\n--- Energy Calculator ---\n");
    printf("1. Kinetic Energy (KE = 0.5 * m * v^2)\n");
    printf("2. Gravitational Potential Energy (PE = m * g * h)\n");
    printf("3. Work (W = F * d)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double m, v, h, F, d;
    switch (choice) {
        case 1:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Velocity (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Kinetic Energy: %.4f J\n", 0.5 * m * v * v);
            break;
        case 2:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Height (h) [m]: "); if (scanf("%lf", &h) != 1) { printf("Invalid input.\n"); return; }
            // Using Earth's gravity (9.81 m/s^2) for simplicity, or could ask for 'g'
            printf("Gravitational Potential Energy: %.4f J\n", m * 9.81 * h);
            break;
        case 3:
            printf("Force (F) [N]: "); if (scanf("%lf", &F) != 1) { printf("Invalid input.\n"); return; }
            printf("Displacement (d) [m]: "); if (scanf("%lf", &d) != 1) { printf("Invalid input.\n"); return; }
            printf("Work: %.4f J\n", F * d);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Wave calculations (unchanged)
void waveCalculator() {
    printf("\n--- Wave Calculator ---\n");
    printf("1. Wave speed (v = f * λ)\n");
    printf("2. Frequency (f = v / λ)\n");
    printf("3. Wavelength (λ = v / f)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double v, f, lambda;
    switch (choice) {
        case 1:
            printf("Frequency (f) [Hz]: "); if (scanf("%lf", &f) != 1) { printf("Invalid input.\n"); return; }
            printf("Wavelength (λ) [m]: "); if (scanf("%lf", &lambda) != 1) { printf("Invalid input.\n"); return; }
            printf("Wave speed: %.4f m/s\n", f * lambda);
            break;
        case 2:
            printf("Wave speed (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Wavelength (λ) [m]: "); if (scanf("%lf", &lambda) != 1) { printf("Invalid input.\n"); return; }
             if (lambda == 0) { printf("Error: Wavelength cannot be zero.\n"); return; }
            printf("Frequency: %.4f Hz\n", v / lambda);
            break;
        case 3:
            printf("Wave speed (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Frequency (f) [Hz]: "); if (scanf("%lf", &f) != 1) { printf("Invalid input.\n"); return; }
             if (f == 0) { printf("Error: Frequency cannot be zero.\n"); return; }
            printf("Wavelength: %.4f m\n", v / f);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Electricity calculations (unchanged)
void electricityCalculator() {
    printf("\n--- Electricity Calculator ---\n");
    printf("1. Ohm's Law (V = I * R)\n");
    printf("2. Power (P = V * I)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double V, I, R;
    switch (choice) {
        case 1:
            printf("Current (I) [A]: "); if (scanf("%lf", &I) != 1) { printf("Invalid input.\n"); return; }
            printf("Resistance (R) [Ω]: "); if (scanf("%lf", &R) != 1) { printf("Invalid input.\n"); return; }
            printf("Voltage: %.4f V\n", I * R);
            break;
        case 2:
            printf("Voltage (V) [V]: "); if (scanf("%lf", &V) != 1) { printf("Invalid input.\n"); return; }
            printf("Current (I) [A]: "); if (scanf("%lf", &I) != 1) { printf("Invalid input.\n"); return; }
            printf("Power: %.4f W\n", V * I);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Thermodynamics calculations (Ideal Gas Law check improved)
void thermodynamicsCalculator() {
    printf("\n--- Thermodynamics Calculator ---\n");
    printf("1. Ideal Gas Law (PV = nRT) - Check values\n"); // Clarified this checks the relationship
    printf("2. Heat (Q = m * c * ΔT)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double P, V, n, T, R = 8.314, m, c, dT; // R in J/(mol·K)
    switch (choice) {
        case 1:
            printf("Pressure (P) [Pa]: "); if (scanf("%lf", &P) != 1) { printf("Invalid input.\n"); return; }
            printf("Volume (V) [m3]: "); if (scanf("%lf", &V) != 1) { printf("Invalid input.\n"); return; }
            printf("Amount (n) [mol]: "); if (scanf("%lf", &n) != 1) { printf("Invalid input.\n"); return; }
            printf("Temperature (T) [K]: "); if (scanf("%lf", &T) != 1) { printf("Invalid input.\n"); return; }
            printf("PV = %.4e Pa·m³\n", P*V); // Using scientific notation for potentially large numbers
            printf("nRT = %.4e J\n", n*R*T);
            // Could add a check if PV is approximately equal to nRT
            if (fabs(P*V - n*R*T) < 1e-9) { // Using a small tolerance for floating point comparison
                printf("The values approximately satisfy the Ideal Gas Law (PV ≈ nRT).\n");
            } else {
                printf("The values do not strongly satisfy the Ideal Gas Law (PV ≠ nRT).\n");
            }
            break;
        case 2:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Specific heat (c) [J/(kg·K)]: "); if (scanf("%lf", &c) != 1) { printf("Invalid input.\n"); return; }
            printf("Temperature change (ΔT) [K]: "); if (scanf("%lf", &dT) != 1) { printf("Invalid input.\n"); return; }
            printf("Heat: %.4f J\n", m * c * dT);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Force calculations (unchanged, input validation added)
void forceCalculator() {
    printf("\n--- Force Calculator ---\n");
    printf("1. Gravity on a body (F = m * g)\n");
    printf("2. Friction (F = μ * N)\n");
    printf("3. Centripetal force (F = m * v^2 / r)\n");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }
    double m, mu, N, v, r;
    switch (choice) {
        case 1:
            printf("Select planet:\n");
            for (int i = 0; i < planetCount; i++) {
                printf("%d. %s\n", i+1, planets[i].name);
            }
            int p;
            if (scanf("%d", &p) != 1) { printf("Invalid input.\n"); return; }
            if (p < 1 || p > planetCount) {
                printf("Invalid planet selection.\n"); return;
            }
            printf("Mass [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Force of gravity: %.4f N\n", m * planets[p-1].gravity);
            break;
        case 2:
            printf("Coefficient of friction (μ): "); if (scanf("%lf", &mu) != 1) { printf("Invalid input.\n"); return; }
            printf("Normal force (N) [N]: "); if (scanf("%lf", &N) != 1) { printf("Invalid input.\n"); return; }
            printf("Frictional force: %.4f N\n", mu * N);
            break;
        case 3:
            printf("Mass (m) [kg]: "); if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Velocity (v) [m/s]: "); if (scanf("%lf", &v) != 1) { printf("Invalid input.\n"); return; }
            printf("Radius (r) [m]: "); if (scanf("%lf", &r) != 1) { printf("Invalid input.\n"); return; }
            if (r == 0) { printf("Error: Radius cannot be zero.\n"); return; }
            printf("Centripetal force: %.4f N\n", m * v*v / r);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Projectile motion calculation (unchanged, input validation added)
void projectileCalculator() {
    printf("\n--- Projectile Motion Calculator ---\n");
    printf("Range of projectile (R = (u^2 * sin(2θ))/g)\n");
    double u, theta;
    printf("Initial speed (u) [m/s]: "); if (scanf("%lf", &u) != 1) { printf("Invalid input.\n"); return; }
    printf("Launch angle (θ) [degrees]: "); if (scanf("%lf", &theta) != 1) { printf("Invalid input.\n"); return; }
    double rad = theta * PI / 180.0;
    // Using Earth's gravity (9.81 m/s^2)
    double g = 9.81;
    if (g == 0) { printf("Error: Gravity cannot be zero.\n"); return; } // Should not happen with hardcoded g
    double range = (u*u * sin(2*rad)) / g;
    printf("Projectile range: %.4f m\n", range);
}

// New: Work-Energy Theorem Calculator
void workEnergyCalculator() {
    printf("\n--- Work-Energy Theorem Calculator ---\n");
    printf("Calculates Work or Change in Kinetic Energy (W = ΔKE = 0.5 * m * (v_f^2 - v_i^2))\n");
    double m, vi, vf, work, deltaKE;

    printf("Enter mass (m) [kg]: ");
    if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
    printf("Enter initial velocity (v_i) [m/s]: ");
    if (scanf("%lf", &vi) != 1) { printf("Invalid input.\n"); return; }
    printf("Enter final velocity (v_f) [m/s]: ");
    if (scanf("%lf", &vf) != 1) { printf("Invalid input.\n"); return; }

    deltaKE = 0.5 * m * (vf * vf - vi * vi);
    work = deltaKE; // By the Work-Energy Theorem

    printf("Change in Kinetic Energy (ΔKE): %.4f J\n", deltaKE);
    printf("Work Done (W): %.4f J\n", work);
}

// New: Simple Harmonic Motion Calculator
void shmCalculator() {
    printf("\n--- Simple Harmonic Motion (SHM) Calculator ---\n");
    printf("1. Mass-Spring System (Period T = 2π * sqrt(m/k))\n");
    printf("2. Simple Pendulum (Period T = 2π * sqrt(L/g))\n");
    printf("Enter your choice: ");
    int choice;
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return; }

    double m, k, L, g, T, f; // mass, spring constant, length, gravity, Period, frequency

    switch (choice) {
        case 1: // Mass-Spring System
            printf("Enter mass (m) [kg]: ");
            if (scanf("%lf", &m) != 1) { printf("Invalid input.\n"); return; }
            printf("Enter spring constant (k) [N/m]: ");
            if (scanf("%lf", &k) != 1) { printf("Invalid input.\n"); return; }

            if (m <= 0 || k <= 0) {
                printf("Error: Mass and spring constant must be positive.\n");
                return;
            }

            T = 2 * PI * sqrt(m / k);
            f = 1.0 / T;
            printf("Period (T): %.4f s\n", T);
            printf("Frequency (f): %.4f Hz\n", f);
            break;
        case 2: // Simple Pendulum
            printf("Enter length of pendulum (L) [m]: ");
            if (scanf("%lf", &L) != 1) { printf("Invalid input.\n"); return; }
            // Using Earth's gravity for simplicity, could ask for custom g
            g = 9.81;
            printf("Using gravitational acceleration (g) = %.2f m/s² (Earth)\n", g);

            if (L <= 0 || g <= 0) {
                 printf("Error: Length and gravity must be positive.\n");
                return;
            }

            T = 2 * PI * sqrt(L / g);
            f = 1.0 / T;
            printf("Period (T): %.4f s\n", T);
            printf("Frequency (f): %.4f Hz\n", f);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}


// Displays help information
void help() {
    printf("\nAvailable commands:\n");
    printf("1. Kinematics: displacement, velocity, acceleration\n");
    printf("2. Dynamics: force, momentum, impulse\n");
    printf("3. Energy: kinetic, potential, work\n");
    printf("4. Wave: speed, frequency, wavelength\n");
    printf("5. Electricity: Ohm's law, power\n");
    printf("6. Thermodynamics: ideal gas law check, heat calculation\n");
    printf("7. Force: gravity, friction, centripetal\n");
    printf("8. Projectile Motion: range calculation\n");
    printf("9. Work-Energy Theorem: calculate work or change in kinetic energy\n"); // Updated help
    printf("10. Simple Harmonic Motion (SHM): calculate period/frequency for mass-spring or pendulum\n"); // Updated help
    printf("11. Help: list functions\n");
    printf("0. Exit the program\n");
}
