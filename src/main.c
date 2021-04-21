#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <common/common.h>
#include <box/box.h>
#include <iff/iff.h>
#include <path/path.h>

int main(int argc, char **argv)
{
    load_data(argv[1]);

    build_shapes();
    build_links();
    
    fputs (&MAP[0][0],stdout);       

    return 0;
}
