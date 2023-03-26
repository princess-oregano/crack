#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "args.h"

int 
process_args(int argc, char *argv[], params_t *params)
{
        if (argc < 4) {
                fprintf(stderr, "Error: Expected more arguments.\n");
                return ARG_INV_USG;
        }

        for (int i = 1; i < argc; i++) {
                if ((strcmp(argv[i], "-i") == 0) ||
                    (strcmp(argv[i], "--input") == 0)) {
                        params->src_filename = argv[++i];
                } else if ((strcmp(argv[i], "-o") == 0) ||
                    (strcmp(argv[i], "--output") == 0)) {
                        params->dst_filename = argv[++i];
                } else {
                        fprintf(stderr, "Error: Wrong parameters.\n");
                        return ARG_INV_USG;
                }
        }

        return ARG_NO_ERR;
}

