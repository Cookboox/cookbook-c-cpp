#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

void print_weird()
{
	printf("James Bond \\  \" Agent 007 \" \\ # 150%% zaruka # /\n");
	printf("Spol. s rucenim omezenym\n");
}

void change_ascii()
{
	printf("vloz znak, a ja ho o jedna zvetsim a vypisu jeho ASCII kod\n");
	char ch;
	scanf("%c", &ch);
	printf("vlozil jsi \"%c\" coz je kod ASCII %d, ja vracim \"%c\", coz je kod ASCII %d \n", ch, ch, ch + 1, ch + 1);
}

void read_one_char()
{
	int ch; // tady to musi byt int -> proc? kvuli konci souboru. EOF se totiz definuje jako hodnota -1 coz je int, kdyz bych mel char
			//dojde k implicitni konverzi a z int -1 by vznikl char s jinou hodnotou (nejspis 255) 
	printf("napis znak\n");

	ch = getchar(); //protoze getchar i putchar pracuji s inty a ne s chary.. divny..
	putchar(ch);
	putchar('\n');
}

void print_ascii_table()
{
	for (int i = 1; i < 128; i++)
	{
		printf("%c-%d \t", i, i);
	}
}

void hex()
{
	printf("napis cislo 0-255 a ja vratim jeho hodnotu v hex dvouznakove\n");
	int number;
	scanf("%d", &number);
	printf("cislo %d, je v hexu 0x%x", number, number);
}

//jak osetrit proti neplatnemu necislenemu vstupu
void add_25pct()
{
	float cena_bez_dane;
	int uz_jednou_zadal = 0;
	
	do
	{		
		if (!uz_jednou_zadal)
		{
			printf("zadej cenu bez dane\n");
		}
		scanf("%f", &cena_bez_dane);
		int ret_val;
		if ((ret_val = isdigit(cena_bez_dane)) != 0 || cena_bez_dane <= 0)
		{
			printf("nesmysl, musi byt cislo a nemuze byt zaporne, zadej ji znovu\n");
			uz_jednou_zadal = 1;
		}
	} while (cena_bez_dane <= 0);
	
	printf("prodejni cena s dani je: %0.2f", cena_bez_dane * 1.25);
}

void obsah_obdelnika()
{
	printf("zadej strany obdelnika\n");
	float a;
	float b;

	do
	{
		printf("strana A: \n");
		scanf("%f", &a);

		if (a <= 0)
			printf("spatne zadani, znovu\n");
	} while (a <= 0);

	do
	{
		printf("strana B: \n");
		scanf("%f", &b);
		if (b <= 0)
			printf("spatne zadani, znovu\n");
	} while (b <= 0);

	printf("obsah obdelnika je: %f", a * b);
}

void obsah_obdelniha2()
{	
	printf("zadej delku a sirku a sirku\n");
	float delka, sirka;
	do
	{
		scanf("%f", &delka);
		scanf("%f", &sirka);
		if (delka <= 0 || sirka <= 0)
			printf("oba paramtery musi byt kladne, zadej je znovu\n");
		
	} while (delka <= 0 || sirka <= 0);

	printf("zadal jsi delku: %f a sirku: %f  --> celkovy obsah je tedy: %f\n", delka, sirka, delka * sirka);
}

void get_whole_part()
{
	printf("zadej desetine cislo a ja vratim jeho celou cast\n");
	float cislo;
	scanf("%f", &cislo);	
	int cele_cislo = cislo;
	printf("zadal jsi %f, ja vypisuju celou cast, ktera je %d", cislo, (int)cislo); 
}

void three_caps()
{
	printf("zadej tri velka pismena a ja je vratim jako tri mala\n");
	char a, b, c;
	// 1] tahle moznost cte dokud nezmacknu enter NESMI tam byt carky mezi %c, bere kazdy znak, takze na terminalu nesmi byt ani jedna mezera
	scanf("%c%c%c", &a, &b, &c);

	// 2] tahle moznost bere kazdy znak, takze na terminalu nesmi byt ani jedna mezera, jinak ji precte jako znak
	// a = getchar();
	// b = getchar();
	// c = getchar();
	int ascii_dif = 'a' - 'A';
	printf("zadal jsi %c, %c, %c, ja vracim, %c, %c, %c\n", a, b, c, a + ascii_dif, b + ascii_dif, c + ascii_dif);
}

