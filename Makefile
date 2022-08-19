make:
	cc -c tbwidgets.c -ldl -fpic
	cc -shared -o libtbwidgets.so tbwidgets.o
	
install:
	mv ./libtbwidgets.so /usr/lib
	ln /usr/lib/libtbwidgets.so /usr/lib/tbw.so
	cp ./tbwidgets.h /usr/include
	ldconfig
