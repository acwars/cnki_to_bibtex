#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

void load_data(const char *filename);
size_t count_chars(const char *s, const char c);
void build_shapes();
void build_links();

/* Maximum MAP area */
#define MAX_ROWS 240
#define MAX_COLS 50

/* Maximum shapes */
#define MAX_SHAPES 100
#define MAX_TXT 160

/* Node's type */
#define BOX 1
#define IFF 2

/* map point */
struct point{ size_t x, y;};
struct shape
{
    size_t id;             /* progressive 1..N_SHAPES */
    int type;
    int align;             /* -/0/+ */
    struct point N,S,W,E;  /* cardinal direction */
    size_t height,width;   
    char txt[MAX_TXT];     /* the text */
};

#define NEWLINE ';'

/* some extern */
extern struct shape SHAPE[MAX_SHAPES];
extern char MAP[MAX_ROWS][MAX_COLS];
extern size_t CURS_Y, CURS_X;
extern size_t N_SHAPES,LARGEST;

/* write to map area */
#if 1
#define PUTC(c)       MAP[CURS_Y][CURS_X++]=((c))
#define PUTC_N(c,n)   do{size_t _n=(n);while(_n--)PUTC((c));}while(0)
#define PUTSPC(n)     CURS_X+=(n)
#define PUTS(s)       do{char *_x=s;while(*_x)PUTC(*_x++);}while(0)
#define PRINT_NEWLINE do{CURS_Y++,CURS_X=0;}while(0)
#else
#define PUTC(c)       putchar((c))
#define PUTC_N(c,n)   do{size_t _n=(n);while(_n--)PUTC((c));}while(0)
#define PUTSPC(n)     PUTC_N(' ',(n))
#define PUTS(s)       fputs(s,stdout);
#define PRINT_NEWLINE PUTC('\n')
#endif

#endif /* INCLUDE_COMMON_H */
