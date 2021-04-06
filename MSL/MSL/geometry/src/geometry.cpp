#include "../include/geometry.hpp"

namespace geometry
{
	Geometry::Geometry(double a, double b, int edges, FigureClass figure)
		: a(a), b(b), edges(edges), figure(figure)
	{

	}

	Geometry::~Geometry()
	{
		
	}
}