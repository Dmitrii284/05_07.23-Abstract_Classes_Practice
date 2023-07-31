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
#include<vector>
#include<conio.h>
class Apple;
class AppleTree;
class Harvest;
class Backpack;

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
	virtual std::shared_ptr<Harvest> harvestFruit1() = 0;
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

//class Spruce : public Plant //
//{
//public:
//	Spruce(const std::string nameTree,float heigthTree, const std::string type, const std::string& color, int numFruits)
//		: Plant(nameTree, heigthTree, type, color, numFruits)
//	{ 
//		std::cout << this << "Spruce object created\n";
//	}
//	~Spruce() override
//	{
//		std::cout << this << " Destroid Plant \n";
//	}
//};
//class Pine : public Plant // Сосна не плодоносное
//{
//public:
//	Pine(const std::string nameTree, float heigthTree, const std::string type, const std::string& color, int numFruits)
//		: Plant(nameTree, heigthTree, type, color, numFruits)
//	{
//		std::cout << this << " Pine object created\n";
//	}
//	~Pine() override
//	{
//		std::cout << this << " Destroid Pine \n";
//	}
//};
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
	void ShowPlant()const override
	{
		Plant::ShowPlant();
		std::cout << " Fruit count: " << fruitCount << std::endl;
	}
	Harvest* harvestFruit()  override
	{
		--fruitCount;
		return new Cherry("Cherry", 10.7, "Bard");
	}
	std::shared_ptr<Harvest> harvestFruit1()  override
	{
		--fruitCount;
		return std::make_shared<Pear>("Cherry", 12.5, "Red-Yellow");
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
	std::shared_ptr<Harvest> harvestFruit1()  override
	{
		--fruitCount;
		return std::make_shared<Pear>("Apple", 10.2, "Red - Green");
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
	void ShowPlant()const override
	{
		Plant::ShowPlant();
		std::cout << " Fruit count: " << fruitCount << std::endl;
	}
	Harvest* harvestFruit()  override
	{
		--fruitCount;
		return new Pear("Pear", 18.8, "Yellow");
	}
	std::shared_ptr<Harvest> harvestFruit1()  override
	{
		--fruitCount;
		return std::make_shared<Pear>("Pear", 30, "Yellow - White");
	}
};

//class Backpack // Создали класс Рюкзак
//{
//private:
//	std::vector<std::shared_ptr<Harvest>> _backpack;// Контейнер для плодов
//public:
//	void PushBackpack(const std::shared_ptr<Harvest>& fruit) // Создаем метод который кладет в контейнер плоды
//	{// Принимает в себя константный умный указатель на объект класса Harvest по ссылке &
//		//_backpack.push_back(std::move(fruit)); // Так не делаем потому что он из main() будет перемещать, а в main() будет пустой аргумент тоесть он будет указывать на NALL
//		_backpack.push_back(fruit); // Каладем в контейнер аргумент функции PushBackpack
//	}
//
//	//Apple pear apple grape potato
//	//grape
//
//	void Show() // Функцию Show для показа объектов контейнера(рюкзака)
//	{
//		std::vector<std::shared_ptr<Harvest>>::iterator fruit = _backpack.begin();// Создаем итератор который указывает на вектор содержащий в себе
//		//умные казатели на объекты класса Harvest
//		std::vector<std::shared_ptr<Harvest>>::iterator deleted = _backpack.end(); // Создаем невалидный итератор для удаляемого значения из вектора
//
//		char action{ '0' };// Создаем переменную в которой храниться ввод от пользователя
//		int count{ 0 };// Создаем индекс элемента накотором стоим
//
//		while (action != '4')
//		{
//			system("cls");
//			(*fruit)->ShowHarvest();
//			std::cout << "\nNumber of fruits : " << _backpack.size() << std::endl;
//			std::cout << "\nFruit " << count + 1 << '/' << _backpack.size() << ' ' << std::endl;
//			std::cout << "\n\n";
//			std::cout << "'1' - previous fruit in the backpack" << std::endl;
//			std::cout << "'2' - next fruit in the backpack" << std::endl;
//			std::cout << "'3' - take fruit" << std::endl;
//			std::cout << "'4' - exit" << std::endl;
//
//			action = _getch(); // _getch() - Ждет ввода от пользователя и кладет его в action если получила ввод
//
//			switch (action)
//			{
//			case '1':
//				if (fruit != _backpack.begin())// Проверка выхода итератора за пределы вектора
//				{// если итератор не равен _backpack.begin() Началу то значит слева есть объекты которые можем показать
//					--fruit;// Здесь двигаемся по вектору влево относительно нашего итератра
//					count--; // Счетчик индекса идет в минус
//				}
//				break;
//			case '2':
//				if (fruit != _backpack.end() - 1)// Если итерватор не  дошел до конца Значит справа есть элементы которые можем показать 
//				{
//					++fruit;// Показывает с права элементы от итератора
//					count++;// Счетчик индекса идет в +
//				}
//				break;
//			case '3':
//				deleted = fruit;// Приравниваем итераторы  Чтобы в дальнейшем значение на которое указывает итератор deleted удалить из вектора
//				break;
//			default:
//				break;
//			}
//		}
//
//		if (deleted != _backpack.end()) // Если в deleted есть валидное значение то мы его удаляем
//			_backpack.erase(deleted);// тут просто удаляем
//	}
//};






int main()
{
	AppleTree tree("Apple Tree", 10,"Average", "Green", 20);
	tree.ShowPlant();
	Harvest* apple = tree.harvestFruit();
	apple->ShowHarvest();
	

	CherryTree tree1("Cherry Tree", 2, "Low", "Blake - Green", 1020);
	tree1.ShowPlant();
	Harvest* cherry = tree1.harvestFruit();
	cherry->ShowHarvest();

	PearTree tree2("Pear Tree", 8, "Average", "Green", 80);
	tree2.ShowPlant();
	Harvest* pearP = tree2.harvestFruit();
	pearP->ShowHarvest();

	/*Backpack backPack;
	std::shared_ptr<Pear> pear = std::make_shared<Pear>("Pear", 150.65, "Yellow");
	std::shared_ptr<Pear> pear1 = std::make_shared<Pear>("Pear", 100.8, "RED");
	std::shared_ptr<Pear> pear2 = std::make_shared<Pear>("Pear", 180.2, "Redand Yellow");
	backPack.PushBackpack(pear);
	backPack.PushBackpack(pear1);
	backPack.PushBackpack(pear2);
	
	backPack.Show();*/

	delete cherry;
	delete apple;
	delete pearP;
	return{};
}