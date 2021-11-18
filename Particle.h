#pragma once
#include "Windows.h"
#include "Timer.h"
#include <cstdlib>
#include <cmath>

class Particle
{
	private:
		double x = 0;
		double y = 0;
		double vx = 0;
		double vy = 0;
		double ax = 0;
		double ay = 0;
		double omega = 0;
		double phi = 0;
		double radius = 0;
		int mx = 0;
		int my = 0;
		Timer timer;
		double lastupdate = 0;
		double life = 0;
		COLORREF color = 0;
		HDC hdc = 0;

		double rand(void);

	public:
		Particle(void);
		~Particle(void);
		void init(void);
		void clean(void);
		void update(void);
		void draw(void);
		void setCursorPos(int mx,int my);
		void setHDC(HDC hdc);



};

