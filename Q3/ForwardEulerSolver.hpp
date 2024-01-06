#ifndef forward_euler_header
#define forward_euler_header

#include "AbstractODESolver.hpp"
#include "Vector.hpp"
#include <string>

class ForwardEulerSolver : public AbstractODESolver
{
  public:
    // Default constructor
    ForwardEulerSolver();

    // Constructor that takes in variables
    ForwardEulerSolver(ODEInterface& anODESystem,
                       const Vector& initialState,
                       const double initialTime,
                       const double finalTime,
                       const double stepSize,
                       const std::string outputFileName = "output.dat",
                       const int saveGap = 1,
                       const int printGap = 1);

    // Function to carry out the Forward Euler method
    void Solve();

    // Function to set the print and file settings
    void SetOutputSettings(std::string outputFileName, int saveGap, int printGap);

  // Variables are private as no derived class needs access
  private:
    std::string mOutputFileName;
    int mSaveGap;
    int mPrintGap;
};

#endif