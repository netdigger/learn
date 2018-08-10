# problem

If a *const static int* value *kB* is defined in a class A, 
and it is used like following codes:
	
	ASSERT_EQ(A::kB, 1);

The linker will not find the define of *kB*

# solution

	int key = A::kB;
	ASSERT_EQ(key, 1);

# Reason

I don't know the reason. I surpose that 
the problem have relationship with *#define ASSERT_EQ*.

