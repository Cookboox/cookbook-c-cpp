#include <stdio.h>
#include <stdlib.h>


void char_name()
{
	char name[14] = "lukas kotatko";
	printf("my name is %s\n", name);

	printf("first letter is %c\n", name[0]);

	//iterate char by char
	for (int i = 0; i < sizeof(name) / sizeof(name[0]); i++)
		printf("%c", name[i]);
}

void doesnt_work()
{
	//POZOR  tohle nejde
	char surname[6];
	surname[6] = "kocka"; //tady to hodi exceptinu, proc? protoze prirazuju pole na char pointer
	printf("%s", surname);
}



void this_works()
{
	char name[10]; //tady mam deset bytu
	strcpy(name, "pepa"); //pepa ma pet bytu, takze ok
	printf("%s", name);

	//strcpy(name, "pepapepapep"); //tohle uz fungovat nebude
}


int main()
{
	//char_name();
	doesnt_work();
	//this_works();

	//char x[] = "lukas"; //pole o velikosti 6
	//size_t xx = sizeof(x);
	//strcpy(x, "lukasss"); //nejde priradit pole o velikosti 8


	return 0;
}
