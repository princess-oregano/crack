#ifndef ARGS_H
#define ARGS_H

enum arg_err_t {
        ARG_NO_ERR = 0,
        ARG_ALLOC = 1,
        ARG_INV_USG = 2,
};

struct params_t {
        char *src_filename = nullptr;
        char *dst_filename = nullptr;
};

// Process all cmd-line args.
int 
process_args(int argc, char *argv[], params_t *params);

#endif // ARGS_H

