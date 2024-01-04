#include "ForwardEulerSolver.hpp"
#include "LinearODE.hpp"
#include "ODEInterface.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // Part i 
    // Creating ODE
    ODEInterface* p_linear_ode = new LinearODE(-1);

    // Solving ODE using Forward Euler method
    ForwardEulerSolver* p_euler_solver_i = new ForwardEulerSolver(*p_linear_ode, 0.0, 0.0, 10.0, 0.05, "output_1di.dat");
    p_euler_solver_i->Solve();

    // Deallocate memory
    delete p_euler_solver_i;

    // Part ii
    // Selecting error values to test
    double values[7] = {0.005, 0.01, 0.02, 0.05, 0.1, 0.25, 0.5};

    // Setting up file to write error values into
    std::ofstream write_file;
    write_file.open("output_1dii_errors.dat");
    assert(write_file.is_open());

    for (int i = 0; i < 7; i++)
    {
        // Create different file names for each step size
        std::string output_file_name = "output_1dii_" + std::to_string(values[i]).substr(0, 5) + ".dat";

        // Use Forward Euler method with each step size
        ForwardEulerSolver* p_euler_solver_ii = new ForwardEulerSolver(*p_linear_ode, 0.0, 0.0, 1.0, values[i], output_file_name);
        p_euler_solver_ii->Solve();

        // Read in each file
        std::ifstream read_file;
        read_file.open(output_file_name);
        assert(read_file.is_open());

        // Calculate number of entries and loop over
        int number_of_entries = 1.0 / values[i] + 1;
        double max_error = 0;
        for (int j = 0; j < number_of_entries; j++)
        {
            double t;
            double approx_u;
            double actual_u;

            // Read in values from output file
            read_file >> t >> approx_u;
            p_linear_ode->ComputeAnalyticSolution(t, actual_u);

            // Check whether error is greater than previously
            if (fabs(approx_u - actual_u) > max_error)
            {
                max_error = fabs(approx_u - actual_u);
            }
        }

        // Close the file
        read_file.close();

        // Print max_error to file
        write_file << values[i] << " " << max_error << "\n";

        // Deallocate memory
        delete p_euler_solver_ii;
    }

    // Close file and deallocate memory
    write_file.close();
    delete p_linear_ode;
}
