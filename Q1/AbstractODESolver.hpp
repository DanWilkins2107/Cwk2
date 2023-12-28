#ifndef abstract_ODE_header
#define abstract_ODE_header

#include "ODEInterface.hpp"

class AbstractODESolver
{

public:
    virtual void Solve() = 0;
    virtual ~AbstractODESolver();

protected:
    double mfinalTime;
    double minitialTime;
    ODEInterface* mpODESystem;
    double mState;
    double mStepSize;
};

#endif