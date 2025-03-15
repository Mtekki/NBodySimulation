# N-Body Simulation in C++

This project simulates the motion of multiple bodies under the influence of gravity using C++. It implements Newton's law of universal gravitation and uses numerical integration (Euler's method) to update the positions and velocities of the bodies over time.


## Features
- Simulates gravitational interactions between multiple bodies.
- Dynamically updates positions and velocities using Euler's method.
- Outputs the positions of bodies at each time step.


## Requirements
- **Compiler**: MSVC (Microsoft Visual C++) or any C++ compiler.
- **IDE**: Visual Studio Code (optional).
- **Operating System**: Windows (for MSVC) or any OS with a C++ compiler.



## How to Build and Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/mtekki/n-body-simulation.git
   cd n-body-simulation
   ```

2.Compile the Code:

If using MSVC:

 ```bash
 cl nbody.cpp /EHsc /Fe:nbody.exe
 ```

 If using GCC:

 ```bash
 g++ nbody.cpp -o nbody.exe
```

3.Run the simulation:

 ```bash
./nbody.exe
```

Sample Output
The program will print the positions of the bodies at each time step. For example:


Step 0:
Body at (0, 0)
Body at (1, 0)

Step 1:
Body at (0.01, 0)
Body at (1.01, 0.01)

...
Code Overview

The project consists of the following key components:

Body Structure: Represents a body with mass, position, velocity, and force.

calculateForces Function: Computes the gravitational forces between all pairs of bodies.

updateBodies Function: Updates the positions and velocities of the bodies using Euler's method.

Main Function: Initializes the bodies and runs the simulation loop.

Future Improvements
Add support for more bodies.

Implement a more efficient algorithm (e.g., Barnes-Hut).

Add graphical visualization using a library like SFML or OpenGL.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Author
Malak

GitHub: mtekki