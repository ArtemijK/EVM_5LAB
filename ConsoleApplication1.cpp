#include "pch.h"
#include <iostream>
int i;
short int m;
int main()
{
	using namespace std;
	cout << "Enter any number from 0 to 15" << endl;
	cin >> m;
	_asm { // Наша ассемблерная вставка
		mov EAX, 0; // помещаем значение 0 в EAX
		INC EAX; // увеличиваем значение EAX на один, тем самым он становится равным 1
		SHL EAX, 16; // сдвигаем побитово значение EAX 16 раз влево, тем самым EAX становится равным 65536
		mov CX, m; // запись m в CX
	start: // функция start
		SHL EAX, 1; // смещение побитово EAX влево на 1
		dec CX // уменьшение числа CX на 1
		cmp CX, 0 // сравниваем CX и 0
		jne start // если CX не равно 0, то вызываем start

		mov i, EAX; // запись EAX в i
		
	};
	cout <<"The resulting number is = " << i << endl; // вывод полученного числа
}