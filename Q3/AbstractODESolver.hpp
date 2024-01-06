#ifndef abstract_ODE_header
#define abstract_ODE_header

#include "ODEInterface.hpp"
#include "Vector.hpp"

class AbstractODESolver
{

  public:
    // Overriden default constructor
    AbstractODESolver();

    // Constructor that takes variables
    AbstractODESolver(double mFinalTime,
                      double minitialTime,
                      ODEInterface* mpODESystem,
                      Vector* mState,
                      double mStepSize);

    // Modify protected variables
    void SetVariables(double mfinalTime,
                      double minitialTime,
                      ODEInterface* mpODESystem,
                      Vector* mState,
                      double mStepSize);

    // Virtual Solve function to be redefined
    virtual void Solve() = 0;

    // Virtual destructor function
    virtual ~AbstractODESolver();

  protected:
    double mFinalTime;
    double mInitialTime;
    ODEInterface* mpODESystem;
    Vector* mState;
    double mStepSize;
};

#endif