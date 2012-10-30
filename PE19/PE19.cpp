/*
 * Author: Matt Schwager
 * schwag09@gmail.com
 * Project Euler problem 19
 * Sundays in the 20th century
 */

#include <iostream>

const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int sundayCount = 0;
	int dayCount = 0;

	//Jan 1 1901 is a Tuesday
	for(int year = 1901; year <= 2000; ++year)
	{
		for(int month = 0; month < 12; ++month)
		{
			//Account for leap years
			if(month == 1)
			{
				if(!(year % 400))
				{
					dayCount++;
				}
				else if(!(year % 100))
				{
				}
				else if(!(year % 4))
				{
					dayCount++;
				}
				else
				{
				}
			}
			dayCount += monthDays[month];

			//Tuesday will count as the first day of the week
			//Therefore sunday is the fifth day of the week
			if(dayCount % 7 == 5)
			{
				sundayCount++;
			}
		}
	}
	std::cout << sundayCount << std::endl;

	return 0;
}
