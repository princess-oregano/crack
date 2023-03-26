#include <stdio.h>
#include "args.h"
#include "file.h"
#include "crack.h"

int
main(int argc, char *argv[])
{
        params_t params {};

        if (process_args(argc, argv, &params) != ARG_NO_ERR) {
                fprintf(stderr, "Could not process arguments.\n");
                return 1;
        }

        file_t src {};
        file_t dst {};
        if (get_file(params.src_filename, &src, "r") != F_ERR_NO_ERR ||
            get_file(params.dst_filename, &dst, "w") != F_ERR_NO_ERR) {
                fprintf(stderr, "Could not get file info.\n");
                return 1;
        }

        char *buffer = nullptr;
        if (read_file(&buffer, &src) != F_ERR_NO_ERR) {
                fprintf(stderr, "Could not read file.\n");
                return 1;
        }

        crack(buffer);
        fwrite(buffer, sizeof(char), (size_t) src.stats.st_size, dst.stream);

        return 0;
}
