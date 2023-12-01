#include <cassert>
#include "UniformGrid1D.hpp"

// Specialised constructor taking min/max x values, and number of grid points 
UniformGrid1D::UniformGrid1D(const double xMin, 
    const double xMax, const int numNodes)
{
  // Set interval
  assert(xMin < xMax);
  mXMin = xMin;
  mXMax = xMax;

  // Set number of nodes
  assert(numNodes > 1);
  mNumNodes = numNodes;

  // Set nodes (and grid size)
  CreateNodes();
}

// Copy constructor
UniformGrid1D::UniformGrid1D(const UniformGrid1D& otherGrid)
{
  mpNodes = new Vector(*(otherGrid.GetNodes()));
  mNumNodes = mpNodes->GetSize();
  mGridSize = otherGrid.GetGridSize();
  mXMin = (*mpNodes)(1);
  mXMax = (*mpNodes)(mNumNodes);
}

// Destructor
UniformGrid1D::~UniformGrid1D()
{
  delete mpNodes;
}

// Accessor to x grid
Vector* UniformGrid1D::GetNodes() const
{
  return mpNodes;
}

// Accessor to grid size (dx)
double UniformGrid1D::GetGridSize() const
{
  return mGridSize;
}

// Sets the number of nodes (and resets nodes)
void UniformGrid1D::SetNumNodes(const int n)
{
  assert(n >1);
  mNumNodes = n;
  bool reset_nodes = true;
  CreateNodes(reset_nodes);
}

// Set the interval xMin and xMax of the grid (and reset nodes)
void UniformGrid1D::SetInterval(const double xMin, const double xMax)
{
  assert(xMin < xMax);
  mXMin = xMin;
  mXMax = xMax;
  bool reset_nodes = true;
  CreateNodes(reset_nodes);
}

// Returns the interior nodes
Vector UniformGrid1D::GetInteriorNodes() const
{

  // Allocate a new vector
  int num_nodes  = mpNodes->GetSize();
  Vector interior_vector(num_nodes-2);

  // Populate vector
  for (int i=2; i<=num_nodes-1; i++)
  {
    interior_vector(i-1) = (*mpNodes)(i);
  }

  return interior_vector;

}

// Create 1D points
void UniformGrid1D::CreateNodes( bool resetNodes)
{

  // Optionally delete the pointer and form a new one
  if (resetNodes)
  {
    delete mpNodes;
  }
  mpNodes = new Vector(mNumNodes);
  
  // Compute grid size
  mGridSize = (mXMax-mXMin)/(mNumNodes-1);

  // Populate grid
  for (int i=1; i<=mNumNodes; i++)
  {
    (*mpNodes)(i) = mXMin + (i-1)*mGridSize;
  }

}
