%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include "1505094_SymbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

extern char *yytext;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
string unit;
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
int IDargs = 0;
vector<string> args_name;
vector<string> args_type; 
bool funcDef = false;
extern int line_count;
int semanticErrors = 0;
//SymbolInfo *symbol; 
string var;
extern string p;
ofstream logout;
extern ofstream errorout;

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

%type <sym>type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable expression_statement compound_statement statement statements
%nonassoc lower_than_else
%nonassoc ELSE
%error-verbose
%%



start : program{
		//fprintf(log,"Line %d : start : program\n\n",line_count);
		logout<<"Line "<<line_count<<" : start program\n"<<endl;
		
		}
		;

program : program unit {
		logout<<"Line "<<line_count<<" : program : program unit\n"<<endl;
		logout<<p<<endl;
		}
	| unit{
		logout<<"Line "<<line_count<<" : program : unit\n"<<endl;
		logout<<unit<<endl;
	}
	;
	
unit : var_declaration{
		logout<<"Line "<<line_count<<" : unit : var_declaration\n"<<endl;
		unit = var_dec;
		logout<<unit<<endl;
		var_dec = "\0";
		}
     | func_declaration{
		//fprintf(log,"Line %d : func_declaration\n\n",line_count);
		logout<<"Line "<<line_count<<" : unit : func_declaration\n"<<endl;
		unit = func_dec;
		logout<<unit<<endl;
		func_dec = "\0";
		}

     | func_definition{
		
		logout<<"Line "<<line_count<<" : unit : func_definition\n"<<endl;
		unit = func_def;
		logout<<unit<<endl;
		func_def = "\0";
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
			//logout<<s->
			errorout<<"Error at line : "<<line_count<<" : function already declared"<<endl;
			semanticErrors++;
			logout<<s->param_list.size()<<endl;
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
			logout<<si->param_list.size()<<endl;
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
		//si->setvarType($1->getvarType());
		si->setreturnType(si->getvarType());
		//si->setidType("function");
		for(int i = 0; i < args_name.size();i++){
			si->param_list.push_back(args_name[i]);
			si->param_type.push_back(args_type[i]);
		}
		logout<<si->param_list.size()<<endl;
		st.insertSym(si);
		func_var = $1->getName();
		//args_type.clear();
		/*st.printAll(logout);*/} compound_statement{
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<< endl;
		func_def = $1->getvarType() + " " + $2->getName() + "("+param+")"+comp_stmt;
		logout<<func_def<<endl<<endl;
		
		
		
		}
		| type_specifier ID LPAREN RPAREN{$2->setType("ID");
		//SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"int","function");
		SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"function",$1->getvarType());
		//si->setvarType($1->getvarType());
		si->setreturnType(si->getvarType());
		//si->setidType("function");
		st.insertSym(si);
		st.printAll(logout);} compound_statement{
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<< endl;
		func_def = $1->getvarType() + " " + $2->getName() + "()"+comp_stmt;
		logout<<func_def<<endl<<endl;
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
		comp_stmt = "{\n   "+stmts+"}\n";
		logout<<comp_stmt<<endl;
		stmts = "\0";
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
			//SymbolInfo *si = new SymbolInfo($3->getName(),$3->getType(),"int","variable");
			SymbolInfo *si = new SymbolInfo($3->getName(),$3->getType(),"variable",var);
			//si->setvarType($1->getvarType());
			si->setidType("variable");
			//si->returnType()
			st.insertSym(si);
			//st.printAll(logout);
		}
		}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD{
		var_dec = var_dec + yytext + $3->getName()+"["+$5->getName()+"]";
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
			//$$ = si;
			//st.printAll(logout);
			
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
		}
	  | compound_statement{
		logout<<"Line "<<line_count<<": statement : compound_statement"<<endl<<endl;
		stmt = comp_stmt;
		logout<<stmt<<endl;
		$$->str = stmt;
		}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement{
		logout<<"Line "<<line_count<<": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl<<endl;
		//$$->setName(stmt);
	}	
	  | IF LPAREN expression RPAREN statement %prec lower_than_else{
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "if(" + $3->str + ")" + $5->str;
		logout<<stmt<<endl;
		$$->str = stmt;
	}
	  | IF LPAREN expression RPAREN statement ELSE  statement{
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl;
		stmt = "if(" + $3->str + ")" + $5->str + "\nelse\n"+$7->str;
		logout<<stmt<<endl;
		$$->str = stmt;
	}
	  | WHILE LPAREN expression RPAREN statement{
		logout<<"Line "<<line_count<<": statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "while(" + $3->str + ")" + $5->str;
		$$->str = stmt;
		logout<<stmt<<endl;
	}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON{
		logout<<"Line "<<line_count<<": statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl<<endl;
		stmt = "printf(" + $3->getName()+");\n";
		$$->str = stmt;
		logout<<stmt<<endl;
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
		$$->str = stmt;	}
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
	SymbolInfo *s = st.lookUp($1->getName(),"variable");
	if(s == NULL){
		errorout<<"Error at line "<<line_count<<" : variable was not declared in this scope"<<endl;
		semanticErrors++;
	}
	else{
		$$ = s;
		//logout<<s->ival<<endl;
		$$->setVal(s->ival);
		$$->setName($1->getName());
		$$->str = VAR;
	}
	}		
	 | ID LTHIRD expression RTHIRD {
	logout<<"Line "<<line_count<<": variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
	VAR = $1->getName() + "[" + expr + "]";
	logout<<VAR<<endl;
	expr = "\0";
	SymbolInfo *si = st.lookUp($1->getName(),"array");
	if(si != NULL){
	//logout<<si->getName()<<"["<<$3->ival<<"]"<<endl<<endl;
	//logout<<si->getarraySize()<<endl<<endl;
	
		/*if($3->ival>si->getarraySize()){
	  	errorout<<"Error at line "<<line_count<<" : arraybound exceeded"<<endl<<endl;
		}*/
		if($3->getvarType() == "float"){
	  	 errorout<<"Error at line "<<line_count<<" : array index cannot be a float"<<endl<<endl;
		semanticErrors++;
		}
		$$ = si;
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
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			logout<<$$->ival<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			
			}
		}
		$$->str = expr;
	}
	   | variable ASSIGNOP logic_expression {
		logout<<"Line "<<line_count<<": expression : variable ASSIGNOP logic_expression"<<endl<<endl;
		expr = $1->str + "=" + logic_expr;
		logout<<expr<<endl;
		logout<<$1->getvarType()<<endl;
		logout<<$3->getvarType()<<endl;
		//expr = "\0";
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		if(si != NULL){
		//if($1->getidType() )	
	if(si->getidType() == "variable"){
		if(si->getvarType() == "int"){
			if($3->getvarType() == "int"){
			    si->setVal($3->ival);
			    logout<<si->ival<<endl;
			}
		   	else if($3->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if($3->getvarType() == "int"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		   	else if($3->getvarType() == "float"){
			    si->setFloat($3->ifloat);
			    logout<<si->ifloat<<endl;
			}
		}
	}else if(si->getidType() == "array"){
		if(si->getvarType() == "int"){
			if($3->getvarType() == "int"){
			    si->initInteger();
			    si->integer[$1->arrayIndex] = $3->ival;
			    logout<<si->getName()<<"["<<$1->arrayIndex<<"] = "<<si->integer[$1->arrayIndex]<<endl;	
			    logout<<$1->arrayIndex<<endl;
			}
		   	else if($3->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if($3->getvarType() == "int"){
			    logout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			}
		   	else if($3->getvarType() == "float"){
			    si->initFloat();
			    si->floating[$1->arrayIndex] = $3->ifloat;
			    logout<<si->floating[$1->arrayIndex]<<endl;
			}
		}
	
	}
	if($3->getidType() == "function" && $3->getvarType() == "void"){errorout<<"Error at line "<<line_count<<" : "<<logic_expr<<" does not return anything"<<endl;semanticErrors++;}
	logic_expr = "\0";
	$$ = si;
	$$->str = expr;
	}
		//$$ = si;
		
	}	
	   ;
			
logic_expression : rel_expression {

		logout<<"Line "<<line_count<<": logic_expression : rel_expression"<<endl<<endl;
		logic_expr = rel_expr;
		logout<<logic_expr<<endl;
		rel_expr = "\0";
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			logout<<$$->ival<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			
			}
		}
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
		if($2->getName() == "&&"){
		   if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			     si->ival = $1->ival && $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			     si->ival = $1->ival && $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			     si->ival = $1->ifloat && $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			     si->ival = $1->ifloat && $3->ifloat;
			}
		   }
		   else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival && $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival && $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat && $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat && $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] && $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] && $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] && $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] && $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] && $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] && $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] && $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] && $3->floating[$3->arrayIndex];
			}
		  }
		   
		}
		else if($2->getName() == "||"){
		   if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			     si->ival = $1->ival || $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			     si->ival = $1->ival || $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			     si->ival = $1->ifloat || $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			     si->ival = $1->ifloat || $3->ifloat;
			}
		   }
		   else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival || $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival || $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat || $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat || $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] || $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] || $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] || $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] || $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] || $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] || $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] || $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] || $3->floating[$3->arrayIndex];
			}
		  }
		   
		}
		
		$$ = si;
		$$->str = logic_expr;
	}	
		 ;
			
