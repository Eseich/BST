// BST.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cBST.h"


int main()
{
	cBST* _cBST;
	_cBST = new cBST;

	//_cBST->Insert(0, 100);
	//_cBST->Insert(0, 200);
	//_cBST->Insert(0, 300);
	//_cBST->Insert(0, 400);
	//_cBST->Insert(0, 500);

	//_cBST->Insert(0, 200);
	//_cBST->Insert(0, 100);
	//_cBST->Insert(0, 300);
	//_cBST->Insert(0, 50);
	//_cBST->Insert(0, 150);
	//_cBST->Insert(0, 25);
	//_cBST->Insert(0, 75);	
	//_cBST->Insert(0, 125);
	//_cBST->Insert(0, 175);
	//_cBST->Insert(0, 250);
	//_cBST->Insert(0, 350);
	//_cBST->Insert(0, 225);
	//_cBST->Insert(0, 275);
	//_cBST->Insert(0, 320);
	//_cBST->Insert(0, 375);
	//_cBST->Delete(300);

	_cBST->Insert(0, 100);
	_cBST->Insert(0, 80);
	_cBST->Insert(0, 110);

	_cBST->Insert(0, 70);
	_cBST->Insert(0, 90);
	_cBST->Insert(0, 85);
	_cBST->Insert(0, 95);

	_cBST->Find(90);
	_cBST->Delete(90);

	_cBST->PrintF(_cBST->GetCurret());
	cout << endl;
	_cBST->PrintM(_cBST->GetCurret());
	cout << endl;
	_cBST->PrintB(_cBST->GetCurret());
	cout << endl;

	return 0;
}

