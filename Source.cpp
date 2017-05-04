#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <iomanip>
#include <fstream>
#include <string>

void Menu::show()
{
	std::cout << "1. Kalkulator zawartosci alkoholu" << std::endl;
	std::cout << "2. Brix to Specific Gravity Calculator" << std::endl;
	std::cout << "3. Specific Gravity to Brix Calculator" << std::endl;
	std::cout << "4. Charakterystyka polskich odmianu chmieli" << std::endl;
}
void Menu::chose()
{
	Alcohol a1;
	Gravity_Calc g1;
	Polish_Hops h1;
	

	std::cout << "Wybierz: ";
	std::cin >> choice;
	
	switch (choice)
	{
	case 1:
		a1.data();
		a1.CountAlc();
		break;
	case 2:
		g1.brix_to_sg();
		break;
	case 3:
		g1.sg_to_brix();
		break;
	case 4:
		h1.load();
		break;

	}
}

void Alcohol::data()
{
	std::cout << "Podaj ekstrakt poczatkowy: ";
	std::cin >> sg;
	std::cout << "Podaj ekstrakt koncowy: ";
	std::cin >> fg;
}

void Alcohol::CountAlc()
{
	double alc = (sg - fg) / 1.938;
	std::cout<<"Zawartosc alkoholu wynosi: " << std::setprecision(3)<<alc<<"%"<<std::endl;
}

void Gravity_Calc::brix_to_sg()
{
	std::cout << "Podaj ekstrakt w brix: " << std::endl;
	std::cin >> brix;
	std::cout << "Ekstrakt w sg wynosi " << (brix / (258.6 - ((brix / 258.2)*227.1))) + 1 << std::endl;
}

void Gravity_Calc::sg_to_brix()
{
	std::cout << "Podaj ekstrakt w sg: " << std::endl;
	std::cin >> sg;
	std::cout << "Ekstrakt w brix wynosi " << (((182.4601 * sg - 775.6821) * sg + 1262.7794) * sg - 669.5622) << std::endl;
}

void Polish_Hops::load()
{
	
	std::cout << "Wpisz nazwe chmielu: ";
	std::cin >> hop_name;
	
	std::ifstream hop_file;
	hop_file.open(hop_name+ ".txt", std::ios::in);
	
	std::string str;

	if (hop_file.is_open())
	{
		while (std::getline(hop_file, str))
		{
			std::cout<<std::endl<<str << std::endl;
		}
		std::cout << std::endl;
		hop_file.close();
	}
	else
		std::cout << "Nie mog� otworzy� pliku" << std::endl;
	

}