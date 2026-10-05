/*
 * morse_decode.c
 *
 *  Created on: Oct 5, 2026
 *      Author: alimohamed2252006
 */


#include "stm32f446xx.h"
#include "morse_decode.h"


/*
 *
 * Level 0
 *
 */

struct Morse_binary_tree root;

/*
 *
 * Level 1
 *
 */

// DOT <<
struct Morse_binary_tree E;

// DASH >>
struct Morse_binary_tree T;

/// CONNECTIONS


/*
 *
 * Level 2
 *
 */

// LEFT SUB TREE <<<<<

// DOT <<
struct Morse_binary_tree I;

// DASH >>
struct Morse_binary_tree A;


// RIGHT SUB TREE >>>>>

// DOT <<
struct Morse_binary_tree N;

// DASH
struct Morse_binary_tree M;


/*
 *
 * Level 3
 *
 */

// LEFT LEFT SUB TREE <<<<< <<<<<

// DOT <<
struct Morse_binary_tree S;

// DASH >>
struct Morse_binary_tree U;


// LEFT RIGHT SUB TREE <<<<< >>>>>

// DOT <<
struct Morse_binary_tree R;

// DASH >>
struct Morse_binary_tree W;


// RIGHT LEFT SUB TREE >>>>> <<<<<

// DOT <<
struct Morse_binary_tree D;

// DASH >>
struct Morse_binary_tree K;


// RIGHT RIGHT SUB TREE >>>>> >>>>>

// DOT <<
struct Morse_binary_tree G;

// DASH >>
struct Morse_binary_tree O;


/**
 *
 * LEVEL 4
 *
 */

// LEFT LEFT LEFT SUB TREE <<<<< <<<<< <<<<<

// DOT <<
struct Morse_binary_tree H;

// DASH >>
struct Morse_binary_tree V;


// LEFT LEFT RIGHT SUB TREE <<<<< <<<<< >>>>>

// DOT <<
struct Morse_binary_tree F;


// LEFT RIGHT LEFT <<<<<< >>>>>> <<<<<

// DOT <<
struct Morse_binary_tree L;


// LEFT RIGHT RIGHT SUB TREE <<<<<< >>>>>> >>>

// DOT <<
struct Morse_binary_tree P;

// DASH >>
struct Morse_binary_tree J;


// RIGHT LEFT LEFT >>>>>> <<<<<< <<<<<

// DOT <<
struct Morse_binary_tree B;

// DASH >>
struct Morse_binary_tree X;


// RIGHT LEFT RIGHT >>>>> <<<<< >>>>

// DOT <<
struct Morse_binary_tree C;

// DASH >>
struct Morse_binary_tree Y;


// RIGHT RIGHT LEFT >>>>> >>>>> <<<<<

// DOT <<
struct Morse_binary_tree Z;

// DASH
struct Morse_binary_tree Q;


char MORSE_ENTRY_SEQUENCE[5];
uint8_t char_i = 0; //index of the string char


char decode_morse_code(struct Morse_binary_tree *node, uint8_t i){ // root 0++

	if(node == NULL){ // Exception! End Of Nodes
		return '2';
	}

	if(MORSE_ENTRY_SEQUENCE[i] == '\0'){ // End Of Text
		return node->data;
	}

	if(MORSE_ENTRY_SEQUENCE[i] == '.' ){//go left
		return decode_morse_code(node->left,++i);
	}else if(MORSE_ENTRY_SEQUENCE[i] == '-'){//go right
		return decode_morse_code(node->right,++i);
	}else{ // any errors?
		return '2';
	}

}


void tree_init(){



	/*
	 *
	 * init tree
	 *
	 */

	/*
	 * level 1
	 */

	root.data = '2';
	root.left = &E;
	root.right = &T;

	/*
	 *
	 * level 2
	 *
	 */

	E.data = 'E';
	E.left = &I;
	E.right = &A;

	T.data = 'T';
	T.left=&N;
	T.right=&M;

	/*
	 *
	 *
	 * level 3
	 *
	 */

	I.data = 'I';
	I.left = &S;
	I.right = &U;

	A.data = 'A';
	A.left = &R;
	A.right = &W;

	N.data = 'N';
	N.left = &D;
	N.right = &K;

	M.data = 'M';
	M.left = &G;
	M.right = &O;

	/*
	 *
	 *
	 * level 4
	 *
	 */

	S.data = 'S';
	S.left = &H;
	S.right = &V;

	U.data = 'U';
	U.left = &F;
	U.right = NULL;

	R.data = 'R';
	R.left = &L;
	R.right = NULL;

	W.data = 'W';
	W.left = &P;
	W.right = &J;

	D.data = 'D';
	D.left = &B;
	D.right = &X;

	K.data = 'K';
	K.left = &C;
	K.right = &Y;

	G.data = 'G';
	G.left = &Z;
	G.right = &Q;

	O.data = 'O';
	O.left = NULL;
	O.right = NULL;

	/*
	 *
	 *
	 * level 5
	 *
	 */

	H.data = 'H';
	H.left = NULL;
	H.right = NULL;

	V.data = 'V';
	V.left = NULL;
	V.right = NULL;

	F.data = 'F';
	F.left = NULL;
	F.right = NULL;

	L.data = 'L';
	L.left = NULL;
	L.right = NULL;

	P.data = 'P';
	P.left = NULL;
	P.right = NULL;

	J.data = 'J';
	J.left = NULL;
	J.right = NULL;

	B.data = 'B';
	B.left = NULL;
	B.right = NULL;

	X.data = 'X';
	X.left = NULL;
	X.right = NULL;

	C.data = 'C';
	C.left = NULL;
	C.right = NULL;

	Y.data = 'Y';
	Y.left = NULL;
	Y.right = NULL;

	Z.data = 'Z';
	Z.left = NULL;
	Z.right = NULL;

	Q.data = 'Q';
	Q.left = NULL;


}

void reset_string(){

	for(int i = 0; i<5;i++){
		MORSE_ENTRY_SEQUENCE[i] = 0; //reset String
	}
	char_i = 0; //reset index

}
