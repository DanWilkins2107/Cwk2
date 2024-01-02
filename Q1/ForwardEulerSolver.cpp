#include "ForwardEulerSolver.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

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
    SetOutputSettings(outputFileName, saveGap, printGap);
}

void ForwardEulerSolver::Solve()
{
    double t_n = mInitialTime;
    double u_n = mState;
    int n = 0;
    double p_f;

    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    std::cout << "Iterations" << std::endl;
    write_file << t_n << " " << u_n << "\n";
    std::cout << "t_0 = " << t_n << "  u_0 = " << u_n << std::endl;

    while (t_n < mFinalTime)
    {
        mpODESystem->ComputeF(t_n, u_n, p_f);

        t_n += mStepSize;
        n += 1;
        u_n += mStepSize * p_f;

        if (n % mSaveGap == 0)
        {
            write_file << t_n << " " << u_n << "\n";
        }

        if (n % mPrintGap == 0)
        {
            std::cout << "t_" << n << " = " << t_n << "   u_" << n << " = " << u_n << std::endl;
        }
    }

    write_file.close();
}

void ForwardEulerSolver::SetOutputSettings(std::string outputFileName, int saveGap, int printGap)
{
    mOutputFileName = outputFileName;
    mSaveGap = saveGap;
    mPrintGap = printGap;
}