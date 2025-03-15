#include <iostream>
#include <vector>
#include <cmath>

// Constants
const double G = 6.67430e-11; // Gravitational constant
const double dt = 0.01;       // Time step

// Body structure
struct Body {
    double mass;
    double x, y;    // Position
    double vx, vy;  // Velocity
    double fx, fy;  // Force
};

// Function to calculate forces
void calculateForces(std::vector<Body>& bodies) {
    for (size_t i = 0; i < bodies.size(); ++i) {
        bodies[i].fx = 0.0;
        bodies[i].fy = 0.0;
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double distance = std::sqrt(dx * dx + dy * dy);
                double force = (G * bodies[i].mass * bodies[j].mass) / (distance * distance);
                bodies[i].fx += force * dx / distance;
                bodies[i].fy += force * dy / distance;
            }
        }
    }
}

// Function to update positions and velocities
void updateBodies(std::vector<Body>& bodies) {
    for (auto& body : bodies) {
        double ax = body.fx / body.mass;
        double ay = body.fy / body.mass;
        body.vx += ax * dt;
        body.vy += ay * dt;
        body.x += body.vx * dt;
        body.y += body.vy * dt;
    }
}

// Main function
int main() {
    // Initialize bodies
    std::vector<Body> bodies = {
        {1.0e12, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, // Body 1
        {1.0e12, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0}  // Body 2
    };

    // Simulation loop
    for (int step = 0; step < 1000; ++step) {
        calculateForces(bodies);
        updateBodies(bodies);

        // Print positions
        std::cout << "Step " << step << ":\n";
        for (const auto& body : bodies) {
            std::cout << "Body at (" << body.x << ", " << body.y << ")\n";
        }
        std::cout << "\n";
    }

    return 0;
}