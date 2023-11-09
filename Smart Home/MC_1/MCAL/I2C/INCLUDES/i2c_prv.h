/*
=======================================================================================================================
Author       : Mamoun
Module       : I2C
File Name    : i2c_prv.h
Date Created : Oct 30, 2023
Description  : Private file for the ATmega32 I2C driver.
=======================================================================================================================
*/


#ifndef MCAL_I2C_INCLUDES_I2C_PRV_H_
#define MCAL_I2C_INCLUDES_I2C_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The minimum and the maximum serial clock frequency for the I2C. */
#define I2C_MIN_SCL_FREQUENCY                              (0UL)
#define I2C_MAX_SCL_FREQUENCY                              (400000UL)

/* The minimum and the maximum slave address value for the I2C slaves. */
#define I2C_MIN_SLAVE_ADDRESS                              (0)
#define I2C_MAX_SLAVE_ADDRESS                              (127)

#endif /* MCAL_I2C_INCLUDES_I2C_PRV_H_ */
