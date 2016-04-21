#include <iostream>
#include <math.h>
using namespace std;

float calculate(char *s, int& i, char c, int a);

float num(char* s, int& i, int a) {
	float x = 0;
	int t = 10;
	
	if ( s[i] == 'x')
	{
		++i;
		return a;
	}
	
	if (*(s+i) == '(') {
		i++;
		x+=calculate(s, i, '+', a);		
		return x;
	}
	
	while (((int) *(s+i)>=48) && ((int) *(s+i) <=57)) {
		x=x*10+((int) *(s+i) - 48);
		++i;
	}
	
	if (*(s+i) =='.') 
	{
		++i;
	}
	
	while (((int) *(s+i)>=48) && ((int) *(s+i)<=57)) {
		x+=((float)((int) *(s+i) - 48)/t);
		i++;
		t*=10;
	}
	
	return x;	
}

float calculate(char *s, int& i, char c, int a) {
	float x;	
	if (c=='-') x=0.0-num(s, i, a);
	else if (c=='/') x=1.0/num(s, i, a);
	else x=num(s, i, a);

	if (*(s+i) == '^') {
		i++;
		x = pow(x, calculate(s, i, '^', a) );
	}
	if (c=='^') return x;
	if (*(s+i) == '(') {
		i++;
		x+=calculate(s, i, '+', a);		
	}
	if (*(s+i) == '*') {
		i++;
		x*=calculate(s, i, '*', a);
	}
	if (*(s+i) == '/') {
		i++;
		x*=calculate(s, i, '/', a);
	}
	if ((c=='*')||(c=='/')) return x;
	if (*(s+i) == '+') {
		i++;
		x+=calculate(s, i, '+', a);
	}
	if (*(s+i) == '-') {
		i++;
		x+=calculate(s, i, '-', a);
	}
	if (*(s+i) ==')') {
		i++;
		return x;
	}
	else return x;
}

float f(char* s, int a)
{
	int i = 0;
	return calculate(s, i, '+', a);
}

int main () {
	char s[40];
	cout << endl << "f(x)=";
	cin.getline(s,40);
	int n;
	char a;
	cout << "Type in n:";
	cin >> n ;
	cout << endl;
	for (int i=1; i<=(2*n-1) ; i++) {
		for (int j=1; j<=(2*n-1) ; j++) {
			int y=n-i;
			int x=j-n;
			if ((x==1)&&(y==(n-1))) cout <<" Y";
			else if ((x==(n-1))&&(y==(-1))) cout <<" X";
			else if ((x==1)&&(y==(-1))) cout <<" O";
			else if (y==(int)f(s, x)) cout <<"XX";
			else if (y==0) cout << "==";
			else if (x==0) cout << "||";
			else cout << "  ";
		}
		cout << endl;
	}

	return 0;
}
