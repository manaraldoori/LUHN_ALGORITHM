#ifndef LUHN_ALGORITHM
#define LUHN_ALGORITHM

#define _CRT_SECURE_NO_WARNINGS

#include<stdlib.h>
#include<stdio.h>

#define MAX 16

int* DoubleUpCardNumber(int card_number[]);
int* PlusDoubled(int card_number[]);
int PlusAllNumbers(int card_number[]);
int Luhn(int card_number[]);

#endif