 #Makefile for adventure system
CC=cc
CFLAGS=-g -Wall -Wextra
ADVLIB=/cmu/misc/cl0x/lib/adventure

advcom: advcom.h advavl.h advcom.o advfcn.o \
	advscn.o advexp.o advavl.o advfio.o
	${CC} -o advcom advcom.o advfcn.o advscn.o advexp.o \
	advavl.o advfio.o

advint: advint.h advmsg.o advtrm.o advprs.o \
	advdbs.o advint.o advjunk.o advexe.o
	${CC} -o advint advmsg.o advtrm.o advprs.o \
	    advdbs.o advint.o advjunk.o advexe.o

sample: osample.adv objects.adi
	advcom osample

all:	advcom advint install

install: advcom advint
	$(INSTALL) advcom advint $(DESTDIR)
	$(INSTALL) ../osample.adv ../objects.adi $(ADVLIB)

