/********************************************
	Name: Frac.h
	Copyright: 2021 (c)
	Author: LY THANH LONG
	Date: 22-03-21 15:08
	Description:
	Fractions
----------------story------------------------
-	Associate Professor, Dr. Nguyen Xuan Huy-
-	05/06/1944								-
-	taught me to write these lines of code	-
---------------------------------------------
*********************************************/
#ifndef __Frac__H
#define __Frac__H
#include <iostream> // console inp out
#include <cmath>

using namespace std;

typedef long long Long;

int Gcd(Long a, Long b) {
	a = abs(a), b = abs(b);
	Long r;
	while(b) {
		r = a % b;
		a = b, b = r;
	} // while
	return a;
} // Gcd

void Go() {
	cout << " ? ";
	fflush(stdin);
	if (cin.get() == '.')
		exit(0);
} // Go

// -123 => "-123"
// 13 => (2) 1101
string ToStr(Long x, int base = 10) {
	string DIG = "0123456789abcdefghijklmnopqrstuvwxyz";
	string s;
	string sign = "";
	if (x == 0) return "0";
	s = "";
	if (x < 0) {
		sign = "-";
		x = -x;
	}
	while (x) {
		s = DIG[x % base] + s;
		x /= base;
	}
	return sign + s;
} // Str

class Frac {
 	private:
		Long Num; // Tu so
		Long Den;  // Mau so
	public:
	
	Frac(Long n, Long d = 1) { // Constructor
		if (d <= 0) {
			cout << "\n ERROR: Denominator <= 0.";
			exit(0); 		
		}
		Num = n, Den = d;
	} // Frac
	
	Frac() { // Constructor
		Num = 0, Den = 1;
	} // Frac
	
	inline Long GetNum() const { return Num; }
	
	inline Long GetDen() const { return Den; }
	
	inline void Set(Long n, Long d = 1) {
		if (d <= 0) {
			cout << "\n ERROR: Denominator <= 0.";
			exit(0); 		
		}
		Num = n, Den = d;
	} // Set

	inline void Set() {
		Num = 0, Den = 1;
	} // Set
	
	inline void Reset() { Set(); }
	
	string Str() {
		string s = ToStr(Num);
		if (Num == 0 || Den == 1) return s;
		s += "/" + ToStr(Den);
		return s;
	} // Str

	inline void Print(const string msg = "") {
		cout << msg << Str();
	} // Print
	
	friend void Print(Frac f, const string msg = "") {
		cout << msg;
		cout << f.GetNum();
		if (f.GetNum() == 0 || f.GetDen() == 1) return;
		cout << "/" << f.GetDen();
	} // Print
	
	
	
 	friend ostream & operator <<(ostream & s, Frac & f) {
		s << f.Str();
		return s;
	} // << 
	
	inline Frac Reduce() {
		Long d = Gcd(Num, Den);
		Num /= d; Den /= d;
		return *this;
	} // Reduce
	
	inline Frac Minus() {
		return Frac(-Num, Den);
	} // Minus
	
	inline int Sign() {
		if (Num == 0) return 0;
		return (Num < 0) ? -1 : 1;
	} // Sign
	
	inline Frac Reverse() {
		if (Num == 0) {
			cout << "\n ERROR: Devide by zero.";
			exit(0); 		
		}
		int d = Sign();
		return Frac(d*Den, d*Num);
	} // Reverse
	
	friend Frac operator +(Frac x, Frac y) {
	  return Frac(x.Num * y.Den + x.Den * y.Num, x.Den * y.Den).Reduce();
	} // +

	friend Frac operator -(Frac x, Frac y) {
	  return x + y.Minus();
	} // -

	friend Frac operator *(Frac x, Frac y) {
	  return Frac(x.Num * y.Num, x.Den * y.Den).Reduce();
	} // *

	friend Frac operator /(Frac x, Frac y) {
	  return x * y.Reverse();
	} // /

	void operator +=(Frac y) {
		*this = *this + y;
	} // += 

	void operator -=(Frac y) {
		*this = *this - y;
	} // -= 

	void operator *=(Frac y) {
		*this = *this * y;
	} // /= 

	void operator /=(Frac y) {
		*this = *this / y;
	} // += 

	Frac operator =(Frac y) {
		Num = y.Num; Den = y.Den;
		return y;
	} // =

   /* so sanh */
   friend bool operator ==(Frac x, Frac y) {
   	return x.Num * y.Den == y.Num * x.Den;
   } // ==
   
   friend bool operator !=(Frac x, Frac y) {
   	return !(x == y);
   } // !=
   
   friend bool operator <(Frac x, Frac y) {
   	return x.Num * y.Den < y.Num * x.Den;
   } // <
 
   friend bool operator >(Frac x, Frac y) {
   	return x.Num * y.Den > y.Num * x.Den;
   } // >

   friend bool operator <=(Frac x, Frac y) {
   	return !(x > y);
   } // <=

   friend bool operator >=(Frac x, Frac y) {
   	return !(x < y);
   } // >=
   
  Frac operator++() { // Prefix increment operator
	   *this += 1;
	   return *this;
  } // ++x

   Frac operator++(int) { // Postfix increment operator
	   Frac t = *this;
	   ++*this;
	   return t;
   } // x++
	 
	Frac operator--() { // Prefix increment operator
	   *this -= 1;
	   return *this;
    } // --x

   Frac operator--(int) { // Postfix increment operator
	   Frac t = *this;
	   --*this;
	   return t;
   } // x--
};

#endif


