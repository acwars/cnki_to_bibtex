#include <stdio.h>
#include <common/common.h>
#include <iff/iff.h>

void iff(struct shape *shape)
{
    char *txt=shape->txt;
    size_t w=shape->width;
    size_t w2=w/2;
    size_t h=shape->height;
    size_t h2=h/2;
    size_t i,x;

    if (shape->align==0)
        x=(MAX_COLS/2-w2)-h;
    else if (shape->align<0)
        x=shape->align*(-1);
    else
        x=MAX_COLS-w-3;

    i=h;
    PUTSPC(x+i);

    /* save upper left coordinates */
    shape->N.y=CURS_Y-1; shape->N.x=CURS_X+w2+1;
    shape->S.y=CURS_Y+h+2; shape->S.x=CURS_X+w2+1;
    shape->W.y=CURS_Y+h2+1; shape->W.x=CURS_X-h2-2;
    shape->E.y=CURS_Y+h2+1; shape->E.x=CURS_X+w+h+1;

    PUTC(IFF_UL);PUTC_N(IFF_HH,w);PUTC(IFF_UR);
    PRINT_NEWLINE;

    i--;PUTSPC(x+i);
    PUTC(IFF_VUL);PUTC_N(' ',w+2);PUTC(IFF_VUR);
    PRINT_NEWLINE;

    i--;PUTSPC(x+i);
    PUTC(IFF_VCL);PUTC_N(' ',h);PUTS(txt);PUTC_N(' ',h);PUTC(IFF_VCR);
    PRINT_NEWLINE;

    i++;PUTSPC(x+i);
    PUTC(IFF_VDL);PUTC_N(' ',w+2);PUTC(IFF_VDR);
    PRINT_NEWLINE;

    i++;PUTSPC(x+i);
    PUTC(IFF_DL);PUTC_N(IFF_HH,w);PUTC(IFF_DR);
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
