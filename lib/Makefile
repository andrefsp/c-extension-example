TEST_OUTPUT=./test
TEST_TARGET=${TEST_OUTPUT}/test


clean-test:
	mkdir -p ${TEST_OUTPUT} && rm -rf ${TEST_OUTPUT}/*

test: clean-test
	C_INCLUDE_PATH=${C_INCLUDE_PATH}:./ gcc test.c -o ${TEST_TARGET} && ${TEST_TARGET}
