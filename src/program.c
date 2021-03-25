#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include "l33t.h"


#define READ_STRING       1
#define CONVERT_TO_L33T   2
#define PRINT_L33T_STRING 3
#define END_PROGRAM       4


void menu (void);
char * get_string (void);
void clear (char * , char * );


int main (void) {

	int opt;
	char * string = NULL;
	char * l33t_string = NULL;

	do {
		menu ();
		scanf ("%i", &opt);

		switch (opt) {
			case READ_STRING:
				clear (string, l33t_string);
				string = get_string (); 
				break;
			case CONVERT_TO_L33T:
				if (string != NULL)
					l33t_string = parse_l33t (string); 
				break;
			case PRINT_L33T_STRING: 
				printf ("\n%s\n%s", string, l33t_string);
				break;
		}

	} while (opt != END_PROGRAM);

	clear (string, l33t_string);
	
	return 0;
	
}


void clear (
	char * string, 
	char * l33t) {

	if (string != NULL)
		free (string);

	if (l33t != NULL)
		free (l33t);
}


char * get_string (void) {

	char * string = malloc (256);
	
	gets (string);

	fgets (string, 256, stdin);
	if (*(string + (strlen (string) - 1)) == '\n')
		*(string + (strlen (string) - 1)) = '\0'; 
	
	return string;

}


void menu (void) {

	printf ("\n\nConversión a L33T");
	printf ("\n\n1. Leer una cadena");
	printf ("\n2. Convertir una cadena a L33T");
	printf ("\n3. Imprimir cadena");
	printf ("\n4. Terminar programa");
	printf ("\n: ");

}
