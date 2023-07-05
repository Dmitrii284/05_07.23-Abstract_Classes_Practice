/*
Практика
Создать базовые классы для растений и плодов
Заложить в классы плодов и растений:

Класс Плод - Возможность узнавать свое название(задается при создании) (Наследники ЯблокиБ Груши, и тд) Harvest
Узнавать свой вес и цвет (так же можно создать при создании)


Класс Растение Знать  какой у него размер Большой маленький(Наследники Деревья Ели Яблоня Вишня) ПЛЭНТ Plant
Знать Размер  Большой , Маленький  Средний 
Цвет и сколько на нем может быть плодов.

Дополнить 05.07.23.
Создать контейнеры наследников для класса Растение
Пример( Яблоня груша Малина Яжевика)
которые связаны со своими наследниками класса плод
и которые возвращают плоды пока они есть на дереве
через виртуальный метод базового класса

*/

#include<iostream>
#include<string>
class Apple;
class AppleTree;
class Harvest;
class Plant
{
private:
	std::string _nameTree;
	float _heigthTree;
	std::string _type;// Большойе Маленькое Среднее
	std::string _color;
	int _numFruits;

public:

	int fruitCount = 0;

	Plant(const std::string& nameTree, float heigthTree, const std::string& type, const std::string& color, int numFruits) : _nameTree{ nameTree },
		_heigthTree{ heigthTree }, _type{ type }, _color{ color }, _numFruits{ numFruits } {  fruitCount = _numFruits; }
		
	 

	virtual void ShowPlant() const
	{
		std::cout << "NameTree: " << _nameTree << std::endl;
		std::cout << "Heigth Tree: " << _heigthTree << std::endl;
		std::cout << "Tree type: " << _type << std::endl; // Большойе Маленькое Среднее
		std::cout << "Color: " << _color << std::endl;
		std::cout << "Numbers of Fruits: " << _numFruits << std::endl;
	}

	virtual ~Plant()
	{
		std::cout << this << " Destroid Plant \n";		
	}

	virtual Harvest* harvestFruit() = 0;
};

class Harvest
{
private:
	std::string _name;
	float _weigth;
	std::string _colorHar;
public:
	
	Harvest(const std::string name, float weigth, const std::string colorHar) : _name{ name },
		_weigth{ weigth }, _colorHar{ colorHar }
	{ 
		std::cout << this << " Harvest object created\n";
	}

	virtual ~Harvest() 
	{	
		std::cout << this << " Destroid Plant \n";	
	}

	virtual	void ShowHarvest() const
	{
		std::cout << "Fruit name: " << _name << std::endl;
		std::cout << "Heigth Tree: " << _weigth << std::endl;		
		std::cout << "Color: " << _colorHar << std::endl;		
	}

	
};

class Apple : public Harvest
{
public:

	Apple(const std::string name, float weigth, const std::string colorHar) : Harvest(name, weigth, colorHar)
	{
		std::cout << this << " Apple object created\n";
	}

	~Apple() override
	{
		std::cout << this << " Destroid Apple \n";
	}
};

class Spruce : public Plant //
{
public:
	Spruce(const std::string nameTree,float heigthTree, const std::string type, const std::string& color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits)
	{ 
		std::cout << this << "Spruce object created\n";
	}
	~Spruce() override
	{
		std::cout << this << " Destroid Plant \n";
	}
};
class Pine : public Plant // Сосна не плодоносное
{
public:
	Pine(const std::string nameTree, float heigthTree, const std::string type, const std::string& color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits)
	{
		std::cout << this << " Pine object created\n";
	}
	~Pine() override
	{
		std::cout << this << " Destroid Pine \n";
	}
};
class CherryTree : public Plant
{
public:
	CherryTree(const std::string nameTree, float heigthTree, const std::string type, const std::string& color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits)
	{
		std::cout << this << " CherryTree object created\n";
	}
	~CherryTree() override
	{
		std::cout << this << " Destroid CherryTree \n";
	}
};
class AppleTree : public Plant
{
public:
	AppleTree(const std::string nameTree, float heigthTree, const std::string type, const std::string& color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits)
	{
		std::cout << this << " AppleTree object created\n";
	}
	~AppleTree() override
	{
		std::cout << this << " Destroid AppleTree \n";
	}

	void ShowPlant()const override
	{
		Plant::ShowPlant();
		std::cout << " Fruit count: " << fruitCount << std::endl;
	}

	Harvest* harvestFruit()  override
	{
		--fruitCount;
		return new Apple("Apple", 20.32, "Green");
	}
};
class PearTree : public Plant
{
public:
	PearTree(const std::string nameTree, float heigthTree, const std::string type, const std::string& color, int numFruits)
		: Plant(nameTree, heigthTree, type, color, numFruits)
	{
		std::cout << this << "PearTree object created\n";
	}

	~PearTree() override
	{
		std::cout << this << " Destroid PearTree \n";
	}

};


class Pear : public Harvest
{
public:
	Pear(const std::string name, float weigth, const std::string colorHar) : Harvest(name, weigth, colorHar)
	{
		std::cout << this << " Pear object created\n";
	}

	~Pear() override
	{
		std::cout << this << " Destroid Pear \n";
	}

};
class Cherry : public Harvest
{
public:
	Cherry(const std::string name, float weigth, const std::string colorHar) : Harvest(name, weigth, colorHar)
	{
		std::cout << this << " Cherry object created\n";
	}
	~Cherry() override
	{
		std::cout << this << " Destroid Cherry \n";
	}

};



int main()
{
	AppleTree tree("Apple Tree", 50," Average", "Green", 20);
	tree.ShowPlant();

	Harvest* apple = tree.harvestFruit();
	apple->ShowHarvest();

	delete apple;

	return{};
}