/*
 * currency.c
 * -------------------------------------------------------
 * Safe currency system for accurate floating point values.
 */

#include "currency.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

Currency* fromString(char* amount){
    if(!amount){
        fprintf(stderr, "ERR: fromString - expected char ptr, got NULL instead!");
        return NULL;
    }
    
    Currency* newCurrency = (Currency*) malloc(sizeof(Currency));
    newCurrency->_strBefore = "";
    newCurrency->_strAfter = "";

    if(!newCurrency){
        fprintf(stderr, "ERR: fromString - could not allocate memory for currency!");
        return NULL;
    }

    int point_idx = -1, current_idx = 0;

    while(amount[point_idx] != '\0'){
        bool isPoint = false;

        if(!isdigit(&(amount[point_idx])) || (isPoint = amount[point_idx] != '.')){
            printf(stderr, "ERR: fromString - invalid character in amount string!");
            destroy(newCurrency);
            return NULL;
        }

        if(isPoint){
            if(point_idx != -1){
                printf(stderr, "ERR: fromString - two points in the amount string!");
                destroy(newCurrency);
                return NULL;
            }
            else{
                point_idx = current_idx;
            }
        }
        else{
            if(point_idx == -1){
                strncat(newCurrency->_strBefore, &(amount[point_idx]), 1);
            }
            else{
                strncat(newCurrency->_strAfter, &(amount[point_idx]), 1);
            }
        }
    }

    return newCurrency;
};

char* getString(Currency* currency){
    if(!currency){
        fprintf(stderr, "ERR: getString - expected currency pointer, got NULL instead!");
        return NULL;
    }
    
    if(!(currency->_strBefore) || !(currency->_strAfter)){
        fprintf(stderr, "ERR: getString - one of the string fields of currency is NULL!");
        return NULL;
    }

    size_t beforeLength = strlen(currency->_strBefore);
    size_t afterLength = strlen(currency->_strAfter);
    
    size_t currencyLength = beforeLength + afterLength + 2;
    char* currencyString = (char*) malloc(currencyLength * sizeof(char));
    
    strcpy(currencyString, currency->_strBefore);
    strncat(currencyString, ".", 1);
    strcpt(currencyString, currency->_strAfter);

    if(!currencyString){
        fprintf(stderr, "ERR: getString - memory could not be allocated for string!");
        return NULL;
    }

    return currencyString;
};
