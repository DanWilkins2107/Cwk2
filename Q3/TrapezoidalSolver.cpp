#include "TrapezoidalSolver.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

// Overridden default constructor
TrapezoidalSolver::TrapezoidalSolver()
{
}

// Main constructor
TrapezoidalSolver::TrapezoidalSolver(ODEInterface& anODESystem,
                                     const double initialState,
                                     const double initialTime,
                                     const double finalTime,
                                     const double stepSize,
                                     const std::string outputFileName,
                                     const int saveGap,
                                     const int printGap)
    : AbstractODESolver(finalTime, initialTime, &anODESystem, initialState, stepSize)
{
    // Sets all the private variables
    SetOutputSettings(outputFileName, saveGap, printGap);
}

// Function to approximate the ODE
void TrapezoidalSolver::Solve()
{

    // Initialises t_n and u_n
    double t_n = mInitialTime;
    double u_n = mState;
    int n = 0;

    // Sets up the write file
    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    // Print the first iteration
    std::cout << "Iterations" << std::endl;
    write_file << t_n << " " << u_n << "\n";
    std::cout << "t_0 = " << t_n << "  u_0 = " << u_n << std::endl;

    // Find the value of a
    double a;
    mpODESystem->GetA(a);

    // Loop until t_n exceeds the final time.
    while (t_n < mFinalTime)
    {

        // Find f
        double f;
        mpODESystem->ComputeF(t_n, u_n, f);

        // Increase t_n
        t_n += mStepSize;
        n += 1;

        // Update u_n with f's contribution to the sum
        u_n += mStepSize * f * 0.5;

        // Find g and add to the ODE
        double g;
        mpODESystem->ComputeF(t_n, 0, g);
        u_n += mStepSize * g * 0.5;

        // Divide through by the sum on left hand side
        u_n /= 1 - mStepSize * 0.5 * a;

        // Save to file if a multiple of mSaveGap
        if (n % mSaveGap == 0)
        {
            write_file << t_n << " " << u_n << "\n";
        }
        // Print to screen if a multiple of mSaveGap
        if (n % mPrintGap == 0)
        {
            std::cout << "t_" << n << " = " << t_n << "   u_" << n << " = " << u_n << std::endl;
        }
    }

    // Close the file
    write_file.close();
}

// Function that saves the private variables.
void TrapezoidalSolver::SetOutputSettings(std::string outputFileName, int saveGap, int printGap)
{
    mOutputFileName = outputFileName;
    mSaveGap = saveGap;
    mPrintGap = printGap;
}