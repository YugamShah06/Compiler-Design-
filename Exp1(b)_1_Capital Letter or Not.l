%{
int count=0;
%}

%%

[A-Z] {printf("%s capital letter\n",yytext);
       count++;}
.     {printf("%s not a capital letter\n",yytext);}
\n {return 0;}

%%

int yywrap(){}
int main(){
yylex();
printf("Number of capital letters in the given input - %d\n",count);
return 0;
}