#include "Matrix.hpp"
#include "Vector.hpp"

// Solve linear system using Gaussian elimination without pivoting
void GaussianElimination(Matrix& p_A, Vector& p_p, Vector& p_f)
{
  int systemSize = p_p.GetSize();

  // Forward elimination step
  // Loop through columns of matrix
  for (int i=1; i<systemSize; i++)
  {
    double diagonal = 1.0 / p_A(i,i);
    // Loop through rows below diagonal
    for (int j=i+1; j<=systemSize; j++)
    {
      double multiplier = diagonal * p_A(j,i);
      // Loop through elements in row being subtracted
      for (int k=i; k<=systemSize; k++)
      {
        p_A(j,k) = p_A(j,k) - multiplier * p_A(i,k);
      }
      p_f(j) = p_f(j) - multiplier * p_f(i);
    }
  }

  // Backward substitution step
  p_p(systemSize) = p_f(systemSize) / p_A(systemSize,systemSize);
  // Loop backwards through rows of matrix
  for (int i=systemSize-1; i>=1; i--)
  {
    p_p(i) = p_f(i);
    // Loop through elements of row for substitution
    for (int k=i+1; k<=systemSize; k++)
    {
      p_p(i) = p_p(i) - p_A(i,k) * p_p(k);
    }
    p_p(i) = p_p(i) / p_A(i,i);
  }
}
