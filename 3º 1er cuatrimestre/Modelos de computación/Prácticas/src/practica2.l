minuscula [a-z]
mayuscula [A-Z]
numero    [0-9]

letra     ({minuscula}|{mayuscula})
normal    ({letra}|{numero})

usuario   (\@{letra}+)
dominio   (\.{letra}+)
byte      ((((""|1)(""|[1-9]))[0-9])|(2[0-4][0-9])|(25[0-5]))

dir_ip    (({byte}\.){3}{byte})
web       ({normal}+{dominio})
correo    (({normal}|"_")+\@{letra}+{dominio})

%%

{usuario} {printf("Usuario válido: '%s'\n", yytext);}
{dominio} {printf("Dominio válido: '%s'\n", yytext);}
{byte}    {printf("Byte válido:    '%s'\n", yytext);}
{dir_ip}  {printf("Dir_ip válido:  '%s'\n", yytext);}
{web}     {printf("Web válido:     '%s'\n", yytext);}
{correo}  {printf("Correo válido:  '%s'\n", yytext);}
.+

%%

int yywrap ()
{
	return 1;
}

int main ()
{
	yylex();
	return 1;
}
