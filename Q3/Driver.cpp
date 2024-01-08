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
    Vector* initial_vector = new Vector(101);
    p_partial_de->ComputeAnalyticSolution(0.0, *initial_vector);

    // Create Forward Euler Method and run solve function
    ForwardEulerSolver* p_euler_solver = new ForwardEulerSolver(*p_partial_de, *initial_vector, 0.0, 10.0, 0.01, 1000, 100, "output_3ci.dat", 1, 1000);
    p_euler_solver->Solve();

    // // Part ii
    // // Array of values to test
    // double values[7] = {100.0,
    //                     200.0,
    //                     400.0,
    //                     800.0,
    //                     1600.0};

    // // Loop over values
    // for (int i = 0; i < 7; i++)
    // {
    //     // Creating file names
    //     std::string output_file_name = "output_3cii_" + std::to_string(int(values[i])) + ".dat";
    //     std::string output_file_name_2 = "output_3cii_" + std::to_string(int(values[i])) + "_sq" + ".dat";

    //     // Running for N_t proportional to N_x
    //     ForwardEulerSolver* p_euler_solver_ii = new ForwardEulerSolver(*p_partial_de, *initial_vector, 0.0, 10.0, 0.01, 10 * values[i], values[i], output_file_name, 1, 1000);
    //     p_euler_solver_ii->Solve();

    //     // Running for N_t proportional to N_x squared
    //     ForwardEulerSolver* p_euler_solver_ii_2 = new ForwardEulerSolver(*p_partial_de, *initial_vector, 0.0, 10.0, 0.01, 0.1 * pow(values[i], 2), values[i], output_file_name_2, 1, 1000);
    //     p_euler_solver_ii_2->Solve();
    // }

    // Part iii (part i repeated)
    // Create vector of correct length N_x + 1
    Vector* initial_vector_2 = new Vector(101);
    p_partial_de->ComputeAnalyticSolution(0.0, *initial_vector);

    // Create Trapezoidal Method and run solve function
    TrapezoidalSolver* p_trapezoidal_solver = new TrapezoidalSolver(*p_partial_de, *initial_vector, 0.0, 10.0, 0.01, 1000, 100, "output_3ciii.dat", 1, 1000);
    p_trapezoidal_solver->Solve();
}