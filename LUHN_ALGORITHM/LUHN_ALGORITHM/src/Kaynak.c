#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"Luhn_Algorithm.h"

#define MAX 16 // kart numaramýz maksimum 16 haneye göre ayarlandý. Odevdeki ornege gore

int card_number[MAX];

// satýrdaki bosluklari geçer ve normal karakter sayisini döndürür. 
//Bu geçerli satýr olup olmadýðýný kontrol etmek için kullanýlýyor.
int LineControl(char* line) {
	int lenght = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ')
			lenght++;
	}
	return lenght;
}
// Gelen string içindeki kart numarasýný int dizisine alýr
void CreateCardNumber(char* line) {
	int x = 0; // int dizisi sayacý
	for (int i = 0; line[i] != '\0'; i++) { // satýr sonuna kadar ilerle
		if (line[i] != ' ') { // boþluk deðilse sayýdýr.
			char c = line[i]; // karakteri al
			card_number[x++] = c-'0'; // ASCII karakter farký sayýyý veriyor. Bunu internetten aldýmm. // int dönüþümü
		}		
	}
}

// dosyadaki satýrlar alt alta yazýldýðýnda sonlarýnda '\n' enter karakteri olur.
// bu satýr parçalamada sorun yaratýr. Bu kadarkteri satýr sonu olarak iþaretliyoruz.
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
	char *buff = malloc(100); // Malloc ile oluþturulmazsa sorun çýkartýyor.

	fp = fopen("./doc/Ornek.txt", "r");

	// dosya okuma baþarýsýz ise
	if (fp == NULL) {
		printf("\nDosya acilamadi\n");
		return;
	}
	// dosya sonuna kadar ilerler. satýr satýr okur.
	while (!feof(fp))
	{		
		fgets(buff, 255, fp); // sýradaki satýrý alýr
		buff = DeleteEnter(buff); // sonda enter varsa siler
		printf("%s - ", buff); // ilgili satýrý ekrana yazar
		if (LineControl(buff) > MAX || LineControl(buff) < MAX)
			printf("Hatali satir (Satirdaki fazladan veya yanlis karakterleri cikarin)\n");
		else {
			CreateCardNumber(buff); // satýrdan kart numarasý elde edilir.
			int solution = Luhn(card_number); // kart numarasý luhn algoritmasýna sokulur ve sonuç verilir.

			// sonucun mod10 u 0 ise baþarýlý deðil ise baþarýsýzdýr.
			if (solution % 10 > 0)
				printf("gecersiz\n");
			else
				printf("gecerli\n");
		}
		
	}
	free(buff); // malloc ile oluþturduðumuz için iþimiz bittiðinde silmemiz gerekir.
	fclose(fp); // dosya okuyucusunu kapat.
}

int main() {

	ReadFile();
	
	return 0;
}