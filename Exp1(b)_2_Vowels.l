%{
#include<stdio.h>
%}

%%

[aAeEiIoOuU]  {printf("Vowel:%c\n",yytext[0]);}
[^aAeEiIoOuU]  {printf("Not a vowel:%c\n",yytext[0]);}

%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}