rel_expression	: simple_expression {
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression"<<endl<<endl;
		rel_expr = $1->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if($$->getvarType() == "float"){
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			
			}
		}
		$$->str = rel_expr;
		}
		| simple_expression RELOP simple_expression{
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression RELOP simple_expression"<<endl<<endl;
		rel_expr = $1->str +" "+ $2->getName() +" "+ $3->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		si->setidType("variable");
		if($2->getName() == "=="){
		     if($1->getvarType() == $3->getvarType() ){
			if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->ival == $3->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->ifloat == $3->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->integer[$1->arrayIndex] == $3->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->floating[$1->arrayIndex] == $3->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->ival == $3->integer[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->ifloat == $3->floating[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->integer[$1->arrayIndex] == $3->integer[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->floating[$1->arrayIndex] == $3->floating[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		}
		     else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		 else if($2->getName() == "!="){
		     if($1->getvarType() == $3->getvarType() ){
			if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->ival != $3->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->ifloat != $3->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->integer[$1->arrayIndex] != $3->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->floating[$1->arrayIndex] != $3->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->ival != $3->integer[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->ifloat != $3->floating[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType()=="int"){
				if($1->integer[$1->arrayIndex] != $3->integer[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if($1->getvarType() == "float" && $3->getvarType()=="float"){
				if($1->floating[$1->arrayIndex] != $3->floating[$3->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		}
		     else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		else if($2->getName() == ">"){
		  if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival > $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival > $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat > $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat > $3->ifloat;
			}
		  }
		  else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival > $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival > $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat > $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat > $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] > $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] > $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] > $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] > $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] > $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] > $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] > $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] > $3->floating[$3->arrayIndex];
			}
		  }
		}
		else if($2->getName() == ">="){
		  if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival >= $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival > $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat >= $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat >= $3->ifloat;
			}
		  }
		  else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival >= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival >= $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat >= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat >= $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] >= $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] >= $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] >= $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] >= $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] >= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] >= $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] >= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] >= $3->floating[$3->arrayIndex];
			}
		  }
		}
		else if($2->getName() == "<"){
		  if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival < $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival < $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat < $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat < $3->ifloat;
			}
		  }
		  else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival < $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival < $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat < $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat < $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] < $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] < $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] < $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] < $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] < $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] < $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] < $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] < $3->floating[$3->arrayIndex];
			}
		  }
		}
		else if($2->getName() == "<="){
		  if($1->getidType() == "variable" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival <= $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival <= $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat <= $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat <= $3->ifloat;
			}
		  }
		  else if($1->getidType() == "variable" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->ival <= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->ival <= $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->ifloat <= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->ifloat <= $3->floating[$3->arrayIndex];
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "variable"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] <= $3->ival;
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] <= $3->ifloat;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] <= $3->ival;
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] <= $3->ifloat;
			}
		  }
		  else if($1->getidType() == "array" && $3->getidType() == "array"){
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
			   si->ival = $1->integer[$1->arrayIndex] <= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "int" && $3->getvarType() == "float"){
			   si->ival = $1->integer[$1->arrayIndex] <= $3->floating[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "int"){
			   si->ival = $1->floating[$1->arrayIndex] <= $3->integer[$3->arrayIndex];
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
			   si->ival = $1->floating[$1->arrayIndex] <= $3->floating[$3->arrayIndex];
			}
		  }
		}
		$$ = si;
		$$->str = rel_expr;
		
	}	
		;
				
