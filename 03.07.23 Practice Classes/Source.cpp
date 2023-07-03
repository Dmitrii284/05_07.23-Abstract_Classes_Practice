/*
Практика
Создать базовые классы для растений и плодов
Заложить в классы плодов и растений:

Класс Плод - Возможность узнавать свое название(задается при создании) (Наследники ЯблокиБ Груши, и тд) Harvest
Узнавать свой вес и цвет (так же можно создать при создании)


Класс Растение Знать  какой у него размер Большой маленький(Наследники Деревья Ели Яблоня Вишня) ПЛЭНТ Plant
Знать Размер  Большой , Маленький  Средний 
Цвет и сколько на нем может быть плодов.

*/

#include<iostream>



class Plant
{
private:
	std::string _nameTree;
	float _heigthTree;
	std::string _type;// Плодовое или нет
public:
	Plant(const std::string& nameTree, float heigthTree, const std::string& type) : _nameTree{nameTree},
		_heigthTree{ heigthTree }, _type{type} { }
		

	~Plant()
	{
		std::cout << this << " Destroid Plant \n";		
	}

};
class Harvest
{
private:
	std::string _name;
	float _weight;
	std::string _color;
public:
	Harvest(const std::string name, float weight, const std::string color ) : _name{ name },
		_weight{ weight },_color{ color }{ }

	~Harvest()
	{	
		std::cout << this << " Destroid Plant \n";	
	}
};

class Spruce : public Plant // Ель не плодоносное
{
public:
	Spruce(const std::string nameTree,float heigthTree, const std::string type) 
		: Plant(nameTree, heigthTree, type)
	{ 
		std::cout << this << "Spruce object created\n";
	}

};
class Pine : public Plant // Сосна не плодоносное
{
public:
	Pine(const std::string nameTree, float heigthTree, const std::string type)
		: Plant(nameTree, heigthTree, type)
	{
		std::cout << this << "Pine object created\n";
	}

};
class CherryTree : public Plant
{
public:
	CherryTree(const std::string nameTree, float heigthTree, const std::string type)
		: Plant(nameTree, heigthTree, type)
	{
		std::cout << this << "CherryTree object created\n";
	}

};
class AppleTree : public Plant
{
public:
	AppleTree(const std::string nameTree, float heigthTree, const std::string type)
		: Plant(nameTree, heigthTree, type)
	{
		std::cout << this << "AppleTree object created\n";
	}

};
class PearTree : public Plant
{
public:
	PearTree(const std::string nameTree, float heigthTree, const std::string type)
		: Plant(nameTree, heigthTree, type)
	{
		std::cout << this << "PearTree object created\n";
	}
};


class Apple : public Harvest
{
public:


};
class Pear : public Harvest
{
public:

};
class Cherry : public Harvest
{
public:

};



