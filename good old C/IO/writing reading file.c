#include <stdlib.h>
#include <stdio.h>



void print_one()
{
	FILE* f_ptr; // this is pointer to a place in a file

	f_ptr = fopen(u8"my_file.txt", "w"); // returns a file pointer, or NULL. if NULL is returned, global variable errno is set to indicate error

	fprintf(f_ptr, u8"hello world,\nhello tralala,\nhelloooooooo\n"); //write to the file from the beginning

	fclose(f_ptr); // close, release the memory
}

void print_two()
{
	FILE* f_ptr = fopen(u8"lalala.txt", "w"); // i can put them all in one line
	fprintf(f_ptr, u8"lalalalala\n");
	fclose(f_ptr);
}



//precte linku po lince, ale pri kazdy lince prida newlinu... to je blby
void read_line_by_line()
{
	FILE* f_ptr;

	f_ptr = fopen(u8"my_file.txt", "r");

	char one_line[20]; //promenna ktera bude drzet radek.. jak velka?? to je otazka..
	

	// f_ptr je pointer na file, resp. na misto ve filu a posouva se s tim jak file ctu, kdyz dojde nakonec, je NULL a to je false a to skonci ten loop. 
	// feof je file-end-of-file
	while (!feof(f_ptr)) 
	{
		//tohle precte radek z konkretniho streamu, stream je treti parametr, a ulozi to do prvniho parametru. druhej parametr je maximalni delka charu, vcetne posledniho null-charu
		//navratova hodnota je char* a kdyz je NULL tak nic neprectl..
		char* ret = fgets(one_line, 20, f_ptr); 
		if (ret)
		{
			puts(one_line); //automatically add contects to new line, takze VZDY pridava \n na zacatek takze je potreba se toho nejak zbavit..
		}
	}
	fclose(f_ptr);
}



//precte neformatovany znak po znaku
void read_char_by_char()
{
	FILE* f_ptr = fopen(u8"my_file.txt", "r");

	char c;
	while (!feof(f_ptr))
	{
		c = fgetc(f_ptr);
		printf("%c", c);
	}

	fclose(f_ptr);
}


//analogie jako nahore
void read_chars()
{
	FILE* f_ptr = fopen(u8"my_file.txt", "r"); //otevri file
	char c = fgetc(f_ptr); //ziskej prvni pismeno
	while (1)
	{
		if (feof(f_ptr))
			break;
		printf("%c", c);
		c = fgetc(f_ptr);
	}
	fclose(f_ptr);
}


int main()
{
	print_one();
	print_two();
	read_line_by_line();
	read_char_by_char();
	read_chars();
	return 0;
}

