#pragma once

class Menu
{
private:
	int choice;
public:
	void show();
	void chose();
};

class Alcohol
{
private:
	double sg, fg;
public:
	void data();
	void CountAlc();
};

class Gravity_Calc
{
private:
	double brix,sg;
public:
	void brix_to_sg();
	void sg_to_brix();
};

class Polish_Hops
{
private:
	std::string hop_name;
public:
	void load();
};