simple_expression : term {
		logout<<"Line "<<line_count<<": simple_expression : term"<<endl<<endl;
		simp_expr = term;
		logout<<simp_expr<<endl;
		logout<<$1->getidType()<<endl;
		term = "\0";
		$$->str = simp_expr;
		if($1->getType() == "ID"){simp_expr = "\0";}
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			//logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			
			}
		}
		//$$->setName(simp_expr);
		simp_expr = "\0";
	}
		  | simple_expression ADDOP term {
		logout<<"Line "<<line_count<<": simple_expression : simple_expression ADDOP term "<<endl<<endl;
		simp_expr = $1->str + $2->getName()+term;
		logout<<simp_expr<<endl;
		term = "\0";
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
		      
			if($1->getidType() == "variable" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival+$3->ival;
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)+$3->ifloat;
				   
				      $$ = si;

				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat+float($3->ival);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat+$3->ifloat;
				      char *ch;
				      
				}	
			}
			else if($1->getidType() == "variable" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival+$3->integer[$3->arrayIndex];
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)+$3->floating[$3->arrayIndex];
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat+float($3->integer[$3->arrayIndex]);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat+$3->floating[$3->arrayIndex];
				      $$ = $1;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]+$3->ival;
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])+$3->ifloat;
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]+float($3->ival);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $3->ifloat+$1->floating[$1->arrayIndex];
				      $$ = si;
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]+$3->integer[$3->arrayIndex];
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])+$3->floating[$3->arrayIndex];
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]+float($3->integer[$3->arrayIndex]);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $3->floating[$3->arrayIndex]+$1->floating[$1->arrayIndex];
				      $$ = si;
				}	
			}
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
		      
		      if($1->getidType() == "variable" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival-$3->ival;
				      $1->setVal(si->ival);
				      logout<<si->ival<<endl;
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)-$3->ifloat;
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat-float($3->ival);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat-$3->ifloat;
				      
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "variable" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival-$3->integer[$3->arrayIndex];
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)-$3->floating[$3->arrayIndex];
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat-float($3->integer[$3->arrayIndex]);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat-$3->floating[$3->arrayIndex];
				      char *ch;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]-$3->ival;
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])-$3->ifloat;
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]-float($3->ival);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat-$3->floating[$3->arrayIndex];
				      char *ch;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]-$3->integer[$3->arrayIndex];
				      //$1->setVal(si->ival);
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])-$3->floating[$3->arrayIndex];
				   
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]-float($3->integer[$3->arrayIndex]);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $3->floating[$3->arrayIndex]-$1->floating[$1->arrayIndex];
				      $$ = si;
				      
				}	
			}
		}
		$$->str= simp_expr;
		
	}
		  ;
					
