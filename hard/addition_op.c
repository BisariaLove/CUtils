#include <stdio.h>

int add_op(int a, int b){
	if(b == 0) return a;

	int sum = a^b;
	int carry = (a&b)<<1;
	return add_op(sum, carry);
}
int main(){

	int res = add_op(759, 654);
	fprintf(stdout, "Sums is: %d\n",res);
	return 0;
}