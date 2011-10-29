/* ---------------------------------------------------------------------------
**  MIPS Assembler UnB - MIPS Assembler Declarations Header
**
**  Description: This file contains several definitions and declarations for 
**  the MIPS Assembler such as structs and constants.
**
**  Author:
**  Project: MIPS Assembler UnB - October 2011
** -------------------------------------------------------------------------*/
#ifndef MIPS_H
#define MIPS_H

#include <stdint.h>

#include "instructions_table.h"
#include "register_table.h"

/* ---------------------------------------------------------------------------
**								DEFINES
** -------------------------------------------------------------------------*/

/* -------------------------- Parameters  --------------------------------- */
#define MAX_SYMBOL_SIZE		(31)

/* ------------------------------ Token types  ----------------------------- */
#define TK_NONE		(0x00)
#define TK_LABEL	(0x01)	
#define TK_SYMBOL	(0x02)
#define TK_INST		(0x03)
#define TK_REG		(0x04)
#define TK_REG_ENC	(0x05)
#define TK_IMM		(0x06)
#define TK_IMM_OPT	(0x07)

/* ------------------------------ Error codes  ----------------------------- */
#define ERR_NO_ERROR		(0x00)
#define ERR_TK_INV			(0x01)
#define ERR_TK_REG_INV		(0x02)
#define ERR_TK_IMM_INV		(0x03)
#define ERR_TK_SYMBOL_INV	(0x04)
#define ERR_MISA_BRACKET	(0x10)		/* Missaligned Brackets	     */
#define ERR_MISP_BRACKET	(0x11)		/* Misplaced Brackets	     */
#define ERR_MISP_COLON		(0x12)		/* Misplaced Colon	     */

/* ---------------------------------------------------------------------------
**								TYPEDEFS
** -------------------------------------------------------------------------*/

/* Type: token
** Description: Holds a token processed by the lexical analyzer from a mips 
** assembly program. The struct has a field for the token 'type' and two fields
** for the token value (int and string). The token type determines which value
** field is going to be used. It also has a pointer to a 'token' struct so that
** a linked list can be created.
** -------------------------------------------------------------------------*/
typedef struct token_st {
    char* value_s;
    int32_t value;
    uint8_t type;
    struct token_st * next;
} token;

/* Type: token_list
** Description: Implements a linked list for holding tokens. Each node contains
** an index, a pointer to a 'token' struct and a pointer to the next node.
** OBS: Remmembering that 'token' structs can produce linked lists, this struct
** is more commonly used for generating a "list of lists of tokens".
** -------------------------------------------------------------------------*/
typedef struct token_list_st {
    uint32_t index;
    token* first_token;
    struct token_list_st * next;
} token_list;

/* Type: 
** Description: 
** -------------------------------------------------------------------------*/
typedef struct {
    uint8_t op;
    uint8_t rs;
    uint8_t rt;
    uint8_t rd;
    uint8_t shamt;
    uint8_t funct;
    int16_t imm16;
    int32_t imm26;
} inst;

/* Type: 
** Description: 
** -------------------------------------------------------------------------*/
typedef struct inst_list_st {
    uint32_t index;
    uint8_t type;
    inst values;
    struct inst_list_st *next;
} inst_list;

/* ---------------------------------------------------------------------------
**						  FUNCTION PROTOTYPES
** -------------------------------------------------------------------------*/

/* Function: print_error_msg
** Description: Method for printing an error mesage to the user
** -------------------------------------------------------------------------*/
void print_error_msg(uint32_t line, uint8_t error);

#endif