term :	unary_expression{
		logout<<"Line "<<line_count<<": term : unary_expression "<<endl<<endl;
		term = una_expr;
		una_expr = "\0";
		logout<<term<<endl;
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			//logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			
			}
		}
	}
     |  term MULOP unary_expression{
		logout<<"Line "<<line_count<<": term : term MULOP unary_expression "<<endl<<endl;
		term = term + $2->getName()+una_expr;
		logout<<term<<endl;
		una_expr = "\0";
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
		      
		      if($1->getidType() == "variable" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival*$3->ival;
				      //$1->setVal(si->ival);
				      
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)*$3->ifloat;
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat*float($3->ival);
				      
				      $$ = si;
					logout<<$$->getvarType()<<endl;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat*$3->ifloat;
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "variable" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->ival*$3->integer[$3->arrayIndex];
				      $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)*$3->floating[$3->arrayIndex];
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat*float($3->integer[$3->arrayIndex]);
				      
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat*$3->floating[$3->arrayIndex];
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]*$3->ival;
				      $$ = si;      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])*$3->ifloat;
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]*float($3->ival);
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]*$3->floating[$3->arrayIndex];
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = $1->integer[$1->arrayIndex]*$3->integer[$3->arrayIndex];
				     $$ = si;
				      
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])*$3->floating[$3->arrayIndex];
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]*float($3->integer[$3->arrayIndex]);
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]*$3->floating[$3->arrayIndex];
				      $$ = si;      
				}	
			}
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
		      
		      if($1->getidType() == "variable" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if($1->ival%$3->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = $1->ival/$3->ival;
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = $1->ival/$3->ival;
					} 
					$$ = si;
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)/$3->ifloat;
				  	$$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat/float($3->ival);
				      $$ = si;
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat/$3->ifloat;
				      $$ = si;
				}	
			}
			else if($1->getidType() == "variable" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if($1->ival%$3->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = $1->ival/$3->integer[$3->arrayIndex];
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = $1->ival/$3->integer[$3->arrayIndex];
					} 
					$$ = si;
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->ival)/$3->floating[$3->arrayIndex];
				   $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->ifloat/float($3->integer[$3->arrayIndex]);
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]/$3->floating[$3->arrayIndex];
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if($1->ival%$3->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = $1->integer[$1->arrayIndex]/$3->ival;
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = $1->integer[$1->arrayIndex]/$3->ival;
					} 
					$$ = si;
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])/$3->ifloat;
				  
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]/float($3->ival);
				      $$ = si;
					logout<<$$->getvarType()<<endl;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]/$3->ifloat;
				      $$ = si;
				      
				}	
			}
			else if($1->getidType() == "array" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if($1->ival%$3->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = $1->integer[$1->arrayIndex]/$3->integer[$3->arrayIndex];
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = $1->integer[$1->arrayIndex]/$3->integer[$3->arrayIndex];
					} 
					$$ = si;
				      
				}
				else if($1->getvarType() == "int" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float($1->integer[$1->arrayIndex])/$3->floating[$3->arrayIndex];
				  
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]/float($3->integer[$3->arrayIndex]);
				      $$ = si;
				      
				}
				else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = $1->floating[$1->arrayIndex]/$3->floating[$3->arrayIndex];
				      $$ = si;
				      
				}	
			}
			
		}
		else if($2->getName() == "%"){
			if($1->getvarType() == "float" || $3->getvarType() == "float"){
				      errorout<<"Error at line "<<line_count<<" : invalid operands of types"<<endl<<endl;
				      semanticErrors++;
			}
			SymbolInfo *si = new SymbolInfo();
			si->setvarType("int");
			si->setType("CONST_INT");
		        if($1->getidType() == "variable" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      si->ival = $1->ival%$3->ival;
				}
			}
			else if($1->getidType() == "variable" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      si->ival = $1->ival%$3->integer[$3->arrayIndex];
				}
			}
			else if($1->getidType() == "array" && $3->getidType() == "variable"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      si->ival = $1->integer[$1->arrayIndex]%$3->ival;
				}
			}
			else if($1->getidType() == "array" && $3->getidType() == "array"){
				if($1->getvarType() == "int" && $3->getvarType() == "int"){
				      si->ival = $1->integer[$1->arrayIndex]%$3->integer[$3->arrayIndex];
				}
			}
			$$ = si;
			
			if($1->getvarType() == "int" && $3->getvarType() == "int"){
				$$->setvarType("int");
			}
			else if($1->getvarType() == "float" && $3->getvarType() == "float"){
				$$->setvarType("float");
			}
		      
		}
		
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
		   if($2->getidType() == "variable"){
			if($2->getvarType() == "int"){
			     si->ival = (-1)*$2->ival;
			     si->setvarType("int");
			}
			else if($2->getvarType() == "float"){ 
			     si->ifloat= (-1)*$2->ifloat;
			     si->setvarType("float");
			}
		   }
		   else if($2->getidType() == "array"){
			if($2->getvarType() == "int"){
			     si->ival = (-1)*$2->integer[$2->arrayIndex];
			     si->setvarType("int");
			}
			else if($2->getvarType() == "float"){ 
			     si->ifloat= (-1)*$2->floating[$2->arrayIndex];
			     si->setvarType("float");
			}
		   }
		}
		else if($1->getName() == "+"){
		   if($2->getidType() == "variable"){
			if($2->getvarType() == "int"){
			     si->ival = $2->ival;
			     si->setvarType("int");
			}
			else if($2->getvarType() == "float"){ 
			     si->ifloat= $2->ifloat;
			     si->setvarType("float");
			}
		   }
		   else if($2->getidType() == "array"){
			if($2->getvarType() == "int"){
			     si->ival = $2->integer[$2->arrayIndex];
			     si->setvarType("int");
			}
			else if($2->getvarType() == "float"){ 
			     si->ifloat= $2->floating[$2->arrayIndex];
			     si->setvarType("float");
			}
		   }
		}
		
		$$ = si;
	}
		 | NOT unary_expression{
		logout<<"Line "<<line_count<<": unary_expression : NOT unary_expression "<<endl<<endl;
		una_expr = "!" + una_expr;
		logout<<una_expr<<endl;
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		if($2->getidType() == "variable"){
		   if($2->getvarType() == "int"){
			si->ival = !($2->ival);
		   }
		   else if($2->getvarType() == "float"){
			si->ival = !($2->ifloat);
		   }
		}
		else if($2->getidType() == "array"){
		   if($2->getvarType() == "int"){
			si->ival = !($2->integer[$2->arrayIndex]);
		   }
		   else if($2->getvarType() == "float"){
			si->ival = !($2->floating[$2->arrayIndex]);
		   }
		}
		}
		 | factor {
		logout<<"Line "<<line_count<<": unary expression : factor "<<endl<<endl;
		una_expr = fac;
		fac = "\0";
		logout<<una_expr<<endl;
		logout<<$1->getidType()<<endl;
		if($1->getidType() == "variable"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->ival);
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->ifloat);
			}
		}else if($1->getidType() == "array"){
		    $$ = $1;
		    if($$->getvarType() == "int"){
			$$->setVal($1->integer[$1->arrayIndex]);
			$$->integer[$1->arrayIndex] = $1->integer[$1->arrayIndex];
			}
			else if($$->getvarType() == "float"){
			//$$->setVal($1->ival);
			$$->setFloat($1->floating[$1->arrayIndex]);
			$$->floating[$1->arrayIndex] = $1->floating[$1->arrayIndex];
			}
		}
		}
		 ;
	
