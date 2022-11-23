CC=gcc
AR=ar
FLAGS= -Wall -g
BC=basicClassification.c
ACL=advancedClassificationLoop.c
ACR=advancedClassificationRecursion.c
BC_OBJECT=basicClassification.o
ACL_OBJECT=advancedClassificationLoop.o
ACR_OBJECT=advancedClassificationRecursion.o

all: libclassloops.so libclassrec.so libclassloops.a libclassrec.a maindrec maindloop mains

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

maindrec: main.o
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

maindloop: main.o
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm
libclassloops.so: $(BC_OBJECT) $(ACL_OBJECT) NumClass.h
	$(CC) -shared -o libclassloops.so $(BC_OBJECT) $(ACL_OBJECT)

libclassrec.so: $(BC_OBJECT) $(ACR_OBJECT) NumClass.h 
	$(CC) -shared -o libclassrec.so $(BC_OBJECT) $(ACR_OBJECT)

libclassrec.a: $(BC_OBJECT) $(ACR_OBJECT) NumClass.h
	$(AR) -rcs libclassrec.a $(BC_OBJECT) $(ACR_OBJECT)

libclassloops.a: $(BC_OBJECT) $(ACL_OBJECT) NumClass.h
	$(AR) -rcs libclassloops.a $(BC_OBJECT) $(ACL_OBJECT)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

basicClassification.o: $(BC) NumClass.h
	$(CC) $(FLAGS) -fPIC -c $(BC)

advancedClassificationLoop.o: $(ACL) NumClass.h
	$(CC) $(FLAGS) -fPIC -c $(ACL)

advancedClassificationRecursion.o: $(ACR) NumClass.h
	$(CC) $(FLAGS) -fPIC -c $(ACR)

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec

