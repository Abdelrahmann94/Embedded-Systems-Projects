/*
=======================================================================================================================
Author       : Mamoun
Module       : Standard Types
File Name    : std_types.h
Date Created : Oct 14, 2023
Description  : The most common standard types used in Embedded C.
=======================================================================================================================
*/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*=====================================================================================================================
                                            < Definitions >
=====================================================================================================================*/

#ifndef NULL_PTR
#define NULL_PTR                   ((void*)(0))
#endif

#ifndef TRUE
#define TRUE                       (1U)
#endif

#ifndef FALSE
#define FALSE                      (0U)
#endif

#ifndef HIGH
#define HIGH                       (1U)
#endif

#ifndef LOW
#define LOW                        (0U)
#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef signed char                sint8;
typedef unsigned char              uint8;
typedef unsigned char*             puint8;
typedef signed short               sint16;
typedef unsigned short             uint16;
typedef signed long                sint32;
typedef unsigned long              uint32;
typedef signed long long           sint64;
typedef unsigned long long         uint64;
typedef float                      float32;
typedef double                     float64;

#endif /* STD_TYPES_H_ */
