
1)<h3>Print Hello World</h3>

include<stdio.h>
int main(){
printf("Hello World");

return 0;

![hello](https://github.com/user-attachments/assets/c8c17ce6-059d-47ea-b799-72e801bc9494)

2)<h3>Variable Declaration</h3>

<h2>C Format Specifiers</h2>
🔢 Integer Types
%d or %i → Integer
Example: int x = 10;

%u → Unsigned Integer
Example: unsigned int y = 50;

%x → Hexadecimal (lowercase)
Example: 255 → ff

%X → Hexadecimal (UPPERCASE)
Example: 255 → FF

%o → Octal Number
Example: 10 → 12

🔣 Character and String
%c → Single Character
Example: char ch = 'A';

%s → String (array of characters)
Example: char name[] = "John";

🔢 Floating Point Numbers
%f → Float
Example: float pi = 3.14;

%.2f → Float with 2 decimal places
Example: 3.14159 → 3.14

%lf → Double
Example: double d = 2.71828;
int age =25;

#include<stdio.h>
int main(){
	int age =25;
	printf("%d" ,age);
	
	return 0;
}


![variable1](https://github.com/user-attachments/assets/680e8d8f-6a5a-4bb6-82cd-b4f900da9a75)

3)<h3>When two variable declare in one varible name</h3>
*<i>Variables in C can be reassigned new values after they are declared.</i>
*<i>The updated value replaces the old value in memory.</i>

#include<stdio.h>
int main(){
	int age =25;
	printf("%d\n" ,age);
	age=31;
	printf("\n%d\n",age);
	
	return 0;
}


![variable2](https://github.com/user-attachments/assets/e30f9dd4-65e8-4dc0-8b9d-d658da533dd6)

4)#include<stdio.h>
	int main(){
	int firstnum =25;
	printf("fist number:%d",firstnum);
	int secondnum=firstnum;
	printf("\nsecond number:%d",secondnum);
	
	return 0;
}
![variable3](https://github.com/user-attachments/assets/5bf3bc0c-70dd-4563-984d-88a3aa0e7b75)

5)#include<stdio.h>
	int main(){
	int firstnum =25;
	printf("fist number:%d",firstnum);
	int secondnum=firstnum;
	printf("\nsecond number:%d",secondnum);
	
	return 0;
}

![variable4](https://github.com/user-attachments/assets/1afa9b6c-0c6f-4b89-b141-d02ca07d0a95)

6)<h3>Prints the size (in bytes) of the age variable</h3>
![variable5](https://github.com/user-attachments/assets/c8d56017-5bb6-42af-8471-ebf3be869bab)

7)<h3>Double Variables</h3>

#include<stdio.h>
int main(){
	double num =10.34; 
	printf("%lf",num);//10.340000(6 bytes)
	printf("\n%.2lf",num);//only 2 decimal points
	
	
	return 0;
}
![variable6](https://github.com/user-attachments/assets/4fe481c9-957f-4332-a8b8-3150a4b02cac)

8)<h3>Float Variable</h3>

#include<stdio.h>
int main(){
	char character='z';
	printf("%c",character); //print as Character
	printf("\n%d",character); //print as integer(ASCII)
	printf("\nSize :%zu",sizeof(character));
	return 0;
}
![variable7](https://github.com/user-attachments/assets/64b9376a-dd64-4fcf-8739-1987a117af1e)

9)<h3>Char Variable</h3>
#include<stdio.h>
int main(){
	char character='z';
	printf("%c",character); //print as Character
	printf("\n%d",character); //print as integer(ASCII)
	printf("\nSize :%zu",sizeof(character));
	return 0;
}
![variable8](https://github.com/user-attachments/assets/79b86fd2-8be4-44ec-8391-b1fb34bc6ef4)

10)<h3>How to get User Input</h3>
*<i>Uses scanf to read the age from user input.</i>

#include<stdio.h>
int main(){
	int age;
	printf("Enter your age:");
	scanf("%d", &age);
	printf("Age is:%d",age);
	return 0;
}

![userinput](https://github.com/user-attachments/assets/4ffe5772-72b0-4c0e-ad41-4e9ef7d7a21b)

11)<h3>How to take multiple inputs together</h3>

#include<stdio.h>
int main(){
double number;
char alpha;
printf("Enter input:");
scanf("%lf %c",&number,&alpha);
printf("double:%lf ",number);
printf("\ncharacter:%c ",alpha);

return 0;
}
![userinput2](https://github.com/user-attachments/assets/a03aae9c-4902-427f-9384-ef0b1dac4885)

12)<h3>C operators</h3>

#include<stdio.h>
int main(){
int num1;
int num2;


printf("Enter number 1:");
scanf("%d",&num1);
printf("Enter number 2:");
scanf("%d",&num2);

int sum=num1+num2;
int mul=num1*num2;
int sub=num2-num1;
int div=num2/num1;

printf("summation:%d",sum);
printf("\nmultiplication:%d",mul);
printf("\nsubstraction :%d",sub);
printf("\ndivision :%d",div);

return 0;
}

![cal](https://github.com/user-attachments/assets/ce47a38d-e71d-4bd7-b9ae-392d8235b00c)
