%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include "1505094_SymbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

extern char *yytext;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
string aaa;
string aab;
string aac;
string aad;
string aae;
string aaf;
string unit;
string comp_code;
string stmts1;
string func_var;
string param;
string var_dec;
string func_dec;
string func_def;
string stmt;
string stmts;
string comp_stmt;
string expr_stmt;
string expr;
string logic_expr;
string rel_expr;
string simp_expr;
string term;
string una_expr;
string fac;
string VAR;
string v_incop;
string v_decop;
string args;
SymbolTable st(30);
vector<string> variable;
vector<string> array;
vector<string> arraysize;
vector<string> args_name;
vector<string> args_type; 
bool funcDef = false;
extern int line_count;
int semanticErrors = 0;
//SymbolInfo *symbol; 
string var;
extern string p;
ofstream logout,fout;
extern ofstream errorout;

int labelCount=0;
int tempCount=0;


char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}

void yyerror(const char *s)
{
	//write your code
}


%}
%union{
SymbolInfo* sym;
}

%token IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT INCOP DECOP ASSIGNOP LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA STRING NOT PRINTLN  
%token <sym>ID 
%token <sym>CONST_INT 
%token <sym>CONST_FLOAT 
%token <sym>CONST_CHAR 
%token <sym>ADDOP
%token <sym>MULOP
%token <sym>LOGICOP
%token <sym>RELOP

%type <sym>type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable expression_statement compound_statement statement statements func_declaration func_definition parameter_list declaration_list arguments unit program var_declaration argument_list
%nonassoc lower_than_else
%nonassoc ELSE
%error-verbose
%%



start : program{
		//fprintf(log,"Line %d : start : program\n\n",line_count);
		logout<<"Line "<<line_count<<" : start program\n"<<endl;
		//ofstream fout;
		//fout.open("code.asm");
		//fout << $1->code;
		$1->code+= "\n\ndecimal_out endp\n\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tor ax,ax\n \tjge enddif\n\tpush ax\n\tmov dl,'-'\n\tmov ah,2\n\tint 21h\n\tpop ax\n\tneg ax\nenddif:\n\txor cx,cx\n\tmov bx,10d\nrepeat:\n\txor dx,dx\n\tdiv bx\n\t push dx\n\tinc cx\n\tor ax,ax\n\tjne repeat\n\tmov ah,2\nprint_loop:\n\tpop dx\n\tor dl,30h\n\tint 21h\n\tloop print_loop\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n\ndecimal_out endp\n";
		fout<<".model small\n"<<endl;
		fout<<".stack 100h\n"<<endl;
		fout<<".data\n"<<endl;
		fout<<"ret DW ?"<<endl;
		for(int i = 0; i < variable.size();i++){
		    fout<<variable[i]<< " DW ?"<<endl;
		}
		for(int i = 0; i < array.size();i++){
		    fout<<array[i]<< " DW "<<arraysize[i] <<" dup(?)"<<endl;
		}
		fout<<$1->code<<endl;
		
		}
		;

program : program unit {
		logout<<"Line "<<line_count<<" : program : program unit\n"<<endl;
		logout<<p<<endl;		
		$$ = $2;
		$$->code += $1->code;
		}
	| unit{
		logout<<"Line "<<line_count<<" : program : unit\n"<<endl;
		logout<<p<<endl;
		$$ = $1;
	}
	;
	
