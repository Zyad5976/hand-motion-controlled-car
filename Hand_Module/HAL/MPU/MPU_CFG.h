/*
 * MPU_CFG.h
 *
 * Created: 8/14/2026 8:58:41 AM
 *  Author: Eltawel
 */ 


#ifndef MPU_CFG_H_
#define MPU_CFG_H_

/* Acc Full Sacle Range (AFS_SEL Bits) */
#define MPU_2G				0
#define MPU_4G				1
#define MPU_8G				2
#define MPU_16G				3

/* Select the Range */
#define MPU_RANGE			MPU_2G

/* Sensitivity Scale Factor for The Selected Range */
#define MPU_SENS			16384

#endif /* MPU_CFG_H_ */