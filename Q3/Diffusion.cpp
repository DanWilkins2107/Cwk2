#include "Diffusion.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>

// Overridden default constructor
Diffusion::Diffusion()
{
}

// Constructor taking in...
Diffusion::Diffusion(const double xMin, const double xMax, const double d)
{
    SetVariables(xMin, xMax, d);
}

// Function to store in f the values of F
void Diffusion::ComputeF(const double t, const Vector u,
                         Vector& f) const
{
    int vec_size = f.GetSize();
    // Loop over interior points
    for (int i = 1; i < vec_size - 1; i++)
    {
        f[i] = u.Read(i + 1) - 2 * u.Read(i) + u.Read(i - 1);
        f[i] *= mD / pow((mXMax - mXMin) / vec_size, 2);
    }
}

// Function to compute the exact solution values u(t) at points x_i
void Diffusion::ComputeAnalyticSolution(const double t,
                                        Vector& u) const
{
    // Find the step size
    int u_length = u.GetSize();
    double step_size = (mXMax - mXMin) / (u_length - 1);
    for (int i = 0; i < u_length; i++)
    {
        u[i] = exp(-1.0 * mD * pow(M_PI, 2) * t) * sin(M_PI * (mXMin + step_size * i));
    }
}

// Function to overwrite the boundary values u_0(t) and u_Nmax(t) of the vector u(t)
void Diffusion::ApplyDirichlet(const double t, Vector& u)
{
    // Change u_0 point
    u[0] = 0.0;

    // Change u_N_x point
    u[u.GetSize() - 1] = 0.0;
}

// Method to compute the matrix A
void Diffusion::ComputeMatrix(Matrix& A) const
{
    // Find dimensions of the matrix
    int size = A.GetNumberOfRows();
    
    // Set first and last rows accounting for Dirichlet Boundary Conditions
    A(1, 1) = 1.0;
    A(size, size) = 1.0;

    // Set rest of the rows
    for (int i = 2; i < size; i++)
    {
        A(i, i - 1) = 1.0;
        A(i, i) = -2.0;
        A(i, i + 1) = 1.0;
    }
}

void Diffusion::SetVariables(const double xMin, const double xMax, const double d)
{
    mXMin = xMin;
    mXMax = xMax;
    mD = d;
}