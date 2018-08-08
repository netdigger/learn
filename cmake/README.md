# problems

1. How to call shell commands in CMake project?
2. How to create source code in CMake?
3. How to compile source code to a static library with -fPIC

## Not solved problems

*test.cpp* is compiled three time in this project.
How to avoid it?

# Notes

## SET_SOURCE_FILES_PROPERTIES

	SET_SOURCE_FILES_PROPERTIES(test.cpp PROPERTIES GENERATED TRUE)

Set *test.cpp* created in build process.

**NOTE**

The directory of test.cpp should be in the build directory.

## ADD_CUSTOM_COMMAND

	ADD_CUSTOM_COMMAND(OUTPUT test.cpp
		COMMAND rm -f test.cpp test.h
		COMMAND ${PROJECT_SOURCE_DIR}/generate.sh ${PROJECT_SOURCE_DIR}/tmpl
		COMMAND mv ${PROJECT_BINARY_DIR}/test.h ${PROJECT_SOURCE_DIR}
		DEPENDS ${TMPLS}
		COMMENT Create test.cpp
		VERBATIM
	)

Create *test.cpp* by the command. 
It uses shell scripte *generte.sh* 
the output *test.cpp* depend on the files *${TMPLS}*

## ADD_CUSTOM_TARGET

	ADD_CUSTOM_TARGET(T DEPENDS test.cpp)

Becuase *ADD_DEPENDENCIES* need targes, and *test.cpp* is not a target.
So a new target *T* have to be created.

## ADD_DEPENDENCIES

	ADD_DEPENDENCIES(test.out T)

*test.out* depends on target *T*

## SET_PROPERTY

	SET_PROPERTY(TARGET a 
		PROPERTY POSITION_INDEPENDENT_CODE ON
	)

Normally, CMake compile all source code which used to archive a static 
library without *-fPIC*. 
*SET_PROPERTY* should be used to define the *POSITION_INDEPENDENT_CODE* 
as *ON*





