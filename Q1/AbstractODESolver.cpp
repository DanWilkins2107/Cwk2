#include "AbstractODESolver.hpp"

// Default constructor
AbstractODESolver::AbstractODESolver()
{
}

// Constructor that sets protected variables
AbstractODESolver::AbstractODESolver(double finalTime,
                                     double initialTime,
                                     ODEInterface* pODESystem,
                                     double state,
                                     double stepSize)
{
    SetVariables(finalTime, initialTime, pODESystem, state, stepSize);
}

// Function to set protected variables
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

// Virtual Destructor Function
AbstractODESolver::~AbstractODESolver()
{
    // Do I need to destruct the pointer?
}