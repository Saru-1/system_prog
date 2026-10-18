#include<stdio.h>
static const char* const test_array[]={
                "VDD",
                "VREF",
                "3.3V",
                "5V",
};
#define SIZE ARRAY_SIZE(test_array)

int main()
{
	printf("Size is : %d",SIZE);
	return 0;
}
