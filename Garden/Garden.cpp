// Garden.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

class Plant
{
public: 
	enum Colors{WHITE, PINK, YELLOW, GREEN, BLACK};
	enum Types{FLOWER, BUSH,TREE};
	enum Fruits{NO, YES};

	Plant(Colors _color, Types _type, Fruits _fruit, const char* _name)
	{
		color = _color;
		type = _type;
		fruit = _fruit;
		strcpy(name, _name);
	}

	Colors getColor() 
	{
		return color;
	}

	Types getType()
	{
		return type;
	}

	Fruits getFruit()
	{
		return fruit;
	}

	char* getName()
	{
		return name;
	}

private:
	Colors color;
	Types type;
	Fruits fruit;
	char name[10];
};

void sortByName(Plant** plants, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j > i; --j) 
		{ 
			if (strcmp(plants[i]->getName(), plants[j]->getName()) > 0)
			{
				Plant *temp = plants[i];
				plants[i] = plants[j];
				plants[j] = temp;		
			}
		}
	}
}

Plant* findByType(Plant** plants, int size, Plant::Types type) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (plants[i]->getType() == type) 
		{
			return plants[i];
		}
	}
	return nullptr;
}

Plant* findByColor(Plant** plants, int size, Plant::Colors color)
{
	for (int i = 0; i < size; ++i)
	{
		if (plants[i]->getColor() == color)
		{
			return plants[i];
		}
	}
	return nullptr;
}

Plant* findByFruit(Plant** plants, int size, Plant::Fruits fruit)
{
	for (int i = 0; i < size; ++i)
	{
		if (plants[i]->getFruit() == fruit)
		{
			return plants[i];
		}
	}
	return nullptr;
}

Plant** init() 
{
	Plant** plants = new Plant*[6];
	plants[0] = new Plant(Plant::Colors::WHITE, Plant::Types::FLOWER, Plant::Fruits::NO, "dandelion");
	plants[1] = new Plant(Plant::Colors::YELLOW, Plant::Types::FLOWER, Plant::Fruits::NO, "orchid");
	plants[2] = new Plant(Plant::Colors::PINK, Plant::Types::BUSH, Plant::Fruits::NO, "lilac");
	plants[3] = new Plant(Plant::Colors::PINK, Plant::Types::BUSH, Plant::Fruits::YES, "almond");
	plants[4] = new Plant(Plant::Colors::PINK, Plant::Types::TREE, Plant::Fruits::YES, "sakura");
	plants[5] = new Plant(Plant::Colors::GREEN, Plant::Types::TREE, Plant::Fruits::NO, "maple");

	return plants;
}

void printPlants(Plant** plants, int size) 
{
	for (int i = 0; i < size; i++)
	{
		cout << plants[i]->getName() << endl;
	}
}

void printSearchResult(Plant* result) 
{
	if (result) 
	{
		cout << "Plant has been found: " << result->getName() << endl;
	}
	else 
	{
		cout << "Plant hasn't been found" << endl;
	}
	_getch();
}

void searchByColorMenu(Plant** plants, int size) 
{
	while (true) 
	{
		system("CLS");
		cout << "1. White" << endl;
		cout << "2. Pink" << endl;
		cout << "3. Yellow" << endl;
		cout << "4. Green" << endl;
		cout << "5. Black" << endl;
		cout << "0. Back to the previous menu" << endl;
		cout << "Your choice: ";

		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			Plant* result = findByColor(plants, size, Plant::Colors::WHITE);
			printSearchResult(result);
		}
		else if (choice == 2) 
		{
			Plant* result = findByColor(plants, size, Plant::Colors::PINK);
			printSearchResult(result);
		}
		else if (choice == 3) 
		{
			Plant* result = findByColor(plants, size, Plant::Colors::YELLOW);
			printSearchResult(result);
		}
		else if (choice == 4) 
		{
			Plant* result = findByColor(plants, size, Plant::Colors::GREEN);
			printSearchResult(result);
		}
		else if (choice == 5) 
		{
			Plant* result = findByColor(plants, size, Plant::Colors::BLACK);
			printSearchResult(result);
		}
		else if (choice == 0) 
		{
			break;
		}
		else 
		{
			cout << "Your number is wrong! Try again";
			_getch();
		}
	}
}

void searchByTypeMenu(Plant** plants, int size) 
{
	while (true) 
	{
		system("CLS");
		cout << "1. Flower" << endl;
		cout << "2. Bush" << endl;
		cout << "3. Tree" << endl;
		cout << "0. Back to the previous menu" << endl;
		cout << "Your choice: ";

		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			Plant* result = findByType(plants, size, Plant::Types::FLOWER);
			printSearchResult(result);
		}
		else if (choice == 2) 
		{
			Plant* result = findByType(plants, size, Plant::Types::BUSH);
			printSearchResult(result);
		}
		else if (choice == 3) 
		{
			Plant* result = findByType(plants, size, Plant::Types::TREE);
			printSearchResult(result);
		}
		else if (choice == 0) 
		{
			break;
		}
		else 
		{
			cout << "Your number is wrong! Try again";
			_getch();
		}
	}
}

void searchByFruitMenu(Plant** plants, int size) 
{
	while (true) 
	{
		system("CLS");
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "0. Back to the previous menu" << endl;
		cout << "Your choice: ";

		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			Plant* result = findByFruit(plants, size, Plant::Fruits::YES);
			printSearchResult(result);
		}
		else if (choice == 2) 
		{
			Plant* result = findByFruit(plants, size, Plant::Fruits::NO);
			printSearchResult(result);
		}
		else if (choice == 0) 
		{
			break;
		}
		else 
		{
			cout << "Your number is wrong! Try again";
			_getch();
		}
	}
}

void searchMenu(Plant** plants, int size) 
{
	while (true) 
	{
		system("CLS");
		cout << "1. By color" << endl;
		cout << "2. By type" << endl;
		cout << "3. By fruit" << endl;
		cout << "0. Back to the previous menu" << endl;
		cout << "Your choice: ";

		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			searchByColorMenu(plants, size);
		}
		else if (choice == 2) 
		{
			searchByTypeMenu(plants, size);
		}
		else if (choice == 3) 
		{
			searchByFruitMenu(plants, size);
		}
		else if (choice == 0) 
		{
			break;
		}
		else 
		{
			cout << "Your number is wrong! Try again";
			_getch();
		}
	}
}

void mainMenu(Plant** plants, int size) 
{
	while (true) 
	{
		system("CLS");
		cout << "1. Search" << endl;
		cout << "2. Sort by name" << endl;
		cout << "0. Exit" << endl;
		cout << "Your choice: ";

		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			searchMenu(plants, size);
		}else if (choice == 2) 
		{
			sortByName(plants, size);
			cout << endl << "Sorted list: " << endl;
			printPlants(plants, size);
			_getch();
		}
		else if (choice == 0) 
		{
			break;
		}
		else 
		{
			cout << "Your number is wrong! Try again";
			_getch();
		}
	}
}

int main()
{
	int const size = 6;
	Plant** plants = init();

	mainMenu(plants, size);

	delete[] plants;
	return 0;
}


