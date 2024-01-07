#include "Diffusion.hpp"
#include "ForwardEulerSolver.hpp"
#include "ODEInterface.hpp"
#include "TrapezoidalSolver.hpp"
#include "UniformGrid1D.hpp"
#include "Vector.hpp"
#include <string>

int main()
{
    // Part i
    // Create PDE
    ODEInterface* p_partial_de = new Diffusion(0.0, 1.0, 0.001);

    // Create vector of correct length N_x + 1
    UniformGrid1D* initial_grid = new UniformGrid1D(0.0, 1.0, 101);
    Vector initial_vector = *initial_grid->GetNodes();

    // Create Forward Euler Method and run solve function
    ForwardEulerSolver* p_euler_solver = new ForwardEulerSolver(*p_partial_de, initial_vector, 0.0, 10.0, 0.01, 1000, 100, "output_3ci.dat", 1, 1000);
    p_euler_solver->Solve();

    // Part ii
    // Array of values to test
    double values[7] = {100.0,
                        200.0,
                        400.0,
                        800.0,
                        1600.0};

    // Loop over values
    for (int i = 0; i < 7; i++)
    {
        std::string output_file_name = "output_3cii_" + std::to_string(int(values[i])) + ".dat";
        std::string output_file_name_2 = "output_3cii_" + std::to_string(int(values[i])) + "_" + std::to_string(2) + ".dat";
        ForwardEulerSolver* p_euler_solver_ii = new ForwardEulerSolver(*p_partial_de, initial_vector, 0.0, 10.0, 0.01, 10 * values[i], values[i], output_file_name, 1, 1000);
        p_euler_solver_ii->Solve();
        ForwardEulerSolver* p_euler_solver_ii_2 = new ForwardEulerSolver(*p_partial_de, initial_vector, 0.0, 10.0, 0.01, 0.1 * pow(values[i], 2), values[i], output_file_name_2, 1, 1000);
    }

    // Part iii
}