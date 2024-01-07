#include "ForwardEulerSolver.hpp"
#include "Vector.hpp"
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

// Overridden default constructor
ForwardEulerSolver::ForwardEulerSolver()
{
}

// Main constructor that will be called
ForwardEulerSolver::ForwardEulerSolver(ODEInterface& anODESystem,
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

// Function carrying out the Forward Euler Method
void ForwardEulerSolver::Solve()
{
    // Setting up initial values for t_n, n and u_n
    double t_n = mInitialTime;
    Vector* p_u_n = new Vector(*mState);
    int vec_size = p_u_n->GetSize();
    int n = 0;

    // Setting up file to write in
    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    // Printing header and initial values, as well as writing to file t_0 and u(t_0)
    std::cout << "Iterations" << std::endl;
    write_file << t_n << " " << p_u_n << "\n";
    std::cout << "t_0 = " << t_n << "  u_0 = " << p_u_n << std::endl;

    while (t_n < mFinalTime)
    {
        // Find out what f is
        Vector p_f(vec_size);
        mpODESystem->ComputeF(t_n, *p_u_n, p_f);

        // Apply Dirichlet Boundary Conditions
        mpODESystem->ApplyDirichlet(t_n, p_f);

        // Find u_n+1, t_n+1 and n
        t_n += mStepSize;
        n += 1;
        *p_u_n = *p_u_n + p_f * mStepSize;

        // Save values to file depending on mSaveGap
        if (n % mSaveGap == 0)
        {
            write_file << t_n << " " << *p_u_n << "\n";
        }

        // Print values depending on mPrintGap
        if (n % mPrintGap == 0)
        {
            std::cout << "t_" << n << " = " << t_n << "   u_" << n << " = " << *p_u_n << std::endl;
        }
    }

    write_file.close();

    // Find the discrete norm of the error
    double error;
    Vector exact_solution(vec_size);
    mpODESystem->ComputeAnalyticSolution(mFinalTime, exact_solution);
    for (int i = 0; i < vec_size; i++)
    {
        error += pow(p_u_n->Read(i) - exact_solution[i], 2);
    }
    error /= double(vec_size);
    error = sqrt(error);
    std::cout << "Discrete norm of the error: " << error << std::endl;
}

// Function to set the print and file settings
void ForwardEulerSolver::SetOutputSettings(std::string outputFileName, int saveGap, int printGap)
{
    mOutputFileName = outputFileName;
    mSaveGap = saveGap;
    mPrintGap = printGap;
}