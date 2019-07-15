%option noyywrap

%{
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include "1505094_SymbolTable.h"
#include "y.tab.h"

using namespace std;

int line_count = 1;
int error_count = 0;

//FILE *logout;
//FILE *tokenout;
ofstream errorout;
extern YYSTYPE yylval;
//SymbolTable st(7);
string p = "\0";

%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
DIGITS {DIGIT}+
NEWLINE \n
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
INVALID_ID [0-9]+[a-zA-Z_][a-zA-Z0-9_]* 
FLOAT_CONST {DIGITS}*\.{DIGITS}(E[+-]?{DIGITS})?
FLOAT_CONST1 {DIGITS}E[+-]?{DIGITS}
CHAR_CONST '[a-zA-Z0-9]'|'\\[nt"afrbv0]'
SINGLELINE_STRING \"[.^"]*\" 
STRING_ERROR1 \"[.^"]*
MULTILINE_STRING \"([^\"\n]|\\{NEWLINE})+\"
MULTILINE_STRINGERROR \"([^\"\n]|(\\{NEWLINE}))*	
SINGLELINE_COMMENT "//".*
TOO_DEC ({DIGIT}*\.)*({DIGIT}*\.{DIGIT}*\.{DIGIT}*)+
ILL_FNUM {DIGIT}*(\.{DIGITS})*(E[+-]?{FLOAT_CONST}*{DIGIT}*{TOO_DEC}*)+
UNTERM_CHAR '[a-zA-Z0-9]*|'\\'
MULTI_CHAR '[^'\n][^'\n]+'
EMPTY_CHAR '\'
MULTILINE_COMMENT1 {SINGLELINE_COMMENT}(\\{NEWLINE}.*)+
MULTILINE_COMMENT2 "/*"({NEWLINE}|[^*]|"*"[^/])*"*/"
COMMENT_ERROR "/*"([.^"*"]*|{NEWLINE}|[^"*/"])*
UNRECOG_CHAR [#@:]




%%
{WHITESPACE} {p = p+yytext;}

{NEWLINE} {line_count++;
	p = p+yytext;}

"if"	{		
			
			//fprintf(tokenout,"<IF>");
			//fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return IF;
		}
		
"else"	{
			//fprintf(tokenout,"<ELSE>");
			//fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return ELSE;
		}

"int"		{
			//fprintf(tokenout,"<INT>");
			//fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return INT;

		}

"do"		{
			//fprintf(tokenout,"<DO>");
			//fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return DO;

		}

"float"		{
			//fprintf(tokenout,"<FLOAT>");
			//fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return FLOAT;

		}

"void"		{
			//fprintf(tokenout,"<VOID>");
			//fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return VOID;

		}

"switch"		{
			//fprintf(tokenout,"<SWITCH>");
			//fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return SWITCH;

		}

"default"		{
			//fprintf(tokenout,"<DEFAULT>");
			//fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return DEFAULT;

		}

"while"		{
			//fprintf(tokenout,"<WHILE>");
			//fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return WHILE;

		}

"break"		{
			//fprintf(tokenout,"<BREAK>");
			//fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return BREAK;

		}

"char"		{
			//fprintf(tokenout,"<CHAR>");
			//fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return CHAR;

		}

"double"		{
			//fprintf(tokenout,"<DOUBLE>");
			//fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return DOUBLE;

		}

"return"		{
			//fprintf(tokenout,"<RETURN>");
			//fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return RETURN;

		}

"case"		{
			//fprintf(tokenout,"<CASE>");
			//fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return CASE;

		}


"continue"		{
			//fprintf(tokenout,"<CONTINUE>");
			//fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);
			p = p+yytext;
			return CONTINUE;

		}

"printf" {return PRINTLN;}




"++" 		{
			//fprintf(tokenout,"<INCOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return INCOP;
		}


"--"		{
			p = p+yytext;
			return DECOP;
		}




"+" | 
"-"		{
			//fprintf(tokenout,"<ADDOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			SymbolInfo *si = new SymbolInfo(string(yytext),"ADDOP");
			yylval.sym = si;
			return ADDOP;
		}

"*" | 
"/" |
"%"		{
			//fprintf(tokenout,"<MULOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			SymbolInfo *si = new SymbolInfo(string(yytext),"MULOP");
			yylval.sym = si;
			return MULOP;
		}


"<" | 
"<=" |
">" |
">=" |
"==" |
"!=" 		{
			//fprintf(tokenout,"<RELOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			SymbolInfo *si = new SymbolInfo(string(yytext),"RELOP");
			yylval.sym = si;
			return RELOP;
		}

 
"="		{
			//fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return ASSIGNOP;
		}

"&&" | 
"||"		{
			//fprintf(tokenout,"<LOGICOP,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			SymbolInfo *si = new SymbolInfo(string(yytext),"LOGICOP");
			yylval.sym = si;
			return LOGICOP;
		}

 
"!"		{
			//fprintf(tokenout,"<NOT,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return NOT;
		}

 
"("		{
			//fprintf(tokenout,"<LPAREN,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return LPAREN;
		}

")"		{
			//fprintf(tokenout,"<RPAREN,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return RPAREN;
		}

"{"		{
			//fprintf(tokenout,"<LCURL,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return LCURL;
		}

"}"		{
			//fprintf(tokenout,"<RCURL,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return RCURL;
		}

"["		{
			//fprintf(tokenout,"<LTHIRD,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			 p = p+yytext;
			return LTHIRD;
		}

"]"		{
			//fprintf(tokenout,"<RTHIRD,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return RTHIRD;
		}


","		{
			//fprintf(tokenout,"<COMMA,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return COMMA;
		}

";"		{
			//(tokenout,"<SEMICOLON,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
			p = p+yytext;
			return SEMICOLON;
		}


{IDENTIFIER}		{
			//fprintf(tokenout,"<ID,%s>",yytext);
			//fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			p = p+yytext;
			SymbolInfo *si=new SymbolInfo(string(yytext),"ID");
			yylval.sym = si;
			return ID;
		}



		
{DIGIT}+ 		{
				//fprintf(tokenout,"<CONST_INT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				p = p+yytext;
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insertSym(*si);
				//st.printCurrentScope();
				yylval.sym = si;
				return CONST_INT;
			}



{TOO_DEC}				{
			//fprintf(logout,"Error at line no %d: Too much decimal points %s\n\n",line_count,yytext);
			//p = p+yytext;
			error_count++;
			}

{FLOAT_CONST}		{
				//fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
				p = p+yytext;
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_FLOAT");
				//st.insertSym(*si);
				//st.printCurrentScope();
				yylval.sym = si;
				//yylval = (YYSTYPE)si;
				return CONST_FLOAT;
			}

{FLOAT_CONST1}		{
				//fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
				p = p+yytext;
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_FLOAT");
				//st.insertSym(*si);
				//st.printCurrentScope();
				yylval.sym = si;
				return CONST_FLOAT;
			}



{ILL_FNUM}	{
			//fprintf(logout,"Error at line no %d: Ill formed number %s\n\n",line_count,yytext);
			error_count++;
			errorout<<"Error at line no "<<line_count<<" : Ill formed number :"<<yytext<<endl;
			}


{INVALID_ID}	{
	//fprintf(logout,"Error at line no %d: Invalid suffix on numeric constant or invalid prefix on identifier %s\n\n",line_count,yytext);
			error_count++;
			errorout<<"Error at line no "<<line_count<<" : Invalid suffix on numeric constant or invalid prefix on identifier: "<<yytext<<endl;
			}

{CHAR_CONST}		{
				//fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				p = p+yytext;
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_CHAR");

				yylval.sym = si;
				return CONST_CHAR;
			}

{UNTERM_CHAR}		{
				//fprintf(logout,"Error at line no %d: Unterminated character %s\n\n",line_count,yytext);
				error_count++;
				errorout<<"Error at line no "<<line_count<<" : Unterminated Character : "<<yytext<<endl;
			}

{EMPTY_CHAR}			{
				//fprintf(logout,"Error at line no %d: Empty character constant error %s\n\n",line_count,yytext);
				error_count++;
				errorout<<"Error at line no "<<line_count<<" : Empty character constant error : "<<yytext<<endl;
			}

{MULTI_CHAR}		{
			//fprintf(logout,"Error at line no %d: Multicharacter constant error for character sequence %s\n\n",line_count,yytext);
			error_count++;
			errorout<<"Error at line no "<<line_count<<" : Empty character constant error : "<<yytext<<endl;
			}	


{SINGLELINE_STRING}	{
				
				p = p+yytext;
				return STRING;
			}

{MULTILINE_STRING}	{
				//fprintf(tokenout,"<STRING,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",line_count,yytext);
				p = p+yytext;
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
				return STRING;
			}


{STRING_ERROR1}		{
				//fprintf(logout,"Error at line no %d: Unterminated String %s\n\n",line_count,yytext);
				error_count++;				
				

			}
		

{MULTILINE_STRINGERROR}	{
				//fprintf(logout,"Error at line no %d: Unterminated String %s\n\n",line_count,yytext);
				error_count++;
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				errorout<<"Error at line no "<<line_count<<" : Unterminated String : "<<yytext<<endl;
			}





{SINGLELINE_COMMENT}	{
				//fprintf(tokenout,"<COMMENT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
				//return COMMENT;
			}

{MULTILINE_COMMENT1}	{
				//fprintf(tokenout,"<COMMENT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
				//return COMMENT;
			}

{MULTILINE_COMMENT2}	{
				//fprintf(tokenout,"<COMMENT,%s>",yytext);
				//fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
				//return COMMENT;
			}

{COMMENT_ERROR}	{
				//fprintf(logout,"Error at line no %d: Unterminated Comment %s\n\n",line_count,yytext);
				error_count++;
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
			}




{UNRECOG_CHAR}		{
				//fprintf(logout,"Error at line no %d: Unrecognised Character %s\n\n",line_count,yytext);
				error_count++;
			}





			

%%
