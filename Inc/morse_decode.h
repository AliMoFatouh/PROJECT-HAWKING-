/*
 * morse_decode.h
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */

#ifndef MORSE_DECODE_H_
#define MORSE_DECODE_H_

#include <stdint.h>

extern char MORSE_ENTRY_SEQUENCE[5];

extern uint8_t char_i; //index of the string char

#define NULL ((void *)0)

struct Morse_binary_tree{

	char data;
	struct Morse_binary_tree* right;
	struct Morse_binary_tree* left;

};
/*
 *
 * Level 0
 *
 */

extern struct Morse_binary_tree root;

/*
 *
 * Level 1
 *
 */

// DOT <<
extern struct Morse_binary_tree E;

// DASH >>
extern struct Morse_binary_tree T;

/// CONNECTIONS


/*
 *
 * Level 2
 *
 */

// LEFT SUB TREE <<<<<

// DOT <<
extern struct Morse_binary_tree I;

// DASH >>
extern struct Morse_binary_tree A;


// RIGHT SUB TREE >>>>>

// DOT <<
extern struct Morse_binary_tree N;

// DASH
extern struct Morse_binary_tree M;


/*
 *
 * Level 3
 *
 */

// LEFT LEFT SUB TREE <<<<< <<<<<

// DOT <<
extern struct Morse_binary_tree S;

// DASH >>
extern struct Morse_binary_tree U;


// LEFT RIGHT SUB TREE <<<<< >>>>>

// DOT <<
extern struct Morse_binary_tree R;

// DASH >>
extern struct Morse_binary_tree W;


// RIGHT LEFT SUB TREE >>>>> <<<<<

// DOT <<
extern struct Morse_binary_tree D;

// DASH >>
extern struct Morse_binary_tree K;


// RIGHT RIGHT SUB TREE >>>>> >>>>>

// DOT <<
extern struct Morse_binary_tree G;

// DASH >>
extern struct Morse_binary_tree O;


/**
 *
 * LEVEL 4
 *
 */

// LEFT LEFT LEFT SUB TREE <<<<< <<<<< <<<<<

// DOT <<
extern struct Morse_binary_tree H;

// DASH >>
extern struct Morse_binary_tree V;


// LEFT LEFT RIGHT SUB TREE <<<<< <<<<< >>>>>

// DOT <<
extern struct Morse_binary_tree F;


// LEFT RIGHT LEFT <<<<<< >>>>>> <<<<<

// DOT <<
extern struct Morse_binary_tree L;


// LEFT RIGHT RIGHT SUB TREE <<<<<< >>>>>> >>>>>

// DOT <<
extern struct Morse_binary_tree P;

// DASH >>
extern struct Morse_binary_tree J;


// RIGHT LEFT LEFT >>>>>> <<<<<< <<<<<

// DOT <<
extern struct Morse_binary_tree B;

// DASH >>
extern struct Morse_binary_tree X;


// RIGHT LEFT RIGHT >>>>> <<<<< >>>>

// DOT <<
extern struct Morse_binary_tree C;

// DASH >>
extern struct Morse_binary_tree Y;


// RIGHT RIGHT LEFT >>>>> >>>>> <<<<<

// DOT <<
extern struct Morse_binary_tree Z;

// DASH
extern struct Morse_binary_tree Q;

void reset_string();
char decode_morse_code(struct Morse_binary_tree *node, uint8_t i);
void tree_init();


#endif /* MORSE_DECODE_H_ */
