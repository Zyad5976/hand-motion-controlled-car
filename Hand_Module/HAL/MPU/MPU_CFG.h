/*
 * MPU_CFG.h
 *
 * Created: 8/14/2026 8:58:41 AM
 *  Author: Eltawel
 */ 


#ifndef MPU_CFG_H_
#define MPU_CFG_H_

/* Raw reference values measured for each hand direction (for documentation) */
#define MPU_Y_RAW_BACKWARD			-7000
#define MPU_Y_RAW_BASE				3500	/* Midpoint of 3000-4000 resting range */
#define MPU_Y_RAW_RIGHT				8000
#define MPU_Y_RAW_LEFT				11000
#define MPU_Y_RAW_FORWARD			17000

/* Boundary values used to classify a live reading into one of the 5 directions.
 * Each boundary is the midpoint between two neighboring raw reference values above. */

/* Below this  -> Backward | Above this -> Base */
#define MPU_Y_BOUNDARY_BACKWARD_TO_BASE		-1750

/* Below this  -> Base     | Above this -> Right */
#define MPU_Y_BOUNDARY_BASE_TO_RIGHT			5750

/* Below this  -> Right    | Above this -> Left */
#define MPU_Y_BOUNDARY_RIGHT_TO_LEFT			9500

/* Below this  -> Left     | Above this -> Forward */
#define MPU_Y_BOUNDARY_LEFT_TO_FORWARD			14000

/* Y-Axis Direction States */
#define MPU_Y_DIR_BACKWARD				0
#define MPU_Y_DIR_BASE					1
#define MPU_Y_DIR_RIGHT					2
#define MPU_Y_DIR_LEFT					3
#define MPU_Y_DIR_FORWARD				4

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
