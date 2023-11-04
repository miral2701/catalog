#include<iostream>
#include <fstream>
#include<string>
#pragma warning (disable:4244)
using namespace std;

class Catalog {
	string firm_name;
	string owner;
	long long phone_number;
	string adress;
	string nishe;
public:
	Catalog() {
		firm_name = "";
		owner = "";
		phone_number = 0;
		adress = "";
		nishe = "";
	}
	Catalog(string firm, string ow, long long num, string ad, string n) {
		firm_name = firm;
		owner = ow;
		phone_number = num;
		adress = ad;
		nishe = n;
	}
	void SetFirmName(string a) {
		firm_name = a;
	}
	void SetOwner(string a) {
		owner = a;
	}
	void SetAdress(string a) {
		adress = a;
	}
	void SetNishe(string a) {
		nishe = a;
	}
	void SetNumber(int a) {
		phone_number = a;
	}

	string GetFirmName() {
		return firm_name;
	}
	string GetOwner() {
		return owner;
	}
	string GetAdress() {
		return adress;
	}
	string GetNishe() {
		return nishe;
	}
	int GetNumber() {
		return phone_number;
	}
	 
};




void SearchByOwner(fstream& out) {
	string a;
	string b;

	cout << "Enter owner:";
	cin >> a;
	out.seekg(0, ios::beg);

	while (!out.eof()) {
		getline(out, b);

		if (b.find(a) != 4294967295) {
			cout << b << endl;
		}
	}
}
void SearchByNumber(fstream& out) {
	string a;
	string b;

	cout << "Enter phone number:";
	cin >> a;
	out.seekg(0, ios::beg);

	while (!out.eof()) {
		getline(out, b);

		if (b.find(a) != 4294967295) {
			cout << b << endl;
		}
	}
}
void SearchByNishe(fstream& out) {
	string a;
	string b;

	cout << "Enter nishe:";
	cin >> a;
	out.seekg(0, ios::beg);

	while (!out.eof()) {
		getline(out, b);

		if (b.find(a) != 4294967295) {
			cout << b << endl;
		}
	}

}
void Add(fstream& out) {
	string a;
	cout << "Enter string:";
	getline(cin, a);
	out.seekg(0, ios::beg);

	out << a << endl;

}
void Show(fstream& out) {
	string b;
	out.seekg(0, ios::beg);
	while (!out.eof()) {
		getline(out, b);
		cout << b << endl;

	}
}

void SearchByFirm(fstream& out) {
	string a;
	string b;

	cout << "Enter firm:";
	cin >> a;
	out.seekg(0, ios::beg);
	while (!out.eof()) {
		getline(out, b);
		if (b.find(a) != 4294967295) {
			cout << b << endl;
		}
	}
}

int main()
{
	Catalog catalog1("Apple", "Steve Jobs ", 1234567, "USA state Washington Seatle 43", "It");
	Catalog catalog2("ItStep", "Mira Madani ", 3453217, "Ukrain< Odesa", "Education");
	Catalog catalog3("Eva", "Ruslan", 38093291, "Ukrain,Kyiv", "Buety & Selfcare");


	fstream out("Text.txt");

	if (out.is_open())
	{
		out << "Firm name:" << catalog1.GetFirmName() << " Owner:" << catalog1.GetOwner() << "Phone number:" << catalog1.GetNumber() << "Adress:" << catalog1.GetAdress() << "Nishe:" << catalog1.GetNishe() << "\n";
		out << "Firm name:" << catalog2.GetFirmName() << " Owner:" << catalog2.GetOwner() << "Phone number:" << catalog2.GetNumber() << "Adress:" << catalog2.GetAdress() << "Nishe:" << catalog2.GetNishe() << "\n";
		out << "Firm name:" << catalog3.GetFirmName() << " Owner:" << catalog3.GetOwner() << "Phone number:" << catalog3.GetNumber() << "Adress:" << catalog3.GetAdress() << "Nishe:" << catalog3.GetNishe() << "\n";

	}
	SearchByFirm(out);
	out.close();
	out.open("Text.txt");
	SearchByNumber(out);
	out.close();
	out.open("Text.txt");
	Show(out);
	out.close();
	out.open("Text.txt");
	cin.ignore();
	Add(out);
	out.close();
	out.open("Text.txt");
	Show(out);
	out.close();
	out.open("Text.txt");

	Add(out);
	out.close();
	out.open("Text.txt");
	Show(out);

	out.close();
	return 0;
}