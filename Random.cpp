// File:  Random.cpp
// Version: 1.6

#include <cstdlib>
#include <ctime>

#include "Random.h"
// class definition

bool Random::seeded = false;

void Random::seed(void)
{
  if(seeded) return; //we only want to seed once
  seeded = true;
  srand((int)time(0)); //seeds the random number generator
}

Random::Random(int l, int h, unsigned int repeats) : low(l), diff(h-l+1), maxRepeats(repeats)
{
	if (l >= h)
		throw std::runtime_error("Random: Error - low value must be less than high value");

   if (maxRepeats < 0)
      throw std::runtime_error("Random: Error - numberRepeats cannot be less than zero (0)");

	if (maxRepeats != 0)
	{
		for (int i = l; i <= h; ++i)
		{
			generatedNumbers[i] = 0;
		}
	}

	seed();
}

int Random::get()
{
	// Generate random number in the range
	int returnVal = (rand()%diff)+low;

	// Unlimited duplicates
	if (maxRepeats == 0)
		return returnVal;

   // Determine if we will increment or decrement
   // through the loop, if needed
   bool increment = (rand()%2);

	// Keep track of the last value that should be checked
   int endPoint;
   if (increment)
   {
      endPoint = returnVal-1;
      if (endPoint < low)
   		endPoint = low+diff-1;
   }
   else
   {
      endPoint = returnVal+1;
      if (endPoint > low+diff-1)
   		endPoint = low;
   }


	// Using the generated random number as a starting point, keep
	// incrementing until you find the first number in the range
   // that hasn't had yet reached the max number of duplicates
	while (generatedNumbers[returnVal] == maxRepeats)
	{
      if (increment)
      {
   		//If incrementing takes us outside the range, then
   		//go back to the starting point of the range
   		if (++returnVal > (low+diff-1))
   		{
   			returnVal = low;
   		}
      }
      else
      {
         //If decrementing takes us outside the range, then
   		//go to the end point of the range
   		if (--returnVal < low)
   		{
   			returnVal = low+diff-1;
   		}
      }

		// If we have gone through the entire range
		// and they all have reached the max repeat value,
		// throw an exception
		if (returnVal == endPoint && generatedNumbers[returnVal] == maxRepeats)
		{
			throw std::runtime_error("Random: Error - All random numbers in the range have been generated to the max repeat value");
		}
	}

	//increase the count of the generated number
	generatedNumbers[returnVal]++;

	return returnVal;
}
