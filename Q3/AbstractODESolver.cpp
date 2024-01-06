#include "AbstractODESolver.hpp"
#include "Vector.hpp"

// Default constructor
AbstractODESolver::AbstractODESolver()
{
}

// Constructor that sets protected variables
AbstractODESolver::AbstractODESolver(double finalTime,
                                     double initialTime,
                                     ODEInterface* pODESystem,
                                     Vector* state,
                                     double stepSize)
{
    SetVariables(finalTime, initialTime, pODESystem, state, stepSize);
}

// Function to set protected variables
void AbstractODESolver::SetVariables(
    double finalTime,
    double initialTime,
    ODEInterface* pODESystem,
    Vector* state,
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
}