#include "AbstractODESolver.hpp"

// Default constructor
AbstractODESolver::AbstractODESolver()
{
}

// Constructor that sets protected variables
AbstractODESolver::AbstractODESolver(const double finalTime,
                                     const double initialTime,
                                     ODEInterface* pODESystem,
                                     const double state,
                                     const double stepSize)
{
    SetVariables(finalTime, initialTime, pODESystem, state, stepSize);
}

// Function to set protected variables
void AbstractODESolver::SetVariables(
    const double finalTime,
    const double initialTime,
    ODEInterface* pODESystem,
    const double state,
    const double stepSize)
{
    mFinalTime = finalTime;
    mInitialTime = initialTime;
    mpODESystem = pODESystem;
    mState = state;
    mStepSize = stepSize;
}

// Virtual Destructor Function
AbstractODESolver::~AbstractODESolver()
{
}