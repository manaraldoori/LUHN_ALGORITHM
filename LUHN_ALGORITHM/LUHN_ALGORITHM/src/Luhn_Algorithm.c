#include "Luhn_Algorithm.h"


// kart numaras�n�n sonundan ba�layarak iki�er ilerler ve numaral� 2 ye katlar.
int* DoubleUpCardNumber(int card_number[]) {
	for (int i = MAX-1; i >=  0; i--) {
		if (i % 2 == 0) // iki�er ilerlenir.
			card_number[i] *= 2;
	}
	return card_number; // son halini d�nd�r.
}

// �kiye katlanan numaralardan 9 dan b�y�k olan�n rakamlar�n� toplar.
int* PlusDoubled(int card_number[]) {
	for (int i = 0; i <MAX; i++) {
		if (card_number[i] > 9) {
			char num[5];
			sprintf(num, "%d", card_number[i]); // int veri stringe d�n��t�r�l�r.

			int c_1 = num[0]-'0'; // stringin her karakteri al�n�r ve inte d�n��t�r�l�r.
			int c_2 = num[1] - '0';

			int total = c_1 + c_2;// topla ve �nceki yerini ata.
			card_number[i] = total;
		}
	}
	return card_number;//son halini d�nd�r.
}

// Kart numaras�ndaki b�t�n say�lar�n toplam�n� d�nd�r.
int PlusAllNumbers(int card_number[]) {
	int total = 0;
	for (int i = 0; i < MAX; i++)
		total += card_number[i];
	return total;
}

// Luhn algoritmas�n� ba�lat�r ve gerekli olan toplam� d�nd�r�r.
int Luhn(int card_number[]) {

	card_number == DoubleUpCardNumber(card_number);
	card_number == PlusDoubled(card_number);

	return PlusAllNumbers(card_number);
}