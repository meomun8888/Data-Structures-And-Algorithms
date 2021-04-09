/*******************************************************
	Name:    Farey.CPP
	Copyright: 2021 (c)
	Author: LY THANH LONG
	Date: 23-03-21 17:11
	Description:
	Farey sequence: Given an integer n > 0.
	Write all reduced fractions t/m in ascending ord:
	0 <= t/m <= 1, 1 <= m <= n
	n = 5:
----------------story------------------------
-	Associate Professor, Dr. Nguyen Xuan Huy-
-	05/06/1944								-
-	taught me to write these lines of code	-
---------------------------------------------
*********************************************************/

#include <iostream>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <list>
#include <iterator>
#include <set>
#include <bits/stdc++.h>



#include "Frac.h"

using namespace std;

void Print(Frac f[], int d, int c, const string msg = "") {
	 cout << msg;
	 int cc = 0;
	 for (int i = d; i <= c; ++i) {
		 ++cc;
		 cout << " " << f[i];
		 if (cc % 10 == 0) cout << "\n ";
	 }

} // Print

void Farey1(int n) {
	Frac f[500];
	// Generate
	f[0].Set(0); f[1].Set(1);
	int k = 1;
	for (int m = 2; m <= n; ++m) {
		 for (int t = 1; t < m; ++t) {
			f[++k].Set(t, m);
			f[k].Reduce();
		 }
	} // for m
	// Print(f, 0, k);
	sort(f, f+k+1);
	// Print(f, 0, k, "\n Sorted: ");
	// Eliminate duplicates
	int j = 0;
	for  (int i = 1; i <= k; ++i) {
		if (f[i] != f[j]) {
			f[++j] = f[i];
		}
	} // for
	k = j;
	Print(f, 0, k, "\n Result: ");
	cout << "\n Total " << k+1 << " fraction(s).";
} // Farey1

typedef list<Frac> LF;

void Print(LF f, const string msg = "") {
	cout << msg;
	LF :: iterator it;
	for (it = f.begin(); it != f.end(); ++it) {
		cout << " " << *it;
	}
} // Print

// Using List
void Farey2(int n) {
	LF f;
	f.push_back(Frac(0));
	f.push_back(Frac(1));
	Print(f," \n Init: ");
	for (int m = 2; m <= n; ++m) {
		 for (int t = 1; t < m; ++t) {
			  f.push_back(Frac(t,m).Reduce());
		 }
	} // for m
	f.sort();
	f.unique();
	
	Print(f," \n Result: ");
	cout << "\n Total: " << f.size() << " fraction(s).";
}  // Frac2

// Using Set
typedef set<Frac> SF;

void Print(SF f, const string msg = "") {
	cout << msg;
	SF :: iterator it;
	for (it = f.begin(); it != f.end(); ++it) {
		Print(*it, " ");
	}
} // Print

// Using Set
void Farey3(int n) {
	SF f;
	f.insert(Frac(0));
	f.insert(Frac(1));
	Print(f," \n Init: ");
	for (int m = 2; m <= n; ++m) {
		 for (int t = 1; t < m; ++t) {
			  f.insert(Frac(t,m).Reduce());
		 }
	} // for m
	Print(f," \n Result: ");
	cout << "\n Total: " << f.size() << " fraction(s).";
}  // Frac3

main() {
	// Farey1(15);
	// Farey2(5);
	Farey3(5);
	
	// --------------------------------
	cout << "\n T h e   E n d .";
	return 0;
}
