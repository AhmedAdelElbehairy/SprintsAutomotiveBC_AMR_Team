/*
 * File Name: STD_TYPES.h
 * Creation Date: 08/09/2021
 * Author: AMR Team
 * Description: Header File for standard data types....
 */

#ifndef __STD_TYPES__
#define __STD_TYPES__
/*-------------------TYPE DEFs--------------------------*/
/*UNSIGNED INT*/
typedef unsigned char                   uint8_t;  
typedef unsigned long int               uint32_t;
typedef unsigned long long int          uint64_t;
/*SIGNED INT*/
typedef signed char                     int8_t;
typedef signed long int                 int32_t;
typedef signed long long int            int64_t;
/*FLOAT*/
typedef float                           float32_t;
typedef double                          double64_t;
/*POINTER TO UNSIGNED INT*/
typedef uint8_t*                        ptr_uint8_t;
typedef uint32_t*                       ptr_uint32_t;
typedef uint64_t*                       ptr_uint64_t;
/*POINTER TO SIGNED INT*/
typedef int8_t*                         ptr_int8_t;
typedef int32_t*                        ptr_int32_t;
typedef int64_t*                        ptr_int64_t;
/*POINTER TO FLOAT*/
typedef float32_t*			            ptr_float32_t;
typedef double64_t*			            ptr_double64_t;
/*POINTER TO FUNCTION (VOID FUNC(VOID))*/
typedef void (*Ptr_VoidFuncVoid_t)(void);
/*ERROR STATE*/
typedef uint8_t ERROR_STATE_t;
/*----------------COMMON MACRROS----------------------*/
#define ERROR_OK        (uint8_t)0
#define ERROR_NOK       (uint8_t)1
#define INIT            (uint8_t)1
#define NOT_INIT        (uint8_t)0

#define NULL_PTR        ((void*)(0))
#define NULL_TERMINATOR (uint8_t)('\0')
#define END_OF_STRING   (uint8_t)('\0')
#define NEW_LINE        (uint8_t)('\r')
#define BACKSPACE       (uint8_t)('\b')



#endif
