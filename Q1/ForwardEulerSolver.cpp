#include "ForwardEulerSolver.hpp"
#include <string>
#include <cassert>
#include <fstream>
#include <iostream>

ForwardEulerSolver::ForwardEulerSolver(ODEInterface& anODESystem,
                                       const double initialState,
                                       const double initialTime,
                                       const double finalTime,
                                       const double stepSize,
                                       const std::string outputFileName = "output.dat",
                                       const int saveGap = 1,
                                       const int printGap = 1)
    : AbstractODESolver(finalTime, initialTime, &anODESystem, initialState, stepSize)
{
    SetOutputSettings(outputFileName, saveGap, printGap);
}

void ForwardEulerSolver::Solve()
{
    double current_time = mInitialTime;
    double current_u_n = mState;

    std::ofstream write_file;
    write_file.open(mOutputFileName);
    assert(write_file.is_open());

    write_file << "Iterations" << "\n";
    std::cout << "Iterations" << std::endl;
}

void ForwardEulerSolver::SetOutputSettings(std::string outputFileName, int saveGap, int printGap)
{
    mOutputFileName = outputFileName;
    mSaveGap = saveGap;
    mPrintGap = printGap;
}