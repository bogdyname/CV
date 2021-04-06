#include <iostream>

namespace geometry
{
	class Geometry
	{

	protected:
		enum FigureClass
		{
			point = -1,
			segment,
			cycle,
			triangle, 
			rectangle,
			polygon
		};

	public:
		Geometry(double a = 0, double b = 0, int edges = 0, FigureClass figure = point);
		~Geometry();

	public:
		bool Create();

		virtual double Perimeter() const;
		virtual double Square() const;

		virtual int Edges() const;
		virtual int Angles() const;

		virtual double a() const;
		virtual double b() const;
		virtual double c() const;

	protected:
		bool CalculatePerimeter();
		bool CalculateSquare();

	protected:
		double a;
		double b;
		double c;

		int edges;
		int angles;
		double Perimeter;
		double Square;
		FigureClass figure;
	};
};