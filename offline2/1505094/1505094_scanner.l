%option noyywrap

%{
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

int line_count = 1;
int error_count = 0;

FILE *logout;
FILE *tokenout;

class SymbolInfo
{
private:
    string name;
    string type;
    //SymbolInfo *next;
public:
    SymbolInfo *next;
    SymbolInfo()
    {
        name = "";
        type = "";
        next = NULL;
    }

    SymbolInfo(string n,string t)
    {
        name = n;
        type = t;
        this->next = NULL;
    }

    void setName(string n)
    {
        name = n;
    }

    void setType(string t)
    {
        type = t;
    }

    string getName()
    {
        return name;
    }

    string getType()
    {
        return type;
    }
    
};


class ScopeTable
{
    int k;
    int id;
    SymbolInfo **symbol;

public:
    ScopeTable *parentScope;
    ScopeTable()
    {
        symbol = 0;
        parentScope = 0;
        k = id = 0;
    }

    ScopeTable(int K,int ID)
    {
        k = K;
        id = ID;
        symbol = new SymbolInfo*[k];
        for (int i = 0; i < k; i++)
        {
            symbol[i]= NULL;
        }
        parentScope = new ScopeTable;
    }

    int HashFunc(string a)
    {
        int h;
        int sum = 0 ;
        string key = a;
        int length = key.length();
        for(int i=0; i< length; i++)
        {
            if(i%2==0)
            {
                sum += (int) key[i] ;
            }
            else
            {
                sum += (sum*255) + (int) key[i] ;
            }

            //sum += (int) key[i] ;
        }
        h = (sum%k);
        return h;
    }

    SymbolInfo* lookUp(string sym)
    {
        int pos = 0;
        int value = HashFunc(sym);
        SymbolInfo *temp = symbol[value];
        while(temp != NULL)
        {
            if(temp->getName() == sym)
            {
                cout<<"Found in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym)<<","<<pos<<endl;
                return temp;

            }
            temp = temp->next;
            pos++;
        }
        return NULL;


    }



    bool insertSymbol(SymbolInfo sym)
    {
        int pos = 0;
        SymbolInfo *prevSym = lookUp(sym.getName());
        if(prevSym != NULL)
        {
            return false;
        }
        else
        {
            int value = HashFunc(sym.getName());
            SymbolInfo* temp = symbol[value];
            //cout<<"hello";
            if(temp == NULL)
            {
                temp = new SymbolInfo(sym.getName(),sym.getType());
                symbol[value] = temp;
                temp->next = NULL;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym.getName())<<","<<pos<<endl;
            }
            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next;
                    pos++;
                }
                SymbolInfo *newSym = new SymbolInfo(sym.getName(),sym.getType());
                //newSym->pos = temp->pos;
                //newSym->pos++;
                newSym->next = NULL;
                temp->next = newSym;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym.getName())<<","<<pos+1<<endl;

            }
            return true;
        }
    }

    
    int getID()
    {
        return id;
    }

    void setID(int ID)
    {
        id = ID;
    }

    void printScopeTable()
    {
        cout<<"ScopeTable#"<<getID()<<endl;
	fprintf(logout,"Scopetable#%d\n",getID());
        for(int i = 0; i < k; i++)
        {
           
		SymbolInfo *temp = symbol[i];
		if(symbol[i]!= NULL){
            		cout<<i<<":-->  ";
			fprintf(logout,"%d :---> ",i);
            			while(temp != NULL)
            			{
                			cout<<"<"<<temp->getName()<<","<<temp->getType()<<">"<<" ";
					fprintf(logout,"<%s,%s>",temp->getName().c_str(),temp->getType().c_str());
                			temp = temp->next;
            			}
            			cout<<endl;
	    			fprintf(logout,"\n");
			}
        	}
     }



};

