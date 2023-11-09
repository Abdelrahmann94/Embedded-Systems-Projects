/*
=======================================================================================================================
Author       : Mamoun
Module       : I2C
File Name    : i2c_cfg.h
Date Created : Oct 30, 2023
Description  : Configuration file for the ATmega32 I2C driver.
=======================================================================================================================
*/


#ifndef MCAL_I2C_INCLUDES_I2C_CFG_H_
#define MCAL_I2C_INCLUDES_I2C_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The desired serial clock frequency for the I2C, The range is [0 KHz ~ 400 KHz]. */
#define I2C_SCL_FREQUENCY                              (400000UL)

/* This I2C device address, The range is [1 ~ 127]. */
#define I2C_DEVICE_ADDRESS                             (1)

#endif /* MCAL_I2C_INCLUDES_I2C_CFG_H_ */
