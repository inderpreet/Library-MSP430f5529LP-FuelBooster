/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/


/*
******************************************************************************
*                                  INCLUDE FILES
******************************************************************************
*/
#include "stdarg.h"


/*
******************************************************************************
*                                  FUNCTION PROTOTYPES
******************************************************************************
*/
extern void fputc(unsigned);
extern void fputs(char *);


/*
******************************************************************************
*                                  FUNCTION DEFINITIONS
******************************************************************************
*/

/**
  * @brief  Convert int to string.For example,convert 12345 to "12345"
  * @param  
  * @retval None
  */
void IntToString(int temp, char *pchar)
{
    char ch, *p = pchar;
    int a = temp;

    if (temp < 0) {
        temp = 0 - temp;
    }

    while (temp != 0) {
        *pchar++ = (char)(temp % 10 + 0x30);
        temp /= 10;
    }

    if (a < 0) {
        *pchar++ = '-';
    }

    *pchar-- = '\0';

    while (pchar > p) {
        ch = *p;
        *p++ = *pchar;
        *pchar-- = ch;
    }
}


/**
  * @brief  
  * @param  
  * @retval None
  */
void Vs_Printf(char *s, char *format, va_list arg)
{
    char *pchar;
    char *temp;

    for (pchar = format; *pchar; pchar++) {
        if (*pchar != '%') {
            *s++ = *pchar;
            continue;
        }

        switch (*++pchar) {
        case 'd'   : {
            IntToString(va_arg(arg, int), s);

            while (*s++);

            *--s = '0';
            break;
        }

        case 's'   : {
            temp = va_arg(arg, char *);

            while (*s++ = *temp++);

            *--s = '0';
            break;
        }

        case 'c'   : {
            *s++ = va_arg(arg, char);
            break;
        }

        default       :
            break;
        }
    }

    *s = '\0';
}


/**
  * @brief  
  * @param  
  * @retval None
  */
void printf(char *fmt, ...)
{

    va_list ap;
    char string[256];
    va_start(ap, fmt);
    Vs_Printf(string, fmt, ap);
    fputs(string);
    va_end(ap);
}
