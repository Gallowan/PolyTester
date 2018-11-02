//Justin Galloway
//Homework 5
//Completed 11/12/15
//Lost all data after almost completing today. :(
//Re-completed as much as possible.

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class PolyTester;

class Polynomial {
	friend class PolyTester;

private:
	int size;
	double* coeff = {0};

public:
	Polynomial();
	Polynomial(double inCoeffs[], int size);

	Polynomial(const Polynomial& obj);
	Polynomial(int num);
	Polynomial(double num);

	Polynomial& operator=(const Polynomial& obj);

	~Polynomial();

	int getSize() const;
	int getDegree() const;
	std::string str() const;
	double solve(double x) const;

	double& operator[](int index);
	Polynomial operator+(const Polynomial& fObj, const Polynomial& sObj) const;
	Polynomial operator-(const Polynomial& fObj, const Polynomial& sObj) const;
	Polynomial operator*(const Polynomial& fObj, const Polynomial& sObj) const;
	Polynomial operator*(const double num, const Polynomial& sObj) const;
	Polynomial& operator+=(const Polynomial& obj);
	Polynomial& operator-=(const Polynomial& obj);
	Polynomial& operator*=(const Polynomial& obj);
	bool operator==(const Polynomial& fObj, const Polynomial& sObj) const;
	bool operator!=(const Polynomial& fObj, const Polynomial& sObj) const;

};

std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

#endif
