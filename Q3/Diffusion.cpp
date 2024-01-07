#include "Diffusion.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

// Overridden default constructor
Diffusion::Diffusion()
{
}

// Constructor taking in...
Diffusion::Diffusion(const double xMin, const double xMax, const double d) {
    SetVariables(xMin, xMax, d);
}

// Function to store in f the values of F
void Diffusion::ComputeF(const double t, const Vector u,
                         Vector& f) const
{
    // Loop over interior points
    for (int i = 1; i < f.GetSize() - 1; i++)
    {
        f[i] = u.Read(i + 1) - 2 * u.Read(i) + u.Read(i - 1);
        f[i] *= mD / ((mXMax - mXMin) / f.GetSize());
    }
}

// Function to compute the exact solution values u(t) at points x_i
void Diffusion::ComputeAnalyticSolution(const double t,
                                        Vector& u) const
{
}

// Function to overwrite the boundary values u_0(t) and u_Nmax(t) of the vector u(t)
void Diffusion::ApplyDirichlet(const double t, Vector& u) {
    // Change u_0 point
    u[0] = 0.0;

    // Change u_N_x point
    u[u.GetSize() - 1] = 0.0;
    
}

// Method to compute the matrix A
void Diffusion::ComputeMatrix(Matrix& A) const {}

void Diffusion::SetVariables(const double xMin, const double xMax, const double d) {
    mXMin = xMin;
    mXMax = xMax;
    mD = d;
}