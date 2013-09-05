#
# Application Makefile   
#

ifndef DEBUG
DEBUG =
endif

ifndef OPTIM
OPTIM = -Osax
endif

PLATFORM=default
PHABOPTS=

#
CFLAGS  = -v$(PLATFORM) -3 -mf -w5 $(OPTIM) $(DEBUG) $(PHABOPTS)
CXXFLAGS = $(CFLAGS)

LIBS = -lAplib -lphrtlib -lphexlib -lphcontrib -lphrender_s \
		-lz -liconv -lxml2 -lsocket -lcrypto -lssl -lstrophe \
		-lnls
LIBS_L = -lphoton
LIBS_S = -lphoton_s

LDFLAGS = -v$(PLATFORM) -3 -mf $(DEBUG) $(LIBS) $(LIBS_L) $(PHABOPTS)
SDFLAGS = -v$(PLATFORM) -3 -mf $(DEBUG) $(LIBS) $(LIBS_S) $(PHABOPTS)

VPATH = ../.

include	../abOfiles
include ../indOfiles

include	../abSfiles
include ../indSfiles

include	../abHfiles
include ../indHfiles

include	../abWfiles

#
# Application Program
#

shr:	$(ABOBJ) $(MYOBJ)
		$(LD) $(SDFLAGS) $(ABOBJ) $(MYOBJ) -M -o Pelican
		usemsg Pelican ../Usemsg
		phabbind Pelican $(ABMOD)

app:	$(ABOBJ) $(MYOBJ)
		$(LD) $(LDFLAGS) $(ABOBJ) $(MYOBJ) -M -o Pelican
		usemsg Pelican ../Usemsg
		phabbind Pelican $(ABMOD)

clean:
		rm -f *.o *.err *.map Pelican

install:
		-cp -vnf Pelican /usr/bin/photon

%.o: ../%.c
			$(CC) $(CFLAGS) -o $@ -c $^
%.o: ../%.cpp
			$(CC) $(CFLAGS) -o $@ -c $^
%.o: ../%.cc
			$(CC) $(CFLAGS) -o $@ -c $^

#
# Headers
#

$(ABOBJ) $(MYOBJ):	$(MYHDR)

#
# Prototype Generation
#

proto:
		approto -p $(ABSRC) $(MYSRC) > proto.h
