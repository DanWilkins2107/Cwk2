#include "ForwardEulerSolver.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

// Overridden default constructor
ForwardEulerSolver::ForwardEulerSolver()
{
}

// Main constructor that will be called
ForwardEulerSolver::ForwardEulerSolver(ODEInterface& anODESystem,
                                       const double initialState,
                                       const double initialTime,
                                       const double finalTime,
                                       const double stepSize,
                                       const std::string outputFileName,
                                       const int saveGap,
                                       const int printGap)
    : AbstractODESolver(finalTime, initialTime, &anODESystem, initialState, stepSize)
{
    // Set the private variables
    SetOutputSettings(outputFileName, saveGap, printGap);
}

// Function carrying out the Forward Euler Method
void ForwardEulerSolver::Solve()
{
    // Setting up initial values for t_n, n and u_n
    double t_n = mInitialTime;
    double u_n = mState;
    int n = 0;

    // Setting up file to write in
    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    // Printing header and initial values, as well as writing to file t_0 and u(t_0)
    std::cout << "Iterations" << std::endl;
    write_file << t_n << " " << u_n << "\n";
    std::cout << "t_0 = " << t_n << "  u_0 = " << u_n << std::endl;

    while (t_n < mFinalTime)
    {
        // Find out what f is
        double f;
        mpODESystem->ComputeF(t_n, u_n, f);

        // Find u_n+1, t_n+1 and n
        t_n += mStepSize;
        n += 1;
        u_n += mStepSize * f;

        // Save values to file depending on mSaveGap
        if (n % mSaveGap == 0)
        {
            write_file << t_n << " " << u_n << "\n";
        }

        // Print values depending on mPrintGap
        if (n % mPrintGap == 0)
        {
            std::cout << "t_" << n << " = " << t_n << "   u_" << n << " = " << u_n << std::endl;
        }
    }

    write_file.close();
}

// Function to set the print and file settings
void ForwardEulerSolver::SetOutputSettings(const std::string outputFileName, const int saveGap, const int printGap)
{
    mOutputFileName = outputFileName;
    mSaveGap = saveGap;
    mPrintGap = printGap;
}