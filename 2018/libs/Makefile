.PHONY: hashmap_tests int_set_tests list_tests char_counter_tests

hashmap_tests: hashmap_tests.c
	clang++ -g hashmap_tests.c -o hashmap_tests && \
	time ./hashmap_tests

int_set_tests:
	clang++ -g int_set_test.c -o int_set_test && \
	time ./int_set_test

list_tests:
	clang++ -g list_tests.cc -o list_tests && \
	time ./list_tests

char_counter_tests:
	clang++ -g char_counter_tests.cc -o char_counter_tests && \
	time ./char_counter_tests