unit : var_declaration{
		logout<<"Line "<<line_count<<" : unit : var_declaration\n"<<endl;
		unit = var_dec;
		logout<<unit<<endl;
		var_dec = "\0";
		$$ = $1;
		}
     | func_declaration{
		//fprintf(log,"Line %d : func_declaration\n\n",line_count);
		logout<<"Line "<<line_count<<" : unit : func_declaration\n"<<endl;
		unit = func_dec;
		logout<<unit<<endl;
		func_dec = "\0";
		$$ = $1;
		}

     | func_definition{
		
		logout<<"Line "<<line_count<<" : unit : func_definition\n"<<endl;
		unit = func_def;
		logout<<unit<<endl;
		func_def = "\0";
		$$ = $1;
		}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
		logout<<"Line "<<line_count<<" : func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"<<endl;
		func_dec =$1->getvarType()+" "+ $2->getName()+"("+param+")"+";";
		logout<<func_dec<<endl<<endl;
		//param = "\0";
		SymbolInfo *s = st.lookUp($2->getName(),"function");
		//logout<<s->getidType()<<endl;
		if(s != NULL ){//&& s->getidType() == "function" && s->getvarType() == $1->getvarType()){
			errorout<<"Error at line : "<<line_count<<" : function already declared"<<endl;
			semanticErrors++;
		}
		else{
			$2->setType("ID");
			SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"function",$1->getvarType());
			si->setvarType($1->getvarType());
			si->setidType("function");
			si->setreturnType(si->getvarType());
			/*for(int i = 0; i < args_name.size();i++){
			     logout<<args_name[i]<<args_type[i]<<endl;
			}*/
			for(int i = 0; i < args_name.size();i++){
			     si->param_list.push_back(args_name[i]);
			     si->param_type.push_back(args_type[i]);
			}
			st.insertSym(si);
			//logout<<si->param_list.size()<<endl;
			args_name.clear();
			args_type.clear();
		}
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON
		{
		func_dec = $1->getvarType()+" "+ $2->getName()+"()"+";";
		logout<<"Line "<<line_count<<" : func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n"<<endl;	
		logout<<func_dec<<endl<<endl;
		SymbolInfo *s = st.lookUp($2->getName(),"function");
		//logout<<s->getidType()<<endl;
		if(s != NULL ){
			errorout<<"Error at line : "<<line_count<<" : function already declared"<<endl;
			semanticErrors++;
		}
		else{
			$2->setType("ID");
			SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"function",$1->getvarType());
			si->setvarType($1->getvarType());
			si->setidType("function");
			si->setreturnType(si->getvarType());
			st.insertSym(si);
			st.printAll(logout);
		}
		//$$ = si;
		}
		|type_specifier ID LPAREN parameter_list RPAREN error
		{
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
		|type_specifier ID LPAREN RPAREN error
		{
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN{SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"function",$1->getvarType());
		
		si->setreturnType(si->getvarType());
		for(int i = 0; i < args_name.size();i++){
			si->param_list.push_back(args_name[i]);
			si->param_type.push_back(args_type[i]);
		}
		st.insertSym(si);
		func_var = $1->getName();
		} compound_statement{
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<< endl;
		func_def = $1->getvarType() + " " + $2->getName() + "("+param+")"+$7->str;
		logout<<func_def<<endl<<endl;
		$$->code += $2->getName() + " proc \n\t";
		$$->code += $7->code;
		$$->code+=$2->getName() + " endp\n\n";
		//fout<<$$->code<<endl;
		
		}
		| type_specifier ID LPAREN RPAREN{$2->setType("ID");
		SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"function",$1->getvarType());
		si->setreturnType(si->getvarType());
		//si->setidType("function");
		st.insertSym(si);
		st.printAll(logout);} compound_statement{
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<< endl;
		func_def = $1->getvarType() + " " + $2->getName() + "()"+comp_stmt;
		logout<<func_def<<endl<<endl;
		$$->code += $2->getName() + " proc\n";
		$$->code += $6->code+"\n\t";
		if($2->getName() == "main"){
			$$->code += "mov ah,4ch\n\tint 21h\n";
		}
		$$->code+=$2->getName() + " endp\n\n" ;
		//fout<<$$->code<<endl;
		//fprintf(log,"Line %d : type_specifier ID LPAREN RPAREN compound_statement\n\n",line_count);
		
		}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID{
		logout << "Line " << line_count << " : parameter_list : parameter_list COMMA type_specifier ID\n"<< endl;
		//logout<<$4->getName()<<endl<<endl;
		param = param+","+$3->getvarType()+" "+$4->getName();;
		logout<<param<<endl;
		args_name.push_back($4->getName());
		args_type.push_back($3->getvarType());
		//fprintf(log,"Line %d : parameter_list COMMA type_specifier ID\n\n",line_count);
		}
		| parameter_list COMMA type_specifier{
		logout << "Line " << line_count << " : parameter_list : parameter_list COMMA type_specifier\n"<< endl;
		//fprintf(log,"Line %d : parameter_list COMMA type_specifier\n\n",line_count);
		}
 		| type_specifier ID
		{
		logout << "Line " << line_count << " : parameter_list : type_specifier ID\n"<< endl;
		param = $1->getvarType()+" "+$2->getName();
		logout<<param<<endl;
		args_name.push_back($2->getName());
		args_type.push_back($1->getvarType());
		}
		| type_specifier{
		logout << "Line " << line_count << " : parameter_list : type_specifier\n"<< endl;
		logout<<$1->getvarType()<<endl<<endl;
		//fprintf(log,"Line %d : type_specifier\n\n",line_count);
		}
 		;

 		
