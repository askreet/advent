.PHONY: hashmap_tests int_set_tests

hashmap_tests: hashmap_tests.c
	gcc -g hashmap_tests.c -o hashmap_tests && \
	time ./hashmap_tests

int_set_tests:
	gcc -g int_set_test.c -o int_set_test && \
	time ./int_set_test