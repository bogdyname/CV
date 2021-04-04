#include <iostream>

namespace geometry
{
	class Geometry
	{
	public:
		Geometry();
		~Geometry();

	public:
		bool Init();


		virtual int Edges();
	};
};