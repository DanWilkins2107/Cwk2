#include "AbstractODESolver.hpp"

AbstractODESolver::AbstractODESolver()
{
}

AbstractODESolver::AbstractODESolver(double finalTime,
                                     double initialTime,
                                     ODEInterface* pODESystem,
                                     double state,
                                     double stepSize)
{
    SetVariables(finalTime, initialTime, pODESystem, state, stepSize);
}

void AbstractODESolver::SetVariables(
    double finalTime,
    double initialTime,
    ODEInterface* pODESystem,
    double state,
    double stepSize)
{
    mFinalTime = finalTime;
    mInitialTime = initialTime;
    mpODESystem = pODESystem;
    mState = state;
    mStepSize = stepSize;
}

AbstractODESolver::~AbstractODESolver()
{
    // Do I need to destruct the pointer?
}