compound_statement : LCURL{st.enterScope(logout);
			for(int i = 0; i < args_name.size(); i++){
			     SymbolInfo *si = new SymbolInfo(args_name[i],"ID","variable",args_type[i]);
			     st.insertSym(si);
			}
			args_name.clear();
			args_type.clear();} statements RCURL{st.printAll(logout);st.exitScope(logout);}{
		logout << "Line " << line_count << " : compound_statement : LCURL statements RCURL\n"<< endl;
		comp_stmt = "{\n   "+$3->str+"}\n";
		logout<<comp_stmt<<endl;
		stmts = "\0";
		$$ = $3;
		$$->str = comp_stmt;
		//fout<<$$->code<<endl;
		}
 		    | LCURL RCURL{logout << "Line " << line_count << " : compound_statement : LCURL RCURL\n"<< endl;}
		    
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON{
		var_dec = $1->getvarType() + " "+var_dec +";";
	
		if(var == "void"){
			logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
		}else{
		logout << "Line " << line_count << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
		logout<<var_dec<<endl; 
		
			}
		}
		|type_specifier declaration_list error{
			logout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
 		 ;
 		 
type_specifier	:VOID 
        {logout << "Line " << line_count << " type_specifier: VOID 	:\n"<< endl;
	//logout<<"void "<<endl<<endl;
	SymbolInfo *si = new SymbolInfo();
	var = "void";
	si->setvarType("void");
	$$ = si;
	logout<<"void"<<endl;
	}
 		| FLOAT
 		{logout << "Line " << line_count << " type_specifier	: FLOAT:\n"<< endl;
		//logout<<"float "<<endl<<endl;
		SymbolInfo *si = new SymbolInfo();
		var = "float";
		si->setvarType("float");
		$$ = si;
		logout<<var<<endl;}
 		| INT
 		{logout << "Line " << line_count << " type_specifier: INT:\n"<< endl;
		//logout<<"int "<<endl<<endl;
		SymbolInfo *si = new SymbolInfo();
		var = "int";
		si->setvarType("int");
		$$ = si;
		logout<<var<<endl;}
 		;
 		
declaration_list : declaration_list COMMA ID{
		logout<<"Line "<<line_count<<": declaration_list : declaration_list COMMA ID"<<endl<<endl;
		//logout<<","<<$3->getName()<<endl<<endl;
		var_dec = var_dec + "," + $3->getName();
		logout<<var_dec<<endl<<endl;
		if(var == "void"){
		   errorout<<"Error at line "<<line_count<<" : variable cannot be void"<<endl;
			semanticErrors++;
		}
		SymbolInfo *s = st.lookUp($3->getName(),"variable");
		if(s != NULL){
			errorout<<"Error at line : "<<line_count<<" variable already declared "<<endl;
			semanticErrors++;
		}
		else{
			$3->setType("ID");
			SymbolInfo *si = new SymbolInfo($3->getName(),$3->getType(),"variable",var);
			si->setidType("variable");
			st.insertSym(si);
			
		}
		}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
		var_dec = var_dec + "," + $3->getName()+"["+$5->getName()+"]";
		logout<<var_dec<<endl;
		if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			SymbolInfo *s = st.lookUp($3->getName(),"array");
			if(s != NULL){
				errorout<<"Error at line : "<<line_count<<": array already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			logout<<"Line "<<line_count<<": declaration_list COMMa ID LTHIRD CONST_INT RTHIRD"<<endl<<endl;
			logout<<p<<endl<<endl;
			SymbolInfo *si = new SymbolInfo();
			si = $3;
			si->setidType("array");
			si->setvarType(var);
			si->setarraySize(atoi($5->getName().c_str()));
			st.insertSym(si);
			arraysize.push_back($5->getName());
			string t;
			int y = st.getScopeNum();       
			ostringstream conv;  
			conv << y;    
			t = conv.str();
			$$->setSymbol($3->getName()+t);
			array.push_back($$->getSymbol());
			//arraysize.push_back($3->getName());
			
			}	
			
			} 
		}
 		  | ID{
			var_dec = $1->getName();
			if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			logout<<"Line "<<line_count<<": declaration_list : ID"<<endl<<endl;
			logout<<var_dec<<endl;
			//logout<<$1->getName()<<endl<<endl;
			SymbolInfo *s = st.lookUp($1->getName(),"variable");
			if(s != NULL){
			    errorout<<"Error at line : "<<line_count<<": variable already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			$1->setType("ID");
			SymbolInfo *si = new SymbolInfo($1->getName(),$1->getType(),"variable",var);
			//si->setvarType($1->getvarType());
			si->setidType("variable");
			//si->returnType()
			st.insertSym(si);
			//st.printAll(logout);
			
		}	//$$ = $1;
}
			}
 		  | ID LTHIRD CONST_INT RTHIRD{
			var_dec = $1->getName()+"["+$3->getName()+"]";
			logout<<var_dec<<endl;
			if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			SymbolInfo *s = st.lookUp($1->getName(),"array");
			if(s != NULL){
				errorout<<"Error at line : "<<line_count<<": array already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			logout<<"Line "<<line_count<<": declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl<<endl;
			//logout<<$1->getName()<<"["<<$3->getName()<<"]"<<endl<<endl;
			SymbolInfo *si = new SymbolInfo($1->getName(),$1->getType());
			si = $1;
			si->setidType("array");
			si->setarraySize(atoi($3->getName().c_str()));
			si->setvarType(var);
			st.insertSym(si);
			int y = st.getScopeNum();
			string t;       
			ostringstream conv;  
			conv << y;    
			t = conv.str();
			$$->setSymbol($1->getName()+t);
			array.push_back($$->getSymbol());
			arraysize.push_back($3->getName());
			//$$ = si;
			//st.printAll(logout);
			
			}	
			
			} 
		}
		  | ID LTHIRD CONST_FLOAT RTHIRD{
		errorout<<"error at line : "<<line_count<<": array index cannot be a float"<<endl<<endl;
		semanticErrors++;
		}
		  | ID LTHIRD CONST_INT error{
			errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;
		}
		  | declaration_list COMMA ID LTHIRD CONST_INT error{
			errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;		
		}
 		  ;
 		  
statements : statement{
		logout<<"Line "<<line_count<<": statements : statement"<<endl<<endl;
		stmts=$1->str;
		logout<<stmt<<endl;
		stmt = "\0";
		$$ = $1;
		$$->str = stmts;
		//stmts = "\0";
		}
	   | statements statement{
		logout<<"Line "<<line_count<<": statements : statements statement"<<endl<<endl;
		stmts = $1->str + $2->str;
		//stmts1 = stmts1 + stmts;
		logout<<stmts<<endl<<endl;
		//logout<<stmts1<<endl;
		//s = stmts;
		stmt = "\0";
		//$$ = $1;
		$$->code = $1->code+$2->code;
		$$->str = stmts;;
		}
	   ;
	   
