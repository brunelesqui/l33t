#ifndef l33t_H
#define l33t_H

typedef struct {
	char * character;
	char * digit;
} rule_l33t;


char * parse_l33t (
	char * );

char * get_number_string (
	char * );

rule_l33t * new_rule ();

void free_rule (rule_l33t * );

char * convert_l33t (
	char * , 
	rule_l33t * ); 

char * redim (
	char * );

#endif
