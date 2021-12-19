#include <iostream>
#include "Header.h"
using namespace std;

timer timer::operator+=(const timer& t) {
	h = h + t.h;
	m = m + t.m;
	s = s + t.s;
	if (s > 59) {
		++m;
		s -= 60;
	}
	if (m > 59) {
		++h;
		m -= 60;
	}
	
	return *this;
}
timer timer::operator+(const timer& t) {
	s = s + t.s;
	m = m + t.m;
	h = h + t.h;
	if (s > 59) {
		++m;
		s -= 60;
	}
	if (m > 59) {
		++h;
		m -= 60;
	}
	return *this;
}
timer timer::operator/=(const size_t& v) {
	double time = 3600 * h + 60 * m + s;
	time /= v;

	h = time / 3600;
	m = (time - (h * 3600)) / 60;
	s = (time - ((h * 3600) + (m * 60)));
	return *this;
}
timer timer::operator/(const size_t& v) {
	double time = 3600 * h + 60 * m + s;
	time /= v;
	
	h = time / 3600;
	m = (time - (h * 3600)) / 60;
	s = (time - ((h * 3600) + (m * 60)));
	return *this;
}
timer::operator double() {
	return(h +  m + s);
}
timer timer::operator-(const timer& max) {
	int hours = h - max.h;
	int minutes = m - max.m;
	double seconds = 0;
	if (minutes) {
		seconds = (s + minutes * 60) - max.s;
	}
	else {
		seconds = s - max.s;
	}
	return timer(hours, minutes, seconds);
}
bool timer::operator<(const timer& t) {
	return(h < t.h && m < t.m && s < t.s);
}
penalty penalty::operator()(timer& t) {
	int hours = t.getHours();
	int minutes = t.getMinutes();
	double seconds = t.getSeconds() + this->seconds;
	t.setMinutes(minutes);
	if (seconds > 59) {
		++minutes;
		seconds -= 60;
	}
	t.setMinutes(minutes);
	t.setSeconds(seconds);
	return *this;
}
ostream& operator<<(ostream& os, const timer& t)
{
	os << t.h << ':' << t.m << ':' << t.s << endl;
	return os;
}
ostream& operator<<(ostream& os, const penalty& p)
{
	os << p.seconds << endl;
	return os;
}