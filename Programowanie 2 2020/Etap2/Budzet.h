#pragma once
class Budzet
{
	double finanse;//Suma pieniêedzy w bud¿ecie, podawana w tysiacach
	int stala;//Sta³e wydatki
public:
	//Zwracanie wartosci bud¿etu
	double get_finanse()const;
	// Bud¿et dla potentata
	void set_finanse();
	// Bud¿et dla ma³ej wytwórni
	void set_finanse2();
	//Poddawanie nowej wartosci bud¿etu
	void nowy_finanse(int i);
};

