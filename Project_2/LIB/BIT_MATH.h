/*
 * BIT_MATH.h
 *
 * Created: 8/7/2026 6:44:31 PM
 *  Author: Eltawel
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Macros */
#define BIT_MASK					1

/* Function Macros */
#define SET_BIT(REG,BIT)			((REG) |= (BIT_MASK << (BIT)))
#define CLEAR_BIT(REG,BIT)			((REG) &= ~(BIT_MASK << (BIT)))
#define TOGGLE_BIT(REG,BIT)			((REG) ^= (BIT_MASK << (BIT)))
#define GET_BIT(REG,BIT)			(((REG) >> (BIT)) & BIT_MASK)

#endif /* BIT_MATH_H_ */