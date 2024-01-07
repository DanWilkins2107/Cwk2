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
    AbstractODESolver(double finalTime,
                      double initialTime,
                      ODEInterface* pODESystem,
                      const Vector* state,
                      double stepSize,
                      int timeSteps,
                      int spaceSteps);

    // Modify protected variables
    void SetVariables(double finalTime,
                      double initialTime,
                      ODEInterface* pODESystem,
                      const Vector* state,
                      double stepSize,
                      int timeSteps,
                      int spaceSteps);

    // Virtual Solve function to be redefined
    virtual void Solve() = 0;

    // Virtual destructor function
    virtual ~AbstractODESolver();

  protected:
    double mFinalTime;
    double mInitialTime;
    double mXMin;
    double mXMax;
    ODEInterface* mpODESystem;
    const Vector* mState;
    double mStepSize;
    int mTimeSteps;
    int mSpaceSteps;
};

#endif