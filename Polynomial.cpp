//Justin Galloway
//Homework 5
//Completed 11/12/15
//Lost all data after almost completing today. :(
//Re-completed as much as possible.

#include <math.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include "Polynomial.h"

Polynomial::Polynomial() : size(1), coeff(new double[1]) {
	coeff[0] = 0.0;
}

Polynomial::Polynomial(double inCoeffs[], int num) :
		size(num), coeff(new double[num]) {
	for (int i = 0; i < size; i++) {
		coeff[i] = inCoeffs[i];
	}
}

Polynomial::Polynomial(const Polynomial& obj) :
		size(obj.size), coeff(new double[obj.size]) {
	for (int i = 0; i < size; i++) {
		coeff[i] = obj.coeff[i];
	}
}

//Simple switch. Size is 1 since it's a constructor.
Polynomial::Polynomial(int num) {
	size = 1;
	coeff[0] = num;
}

//Simple switch. Size is 1 still.
Polynomial::Polynomial(double num) {
	size = 1;
	coeff[0] = num;
}

//If not already equal, deletes the poly and creates a new one.
Polynomial& Polynomial::operator=(const Polynomial& obj); {
	if (this == &obj) {
		return *this;
	} else {
		delete [] coeff;
		coeff = new double[obj.size];
		size = obj.size;
		for (int i = 0; i < size; i++) {
			coeff[i] = obj.coeff[i];
		}
	}
} //? Check for clarity later. Has syntax error.

Polynomial::~Polynomial() {
	delete []coeff;
}

int Polynomial::getSize() const{
	return size;
}

int Polynomial::getDegree() const{
	return coeff[size-1]; //?
}

void Polynomial::std::string str() const {
	if (size == 0) {
		return;
	}

	for (int i = size - 1; i > 0; i--) {
		std::cout << coeff[i] << "x^" << i << " + ";
	}
	std::cout << coeff[0];
}

double Polynomial::solve(double x) const {
	double result = 0.0;
	for (int i = 0; i < getSize(); i++) {
		double expNum = pow(x,i);
		double value = coeff[i]*expNum;
		result += value;
	}
	return result;
}

double& Polynomial::operator[](int index) {
	int newSize = index;
	if (index < size) {
		return coeff[index];
	} else {
		double* newCoeff = new double[newSize];
		size = newSize;
		for (int i = 0; i < newSize; i++) {
			newCoeff[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			newCoeff[i] += coeff[i];
		}
		delete [] coeff;
		return newCoeff[index];
	}
}

//Takes two Polynomials labeled first and second and adds them together.
Polynomial operator+(const Polynomial& fObj, const Polynomial& sObj) const {
	Polynomial result(fObj);
	result += sObj;
	return result;
}

Polynomial operator-(const Polynomial& fObj, const Polynomial& sObj) const {
	Polynomial result(fObj);
	result -= sObj;
	return result;
}

Polynomial operator*(const Polynomial& fObj, const Polynomial& sObj) const {
	Polynomial result(fObj);
	result *= sObj;
	return result;
}

Polynomial operator*(const double num, const Polynomial& sObj) const {
	Polynomial result(sObj);
	result *= num;
	return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& obj) {
	int newSize = (obj.size > size) ? obj.size : size;
	double *newCoeff = new double[newSize];

	//Initializes as 0.
	for (int i = 0; i < newSize; i++) {
		newCoeff[i] = 0;
	}
	for (int i = 0; i < obj.size; i++) {
		newCoeff[i] += obj.coeff[i];
	}
	for (int i = 0; i < size; i++) {
		newCoeff[i] += coeff[i];
	}
	//Rewrites everything else.
	delete [] coeff;
	coeff = newCoeff;
	size = newSize;
	return *this;
}

//Same as previous function, with flipped signs.
Polynomial& Polynomial::operator-=(const Polynomial& obj) {
	int newSize = (obj.size > size) ? obj.size : size;
	double *newCoeff = new double[newSize];

	//Initializes as 0.
	for (int i = 0; i < newSize; i++) {
		newCoeff[i] = 0;
	}
	for (int i = 0; i < obj.size; i++) {
		newCoeff[i] -= obj.coeff[i];
	}
	for (int i = 0; i < size; i++) {
		newCoeff[i] -= coeff[i];
	}
	//Rewrites everything else.
	delete [] coeff;
	coeff = newCoeff;
	size = newSize;
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& obj) {
	for (int i = 0; i < size; i++) {
		coeff[i] *= obj;
	}
	return *this;
}

//Takes two Polynomials and compares their size and each position.
bool operator==(const Polynomial& fObj, const Polynomial& sObj) const {
	if (fObj.size != sObj.size) {
		return false;
	}
	for (int i = 0; i < fObj.size; i++) {
		if (fObj.coeff[i] != sObj.coeff[i]) {
			return false;
		}
	}
	return true;
}

//Same as previous function, but with flipped results.
bool operator!=(const Polynomial& fObj, const Polynomial& sObj) const {
	if (fObj.size != sObj.size) {
		return true;
	}
	for (int i = 0; i < fObj.size; i++) {
		if (fObj.coeff[i] != sObj.coeff[i]) {
			return true;
		}
	}
	return false;
}


















