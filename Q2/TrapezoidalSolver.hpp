#ifndef trapezoidal_solver_header
#define trapezoidal_solver_header

#include "AbstractODESolver.hpp"
#include <string>

class TrapezoidalSolver : public AbstractODESolver
{
  public:
    TrapezoidalSolver(ODEInterface& anODESystem,
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