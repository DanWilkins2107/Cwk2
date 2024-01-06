#ifndef abstract_ODE_header
#define abstract_ODE_header

#include "ODEInterface.hpp"

class AbstractODESolver
{

  public:
    // Overriden default constructor
    AbstractODESolver();

    // Constructor that takes variables
    AbstractODESolver(const double mFinalTime,
                      const double minitialTime,
                      ODEInterface* mpODESystem,
                      const double mState,
                      const double mStepSize);

    // Modify protected variables
    void SetVariables(const double mfinalTime,
                      const double minitialTime,
                      ODEInterface* mpODESystem,
                      const double mState,
                      const double mStepSize);

    // Virtual Solve function to be redefined
    virtual void Solve() = 0;

    // Virtual destructor function
    virtual ~AbstractODESolver();

  // Protected variables that need to be accessed in derived classes
  protected:
    double mFinalTime;
    double mInitialTime;
    ODEInterface* mpODESystem;
    double mState;
    double mStepSize;
};

#endif