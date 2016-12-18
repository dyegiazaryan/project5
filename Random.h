#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#ifndef _RANDOM_H_
#define _RANDOM_H_
// File:  Random.h
// Version: 1.6
// class declaration

//if compiling for C++11 or later
//#include <unordered_map>

//if compiling using g++ for versions prior to C++11
#include <tr1/unordered_map>

// For exception handling
#include <stdexcept>

class Random
{
  public:
    Random(int l, int h, unsigned int repeats = 0); //constructor
    int get();
  private:
    int low;
    int diff;
	unsigned int maxRepeats;
    static void seed(void);
    static bool seeded;
	std::tr1::unordered_map<int, unsigned int> generatedNumbers;
};
#endif


#endif // RANDOM_H_INCLUDED
