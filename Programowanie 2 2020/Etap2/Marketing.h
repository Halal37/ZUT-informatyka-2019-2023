#pragma once
class Marketing
{
public:
	int kupno;//Kupienie pozytywnych recenzji
	const int sniad;//Reklamy na œniadaniówkach
	/*const size_t plakaty;//Reklamy plakaty
	const size_t trailer;//Reklamy trailery
	const size_t bilb;//Reklamy bilbordy
	const size_t internet;//Kampania internetowa
	*/
	Marketing(int Kupno, int Sniad);
	//Wypisanie informacji marketingowych
	void informacje_marketingowe() const;
};

