#include "stdafx.h"
#include <iostream>
#include "Header.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm> 

void Menu::show()
{
	
	std::cout << "1. Kalkulator zawartosci alkoholu" << std::endl;
	std::cout << "2. Kalkulator BRIX do SG" << std::endl;
	std::cout << "3. Kalkulator SG do BRIX" << std::endl;
	std::cout << "4. Charakterystyka polskich odmianu chmieli" << std::endl;
	std::cout << "5. Zakoncz dzialanie programu" << std::endl;
}
void Menu::chose()  //funkcja chose wywoluje wszystkie pozostale funkcje z menu
{
	
	
	
	Menu m1;
	
	do {			//poczatek petli menu, wykonuje sie dopoki uzytkownik nie wcisnie 5

		std::cout << std::endl;
		m1.show();
		std::cout << "Wybierz: ";
		std::cin >> choice;

		if (!(std::cin))
		{
			std::cout << std::endl;
			std::cout << "Bledny wybor, sprobuj jeszcze raz ";
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

			switch (choice)
			{
			case 1:
			{
				Alcohol *p = new Alcohol;
				
				p->data();
				p->CountAlc();
				delete p;

				break;
			}

			case 2:
			{
				Gravity_Calc *p = new Gravity_Calc;
				
				p->brix_to_sg();
				delete p;

				break;
			}

			case 3:
			{
				Gravity_Calc *p = new Gravity_Calc;
				
				p->sg_to_brix();
				delete p;
				break;
			}
			case 4:
			{
				Polish_Hops *p = new Polish_Hops;
				p->load();
				
				std::string ans;

				std::cout << "Czy chcesz sprawdzic jeszcze jeden chmiel? (TAK/NIE) ";
				std::cin >> ans;
				std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

				while (ans == "tak")
				{
					p->load();
					std::cout << "Czy chcesz sprawdzic jeszcze jeden chmiel? (TAK/NIE) ";
					std::cin >> ans;
					std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
				}
				delete p;

				break;
			}
			default:
				std::cout << std::endl;
				std::cout << "Bledny wybor, sprobuj jeszcze raz ";
				std::cout << std::endl;
				break;
			}
		
	} while (choice != 5); //przy wcisnieciu 5 konczy dzialanie programu
	
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
	hop_file.open("hops/"+hop_name+ ".txt", std::ios::in);
	
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
		std::cout << "Nie mam takiego chmielu w bazie" << std::endl;
	

}