class SymbolTable
{
private:
    ScopeTable *currentScope;
    int m;
    int scopeTableNO;

public:
    SymbolTable()
    {
        m = 0;
        //scope = 0;
        currentScope = 0;
        scopeTableNO = 0;
    }

    SymbolTable(int n)
    {
        m = n;
        //CurrentScope = 0;
        scopeTableNO = 1;
        currentScope = new ScopeTable(m,scopeTableNO);
        currentScope->parentScope = NULL;
    }

    bool insertSym(SymbolInfo sym)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            return false;
        }
        bool a = currentScope->insertSymbol(sym);
        if(a == true)
        {
            return true;
        }
        else
        {
            cout<<"<"<<sym.getName()<<","<<sym.getType()<<">"<<"already exists in current ScopeTable"<<endl;
            return false;
        }
    }

    SymbolInfo *lookUp(string sym)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            //return false;
        }
        SymbolInfo *temp = new SymbolInfo();
        //temp = currentScope->lookUp(sym);
        ScopeTable *sc = new ScopeTable;
        sc = currentScope;
        while(sc != NULL)
        {
            temp = sc->lookUp(sym);
            if(temp != NULL)
            {
                //cout<<"Found in ScopeTable #"<<sc->getID()<<" at position "<<currentScope->HashFunc(sym)<<","<<pos<<endl;
                break;
            }
            sc = sc->parentScope;
        }
        /*if(temp == NULL){
            cout<<"Not found"<<endl;
        }*/
        return temp;
    }



    void printCurrentScope()
    {
        if(currentScope != NULL)
        {
            currentScope->printScopeTable();
        }
        else
        {
            cout<<"No ScopeTable is present"<<endl;
        }
    }

    void printAll()
    {
        ScopeTable *sc = new ScopeTable;
        sc = currentScope;
        while(sc != NULL)
        {
            sc->printScopeTable();
            sc = sc->parentScope;
        }
    }


};

SymbolTable st(7);

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

{NEWLINE} {line_count++;}

"if"	{		
			
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n\n",line_count,yytext);
		}

"int"		{
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n\n",line_count,yytext);

		}

"do"		{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n\n",line_count,yytext);

		}

"float"		{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n\n",line_count,yytext);

		}

"void"		{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n\n",line_count,yytext);

		}

"switch"		{
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n\n",line_count,yytext);

		}

"default"		{
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n\n",line_count,yytext);

		}

"while"		{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n\n",line_count,yytext);

		}

"break"		{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n\n",line_count,yytext);

		}

"char"		{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n\n",line_count,yytext);

		}

"double"		{
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n\n",line_count,yytext);

		}

"return"		{
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n\n",line_count,yytext);

		}

"case"		{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n\n",line_count,yytext);

		}


"continue"		{
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n\n",line_count,yytext);

		}

"struct"		{
			fprintf(tokenout,"<STRUCT>");
			fprintf(logout,"Line no %d: TOKEN <STRUCT> Lexeme %s found\n\n",line_count,yytext);

		}

"typedef"		{
			fprintf(tokenout,"<TYPEDEF>");
			fprintf(logout,"Line no %d: TOKEN <TYPEDEF> Lexeme %s found\n\n",line_count,yytext);

		}

"union"		{
			fprintf(tokenout,"<UNION>");
			fprintf(logout,"Line no %d: TOKEN <UNION> Lexeme %s found\n\n",line_count,yytext);

		}

"unsigned"		{
			fprintf(tokenout,"<UNSIGNED>");
			fprintf(logout,"Line no %d: TOKEN <UNSIGNED> Lexeme %s found\n\n",line_count,yytext);

		}


