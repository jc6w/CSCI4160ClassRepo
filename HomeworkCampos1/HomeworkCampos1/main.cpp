#include <iostream>
#include<math.h>
#include "Time.h"
using std::cin;
using std::cout;

bool compare(Time, Time);


int main()
{
	Time mealTime (5,30,'P');
	Time goToWorkTime(5,30,'P');
	bool hurry;

	cout << "We'll be eating at ";
	mealTime.display();

	cout << "You leave for work at ";
	goToWorkTime.display();

	hurry = compare(mealTime, goToWorkTime);

	switch (hurry)
	{
	case true:
		cout << "Sorry you can't eat with us.\n\n";
		break;

	default:
		cout << "If you hurry, you can eat first.\n\n";
	}

	goToWorkTime.advance();

	cout << "You leave for work at ";
	goToWorkTime.display();


	hurry = compare(mealTime, goToWorkTime);

	switch (hurry)
	{
	case true:
		cout << "Sorry you can't eat with us.\n\n";
		break;

	default:
		cout << "If you hurry, you can eat first.\n\n";
	}


	return 0;
}


bool compare(Time meal, Time work)
{

	if (islessequal(work.getDayNight(), meal.getDayNight()))
	{
		if (islessequal(work.getHour(),meal.getHour()))
		{
			if (islessequal(work.getMinute(), meal.getMinute()))
			{
				return true;
			}
		}
	}

	return false;
}
