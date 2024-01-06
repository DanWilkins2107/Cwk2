#include "ODEInterface.hpp"
#include "TrapezoidalSolver.hpp"
#include "LinearODE.hpp"
#include "Vector.hpp"

int main()
{
    ODEInterface* p_linear_ode = new LinearODE(-1);

    // Solving ODE using Trapezoidal method
    TrapezoidalSolver* p_trapezoidal_solver_i = new TrapezoidalSolver(*p_linear_ode, 0.0, 0.0, 10.0, 0.05, "output_2bi.dat");
    p_trapezoidal_solver_i->Solve();

    // Deallocate Memory
    delete p_trapezoidal_solver_i;
}