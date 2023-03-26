#include <stdio.h>
#include <assert.h>
#include "crack.h"

const int POS = 33;
const int NOP = 90;

int
crack(char *buffer)
{
        assert(buffer); 

        for (int i = 0; i < 3; i++) {
                buffer[i+POS] = NOP;
        }
       
        return CRK_NO_ERR;
}

