
/* advcom.h - adventure compiler definitions */
/*
	Copyright (c) 1986, by David Michael Betz
	All rights reserved
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* limits */
#define TKNSIZE		50	/* maximum token size */
#define OSIZE		104	/* maximum object size (O_SIZE/2 + OPMAX*2) */
#define OPMAX		50	/* maximum # properties/object */
#define WMAX		500	/* maximum number of words */
#define OMAX		500	/* maximum number of objects */
#define AMAX		200	/* maximum number of actions */
#define DMAX		16384	/* maximum data space */
#define CMAX		16384	/* maximum code space */
#define FMAX		20	/* file name maximum */

/* useful definitions */
#define TRUE		1
#define FALSE		0
#define EOS		'\0'

/* token definitions */
#define T_OPEN		1
#define T_CLOSE		2
#define T_STRING	3
#define T_IDENTIFIER	4
#define T_NUMBER	5
#define T_EOF		6

/* symbol types */
#define ST_OBJECT	1
#define ST_ACTION	2
#define ST_VARIABLE	3
#define ST_CONSTANT	4
#define ST_PROPERTY	5

/* symbol structure */
typedef struct symbol {
    char *s_name;		/* symbol name */
    int s_type;			/* symbol type */
    int s_value;		/* symbol value */
    struct symbol *s_next;	/* next symbol in table */
} SYMBOL;

/* function argument structure */
typedef struct argument {
    char *arg_name;		/* argument name */
    struct argument *arg_next;	/* next argument */
} ARGUMENT;

