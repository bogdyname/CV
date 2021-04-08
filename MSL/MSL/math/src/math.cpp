#include "../include/math.hpp"

Math::Math()
{

}

Math::~Math()
{

}

bool Math::DivisibilityCriteria(int x, DivCriteria criteria)
{
	if (x < 2)
		return false;

	switch (criteria)
	{
	case Math::two:
		break;
	case Math::three:
		break;
	case Math::four:
		break;
	case Math::five:
		break;
	case Math::six:
		break;
	case Math::seven:
		break;
	case Math::eight:
		break;
	case Math::nine:
		break;
	case Math::ten:
		break;
	case Math::eleven:
		break;
	case Math::hundred:
		break;
	case Math::thousand:
		break;
	default:
		break;
	}

	return true;
}

int Math::GreatestCommonFactor(int x)
{

}