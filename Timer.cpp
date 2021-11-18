#include "Timer.h"

Timer::Timer()
{
	reset(); 
}

Timer::~Timer()
{
}

void Timer::reset()
{
	start = GetTickCount64();
}

double Timer::get()
{
	return (GetTickCount64() - start) / 1000.0;
}