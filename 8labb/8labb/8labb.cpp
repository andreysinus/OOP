#include "iostream"
#include "cstdio"
#include "string"
using namespace std;

const char* con = "N/A"; //постоянная для неизвестных начальных символьных значений
class Oborudovanie //класс для объявления элементов
{
public:
	virtual char* tochar(string a) = 0;
	virtual void enter() = 0; //функция ввода значений
	virtual int get_size() = 0; //функция вывода размера
	virtual float get_price() = 0; //функция вывода цены
	virtual void print() const = 0;
protected:
	char* name; int siz; char* corp; float zena;
};

class Home : public Oborudovanie
{
public:
	Home();// конструктор по умолчанию
	~Home() { delete[] name; delete[] corp; }; //деструктор по умолчанию
	Home(const char* ent_corp, const char* ent_name, int size, float z);// конструктор с параметрами
	Home(const Home& m);// копирующий конструктор
	void destr();//деструктор
	virtual void print() const override;// селектор
	Home& copy(const Home& f);// копирующий конструктор
	Home summa(Home f);//суммирующий конструктор
	void cheap(Home a); //сравнение по цене
	virtual void enter()override; //функция ввода значений
	virtual int get_size()override; //функция вывода размера
	virtual float get_price()override; //функция вывода цены
	virtual char* tochar(string a) override; //функция конвертирования строки в массив символов
	Home incr();
	Home decr();
	Home& operator =(const Home& m);
};

Home::Home()// конструктор по умолчанию
{
	name = new char[strlen(con) + 1]; corp = new char[strlen(con) + 1];
	strcpy(name, con); siz = 0; strcpy(corp, con); zena = 0;
}

void Home::destr() {
	delete[] name; delete[] corp;
}//определение деструктора

Home::Home(const char* ent_corp, const char* ent_name, int size, float z)// конструктор с параметрами
{
	corp = new char[strlen(ent_corp) + 1]; strcpy(corp, ent_corp); name = new char[strlen(ent_name) + 1]; strcpy(name, ent_name); siz = size;
	zena = z;
}

Home::Home(const Home& m)// определение селектора
{
	if (this != &m) {
		siz = m.siz; zena = m.zena;
		name = new char[strlen(m.name) + 1]; strcpy(name, m.name);
		corp = new char[strlen(m.corp) + 1]; strcpy(corp, m.corp);
	}
}

void Home::print() const // определение функции вывода значений
{
	cout << "Corporation: " << corp << endl << "Name: " << name << endl << "Size: " << siz << " L" << endl << "Price: " << zena << "$" << endl
		<< "______________________" << endl;
}

Home& Home::copy(const Home& f) // копирующий конструктор
{
	if (this != &f) {
		siz = f.siz; zena = f.zena;
		name = new char[strlen(f.name) + 1]; strcpy(name, f.name);
		corp = new char[strlen(f.corp) + 1]; strcpy(corp, f.corp);
	}
	return(*this);
}

Home  Home::summa(Home f) // определение функции сложения
{
	Home h; h.siz = siz + f.siz; h.zena = zena + f.zena;
	h.corp = new char[strlen(corp) + strlen(f.corp)]; strcpy(h.corp, corp); strcat(h.corp, f.corp);
	h.name = new char[strlen(name) + strlen(f.name)]; strcpy(h.name, name); strcat(h.name, f.name);
	return (h);
}

char* Home::tochar(string b)// перевод string в char*
{
	char* h;
	h = new char[b.length() + 1];
	for (int i(0); i <= b.length(); i++)  h[i] = b[i];
	return(h);
}

void Home::enter() // определение функции ввода значений
{
	string co, na;
	cout << "Enter corporation: ";  cin >> co;
	corp = tochar(co);// конвертирование значений из строковых значений в массив символов
	cout << "Enter name: ";  cin >> na;
	name = tochar(na);// конвертирование значений из строковых значений в массив символов
	cout << "Enter size: ";  cin >> siz;
	cout << "Enter price: ";  cin >> zena;
	//system("cls");
}

int Home::get_size()//вывести объём
{
	return siz;
}

float Home::get_price()//вывести цену
{
	return zena;
}

void Home::cheap(Home a) // сравнение по цене
{
	if (zena > a.zena)
	{
		cout << "Holodilnik " << a.name << " deshevle." << endl;
	}
	else {
		if (a.zena == zena) { cout << "Holodilnik " << name << " odinakoviy po price." << endl; }
		else {
			cout << "Holodilnik " << name << " deshevle." << endl;
		}
	}
}

Home  Home::incr() {
	++siz; return (*this);
}

Home  Home::decr() {
	--siz; return (*this);
}
Home& Home ::operator =(const Home& f) {//перегрузка оператора =
	if (this != &f) {
		siz = f.siz; zena = f.zena;
		name = new char[strlen(f.name) + 1]; strcpy(name, f.name);
		corp = new char[strlen(f.corp) + 1]; strcpy(corp, f.corp);
	}
	return(*this);
}


class Industrial : public Oborudovanie
{
public:
	Industrial() {
		name = new char[strlen(con) + 1]; corp = new char[strlen(con) + 1];
		strcpy(name, con); siz = 0; strcpy(corp, con); zena = 0; noise = 0;
	};

	Industrial(const char* ent_corp, const char* ent_name, int size, int sp, float z)// конструктор с параметрами
	{
		corp = new char[strlen(ent_corp) + 1]; strcpy(corp, ent_corp); name = new char[strlen(ent_name) + 1]; strcpy(name, ent_name); siz = size; noise = sp; 
		zena = z;
	};
	~Industrial() {
		delete[] name; delete[] corp;
	}
	virtual void print() const override {
		cout << "Corporation: " << corp << endl << "Name: " << name << endl << "Size: " << siz << " L" << endl << "Noise:" <<noise<< " dB" << endl << "Price: " << zena << "$" << endl
			<< "______________________" << endl;

	};// селектор
	virtual void enter(); //функция ввода значений
	virtual int get_size() {
		return siz;
	}; //функция вывода размера
	virtual float get_price() {
		return zena;
	}; //функция вывода цены
	virtual char* tochar(string a); //функция конвертирования строки в массив символов
protected:
	float noise;
};
char* Industrial::tochar(string b)// перевод string в char*
{
	char* h;
	h = new char[b.length() + 1];
	for (int i(0); i <= b.length(); i++)  h[i] = b[i];
	return(h);
}
void Industrial::enter() {
	string co;
	cout << "Enter corporation: ";  cin >> co;
	corp = tochar(co);// конвертирование значений из строковых значений в массив символов
	cout << "Enter name: ";  cin >> co;
	name = tochar(co);// конвертирование значений из строковых значений в массив символов
	cout << "Enter size: ";  cin >> siz;
	cout << "Enter price: ";  cin >> zena;
	cout << "Enter noise: ";  cin >> noise;
}



int main() {
	Oborudovanie *n, *z, *j;
	Home Bir("Birusa", "B560KH", 510, 450);
	Industrial Sams("Samsung", "RB30J3200SS", 322, 39, 590);
	Industrial newHol;
	n = &Bir; z = &Sams, j = &newHol;
	n->print();
	cout << endl;
	z->print();
	cout << endl;
	j->enter();
	cout << endl;
	j->print();
	cout << endl;
	system("pause");
}
