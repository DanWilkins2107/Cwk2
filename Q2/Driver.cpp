#include "TrapezoidalSolver.hpp"
#include "LinearODE.hpp"
#include "ODEInterface.hpp"


int main() {
    // Part i
    ODEInterface* p_linear_ode = new LinearODE(-1);
    TrapezoidalSolver* p_trapezoidal_solver = new TrapezoidalSolver(*p_linear_ode, 0.0, 0.0, 10.0, 0.05, "output.2di.dat");
    p_trapezoidal_solver->Solve();

    // Part ii
    double values[7] = {0.005, 0.01, 0.02, 0.05, 0.1, 0.25, 0.5};

}