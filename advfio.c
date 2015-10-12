
/* advfio.c - file i/o routines for the adventure compiler */
/*
	Copyright (c) 1986, by David Michael Betz
	All rights reserved
*/

#define BSIZE	8192

/* global variables */
long ad_foff;

/* external routines */
extern long lseek();

/* local variables */
static char buf[BSIZE];
static int boff;
static int fd;

void ad_create(char *name)
{
    /* create the file */
    if ((fd = creat(name,0666)) < 0)
	fail("can't create output file");
	
    /* initialize the buffer and file offset */
    ad_foff = 0L;
    boff = 0;
}

void ad_close(void)
{
    ad_flush();
    close(fd);
}

void ad_putc(int ch)
{
    buf[boff++] = ch; ad_foff++;
    if (boff >= BSIZE)
	ad_flush();
}

void ad_seek(long pos)
{
    ad_flush();
    if (lseek(fd,pos,0) != pos)
	fail("error positioning output file");
    ad_foff = pos;
}

void ad_flush(void)
{
    if (boff) {
	if (write(fd,buf,boff) != boff)
	    fail("error writing to output file");
	boff = 0;
    }
}
