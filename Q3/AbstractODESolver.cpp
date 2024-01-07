#include "AbstractODESolver.hpp"
#include "Vector.hpp"

// Default constructor
AbstractODESolver::AbstractODESolver()
{
}

// Constructor that sets protected variables
AbstractODESolver::AbstractODESolver(const double finalTime,
                                     const double initialTime,
                                     ODEInterface* pODESystem,
                                     const Vector* state,
                                     const double stepSize, 
                                     const int timeSteps, 
                                     const int spaceSteps)
{
    SetVariables(finalTime, initialTime, pODESystem, state, stepSize, timeSteps, spaceSteps);
}

// Function to set protected variables
void AbstractODESolver::SetVariables(
    const double finalTime,
    const double initialTime,
    ODEInterface* pODESystem,
    const Vector* state,
    const double stepSize, 
    const int timeSteps,
    const int spaceSteps)
{
    mFinalTime = finalTime;
    mInitialTime = initialTime;
    mpODESystem = pODESystem;
    mState = state;
    mStepSize = stepSize;
    mTimeSteps = timeSteps;
    mSpaceSteps = spaceSteps;
}

// Virtual Destructor Function
AbstractODESolver::~AbstractODESolver()
{
}