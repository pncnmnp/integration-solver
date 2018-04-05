/*
<Integration Solver : solves integration by Simpson's 3/8 rule>
Copyright (C) 2018 Parth Parikh

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define n 100000/* Accuracy upto 100000 Iterations */

void def_x (float *func_def_x, float difference) {

	for(int i = 1; i < n; i++) {
		*(func_def_x + i) = *(func_def_x) + i*difference;
	}
}

void choose (int *function) {

	printf("11 : sin(x)\t22 : cos(x)\t33 : tan(x)\n");
	printf("44 : cot(x)\t55 : sec(x)\t66 : cosec(x)\n");
	printf("77 : log(x)\t88 : exp(x)\t99 : pow(x,a)\n");
	printf("Enter your choice: ");
	scanf("%d",function);
}

void def_y (float *func_def_x, float *func_def_y, int *function) {

	if(*function == 11){
		for(int i = 0; i < n; i++){
		*(func_def_y + i) = sin(*(func_def_x + i));
		}
	}

	else if(*function == 22){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = cos(*(func_def_x + i));
	}

	else if(*function == 33){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = tan(*(func_def_x + i));
	}

	else if(*function == 44){
		for(int i = 0; i < n; i++)
 		*(func_def_y + i) = 1/tan(*(func_def_x + i));
	}
	
	else if(*function == 55){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = 1/cos(*(func_def_x + i));
	}
	
	else if(*function == 66){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = 1/sin(*(func_def_x + i));
	}

	else if(*function == 77){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = log10(*(func_def_x + i));
	}

	else if(*function == 88){
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = exp(*(func_def_x + i));
	}

	else if(*function == 99){
		int power = 0;
		printf("Enter power (a) : ");
		scanf("%d",&power);
		for(int i = 0; i < n; i++)
		*(func_def_y + i) = pow((*(func_def_x + i)),power);
	}
}

void simpsons_rule (float *func_def_y, float difference) {

	float answer = 0.0;

	for(int i = 1; i < n-1; i++) {
		if (i%3==0)
			answer += (*(func_def_y+i))*2;
		else
			answer += (*(func_def_y+i))*3;
	}

	answer += *(func_def_y) + *(func_def_y+(n-1));

	printf("Answer: %f\tDifference: %f\n",answer,difference);
	printf("Integration is : %f (4-Digit-Accuracy)\n", 3*difference*(answer)/8);
}

int main (void) {

	float *func_def_x, *func_def_y, upp_bound = 0.0, lwr_bound = 0.0, func_x[n], func_y[n];
	int *function, choice = 0;
	
	function = &choice;
	func_def_x = &func_x[0];
	func_def_y = &func_y[0];		

	printf("Enter the upper and lower bounds of the function: ");
	scanf("%f%f",&upp_bound,&lwr_bound);

	float difference = (upp_bound-lwr_bound)/n;

	*func_def_x = lwr_bound;

	def_x (func_def_x, difference);

	choose(function);

	def_y (func_def_x, func_def_y, function);

	simpsons_rule (func_def_y, difference);

	return 0;
}
