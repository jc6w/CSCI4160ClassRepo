#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
private:
	unsigned int hour, minute;
	char AMorPM;



public:
	//setters
	void setHour(unsigned int h)	{ hour = h; }
	void setMinute(unsigned int m) { minute = m; }
	void setDayNight(char a) { AMorPM = a; }
	
	//getters
	unsigned int getHour() { return hour; }
	unsigned int getMinute() { return minute; }
	char getDayNight() { return AMorPM; }

	//constructor
	Time();			//default constructor
	Time(unsigned int, unsigned int, char);

	//member functions
	void milTime(Time);
	void display();
	void advance();
};







#endif