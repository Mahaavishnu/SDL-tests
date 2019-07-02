CPP=gcc    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL2 #-lSDL_mixer #Linker
EXEC=test  #Nom du programme à modifier

all: ${EXEC}

${EXEC}: test.o
	${CPP} $(CFLAGS) -o ${EXEC} test.o ${LDFLAGS}

test.o: test.c
	${CPP} $(CFLAGS) -c test.c



clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${EXEC}
