#ifndef UNIFORMGRID1DHEADERDEF
#define UNIFORMGRID1DHEADERDEF

#include "Vector.hpp"

// Class for handling a uniform grid in the interval [xMin,xMax] with numNodes nodes
class UniformGrid1D 
{

  public:

    // Specialised constructor taking min/max x values, and number of grid points 
    UniformGrid1D(const double xMin, 
	const double xMax, 
	const int numNodes);

    // Overloaded copy constructor
    UniformGrid1D(const UniformGrid1D& otherGrid);

    // Destructor
    ~UniformGrid1D();

    // Accessor to grid nodes
    Vector* GetNodes() const;

    // Returning the interior nodes
    Vector GetInteriorNodes() const;

    // Returning the grid size (dx)
    double GetGridSize() const;

    // Set the number of nodes (deletes and resets previously existing nodes)
    void SetNumNodes(const int n);

    // Set the interval xMin and xMax of the grid (and reset nodes)
    void SetInterval(const double xMin, const double xMax);

  private:

    // Hidden default constructor
    UniformGrid1D();

    // Populates the grid nodes and assign grid size,
    // resetting the nodes if required
    void CreateNodes(bool resetNodes = false);

    // Pointer to grid nodes
    Vector* mpNodes;

    // Grid size (dx)
    double mGridSize;

    // Coordinates defininng the interval of the grid
    double mXMin, mXMax;

    // Number of nodes
    int mNumNodes;

};

#endif
