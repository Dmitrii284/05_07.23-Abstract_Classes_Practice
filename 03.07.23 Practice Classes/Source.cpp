/*
��������
������� ������� ������ ��� �������� � ������
�������� � ������ ������ � ��������:

����� ���� - ����������� �������� ���� ��������(�������� ��� ��������) (���������� ������� �����, � ��) Harvest
�������� ���� ��� � ���� (��� �� ����� ������� ��� ��������)


����� �������� �����  ����� � ���� ������ ������� ���������(���������� ������� ��� ������ �����) ����� Plant
����� ������  ������� , ���������  ������� 
���� � ������� �� ��� ����� ���� ������.

*/

#include<iostream>



class Plant
{
private:
	std::string _nameTree;
	float _heigthTree;
	std::string _type;// �������� ��� ���
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

class Spruce : public Plant // ��� �� �����������
{
public:
	Spruce(const std::string nameTree,float heigthTree, const std::string type) 
		: Plant(nameTree, heigthTree, type)
	{ 
		std::cout << this << "Spruce object created\n";
	}

};
class Pine : public Plant // ����� �� �����������
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



