/************************************************************************************/
/*  Author  : Ahmed Mohey                                                           */
/*  Version : v01                                                                   */
/*  Date    : 29 Oct 2023                                                           */
/************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* Regisrers Definition */
#define SPI_uint8_SPCR_REG               *((volatile uint8 *)0x2D)
#define SPI_uint8_SPSR_REG               *((volatile uint8 *)0x2E)
#define SPI_uint8_SPDR_REG               *((volatile uint8 *)0x2F)

/* Macros for Register's Bits */
// SPCR
#define SPI_uint8_SPR0_BIT               0
#define SPI_uint8_SPR1_BIT               1
#define SPI_uint8_CPHA_BIT               2
#define SPI_uint8_CPOL_BIT               3
#define SPI_uint8_MSTR_BIT               4
#define SPI_uint8_DORD_BIT               5
#define SPI_uint8_SPE_BIT                6
#define SPI_uint8_SPIE_BIT               7

/* Macros for Register's Bits */
// SPSR
#define SPI_uint8_SPI2X_BIT              0
#define SPI_uint8_WCOL_BIT               6
#define SPI_uint8_SPIF_BIT               7

/* macros for config clock polarity */
#define SPI_RISING_FALLING            0
#define SPI_FALLING_RISING            1

/* macros for config clock phase */
#define SPI_SAMPLE_SETUP              0
#define SPI_SETUP_SAMPLE              1

/* macros for clock prescaler */
#define SPI_CLK_PRESC_4               0
#define SPI_CLK_PRESC_16              1
#define SPI_CLK_PRESC_64              2
#define SPI_CLK_PRESC_128             3

#endif
