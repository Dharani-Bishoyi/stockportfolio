#####################################################
# Created by: suma                             #
# Created on: Monday 24 October 2022 08:25:17 PM IST #
#####################################################
SRCDIR = ../src
EXTDIR = ../external
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR




all:

	gcc ${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/crud.c -o ${OBJDIR}/crud.o
	gcc ${CFLAGS}  ${SRCDIR}/queue.c -o ${OBJDIR}/queue.o
	gcc ${CFLAGS}  ${SRCDIR}/listMgmt.c -o ${OBJDIR}/listMgmt.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${EXTDIR}/log.c -o ${OBJDIR}/log.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/log.o ${OBJDIR}/crud.o ${OBJDIR}/queue.o ${OBJDIR}/utility.o ${OBJDIR}/listMgmt.o  -o ${BINDIR}/stockPortfolio.bin

memcheck:
	valgrind ${BINDIR}/stockPortfolio.bin > ${REPORTDIR}/memcheck.txt 2>&1


clean:

	rm ${OBJDIR}/main.o ${BINDIR}/stockPortfolio.bin ${OBJDIR}/log.o ${OBJDIR}/crud.o ${OBJDIR}/listMgmt.o ${OBJDIR}/utility.o ${OBJDIR}/queue.o


##################### End of Makefile #####################
