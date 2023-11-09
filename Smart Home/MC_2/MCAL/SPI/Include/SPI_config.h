/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 29 Oct 2023                                                           */
/************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/* configuration of the SPI Clock Polarity mode           */
/*      Options: SPI_RISING_FALLING
                 SPI_FALLING_RISING                      */
#define SPI_u8_CLOCK_POLARITY       SPI_RISING_FALLING 

/* configuration of the SPI Clock Phase mode           */
/*      Options: SPI_SAMPLE_SETUP
                 SPI_SETUP_SAMPLE                         */
#define SPI_u8_CLOCK_PHASE          SPI_SAMPLE_SETUP 

/* configuration of the shifting register           */
/*      Options: SPI_SHIFTING_LSB
                 SPI_SHIFTING_MSB         */
#define SPI_u8_SHIFTING_MODE       SPI_SHIFTING_LSB 

/* configuration of the Clock prescaler           */
/*      Options: SPI_CLK_PRESC_4
                 SPI_CLK_PRESC_16
                 SPI_CLK_PRESC_64
                 SPI_CLK_PRESC_128                 */
#define SPI_u8_CLK_PRESCALING       SPI_CLK_PRESC_4 

/* non blocking mechanism macro */
#define SPI_TIME_OUT            50000

#endif