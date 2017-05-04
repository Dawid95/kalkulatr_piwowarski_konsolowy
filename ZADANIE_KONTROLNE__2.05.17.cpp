// ZADANIE_KONTROLNE__2.05.17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Header.h"


int main()
{
	setlocale(LC_ALL, "");
	
	Menu menu1;
	menu1.show();
	menu1.chose();

	
	
	
	system("pause");
    return 0;
}