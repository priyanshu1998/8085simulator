#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern int perLineExec ;

typedef struct Flags
{
	uint8_t z : 1;
	uint8_t s : 1;
	uint8_t p : 1;
	uint8_t cy : 1;
	uint8_t ac : 1;
	uint8_t pad : 3;
} Flags;

typedef struct State8085
{
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
	uint8_t e;
	uint8_t h;
	uint8_t l;
	uint16_t sp;
	uint16_t pc;
	struct Flags cc;
	uint8_t int_enable;
	uint8_t *memory;
} State8085;

// Flags CC_ZSPAC = {0, 0, 0, 0, 0};


typedef enum { PRESERVE_CARRY, UPDATE_CARRY } should_preserve_carry;

int parity(int x, int size);

int Disassemble8085Op(uint8_t *codebuffer, int pc);

void LogicFlagsA(State8085 *state, uint8_t ac);

void ArithFlagsA(State8085 *state, uint16_t res, should_preserve_carry preserveCarry);

void UnimplementedInstruction(State8085 *state);

void InvalidInstruction(State8085 *state);

uint8_t addByte(State8085 *state, uint8_t lhs, uint8_t rhs, should_preserve_carry preserveCarry);

uint8_t addByteWithCarry(State8085 *state, uint8_t lhs, uint8_t rhs, should_preserve_carry preserveCarry);

uint8_t subtractByte(State8085 *state, uint8_t lhs, uint8_t rhs, should_preserve_carry preserveCarry);

uint8_t subtractByteWithBorrow(State8085 *state, uint8_t lhs, uint8_t rhs, should_preserve_carry preserveCarry);

void call(State8085 *state, uint16_t offset, uint16_t addr);

void returnToCaller(State8085 *state, uint16_t offset);

int Emulate8085Op(State8085 *state, uint16_t offset);

State8085 *Init8085(void);

void LoadProgram(State8085 *state, char* file, uint16_t offset);

State8085 *ExecuteProgram(State8085 *state);

void free_allocated_mem(State8085 *state);

void mem_write(State8085 *state);

void mem_read(State8085 *state);