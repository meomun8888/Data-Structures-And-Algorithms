/*
	Name:    TESTFRAC.CPP
	Copyright: 2021 (c)
	Author: LY THANH LONG
	Date: 23-03-21 17:11
	Description:
	Test of class Frac
*/
/*
----------------story------------------------
-	Associate Professor, Dr. Nguyen Xuan Huy-
-	05/06/1944								-
-	taught me to write these lines of code	-
---------------------------------------------
*/
#include <iostream>
#include <time.h>
#include <windows.h>


#include "Frac.h"

using namespace std;

void Show(Frac x) {
	cout << "\n Show " << x;
} // Show

/*--------------------------------------------
Test thuan nghich: front-back Test (FB Test)
Test doi xung: Symmetry Test (ST Test)
Idea:
1. Xuat phat tu cau hinh A.
2. Test xuoi: A -> B.
3. Test nguoc: B -> C
4. A = C ?

Vi du
Frac x, y, z, t, v
1. Sinh ngau nhien 3 phan so: x, y, z, z != 0
2. Tinh t = (x+y)z = xz + yz
3. Tim v = (t - yz)/z
4. v = x ?
----------------------------------------------*/


void FBTest() {
	srand(time(NULL));
	Frac x, y, z, t, v;
	int r = 10;
	while(true) {
		x.Set(rand() % r, rand() % r + 1);
		y.Set(rand() % r, rand() % r + 1);
		z.Set(rand() % r + 1, rand() % r + 1);
		cout << "\n x = " << x;
		cout << "\n y = " << y;
		cout << "\n z = " << z;
		t = (x + y)*z; // t = xz + yz
		v = (t - y*z) / z;
		cout << "\n v = " << v << " == x ? ";
		if (v == x) cout << " CORRECT.";
		else cout << " ERROR.";
		Go();
    }
} // Test2

void Test1() {
	Frac x(1,2), y(3,4), z(x), t(4);
	cout << "\n x: " << x;
	cout << "\n y: " << y;
	cout << "\n z: " << z;
	cout << "\n t: " << t;
	Show(x); // 1/2
	cout << "\n x: " << x; // 1/2
	Show(++x); // 3/2
	cout << "\n x: " << x; // 3/2
	
	Show(y); // 3/4
	cout << "\n y: " << y; // 3/4
	
	Show(y++); // 3/4 -> 7/4
	cout << "\n y: " << y; // 7/4
	
	Show(z); // 1/2
	cout << "\n z: " << z; // 1/2

	Show(z--); // 1/2 -> -1/2
	cout << "\n z: " << z; // -1/2
	
	Show(z); // -1/2
	cout << "\n z: " << z; // -1/2

	Show(--z); // -1/2 - 1 = -3/2
	cout << "\n z: " << z; // -3/2
	
	Show(t); // 4
	cout << "\n t: " << t; // 4
	
	Show(++t); // 5
	cout << "\n t: " << t; // 5
	
	Show(t++); // 5
	cout << "\n t: " << t; // 6
}  // Test1



main() {
	// Test1();
	FBTest();
	// --------------------------------
	cout << "\n T h e   E n d .";
	return 0;
}
