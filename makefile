simple:
	g++ book.cpp -o book -lntl -lgmp
	./book
	rm -f book
rsa:
	g++ rsa.cpp -o rsa -lntl -lgmp
	./rsa
	rm -f rsa
decrypt:
	g++ decrypt.cpp -o decrypt -lntl -lgmp
	./decrypt
	rm -f decrypt
test:
	g++ test.cpp -o test -lntl -lgmp
	./test
	rm -f test
clean:
	rm -f test rsa book decrypt