void three_caps_with_check()
{
	printf("zadej tri VELKA pismena a ja je vratim jako tri male\n");
	char a, b, c;

	do
	{
		a = getchar();
		if (!isalpha(a) || islower(a))
			continue;
	} while (!isalpha(a) || islower(a));

	do
	{
		b = getchar();
		if (!isalpha(b) || islower(b))
			continue;
	} while (!isalpha(b) || islower(b));

	do
	{
		c = getchar();
		if (!isalpha(c) || islower(c))
			continue;
	} while (!isalpha(c) || islower(c));

	int ascii_dif = 'a' - 'A';
	printf("zadal jsi pismena %c, %c, %c, ja vracim, %c, %c, %c\n", a, b, c, a + ascii_dif, b + ascii_dif, c + ascii_dif);
}
	
void three_lows()
{
	printf("dej mi tri mala pismena a ja ti vratim velka v obracenem poradi\n");
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	printf("zadal jsi %c, %c, %c ja vracim %c, %c, %c", a, b, c, toupper(c), toupper(b), toupper(a));
}

void three_lows_scanf()
{
	printf("dej mi tri mala pismena a ja ti vratim VELKA v obracenem poradi\n");
	char a, b, c;
	int read;
	if ((read = scanf("%c%c%c", &a, &b, &c)) == 3)
	{
		printf("vracim %c, %c, %c", c, b, a);
	}
	else
	{
		printf("chyba pri nacitani..\n");
	}
}

void three_lows_with_check()
{
	printf("dej mi tri mala pismena a ja ti vratim VELKA v obracenem poradi\n");
	char a, b, c;
	
	while (1)
	{
		a = getchar();
		if (!isalpha(a) || isupper(a))
			continue;
		else
			break;
	}

	while (1)
	{
		b = getchar();
		if (!isalpha(b) || isupper(b))
			continue;
		else
			break;
	}

	while (1)
	{
		c = getchar();
		if (!isalpha(c) || isupper(c))
			continue;
		else
			break;
	}
	printf("zadal jsi %c, %c, %c, ja vracim %c, %c, %c", a, b, c, toupper(c), toupper(b), toupper(a));
}

//-1 je maximalni unsigned int
void max_int()
{
	printf("maximani cislo co je mozne ulozit do unsigned int je %u\n", UINT_MAX);
	printf("maximani cislo co je mozne ulozit do signed int je %d\n", INT_MAX);

	unsigned int x = -1; 
	printf("trik - maximani cislo co je mozne ulozit do unsigned int je %u\n", x);
	printf("trik - maximani cislo co je mozne ulozit do signed int je %d\n", x/2);
}

void max_long()
{
	printf("maximani cislo co je mozne ulozit do unsigned long je %lu\n", ULONG_MAX);
	printf("maximani cislo co je mozne ulozit do signed long je %ld\n", LONG_MAX);

	unsigned long x = -1;
	printf("trik - maximani cislo co je mozne ulozit do unsigned long je %lu\n", x);
	printf("trik - maximani cislo co je mozne ulozit do signed long je %ld\n", x / 2);
}

void max_short()
{
	printf("maximani cislo co je mozne ulozit do unsigned short je %u\n", USHRT_MAX);
	printf("maximani cislo co je mozne ulozit do signed short je %d\n", SHRT_MAX);

	unsigned short x = -1;
	printf("trik - maximani cislo co je mozne ulozit do unsigned short je %u\n", x);
	printf("trik - maximani cislo co je mozne ulozit do signed short je %d\n", x / 2);
}

void devide()
{
	printf("celocislene deleni musi mit ob inty\n");
	int x = 8;
	int y = 20;
	printf("vysledek celociselneho deleni je %d\n", y / x);

	printf("realne deleni musi mit aspon jeden float\n");
	float xf = 8;
	int yf = 20;
	printf("vysledek float deleni je %f\n", yf / xf);

	printf("modulo vraci zbytek celociselneho deleni\n");
	int xff = 8;
	int yff = 20;
	printf("vysledek modulo je %d\n", yff % xff);
}

//zajimavy ze tady neni potreba delat check proti vlozeni charu misto floatu apod
void avg()
{
	printf("zadej tri realna cisla\n");
	float a, b, c;
	int read;
	if ((read = scanf("%f%f%f", &a, &b, &c)) == 3)
	{
		printf("prumer je %.2f", (a + b + c) / 3.0);
	}
	else
	{
		printf("chyba pri nacitani..\n");
	}
}


void beep()
{
	char beep = '\a';
	printf("%c", beep);
}

int main()
{
	//read_one_char();
	//change_ascii();
	//hex();
	//add_25pct();
	//obsah_obdelnika();
	//obsah_obdelniha2();
	//get_whole_part();
	//three_caps_with_check();
	//three_lows();
	//three_lows_with_check();
	//max_int();
	//max_long();
	//max_short();
	//devide();
	//avg();
	//three_lows_scanf();
	//beep();

	return 0;
}