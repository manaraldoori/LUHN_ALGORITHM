#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"Luhn_Algorithm.h"

#define MAX 16 // kart numaram�z maksimum 16 haneye g�re ayarland�. Odevdeki ornege gore

int card_number[MAX];

// sat�rdaki bosluklari ge�er ve normal karakter sayisini d�nd�r�r. 
//Bu ge�erli sat�r olup olmad���n� kontrol etmek i�in kullan�l�yor.
int LineControl(char* line) {
	int lenght = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ')
			lenght++;
	}
	return lenght;
}
// Gelen string i�indeki kart numaras�n� int dizisine al�r
void CreateCardNumber(char* line) {
	int x = 0; // int dizisi sayac�
	for (int i = 0; line[i] != '\0'; i++) { // sat�r sonuna kadar ilerle
		if (line[i] != ' ') { // bo�luk de�ilse say�d�r.
			char c = line[i]; // karakteri al
			card_number[x++] = c-'0'; // ASCII karakter fark� say�y� veriyor. Bunu internetten ald�mm. // int d�n���m�
		}		
	}
}

// dosyadaki sat�rlar alt alta yaz�ld���nda sonlar�nda '\n' enter karakteri olur.
// bu sat�r par�alamada sorun yarat�r. Bu kadarkteri sat�r sonu olarak i�aretliyoruz.
char* DeleteEnter(char *line) {
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == '\n')
			line[i] = '\0';
	}	
	return line;
}

// Dosya oku
void ReadFile() {
	FILE *fp;
	char *buff = malloc(100); // Malloc ile olu�turulmazsa sorun ��kart�yor.

	fp = fopen("./doc/Ornek.txt", "r");

	// dosya okuma ba�ar�s�z ise
	if (fp == NULL) {
		printf("\nDosya acilamadi\n");
		return;
	}
	// dosya sonuna kadar ilerler. sat�r sat�r okur.
	while (!feof(fp))
	{		
		fgets(buff, 255, fp); // s�radaki sat�r� al�r
		buff = DeleteEnter(buff); // sonda enter varsa siler
		printf("%s - ", buff); // ilgili sat�r� ekrana yazar
		if (LineControl(buff) > MAX || LineControl(buff) < MAX)
			printf("Hatali satir (Satirdaki fazladan veya yanlis karakterleri cikarin)\n");
		else {
			CreateCardNumber(buff); // sat�rdan kart numaras� elde edilir.
			int solution = Luhn(card_number); // kart numaras� luhn algoritmas�na sokulur ve sonu� verilir.

			// sonucun mod10 u 0 ise ba�ar�l� de�il ise ba�ar�s�zd�r.
			if (solution % 10 > 0)
				printf("gecersiz\n");
			else
				printf("gecerli\n");
		}
		
	}
	free(buff); // malloc ile olu�turdu�umuz i�in i�imiz bitti�inde silmemiz gerekir.
	fclose(fp); // dosya okuyucusunu kapat.
}

int main() {

	ReadFile();
	
	return 0;
}