statement : var_declaration{
		logout<<"Line "<<line_count<<": statement : var_declaration"<<endl<<endl;
		stmt = var_dec;
		logout<<stmt<<endl;
		var_dec = "\0";
		$$->str = stmt;
		}
	  | expression_statement{
		logout<<"Line "<<line_count<<": statement : expression_statement"<<endl<<endl;
		stmt = expr_stmt;
		logout<<stmt<<endl;
		expr_stmt = "\0";
		$$->str = stmt;
		$$->code = $1->code;
		}
	  | compound_statement{
		logout<<"Line "<<line_count<<": statement : compound_statement"<<endl<<endl;
		stmt = comp_stmt;
		logout<<stmt<<endl;
		$$->str = stmt;
		$$ = $1;
		}
	  | FOR LPAREN expression_statement expression_statement expression{aaa = expr;aae = $5->code;} RPAREN statement{
		logout<<"Line "<<line_count<<": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl<<endl;
		//$$->setName(stmt);
		stmt = "for(" + $3->str + $4->str + aaa +")" + $8->str;
		logout<<stmt<<endl;
		$$ = $3;
		char *start = newLabel();
		char *exit = newLabel();
		$$->code += string(start) + ":\n";
		$$->code+=$4->code;
		$$->code+="\tmov ax , "+$4->getSymbol()+"\n";
		$$->code+="\tcmp ax , 0\n";
		$$->code+="\tje "+string(exit)+"\n";
		$$->code+=$8->code;
		$$->code+=aae+"\n";
		$$->code+="\tjmp "+string(start)+"\n";
		$$->code+=string(exit)+":\n";
		//fout<<$$->code<<endl;
		$$->str = stmt;
		
	}	
	  | IF LPAREN expression RPAREN statement %prec lower_than_else{
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "if(" + $3->str + ")" + $5->str;
		logout<<stmt<<endl;
		$$ = $3;
		char *label = newLabel();
		$$->code += "mov ax, "+$3->getSymbol()+"\n\t";
		$$->code += "cmp ax, 0\n\t";
		$$->code += "je "+string(label)+"\n";
		$$->code += $5->code;
		$$->code += string(label)+":\n";
		$$->str = stmt;
		//fout<<$$->code<<endl;
	
	}
	  | IF LPAREN expression RPAREN statement ELSE  statement{
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl;
		stmt = "if(" + $3->str + ")" + $5->str + "\nelse\n"+$7->str;
		logout<<stmt<<endl;
		$$ = $3;
		char *Else = newLabel();
		char *exit = newLabel();
		$$->code += "mov ax, "+ $3->getSymbol() +"\n\t";
		$$->code += "cmp ax, 0\n\t";
		$$->code += "je "+ string(Else)+"\n";
		$$->code += $5->code + "\n\t";
		$$->code += "jmp " + string(exit) +"\n";
		$$->code += string(Else)+":\n\t";
		$$->code += $7->code+"\n";
		$$->code += string(exit);
		$$->str = stmt;
		//fout<<$$->code<<endl;
		
	}
	  | WHILE LPAREN expression{aab = expr;aac = $3->code;} RPAREN statement{
		logout<<"Line "<<line_count<<": statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "while(" + aab + ")" + $6->str;
		$$->str = stmt;
		logout<<stmt<<endl;
		char *startLoop = newLabel();
		char *endLoop = newLabel();
		//$$ = $3;
		$$->code += string(startLoop)+":\n";
		$$->code += aac+"\n\t";
		$$->code += "mov ax, " + $3->getSymbol() + "\n\t";
		$$->code += "cmp ax, 0\n\t";
		$$->code += "je " + string(endLoop) + "\n\t";
		$$->code += $6->code+"\n\t";
		$$->code += "jmp "+string(startLoop)+"\n";
		$$->code += string(endLoop)+":\n\t";
		
		//fout<<$$->code<<endl;
	}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{
		logout<<"Line "<<line_count<<": statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl<<endl;
		stmt = "printf(" + $3->getName()+");\n";
		$$->str = stmt;
		logout<<stmt<<endl;
		$$->code += "\tmov ax, " + $3->getName() +"\n";
		$$->code += "\tcall decimal_out\n";
	} 
	  | PRINTLN LPAREN ID RPAREN error{
		errorout << "Error at line " << line_count << "; missing" << endl << endl;
		semanticErrors++;
	}
	  | RETURN expression SEMICOLON{
		logout<<"Line "<<line_count<<": statement : RETURN expression SEMICOLON"<<endl<<endl;
		stmt = "return "+  $2->str +";";
		logout<<stmt<<endl;
		expr = "\0";
		$$->str = stmt;	
		$$->code = $2->code;
		$$->code+= "\tmov ret, ax\n";
		
	}
	| RETURN expression error{
		errorout << "Error at line " << line_count << "; missing" << endl << endl;
		semanticErrors++;
	}
	  ;
	  
