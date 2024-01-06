#ifndef trapezoidal_solver_header
#define trapezoidal_solver_header

#include "AbstractODESolver.hpp"
#include <string>

class TrapezoidalSolver : public AbstractODESolver
{
  public:
    // Overridden default constructor
    TrapezoidalSolver();

    // Constructor that takes in variables
    TrapezoidalSolver(ODEInterface& anODESystem,
                      const double initialState,
                      const double initialTime,
                      const double finalTime,
                      const double stepSize,
                      const std::string outputFileName = "output.dat",
                      const int saveGap = 1,
                      const int printGap = 1);

    // Function that approximates the ODE.
    void Solve();

    // Function that saves the output settings.
    void SetOutputSettings(const std::string outputFileName, const int saveGap, const int printGap);

  private:
    std::string mOutputFileName;
    int mSaveGap;
    int mPrintGap;
};

#endif