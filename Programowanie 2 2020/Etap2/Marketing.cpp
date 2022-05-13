#include "Marketing.h"
#include <iostream>
using namespace std;
Marketing::Marketing(int Kupno, int Sniad) :
	kupno(Kupno),
	sniad(Sniad) {
}

void Marketing::informacje_marketingowe() const
{
	cout << "Kupno recenzji: "<<kupno<<endl;
	cout << "Sniadaniowki: "<<sniad<<endl;
}

