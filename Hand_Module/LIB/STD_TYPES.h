/*
 * STD_TYPES.h
 *
 * Created: 8/7/2026 6:44:11 PM
 *  Author: Eltawel
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* unsigned */
typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;
typedef unsigned long	u64;

/* signed */
typedef signed char		s8;
typedef signed short	s16;
typedef signed int		s32;
typedef signed long		s64;

/* float */
typedef float			f32;
typedef double			f64;

/* nul & null */
#define null			((void *)0)
#define nul				'\0'

#endif /* STD_TYPES_H_ */