factor	: variable {logout<<"Line "<<line_count<<": factor : variable "<<endl<<endl; $$=$1;
	fac = $1->getName();
	//fac = VAR;
	logout<<fac<<endl;}
	| ID LPAREN argument_list RPAREN{
	logout<<"Line "<<line_count<<": factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
	fac = $1->getName() + "(" +args+")";
	logout<<fac<<endl;
	int flag = 0;
	SymbolInfo *si = st.lookUp($1->getName(),"function");
	//logout<<si->param_list.size()<<endl;
	logout<<args_type.size()<<endl;
	if(si == NULL){
		errorout<<"Error at line "<<line_count<<" "<<$1->getName()<<"() function doesn't exist"<<endl<<endl;
		semanticErrors++;
		}
	else{
		  if(args_type.size() != si->param_type.size()){
			errorout<<"Error at line "<<line_count<<" : arguments number mismatch"<<endl<<endl;
			semanticErrors++;
		  }
		  else{
			for(int i = 0; i< args_type.size(); i++){
			   if(si->param_type[i] != args_type[i]){
				flag = 1; 
				break;
			    }else{flag = 0;}
			}
		
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
		expr = "\0";}
	| CONST_INT{
		logout<<"Line "<<line_count<<": factor : CONST_INT"<<endl<<endl;
		logout<<$1->getName()<<endl<<endl;
		$1->setidType("variable");
		$1->setvarType("int");
		fac = $1->getName();
		int i = atoi($1->getName().c_str());
		$1->setVal(i);
		$$ = $1;
	} 
	| CONST_FLOAT{
		logout<<"Line "<<line_count<<": factor : CONST_FLOAT"<<endl<<endl;
		fac = $1->getName();
		logout<<fac<<endl<<endl;
		$1->setidType("variable");
		$1->setvarType("float");
		float i = atof($1->getName().c_str());
		$1->ifloat = i; 
		$$ = $1;
          }
	
	| variable INCOP {
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_incop = $1->getName() + "++";
		fac = fac + v_incop;
		logout<<v_incop<<endl;
		v_incop = "\0";
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		if(si != NULL){
			if($1->getidType() == "variable"){
				if(si->getvarType() == "int"){
				si->ival = si->ival + 1;
				}
				else if(si->getvarType() == "float"){
				si->ifloat = si->ifloat + 1.0;
				}
			
			}
		else if(si->getidType() == "array"){
			if(si->getvarType() == "int"){
				si->integer[$1->arrayIndex] = si->integer[$1->arrayIndex] + 1;
			}
			else if(si->getvarType() == "float"){
				si->floating[$1->arrayIndex] = si->floating[$1->arrayIndex] + 1.0;
			}
			
		}
		$$ = si;
	}
	}
	| variable DECOP{
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_decop = $1->getName() + "--";
		fac = fac+v_decop;
		logout<<v_decop<<endl;
		v_decop = "\0";
		SymbolInfo *si = st.lookUp($1->getName(),$1->getidType());
		if(si != NULL){
			if($1->getidType() == "variable"){
				if(si->getvarType() == "int"){
				si->ival = si->ival - 1;
				}
				else if(si->getvarType() == "float"){
				si->ifloat = si->ifloat - 1.0;
				}
			
			}
		else if(si->getidType() == "array"){
			if(si->getvarType() == "int"){
				si->integer[$1->arrayIndex] = si->integer[$1->arrayIndex] - 1;
			}
			else if(si->getvarType() == "float"){
				si->floating[$1->arrayIndex] = si->floating[$1->arrayIndex] - 1.0;
			}
			
		}
		$$ = si;
	}
	}
	
argument_list : arguments{logout<<"Line "<<line_count<<": argument_list : arguments "<<endl<<endl;
			logout<<args<<endl;}
			  |
			  ;
	
arguments : arguments COMMA logic_expression{logout<<"Line "<<line_count<<": arguments COMMA logic_expression "<<endl<<endl;
			args = args + "," + logic_expr;
			logout<<args<<endl;
			args_type.push_back($3->getvarType());
		}
	      | logic_expression
		{logout<<"Line "<<line_count<<": logic_expression "<<endl<<endl;
		args = logic_expr;
		logout<<args<<endl;
		args_type.push_back($1->getvarType());
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
	
	
	yyparse();
	st.printAll(logout);
	logout << "Total Lines : " << line_count-1 << endl << endl; 
	logout << "Total Errors : " << semanticErrors << endl;
	errorout << "Total Errors : " << semanticErrors << endl;
	logout.close();
	errorout.close();

	return 0;
}
