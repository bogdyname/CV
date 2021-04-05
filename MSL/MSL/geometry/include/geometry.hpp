#include <iostream>

namespace geometry
{
	class Geometry
	{

	protected:
		enum FigureClass
		{
			point = -1,
			cycle,
		};

	public:
		Geometry(double a = 0, double b = 0, int edges = 0);
		~Geometry();

	public:
		bool Init();


		virtual int Edges();

	protected:


	protected:
		double a;
		double b;

		int edges;
		double Perimeter;
		double Square;
	};
};