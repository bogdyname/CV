#include "../include/geometry.hpp"

namespace geometry
{
	Geometry::Geometry(Math* parent = 0, double a, double b, int edges, FigureClass figure)
		: parent(parent), a(a), b(b), edges(edges), figure(figure)
	{

	}

	Geometry::~Geometry()
	{
		
	}
}