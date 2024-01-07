#include "Diffusion.hpp"
#include "ForwardEulerSolver.hpp"
#include "ODEInterface.hpp"
#include "TrapezoidalSolver.hpp"
#include "Vector.hpp"

int main()
{
    // Part i
    // Create PDE
    ODEInterface* p_partial_de = new Diffusion(0.0, 1.0, 0.001);

    // Create vector of correct length N_x + 1
    Vector initial_state(101);

    // Create Forward Euler Method and run solve function
    ForwardEulerSolver* p_euler_solver = new ForwardEulerSolver(*p_partial_de, initial_state, 0.0, 10.0, 0.01, 1000, 100, "output_3i.dat", 1, 1);
    p_euler_solver->Solve();

    // Part ii

    // Part iii
}