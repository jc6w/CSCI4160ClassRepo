#include "Time.h"
#include <iostream>
using std::cout;


Time::Time()
{
	hour = 12;
	minute = 0;
	AMorPM = 'A';
}


Time::Time(unsigned int h, unsigned int m, char ap)
{
	setHour(h);
	setMinute(m);
	setDayNight(ap);
}

void Time::milTime(Time t)
{
	int h = t.getHour();
	int m = t.getMinute();
	char ap = t.getDayNight();


	if (ap == 'P' && h < 12)
	{
		h += 12;
	}
	if ((h == 12&& ap == 'A')  || h == 24)
	{
		h = 0;
	}
	if (m >= 60 && m < 120)
	{
		if (h == 11 && ap == 'A')
		{
			m -= 60;
			h += 1;
			ap = 'P';
		}
		else if (h == 11 && ap == 'P')
		{
			m -= 60;
			h += 1;
			ap = 'A';
		}
		else
		{
			m -= 60;
			h += 1;
		}
	}
}

void Time::display()
{
	cout << hour << ":";
	
	if (minute < 10)
	{
		cout << "0" << minute << " ";
	}
	else
	{
		cout << minute << " ";
	}


	if (AMorPM == 'A')
	{
		cout << "AM" << "\n\n";
	}
	else if (AMorPM == 'P')
	{
		cout << "PM" << "\n\n";
	}
}

void Time::advance()
{
	minute = (minute + 30);
	if (minute >= 60)
	{
		if (hour == 11 && AMorPM == 'A')
		{
			minute = minute - 60;
			hour = hour + 1;
			AMorPM = 'P';
		}
		else if (hour == 11 && AMorPM == 'P')
		{
			minute = minute - 60;
			hour = hour + 1;
			AMorPM = 'A';
		}
		else
		{
			minute = minute - 60;
			hour = hour + 1;
		}

	}

	cout << "Your boss called. You go in later at " << hour << ":";
	
	if (minute < 10)
	{
		cout << "0" << minute << " ";
	}
	else
	{
		cout << minute << " ";
	}


	if (AMorPM == 'A')
	{
		cout << "AM" << "\n\n";
	}
	else if (AMorPM == 'P')
	{
		cout << "PM" << "\n\n";
	}

}