"+=" | 
"-="		{
			fprintf(tokenout,"<ADDASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDASSIGN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}



"++" | 
"--"		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}







"+" | 
"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"*" | 
"/" |
"%"		{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}


"<" | 
"<=" |
">" |
">=" |
"==" |
"!=" 		{
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

 
"="		{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"&&" | 
"||"		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"&" | 
"|" |
"^" |
"<<" |
">>"		{
			fprintf(tokenout,"<BITOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

 
"!"		{
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

 
"("		{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

")"		{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"{"		{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"}"		{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"["		{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"]"		{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}


","		{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

";"		{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}


{IDENTIFIER}		{
			fprintf(tokenout,"<ID,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			SymbolInfo *si=new SymbolInfo(string(yytext),"ID");
			st.insertSym(*si);
			st.printCurrentScope();
		}



		
{DIGIT}+ 		{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				st.insertSym(*si);
				st.printCurrentScope();
			}



{TOO_DEC}				{
			fprintf(logout,"Error at line no %d: Too much decimal points %s\n\n",line_count,yytext);
			error_count++;
			}

{FLOAT_CONST}		{
				fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_FLOAT");
				st.insertSym(*si);
				st.printCurrentScope();
			}

{FLOAT_CONST1}		{
				fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n\n",line_count,yytext);
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_FLOAT");
				st.insertSym(*si);
				st.printCurrentScope();
			}



{ILL_FNUM}	{
			fprintf(logout,"Error at line no %d: Ill formed number %s\n\n",line_count,yytext);
			error_count++;
			}


{INVALID_ID}	{
	fprintf(logout,"Error at line no %d: Invalid suffix on numeric constant or invalid prefix on identifier %s\n\n",line_count,yytext);
			error_count++;
			}

{CHAR_CONST}		{
				fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_CHAR");
				st.insertSym(*si);
				st.printCurrentScope();
			}

{UNTERM_CHAR}		{
				fprintf(logout,"Error at line no %d: Unterminated character %s\n\n",line_count,yytext);
				error_count++;
			}

{EMPTY_CHAR}			{
				fprintf(logout,"Error at line no %d: Empty character constant error %s\n\n",line_count,yytext);
				error_count++;
			}

{MULTI_CHAR}		{
			fprintf(logout,"Error at line no %d: Multicharacter constant error for character sequence %s\n\n",line_count,yytext);
			error_count++;
			}	


{SINGLELINE_STRING}	{
				fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				
				fprintf(tokenout,"<STRING,%s>",s.c_str());
				
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
			}

{MULTILINE_STRING}	{
				fprintf(tokenout,"<STRING,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
			}


{STRING_ERROR1}		{
				fprintf(logout,"Error at line no %d: Unterminated String %s\n\n",line_count,yytext);
				error_count++;				


			}
		

{MULTILINE_STRINGERROR}	{
				fprintf(logout,"Error at line no %d: Unterminated String %s\n\n",line_count,yytext);
				error_count++;
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
			}





{SINGLELINE_COMMENT}	{
				fprintf(tokenout,"<COMMENT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
			}

{MULTILINE_COMMENT1}	{
				fprintf(tokenout,"<COMMENT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
			}

{MULTILINE_COMMENT2}	{
				fprintf(tokenout,"<COMMENT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n\n",line_count,yytext);
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
				//insert in symbol table and print symbol table content(only non empty buckets)
				//SymbolInfo *si=new SymbolInfo(string(yytext),"CONST_INT");
				//st.insert(si);
			}

{COMMENT_ERROR}	{
				fprintf(logout,"Error at line no %d: Unterminated Comment %s\n\n",line_count,yytext);
				error_count++;
				string s = string(yytext);
				for(int i = 0; i<s.length();i++){
					if(s[i] == '\n') {line_count++;}
				}
			}




{UNRECOG_CHAR}		{
				fprintf(logout,"Error at line no %d: Unrecognised Character %s\n\n",line_count,yytext);
				error_count++;
			}





			

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("1505094_log.txt","w");
	tokenout= fopen("1505094_token.txt","w");

	yyin= fin;
	yylex();
	fprintf(logout,"Total lines : %d\n",line_count-1);
	fprintf(logout,"Total errors : %d\n",error_count);
	//st.print();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
