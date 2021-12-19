#pragma once
#include <iostream>
class timer {
	int h, m;
	double s;
public:
	timer() {
		h = 0;
		m = 0;
		s = 0;
	}
	timer(int h, int m, double s) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	int getHours() {
		return h;
	}
	int getMinutes() {
		return m;
	}
	void setMinutes(int m) {
		if (m > 0) {
			this->m = m;
		}
	}
	double getSeconds() {
		return s;
	}
	void setSeconds(double s) {
		if (s > 0) {
			this->s = s;
		}
	}
	timer operator+=(const timer& t);
	timer operator+(const timer& t);
	timer operator/=(const size_t& v);
	timer operator/(const size_t& v);
	operator double();
	timer operator-(const timer& max);
	bool operator<(const timer& t);
	friend std::ostream& operator<<(std::ostream& os, const timer& t);
};
class penalty{

	double seconds;
public:
	penalty(){
		seconds = 0;
	}
	penalty(double s) {
		seconds = s;
	}
	penalty operator()(timer& t);
	friend std::ostream& operator<<(std::ostream& os, const penalty& p);
};