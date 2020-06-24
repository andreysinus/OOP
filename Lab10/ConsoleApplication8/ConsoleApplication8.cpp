#include <iostream>
#include "time.h"
#include <string>
#include "windows.h"
using namespace std;

class Holod {
protected:
	int price, volume;
	string name;
public:
	Holod()
	{
		volume = 0;
		price = 0;
		name = "";
	}
	Holod(int volume, int price, string name)
	{
		this->price = price;
		this->volume = volume;
		this->name = name;
	}
	virtual void read()
	{

		cout << "Название:";
		cin >> name;
		cout << "Цена:";
		cin >> price;
		cout << "Объем:";
		cin >> volume;
	}
	virtual void print()
	{

		if (name == "") { throw 1; }
		else cout << "Название:" << name << endl;
		if (price == 0) { throw 2; }
		else cout << "Цена:" << price << endl;
		if (volume == 0) { throw 3; }
		else cout << "Объем:" << volume << endl;
	}
	string getName() { return name; }
	int getVolume() { return volume; }
	int getPrice() { return price; }
};


class Commercial : public Holod {
protected:
	int noise;
	int v, p;
	string n;
public:
	Commercial(): Holod() {
		noise = 0;
		v = 0;
		p = 0;
		n = "";
	}
	Commercial(int volume, int price, string name, int noise) :Holod(volume, price, name)
	{
		this->noise = noise;
		this->v = volume;
		this->p = price;
		this->n = name;
	}
	int getNoise() { return noise; }
	virtual void read()
	{
		cout << "Уровень шума:";
		cin >> volume;
	}
	virtual void print()
	{
		if (n == "") { throw 1; }
		else cout << "Название:" << n << endl;
		if (p == 0) { throw 2; }
		else cout << "Цена:" << p << endl;
		if (v == 0) { throw 3; }
		else cout << "Объем:" << v << endl;
		if (noise == 0) { throw 4; }
		else cout << "Уровень шума:" << noise << endl;

	}
};

class Industrial : public Holod {
protected:
	string enEfClass;
	int v, p;
	string n;
public:
	Industrial() : Holod() {
		enEfClass = "";
		v = 0;
		p = 0;
		n = "";
	}
	Industrial(int volume, int price, string name, string enEfClass) :Holod(volume, price, name)
	{
		this->enEfClass = enEfClass;
		this->v = volume;
		this->p = price;
		this->n = name;
	}
	string getClass() { return enEfClass; }
	virtual void read()
	{
		cout << "Класс энергоэффективности:";
		cin >> enEfClass;
	}
	virtual void print()
	{
		if (n == "") { throw 1; }
		else cout << "Название:" << n << endl;
		if (p == 0) { throw 2; }
		else cout << "Цена:" << p << endl;
		if (v == 0) { throw 3; }
		else cout << "Объем:" << v << endl;
		if (enEfClass == "") { throw 5; }
		else cout << "Класс энергоэффективности:" << enEfClass << endl;
	}
};

class FrostCam : public Industrial, public Commercial {
protected:
	string type;
	int numOfCam;
	int v, p;
	string n;
public:
	FrostCam() : Commercial() {
		type = "";
		numOfCam = 0;
		v = 0;
		p = 0;
		n = "";
	}
	FrostCam(int volume, int price, string name, int noise, string type, int numOfCam) : Commercial(volume, price, name, noise) {
		this->type = type;
		this->numOfCam = numOfCam;
		this->v = volume;
		this->p = price;
		this->n = name;
	}
	string gettype() { return type; }
	int getNumOfCam() { return numOfCam; }
	virtual void read()
	{
		cout << "Тип морозилки:";
		cin >> type;
		cout << "Количество камер:";
		cin >> numOfCam;
	}
	virtual void print()
	{
		if (n == "") { throw 1; }
		else cout << "Название:" << n << endl;
		if (p == 0) { throw 2; }
		else cout << "Цена:" << p << endl;
		if (v == 0) { throw 3; }
		else cout << "Объем:" << v << endl;
		if (noise == 0) { throw 4; }
		else cout << "Уровень шума:" << noise << endl;
		if (type == "") { throw 6; }
		else cout << "Тип морозилки:" << type << endl;
		if (numOfCam == 0) { throw 7; }
		else cout << "Количество камер:" << numOfCam << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	int o = 0;
	Holod one(420, 15900, "Lg gk-13229");
	one.print();
	cout << endl;
	
	Commercial two(480,17900,"Samsung sk-98209",78);
	two.print();
	cout << endl;
	Industrial three(590, 29100, "Samsung sgc-8721", "A++");
	three.print();
	cout << three.getName() << endl;
	cout << endl;
	FrostCam four(750, 0, "Hotpoint-Ariston YGL-87u1", 55, "Шкаф", 2);
	try {
		four.print();
		cout << endl;
	}
	catch (int o) {
		switch (o) {
		case 1: {
			cout << "Не введено название" << endl;
			break;
		}
		case 2: {
			cout << "Не введена цена оборудования" << endl;
			break;
		}
		case 3: {
			cout << "Не введен объем камеры" << endl;
			break;
		}
		case 4: {
			cout << "Не введен уровень шума" << endl;
			break;
		}
		case 5: {
			cout << "Не введен класс энергоэффективности" << endl;
			break;
		}
		case 6: {
			cout << "Не введен тип морозильной камеры" << endl;
			break;
		}
		case 7: {
			cout << "Не введено количество камер" << endl;
			break;
		}
		}
	}
	cout << endl;

	system("pause");
	return 0;
}