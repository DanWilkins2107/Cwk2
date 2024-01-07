#ifndef diffusion_header
#define diffusion_header

#include "Matrix.hpp"
#include "ODEInterface.hpp"
#include "Vector.hpp"

class Diffusion : public ODEInterface
{
  public:
    // Overridden default constructor
    Diffusion();
    // Constructor taking in...
    Diffusion(const double xMin, const double xMax, const double d);

    // Function to store in f the values of F
    void ComputeF(const double t, const Vector u,
                  Vector& f) const;

    // Function to compute the exact solution values u(t) at points x_i
    void ComputeAnalyticSolution(const double t,
                                 Vector& u) const;

    // Function to overwrite the boundary values u_0(t) and u_Nmax(t) of the vector u(t)
    void ApplyDirichlet(const double t, Vector& u);

    // Method to compute the matrix A
    void ComputeMatrix(Matrix& A) const;

    void SetVariables(const double xMin, const double xMax, const double D);

  protected:
    double mXMin;
    double mXMax;
    double mD;
    
};

#endif