#pragma once
class Budzet
{
	double finanse;//Suma pieni�edzy w bud�ecie, podawana w tysiacach
	int stala;//Sta�e wydatki
public:
	//Zwracanie wartosci bud�etu
	double get_finanse()const;
	// Bud�et dla potentata
	void set_finanse();
	// Bud�et dla ma�ej wytw�rni
	void set_finanse2();
	//Poddawanie nowej wartosci bud�etu
	void nowy_finanse(int i);
};

