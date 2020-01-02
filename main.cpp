#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// проверка на разделитель
bool isDelimeter(char c) {
	return c == ' ' || c == '.' || c == ';' || c == '\n' || c == ':';
}

// получение строки
string getChangeString(ifstream& in) {
	string res = "";

	char c; // символ для считывания

	if (!in.eof())
		in.get(c); // считываем 1-ый символ

	// пока не конец файла
	while (!in.eof()) {
		string word1 = "", word2 = "", delimeters = "";

		// считываем разделители до 1 слова
		while (!in.eof() && isDelimeter(c)) {
			res += c;
			c = in.get();
		}

		// считывание 1-ого слова
		while (!in.eof() && !isDelimeter(c)) {
			word1 += c;
			c = in.get();
		}

		// считывание разделителей между 1 и 2 словом
		while (!in.eof() && isDelimeter(c)) {
			delimeters += c;
			c = in.get();
		}

		// считывание 2 слова
		while (!in.eof() && !isDelimeter(c)) {
			word2 += c;
			c = in.get();
		}

		res += word2 + delimeters + word1; // добавляем в строку
	}

	return res; // возвращаем строку
}

int main() {
	try {
		string name; // имя файла

		cout << "Enter file name: ";
		getline(cin, name); // получаем имя файла

		ifstream in(name); // открываем файл

		if (!in) {
			throw "Incorrest file.";
		}

		string res = getChangeString(in); // получаем итоговую строку
		cout << "Result: " << res << endl; // выводим строку
		in.close();

	}
	// ловим исключения
	catch (const char* s) {
		cout << s << endl; // выводим сообщения об ошибке
	}
}
