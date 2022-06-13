#include "Luhn_Algorithm.h"


// kart numarasýnýn sonundan baþlayarak ikiþer ilerler ve numaralý 2 ye katlar.
int* DoubleUpCardNumber(int card_number[]) {
	for (int i = MAX-1; i >=  0; i--) {
		if (i % 2 == 0) // ikiþer ilerlenir.
			card_number[i] *= 2;
	}
	return card_number; // son halini döndür.
}

// Ýkiye katlanan numaralardan 9 dan büyük olanýn rakamlarýný toplar.
int* PlusDoubled(int card_number[]) {
	for (int i = 0; i <MAX; i++) {
		if (card_number[i] > 9) {
			char num[5];
			sprintf(num, "%d", card_number[i]); // int veri stringe dönüþtürülür.

			int c_1 = num[0]-'0'; // stringin her karakteri alýnýr ve inte dönüþtürülür.
			int c_2 = num[1] - '0';

			int total = c_1 + c_2;// topla ve önceki yerini ata.
			card_number[i] = total;
		}
	}
	return card_number;//son halini döndür.
}

// Kart numarasýndaki bütün sayýlarýn toplamýný döndür.
int PlusAllNumbers(int card_number[]) {
	int total = 0;
	for (int i = 0; i < MAX; i++)
		total += card_number[i];
	return total;
}

// Luhn algoritmasýný baþlatýr ve gerekli olan toplamý döndürür.
int Luhn(int card_number[]) {

	card_number == DoubleUpCardNumber(card_number);
	card_number == PlusDoubled(card_number);

	return PlusAllNumbers(card_number);
}