expression_statement 	: SEMICOLON{
		logout<<"Line "<<line_count<<": expression_statement : SEMICOLON"<<endl<<endl;
		//logout<<";"<<endl<<endl;
		expr_stmt = expr_stmt + ";\n";
		logout<<expr_stmt<<endl;
		//$$->setName(expr_stmt);
	}			
			| expression SEMICOLON{
		logout<<"Line "<<line_count<<": expression_statement : expression SEMICOLON"<<endl<<endl;
		expr_stmt = $1->str +";\n";
		SymbolInfo *si = new SymbolInfo();
		si->str = expr_stmt;
		logout<<expr_stmt<<endl;
		$$ = si;
		$$->code = $1->code;
		expr = "\0";
		
	}| expression error{
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
			;
	  
variable : ID{
	logout<<"Line "<<line_count<<": variable : ID"<<endl<<endl;
	VAR = $1->getName();
	logout<<VAR<<endl;
	//VAR = "\0";
	logout<<$1->getName()<<endl<<endl;
	$1->setidType("variable");
	//char *temp = newTemp();
	SymbolInfo *s = st.lookUp($1->getName(),"variable");
	if(s == NULL){
		errorout<<"Error at line "<<line_count<<" : variable "<<VAR<<" was not declared in this scope"<<endl;
		semanticErrors++;
	}
	else{
		$$ = s;
		//logout<<s->ival<<endl;
		$$->setVal(s->ival);
		$$->setName($1->getName());
		$$->code="";
		int y = st.getScopeNum();
		string t;       
		ostringstream conv;  
		conv << y;    
		t = conv.str();
		$$->setSymbol($$->getName()+t);
		variable.push_back($$->getSymbol());
		$$->str = VAR;
	}
	//st.printAll(logout);
	}		
	 | ID LTHIRD expression RTHIRD {
	logout<<"Line "<<line_count<<": variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
	VAR = $1->getName() + "[" + expr + "]";
	logout<<VAR<<endl;
	logout<<$3->getName()<<endl;
	expr = "\0";
	SymbolInfo *si = st.lookUp($1->getName(),"array");
	if(si != NULL){
		if($3->getvarType() == "float"){
	  	 errorout<<"Error at line "<<line_count<<" : array index cannot be a float"<<endl<<endl;
		 semanticErrors++;
		}
		$$ = si;
		//$$->code="";
		int y = st.getScopeNum();
		string t;       
		ostringstream conv;  
		conv << y;    
		t = conv.str();
		$1->setSymbol($1->getName()+t);
		$$->setSymbol($1->getSymbol());
		//array.push_back($1->getSymbol());
		$$->arraySym = $1->getSymbol()+"[bx]";
		$$->code=$3->code+"\tmov bx, " +$3->getName() +"\n\tadd bx, bx\n";
		//$$->code += "mov ax, "+$$->arraySym+"\n";
		delete $3;
		//$$->arraySym = $1->getSymbol()+"[bx]";
		}
		$$->str = VAR;
		//logout<<$$->getName()<<endl;
}
	| ID LTHIRD expression error {
		errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;
	}
	 ;
	 
 expression : logic_expression	{
		logout<<"Line "<<line_count<<": expression : logic_expression	"<<endl<<endl;
		expr = logic_expr;
		logout<<expr<<endl;
		logic_expr = "\0";
		//expr = "\0";
		
		$$ = $1;
		$$->str = expr;
	}
	   | variable ASSIGNOP logic_expression {
		logout<<"Line "<<line_count<<": expression : variable ASSIGNOP logic_expression"<<endl<<endl;
		expr = VAR + "=" + logic_expr;
		logout<<expr<<endl;
		
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		
		if(si != NULL){
		si->setvarType($1->getvarType());
		si->code = $3->code + $1->code;
		si->code +="\tmov ax, "+$3->getSymbol()+"\n";
		si->code+= "\tmov "+ $1->getSymbol()+", ax\n";
		//$$->code=$3->code+$1->code;
	if(si->getvarType() == "variable"){
		if(si->getvarType() == "int"){
			if($3->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if($3->getvarType() == "int"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
	}else if($1->getidType() == "array"){
		if(si->getvarType() == "int"){
			if($3->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if($3->getvarType() == "int"){
			    logout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			}
		   	
		}
	
	}
	if($3->getidType() == "function" && $3->getvarType() == "void"){errorout<<"Error at line "<<line_count<<" : "<<logic_expr<<" does not return anything"<<endl;semanticErrors++;}
	logic_expr = "\0";
	$$ = si;
	$$->str = expr;
	//fout<<$$->code<<endl;
	}}
		//$$ = si;
		
	;
			
logic_expression : rel_expression {

		logout<<"Line "<<line_count<<": logic_expression : rel_expression"<<endl<<endl;
		logic_expr = rel_expr;
		logout<<logic_expr<<endl;
		rel_expr = "\0";
		$$ = $1;
		$$->str = logic_expr;
		
	}	
		 | rel_expression LOGICOP rel_expression{
		logout<<"Line "<<line_count<<": logic_expression : rel_expression LOGICOP rel_expression"<<endl<<endl;
		logic_expr = $1->str +" "+ $2->getName() +" "+ $3->str;
		logout<<logic_expr<<endl;
		rel_expr = "\0";
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		si->setidType("variable");
		//$$=si;
		si->code = $1->code;
		si->code+=$3->code;
		char *L1 = newLabel();
		char *L2 = newLabel();
		char *temp = newTemp();
		if($2->getName() == "&&"){
		   si->code += "\tmov ax, " + $1->getSymbol() + "\n\t";
		   si->code = si->code + "cmp ax, 0\n\t";
		   si->code = si->code + "je " + string(L1) + "\n\t";
		   si->code = si->code +  "mov ax, " + $3->getSymbol() + "\n\t";
		   si->code = si->code + "cmp ax, 0\n\t";
		   si->code = si->code + "je " + string(L1) + "\n\t";
		   si->code = si->code +  "mov " + string(temp) + ", 1\n\t";
		   si->code = si->code + "jmp " + string(L2) +"\n";
		   si->code = si->code + string(L1) + ":\n\t";
		   si->code = si->code +  "mov " + string(temp) + ", 0\n";
		   si->code = si->code + string(L2) + ":\n\t";
		//fout<<si->code<<endl;
		}
		else if($2->getName() == "||"){
		   si->code += "\tmov ax, " + $1->getSymbol() + "\n\t";
		   si->code = si->code + "cmp ax, 0\n\t";
		   si->code = si->code + "jne " + string(L1) + "\n\t";
		   si->code = si->code +  "mov ax, " + $3->getSymbol() + "\n\t";
		   si->code = si->code + "cmp ax, 0\n\t";
		   si->code = si->code + "je " + string(L1) + "\n\t";
		   si->code = si->code +  "mov " + string(temp) + ", 0\n\t";
		   si->code = si->code + "jmp " + string(L2) +"\n";
		   si->code = si->code + string(L1) + ":\n\t";
		   si->code = si->code +  "mov " + string(temp) + ", 1\n";
		   si->code = si->code + string(L2) + ":\n\t";
		
		   
		}
		si->setSymbol(string(temp));
		$$ = si;
		//fout<<$$->code<<endl;
		$$->str = logic_expr;
	}	
		 ;
			
rel_expression	: simple_expression {
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression"<<endl<<endl;
		rel_expr = $1->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		$$ = $1;
		$$->str = rel_expr;
		}
		| simple_expression RELOP simple_expression{
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression RELOP simple_expression"<<endl<<endl;
		rel_expr = $1->str +" "+ $2->getName() +" "+ $3->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		SymbolInfo *si = new SymbolInfo();
		$$ = $1;
		$$->setvarType("int");
		$$->setidType("variable");
		
		$$->code+=$3->code;
		$$->code+="\tmov ax, " + $1->getSymbol()+"\n";
		$$->code+="\tcmp ax, " + $3->getSymbol()+"\n";
		char *temp=newTemp();
		char *label1=newLabel();
		char *label2=newLabel();
		if($2->getName() == "=="){
		     if($1->getvarType() == $3->getvarType() ){
			     $$->code+="\tje "+ string(label1)+"\n";
			}
		    else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		 else if($2->getName() == "!="){
		     if($1->getvarType() == $3->getvarType() ){
			$$->code+="\tjne "+ string(label1)+"\n";
		}
		     else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		else if($2->getName() == ">"){
			$$->code+="\tjg "+ string(label1)+"\n";
		}
		else if($2->getName() == ">="){
			$$->code+="\tjge "+ string(label1)+"\n";
		}
		else if($2->getName() == "<"){
			$$->code+="\tjl "+ string(label1)+"\n";
		}
		else if($2->getName() == "<="){
			$$->code+="\tjle "+ string(label1)+"\n";
		}
		//$$ = si;
		$$->str = rel_expr;
		$$->code+="\tmov "+string(temp) +", 0\n\tjmp "+string(label2) +"\n"+string(label1)+":\n\tmov "+string(temp)+", 1\n";
		$$->code+=string(label2)+":\n";
		$$->setSymbol(temp);
		variable.push_back($$->getSymbol());
		//fout<<$$->code<<endl;
		
	}	
		;
				
simple_expression : term {
		logout<<"Line "<<line_count<<": simple_expression : term"<<endl<<endl;
		simp_expr = term;
		logout<<simp_expr<<endl;
		term = "\0";
		$$ = $1;
		$$->str = simp_expr;
		if($1->getType() == "ID"){simp_expr = "\0";}
		//$$->setName(simp_expr);
		simp_expr = "\0";
	}
		  | simple_expression ADDOP term {
		logout<<"Line "<<line_count<<": simple_expression : simple_expression ADDOP term "<<endl<<endl;
		simp_expr = $1->str + $2->getName()+term;
		logout<<simp_expr<<endl;
		term = "\0";
		$$ = $1;
		$$->code += $3->code;
		char* temp = newTemp();
		if($2->getName() == "+"){
			if($1->getvarType() == "int" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
		        
			$$->code += "\tmov ax, " + $1->getSymbol() + "\n\tadd ax, " + $3->getSymbol() + "\n\tmov " + string(temp) +" , ax\n";
			//fout<<$$->code<<endl;
			}
			
		
		else if($2->getName() == "-"){
			if($1->getvarType() == "int" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
		      //char* temp = newTemp();
		$$->code += "\tmov ax, " + $1->getSymbol() + "\n\tsub ax, " + $3->getSymbol() + "\n\tmov " + string(temp) +" , ax\n";
			//fout<<$$->code<<endl;
		      
		}
		$$->str= simp_expr;
		//$$->setidType("variable");
		
		$$->setSymbol(string(temp));
		variable.push_back($$->getSymbol());
	}
		  ;
					
term :	unary_expression{
		logout<<"Line "<<line_count<<": term : unary_expression "<<endl<<endl;
		term = una_expr;
		una_expr = "\0";
		logout<<term<<endl;
		$$ = $1;
	}
     |  term MULOP unary_expression{
		logout<<"Line "<<line_count<<": term : term MULOP unary_expression "<<endl<<endl;
		term = term + $2->getName()+una_expr;
		logout<<term<<endl;
		una_expr = "\0";
		$$=$1;
		$$->code += $3->code;
		if($2->getName() == "*"){
			if($1->getvarType() == "int" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
			char *temp=newTemp();
			$$->code += "\tmov ax, " + $1->getSymbol() +"\n\tmov bx , "+$3->getSymbol()+ "\n\tmul bx\n\tmov "+ string(temp) + ", ax\n";
			//variable.push_back(string(temp));	//$$->code += "\tmov "+ string(temp) + ", ax\n";
		        //fout<<$$->code<<endl;
		      
		}
		else if($2->getName() == "/"){
			if($1->getvarType() == "int" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				$$->setvarType("float");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
		      
		      char *temp=newTemp();
			$$->code += "\tmov ax, " + $1->getSymbol() +"\n\tmov bx , "+$3->getSymbol()+ "\n\tdiv bx\n\tmov "+ string(temp) + ", ax\n";
			//variable.push_back(string(temp));	//$$->code += "\tmov "+ string(temp) + ", ax\n";
		        //fout<<$$->code<<endl;
		}
		else if($2->getName() == "%"){
			if($1->getvarType() == "float" || $3->getvarType() == "float"){
				      errorout<<"Error at line "<<line_count<<" : invalid operands of types"<<endl<<endl;
				      semanticErrors++;
			}
			char *temp=newTemp();
			$$->code += "\tmov ax, " + $1->getSymbol() +"\n\tmov bx , "+$3->getSymbol()+ "\n\tdiv bx\n\tmov "+ string(temp) + ", dx\n";
			//variable.push_back(string(temp));
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
		      
		}
		//$$->setSymbol(string(temp));
		//variable.push_back(string(temp));
		
}
     ;

unary_expression : ADDOP unary_expression {
		logout<<"Line "<<line_count<<": unary_expression : ADDOP unary_expression"<<endl<<endl;
		//logout<<$2->getvarType()<<endl;
		una_expr = $1->getName()+una_expr;
		logout<<una_expr<<endl;
		SymbolInfo *si = new SymbolInfo();
		si->setidType("variable");
		if($1->getName() == "-"){
		   si = $2;
		       char *temp = newTemp();
		      si->code += "\tmov ax, " + $2->getSymbol() + "\n\tneg ax\n\tmov " + string(temp)+ ", ax\n";
		  //fout<<si->code<<endl;
		  si->setSymbol(string(temp));
		   variable.push_back(si->getSymbol());    
		   
		}
		else if($1->getName() == "+"){
		   si = $2;
		}
		
		$$ = si;
	}
		 | NOT unary_expression{
		logout<<"Line "<<line_count<<": unary_expression : NOT unary_expression "<<endl<<endl;
		una_expr = "!" + una_expr;
		logout<<una_expr<<endl;
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		   char *temp=newTemp();
		  si->code = "\tmov ax, " + $2->getSymbol() + "\n\tnot ax\n\tmov " + string(temp)+ ", ax\n";
		  //fout<<si->code<<endl;
		  si->setSymbol(string(temp));
		
		$$ = si;
	}
		 | factor {
		logout<<"Line "<<line_count<<": unary expression : factor "<<endl<<endl;
		una_expr = fac;
		fac = "\0";
		logout<<una_expr<<endl;
		//logout<<$1->getidType()<<endl;
		$$=$1;}
		 ;
	
factor	: variable {logout<<"Line "<<line_count<<": factor : variable "<<endl<<endl;
			$$= $1;
			fac= $$->getName();
			logout<<fac<<endl;
			if($$->getidType()=="variable"){
			     $$->code = $1->code;
			}
			
			else if($$->getidType() == "array"){
				char *temp= newTemp();
				$$->code+="\tmov ax, " + $1->getSymbol() + "[bx]\n";
				$$->code+= "\tmov " + string(temp) + ", ax\n";
				$$->setSymbol(string(temp));
				variable.push_back($$->getSymbol());
			}
}
	| ID LPAREN argument_list RPAREN{
	logout<<"Line "<<line_count<<": factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
	fac = $1->getName() + "(" +args+")";
	logout<<fac<<endl;
	int flag = 0;
	SymbolInfo *si = st.lookUp($1->getName(),"function");
	//logout<<si->param_list.size()<<endl;
	//logout<<args_type.size()<<endl;
	if(si == NULL){
		errorout<<"Error at line "<<line_count<<" "<<$1->getName()<<"() function doesn't exist"<<endl<<endl;
		semanticErrors++;
		}
	else{	
		  //char *temp = newTemp();
		  if(args_type.size() != si->param_type.size()){
			errorout<<"Error at line "<<line_count<<" : arguments number mismatch"<<endl<<endl;
			semanticErrors++;
		  }
		  else{
			for(int i = 0; i< args_type.size(); i++){
			   char *temp = newTemp();
			   if(si->param_type[i] != args_type[i]){
				flag = 1; 
				break;
			    }
			    else{
				flag = 0;
				}
			   si->code += "mov ax, "+si->param_list[i]+"\n\t";
			   si->code += "mov "+string(temp)+", ax\n\t";
			   variable.push_back(string(temp));
			}
		si->code += "call " + $1->getName()+"\n\t";
		
		char *t = newTemp();
		if(si->getvarType() == "int" || si->getvarType() == "float"){
			si->code += "mov "+string(t)+", ret\n";
		}
		si->setSymbol(string(t));
		variable.push_back(string(t));
		if(flag == 1){
		   errorout<<"Error at line "<<line_count<<" : arguments mismatch"<<endl<<endl;
			semanticErrors++;
		}
		
		args_type.clear();
		$$ = si;
		}	 
	}
	
	}
	| LPAREN expression RPAREN{logout<<"Line "<<line_count<<": factor : LPAREN expression RPAREN "<<endl<<endl;
		fac = "(" + expr + ")";
		logout<<fac<<endl;
		expr = "\0";
		$$ = $2;
		}
	| CONST_INT{
		logout<<"Line "<<line_count<<": factor : CONST_INT"<<endl<<endl;
		fac = $1->getName();
		logout<<$1->getName()<<endl<<endl;
		$1->setidType("variable");
		$1->setvarType("int");
		$1->setSymbol($1->getName());
		$$ = $1;
	} 
	| CONST_FLOAT{
		logout<<"Line "<<line_count<<": factor : CONST_FLOAT"<<endl<<endl;
		fac = $1->getName();
		logout<<fac<<endl<<endl;
		$1->setidType("variable");
		$1->setvarType("float");
		$1->setSymbol($1->getName());
		$$ = $1;
          }
	
	| variable INCOP {
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_incop = $1->getName() + "++";
		fac = fac + v_incop;
		logout<<v_incop<<endl;
		v_incop = "\0";
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		si = $1;
		if(si != NULL){
		    if(si->getidType() == "variable"){
			si->code += "\tmov ax, " + $1->getSymbol() + "\n\tinc ax\n\tmov "+$1->getSymbol()+", ax";
			$$ = si;
		    }
		    else if(si->getidType() == "array"){
			si->code += "\tmov ax, " + $1->getSymbol() + "[bx]\n\tinc ax\n\tmov "+$1->getSymbol()+"[bx], ax";
			$$ = si;
		    }

		}
	}
	
	| variable DECOP{
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_decop = $1->getName() + "--";
		fac = fac+v_decop;
		logout<<v_decop<<endl;
		v_decop = "\0";
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		si = $1;
		if(si != NULL){
		    if(si->getidType() == "variable"){
			si->code += "\tmov ax, " + $1->getSymbol() + "\n\tdec ax\n\tmov "+$1->getSymbol()+", ax";
			$$ = si;
		    }
		    else if(si->getidType() == "array"){
			si->code += "\tmov ax, " + $1->getSymbol() + "[bx]\n\tdec ax\n\tmov "+$1->getSymbol()+"[bx], ax";
			$$ = si;
		    }

		}
	};
	
argument_list : arguments{
		logout<<"Line "<<line_count<<": argument_list : arguments "<<endl<<endl;
			logout<<args<<endl;$$=$1;}
			  
			  ;
	
arguments : arguments COMMA logic_expression{logout<<"Line "<<line_count<<": arguments : arguments COMMA logic_expression "<<endl<<endl;
			args = args + "," + logic_expr;
			logout<<args<<endl;
			args_type.push_back($3->getvarType());
			//args_name.push_back($3->getSymbol())
			$$ = $3;
			
		}
	      | logic_expression
		{
		logout<<"Line "<<line_count<<": arguments : logic_expression "<<endl<<endl;
		args = logic_expr;
		logout<<args<<endl;
		args_type.push_back($1->getvarType());
		//args_name.push_back($3->getSymbol())
		$$ = $1;
		//$$->code = "mov "+$1->getSymbol()+", ax\n"
		logout<<$$->code<<endl;
		}
	      ;
 

%%

int main(int argc,char *argv[]){
	
	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("1505094_log.txt");
	errorout.open("1505094_errors.txt");
	fout.open("code.asm");
	
	yyparse();
	st.printAll(logout);
	logout << "Total Lines : " << line_count-1 << endl << endl; 
	logout << "Total Errors : " << semanticErrors << endl;
	errorout << "Total Errors : " << semanticErrors << endl;
	logout.close();
	errorout.close();
	fout.close();
	return 0;
}
