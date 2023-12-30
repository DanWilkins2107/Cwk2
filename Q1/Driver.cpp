#include "ForwardEulerSolver.hpp"
#include "LinearODE.hpp"
#include "ODEInterface.hpp"
#include <iostream>

int main()
{
    // Instantiate and use the LinearODE and Forward Euler Solution
    ODEInterface* p_linear_ode = new LinearODE(-1);
    ForwardEulerSolver* euler_solver = new ForwardEulerSolver(*p_linear_ode, 0.0, 0.0, 10.0, 0.05);
}