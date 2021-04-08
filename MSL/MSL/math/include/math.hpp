#include <cmath>
#include <iostream>

class Math
{
	enum DivCriteria
	{
		two = 2, 
		three = 3,
		four = 4,
		five = 5,
		six = 6,
		seven = 7,
		eight = 8, 
		nine = 9,
		ten = 10,
		eleven = 11,
		hundred = 100,
		thousand = 1000
	};

	Math();
	~Math();

protected:
	bool DivisibilityCriteria(int x, DivCriteria criteria = two);
	int GreatestCommonFactor(int x);
};