#include <ctype.h> // isalpha, isdigit
#include <string.h> // strlen, tolower
#include <stdlib.h> // malloc, realloc, atoi
#include "l33t.h"


/* Retorna la regla correspondiente o el caracter mismo. */
char * convert_l33t (
	char * character, 
	rule_l33t * rule) {

	unsigned int i = 0;

	while (*(rule->character + i) != '\0') {
		if (tolower (*character) == *(rule->character + i)) 
			return (rule->digit + i);
		
		i++;
	}
	
	return character;

}


/* Analiza la cadena en busca de reglas del l33t */
char * parse_l33t (char *plane_text) {

	char * l33t_text = redim (plane_text);
	unsigned int i = 0;
	unsigned int j = 0;

	rule_l33t * rule = new_rule ();
	
	while (*(plane_text + i) != '\0') {

		if (isalpha (*(plane_text + i))) {
			*(l33t_text + j) = *(convert_l33t (plane_text + i, rule));	
			j++;	
		}
		else {
			 if (isdigit (*(plane_text + i))) { 				
				char * number_string = get_number_string ((plane_text + i));

				while (*number_string != '\0') {
					*(l33t_text + j) = *(convert_l33t (number_string, rule));
					
					number_string++;
					j++;
				} 
			}
			else {
				*(l33t_text + j) = *(plane_text + i);
				j++;
			}
		}

		i++;

	}

	*(l33t_text + j) = '\0';	
	
	free_rule (rule);

	return l33t_text;

}


char * redim (char * plane_text) {

	unsigned int final_size = 1;
	unsigned int i = 0;
	char * l33t_text = NULL;

	while (*(plane_text + i) != '\0') {
		if (isdigit (*(plane_text +i))) 
			final_size += strlen (get_number_string ((plane_text + i)));

		i++;
	}

	l33t_text = malloc (strlen (plane_text) + final_size);
	if (l33t_text == NULL) 
		exit (1);

	return l33t_text;
}


/* Liberamos la memoria */
void free_rule (rule_l33t * rule) {

	free (rule->character);
	free (rule->digit);
	free (rule);

}


/* Crea una regla para el l33t */
rule_l33t * new_rule () {
	
	rule_l33t * rule = malloc (sizeof (rule_l33t));

	char * CHARACTERS = { "aeiots" };
	char * DIGITS = { "431075" };

	rule->character = malloc (strlen (CHARACTERS) + 1);
	rule->digit = malloc (strlen (DIGITS) + 1);

	strcpy (rule->character, CHARACTERS);
	strcpy (rule->digit, DIGITS);

	return rule;

}


char * get_number_string (
	char * number) {

	char * number_string[] = { 
		"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };

	return number_string[atoi (number)];
}
