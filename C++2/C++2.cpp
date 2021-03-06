
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;




struct DATA 
{
	unsigned short day;
	unsigned short mounth;
	unsigned short year;
};

struct ADRESS
{
	unsigned short postcode; // почтовый индекс 
	string country; // страна
	string region; // область 
	string district; // район
	string city; // город 
	string street; // улица 
	unsigned short house; // дом 
	unsigned short apartment; // квартира

};

struct Patient {
	string surname; // фамилия
	string name;  // имя
	string patronymic; // отчество
	string sex; // пол
	string nationality; // национальность
	unsigned short height; // рост
	unsigned short weight; // вес
	DATA date; // рождение
	int number_phone; // номер телефона
	ADRESS home_adress; // дом.адресс
	unsigned short hospital_number;//номер больницы
	unsigned short department; //отделение
	unsigned short number_of_medecinecard; // номер мед.карты
	string diagnosis; // диагноз
	unsigned short blood_type; // группа крови
	
};

Patient InitPatient();
Patient* InitArray(int);
void DisplayArray(Patient*, int);
void DisplayPatient(Patient);

//Метод ввода с проверкой вводимого
int readInt() {
	unsigned short N;
	while (!(cin >> N) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "" << endl;
	}
	return N;
}

// Метод ввода с проверкой, что вводимое число - позитивное
int readPositiveInt() {
	unsigned short N;
	bool check = false;
	unsigned short temp;
	while (check == false) {
		temp = readInt();
		if (temp & (1U << (sizeof(temp) * 8 - 1))) {
			cout << "Ошибка! введите положительное число - ";
		}
		else {
			N = temp;
			check = true;
		}
	}
	return N;
}

Patient InitPatient()
{
	Patient Man;
	cout << "Введите фамилию: "<<endl;
	getline(cin, Man.surname);
	cin.ignore();
	
	cout << "Введите имя: "<<endl;
	getline(cin, Man.name);
	cin.ignore();
	cout << "Введите отчество: " << endl;
	getline(cin, Man.patronymic);
	cin.ignore();
	cout << "Введите пол: " << endl;
	getline(cin, Man.sex);
	cin.ignore();
	cout << "Введите национальность: " << endl;
	getline(cin, Man.nationality);
	cin.ignore();
	cout << "Введите рост: " ;
	Man.height = readPositiveInt();
	cin.ignore();
	cout << "Введите вес: " ;
	Man.weight = readPositiveInt();
	cin.ignore();
	cout << "Введите день рождения: ";
	Man.date.day = readPositiveInt();
	cin.ignore();
	cout << "Введите месяц рождения: " ;
	Man.date.mounth = readPositiveInt();
	cin.ignore();
	cout << "Введите год рождения: ";
	Man.date.year = readPositiveInt();
	cin.ignore();
	cout << "Введите номер телефона: ";
	Man.number_phone = readPositiveInt();
	cin.ignore();
	cout << "Введите почтовый индекс: ";
	Man.home_adress.postcode = readPositiveInt();
	cin.ignore();
	cout << "Введите страну: " << endl;
	getline(cin, Man.home_adress.country);
	cin.ignore();
	cout << "Введите область: " << endl;
	getline(cin, Man.home_adress.region);
	cin.ignore();
	cout << "Введите район: " << endl;
	getline(cin, Man.home_adress.district);
	cin.ignore();
	cout << "Введите город: " << endl;
	getline(cin, Man.home_adress.city);
	cin.ignore();
	cout << "Введите улицу: " << endl;
	getline(cin, Man.home_adress.street);
	cin.ignore();
	cout << "Введите дом: " ;
	Man.home_adress.house = readPositiveInt();
	cin.ignore();
	cout << "Введите квартиру: ";
	Man.home_adress.apartment = readPositiveInt();
	cin.ignore();
	cout << "Введите номер больницы: ";
	Man.hospital_number = readPositiveInt();
	cin.ignore();
	cout << "Введите отделение больницы: ";
	Man.department = readPositiveInt();
	cin.ignore();
	cout << "Введите номер медецинской карты: " ;
	Man.number_of_medecinecard = readPositiveInt();
	cin.ignore();
	cout << "Введите диагноз пациенты: " << endl;
	getline(cin, Man.diagnosis);
	cin.ignore();
	cout << "Введите группу крови пациента: ";
	Man.blood_type = readPositiveInt();
	cin.ignore();
	if (Man.blood_type > 4)
	{
		cout << "Введите группу крови пациента заново: " << endl;
		Man.blood_type = readPositiveInt();
		cin.ignore();
	}
	
	return Man;
}




Patient* InitArray(int N)
{
	int i;
	Patient*Massive = new Patient[N];
	
	for (i = 0; i < N; i++)
	{
		cout << "Вводите информацию об пациенте по номером " + (i + 1) << ": "<<endl;
		Massive[i] = InitPatient();
	}

	return Massive;

}

void DisplayArray(Patient* Massive, int N)
{
	int i;

	for (i = 0; i < N; i++)
	{
		DisplayPatient(Massive[i]);
	}

}

void DisplayPatient(Patient Man)
{
	cout <<"Фамилия пациента: " <<Man.surname << endl;
	cout << "Имя пациента: " <<Man.name << endl;
	cout << "Отчество пациента: " << Man.patronymic << endl;
	cout << "Пол пациента: " << Man.sex << endl;
	cout << "Национальность пациента: " << Man.nationality << endl;
	cout << "Рост пациента: " << Man.height << endl;
	cout << "Вес пациента: " << Man.weight << endl;
	cout << "День рождения пациента: " << Man.date.day << endl;
	cout << "Месяц рождения пациента: " << Man.date.mounth << endl;
	cout << "Год рождения пациента: " << Man.date.year << endl;
	cout << "Номер телефона пациента: " << Man.number_phone << endl;
	cout << "Почтовый индекс пациента: " << Man.home_adress.postcode << endl;
	cout << "Страна проживания пациента: " << Man.home_adress.country << endl;
	cout << "Область проживания пациента: " << Man.home_adress.region << endl;
	cout << "Район проживания пациента: " << Man.home_adress.district << endl;
	cout << "Город проживания пациента: " << Man.home_adress.city << endl;
	cout << "Улица пациента: " << Man.home_adress.street << endl;
	cout << "Номер дома пациента: " << Man.home_adress.house << endl;
	cout << "Номер квартиры пациента: " << Man.home_adress.apartment << endl;
	cout << "Номер больницы пациента: " << Man.hospital_number << endl;
	cout << "Отделение пациента: " << Man.department << endl;
	cout << "Номер Медецинской карты пациента: " << Man.number_of_medecinecard << endl;
	cout << "Диагноз пациента: " << Man.diagnosis << endl;
	cout << "Группа крови пациента: " << Man.blood_type << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------" << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int N;
	Patient* MassiveStruct;

	cout << "Введите количество пациентов: " << endl;
	cin >> N;

	MassiveStruct = InitArray(N);
	if (MassiveStruct == NULL)
	{
		cout << "Динамический массив не существует" << endl<<"Нажмителюбую клавишу что-бы выйти";
		
	}
	cin.clear();
	cout << "Лист Пациентов : " << endl;
	DisplayArray(MassiveStruct, N);
}
