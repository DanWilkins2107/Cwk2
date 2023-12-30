#ifndef abstract_ODE_header
#define abstract_ODE_header

#include "ODEInterface.hpp"

class AbstractODESolver
{

public:
    AbstractODESolver();
    AbstractODESolver(double mFinalTime,
                      double minitialTime,
                      ODEInterface* mpODESystem,
                      double mState,
                      double mStepSize);

    void SetVariables(double mfinalTime,
                      double minitialTime,
                      ODEInterface* mpODESystem,
                      double mState,
                      double mStepSize);

    virtual void Solve() = 0;
    virtual ~AbstractODESolver();

protected:
    double mFinalTime;
    double mInitialTime;
    ODEInterface* mpODESystem;
    double mState;
    double mStepSize;
};

#endif