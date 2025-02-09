%{
int n = 0;
%}

%%

"while"|"if"|"else" {n++; printf("keywords: %s\n", yytext);}
"int"|"float" {n++; printf("keywords: %s\n", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {n++; printf("identifier: %s\n", yytext);}
"<="|"=="|"="|"++"|"-"|"*"|"+" {n++; printf("operator: %s\n", yytext);}
[(){}|,;] {n++; printf("separator: %s\n", yytext);}
[0-9]*"."[0-9]+ {n++; printf("float: %s\n", yytext);}
[0-9]+ {n++; printf("integer: %s\n", yytext);}
[ \t\n\r]+ ;  // Skip whitespace
. { printf("Unknown character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;  // End the lexing process
}

int main() {
    yylex();
    printf("\nTotal number of tokens = %d\n", n);
    return 0;
}
