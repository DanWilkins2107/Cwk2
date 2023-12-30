#ifndef forward_euler_header
#define forward_euler_header

#include "AbstractODESolver.hpp"
#include <string>

class ForwardEulerSolver : public AbstractODESolver
{
public:
    ForwardEulerSolver(ODEInterface& anODESystem,
                       const double initialState,
                       const double initialTime,
                       const double finalTime,
                       const double stepSize,
                       const std::string outputFileName = "output.dat",
                       const int saveGap = 1,
                       const int printGap = 1);

    void Solve();

    void SetOutputSettings(std::string outputFileName, int saveGap, int printGap);

protected:
    std::string mOutputFileName;
    int mSaveGap;
    int mPrintGap;
};

#endif