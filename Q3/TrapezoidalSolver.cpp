#include "TrapezoidalSolver.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

void GaussianElimination(Matrix& p_A, Vector& p_p, Vector& p_f);
// Overridden default constructor
TrapezoidalSolver::TrapezoidalSolver()
{
}

// Main Constructor to be Called
TrapezoidalSolver::TrapezoidalSolver(ODEInterface& anODESystem,
                                     const Vector& initialState,
                                     const double initialTime,
                                     const double finalTime,
                                     const double stepSize,
                                     const int timeSteps,
                                     const int spaceSteps,
                                     const std::string outputFileName,
                                     const int saveGap,
                                     const int printGap)
    : AbstractODESolver(finalTime, initialTime, &anODESystem, &initialState, stepSize, timeSteps, spaceSteps)
{
    // Set the private variables
    SetOutputSettings(outputFileName, saveGap, printGap);
}

// Function to approximate the ODE
void TrapezoidalSolver::Solve()
{

    // Initialises t_n and u_n
    double t_n = mInitialTime;
    Vector* p_u_n = new Vector(*mState);
    int vec_size = p_u_n->GetSize();
    int n = 0;

    // Sets up the write file
    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    // Print the first iteration
    std::cout << "Iterations" << std::endl;
    write_file << t_n << " " << p_u_n << "\n";
    std::cout << "t_0 = " << t_n << "  u_0 = " << p_u_n << std::endl;

    // Compute matrix A
    Matrix* A;
    mpODESystem->ComputeMatrix(*A);

    // Loop until t_n exceeds the final time.
    while (t_n < mFinalTime)
    {

        // Find f
        Vector p_f(vec_size);
        mpODESystem->ComputeF(t_n, *p_u_n, p_f);

        // Increase t_n
        t_n += mStepSize;
        n += 1;

        // Update u_n with f's contribution
        *p_u_n = *p_u_n + p_f * 0.5 * mStepSize;

        // Perform Gaussian elimination to find p_u_nplus1
        Vector p_u_nplus1(vec_size);
        Matrix lhs = *A * mStepSize * 0.5;
        GaussianElimination(lhs, p_u_nplus1, *p_u_n);

        *p_u_n = p_u_nplus1;

        // Save to file if a multiple of mSaveGap
        if (n % mSaveGap == 0)
        {
            write_file << t_n << " " << p_u_n << "\n";
        }
        // Print to screen if a multiple of mSaveGap
        if (n % mPrintGap == 0)
        {
            std::cout << "t_" << n << " = " << t_n << "   u_" << n << " = " << p_u_n << std::endl;
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