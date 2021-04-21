#include <stdio.h>
#include <common/common.h>
#include <box/box.h>

void box(struct shape *shape)
{
    char *msg=shape->txt;
    size_t w=shape->width;
    size_t w2=w/2;
    size_t h=shape->height;
    size_t h2=h/2;
    size_t i,x;

    if (shape->align==0)
        x=MAX_COLS/2-w2;
    else if (shape->align<0)
        x=shape->align*(-1);
    else
        x=shape->align;

    PUTSPC(x);

    /* save upper left coordinates */
    shape->N.y=CURS_Y-1; shape->N.x=CURS_X+w2+1;
    shape->S.y=CURS_Y+h+2; shape->S.x=CURS_X+w2+1;
    shape->W.y=CURS_Y+h2+1; shape->W.x=CURS_X-1;
    shape->E.y=CURS_Y+h2+1; shape->E.x=CURS_X+w+2;

    PUTC(BOX_UL);PUTC_N(BOX_HH,w);PUTC(BOX_UR);
    PRINT_NEWLINE;
    PUTSPC(x);

    for (i=0;i<h;i++)
    {
        PUTC(BOX_VV);
        PUTC(' ');PUTS(msg);PUTC(' ');
        PUTC(BOX_VV);
        PRINT_NEWLINE;
        PUTSPC(x);
    }

    PUTC(BOX_DL);PUTC_N(BOX_HH,w);PUTC(BOX_DR);
    PRINT_NEWLINE;

    PRINT_NEWLINE;
    PRINT_NEWLINE;
/*
    MAP[shape->N.y][shape->N.x]='1';
    MAP[shape->S.y][shape->S.x]='2';
    MAP[shape->W.y][shape->W.x]='3';
    MAP[shape->E.y][shape->E.x]='4';
*/
}
