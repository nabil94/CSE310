#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;



class SymbolInfo
{
private:
    string name;
    string type;
    string symbol;
	string idType;
	string varType;
	string returnType;
	int arraySize;
	
    //SymbolInfo *next;
public:
    SymbolInfo *next;
    //int pos;
	//vector<SymbolInfo> param_list;
	vector<string> param_list;
	vector<string> param_type;
	string code;
	string arraySym;
	int integer[100];
	float floating[100];
	char character[100];
	int ival = 1;
	float ifloat = 1.0;
	char ichar;
	bool ibool = false;
	//int arraySize;
	int arrayIndex;
	string str;
	SymbolInfo(string v){
		varType = v;
	}
	
    SymbolInfo()
    {
        name = "\0";
        type = "\0";
	idType = "\0";
	varType = "\0";
        next = NULL;
	//param_list = new vector<String>();
        //pos = 0;
    }

	

    SymbolInfo(string n,string t)
    {
        name = n;
        type = t;
        this->next = NULL;
        //this->pos = 0;
    }

    SymbolInfo(string n,string t,string it,string vt)
    {
        name = n;
        type = t;
	idType = it;
	varType = vt;
        this->next = NULL;
        //this->pos = 0;
    }

    void setName(string n)
    {
        name = n;
    }

    void setType(string t)
    {
        type = t;
    }
	
	void setSymbol(string s){
	    symbol = s;
	}

	void setidType(string id){
		idType = id;
	}

	void setvarType(string id){
		varType = id;
	}

	void setreturnType(string id){
		returnType = id;
	}

	

	void initInteger(){
		for(int i = 0; i < 100; i++){
		   integer[i] = 1;
		}
	}

	void initFloat(){
		for(int i = 0; i < 100; i++){
		   floating[i] = 1.0;
		}
	}

	void initCharacter(){
		for(int i = 0; i < 100; i++){
		   character[i] = '\0';
		}
	}

	void setarraySize(int a){ arraySize = a;}

	void setVal(int v){
		ival = v;
	}

	void setFloat(float f){
		ifloat = f;
	}

	void setChar(char c){
		ichar = c;
	}

	void setIbool(){
	     ibool = true;
	}

	void setArrayIndexVal(int idx,int val){integer[idx] = val;}

	

    string getName()
    {
        return name;
    }

    string getType()
    {
        return type;
    }

    string getSymbol(){
	return symbol;
    }

    string getidType()
    {
        return idType;
    }

    string getvarType()
    {
        return varType;
    }

    string getreturnType()
    {
        return returnType;
    }

	int getArraySize(){
		return arraySize;
	}
    /*
        int setPos(int p)
        {
            pos = p;
        }
*/
        int getarraySize()
        {
            return arraySize;
        }
};

//SymbolInfo *head;
/*
struct listNode{
    SymbolInfo *head;
};
*/
class ScopeTable
{
    //int s;
    int k;
    int id;
    SymbolInfo **symbol;

public:
    //int s = -1;
    ScopeTable *parentScope;
    ScopeTable()
    {
        //s = 0;
        symbol = 0;
        parentScope = 0;
        k = id = 0;
    }

    ScopeTable(int K,int ID)
    {
        //s = 0;
        k = K;
        id = ID;
        symbol = new SymbolInfo*[k];
        for (int i = 0; i < k; i++)
        {
            symbol[i]= NULL;
            //symbol[i]->pos = 0;
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
        /*for(int i = 0;i<length;i++){
            sum = sum + (int)key[i];
        }*/
        h = (sum%k);
        return h;
    }

    SymbolInfo* lookUp(string sym,string id)
    {
        int pos = 0;
        int value = HashFunc(sym);
        SymbolInfo *temp = symbol[value];
        while(temp != NULL)
        {
            //pos++;
            if(temp->getName() == sym && temp->getidType() == id)
            {
                cout<<"Found in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym)<<","<<pos<<endl;
                return temp;

            }
            temp = temp->next;
            pos++;
        }
        return NULL;


    }

    SymbolInfo* flookUp(string sym,string type,string id,string var)
    {
        int pos = 0;
        int value = HashFunc(sym);
        SymbolInfo *temp = symbol[value];
        while(temp != NULL)
        {
            //pos++;
            if(temp->getName() == sym && temp->getType() == type && temp->getidType() == id && temp->getvarType() == var)
            {
                cout<<"Found in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym)<<","<<pos<<endl;
                return temp;

            }
            temp = temp->next;
            pos++;
        }
        return NULL;


    }


    bool insertSymbol(SymbolInfo *sym)
    {
        int pos = 0;
        SymbolInfo *prevSym = lookUp(sym->getName(),sym->getidType());
        if(prevSym != NULL)
        {
            return false;
        }
        else
        {
            int value = HashFunc(sym->getName());
            SymbolInfo* temp = symbol[value];
            //cout<<"hello";
            if(temp == NULL)
            {
                temp = sym;
		//if(temp->getidType() == "array"){ temp->setarraySize(sym.getarraySize());}
                //temp->name = sym.getName();
                //temp->type = sym.getType();
                //cout<<"hello";
                symbol[value] = temp;
                temp->next = NULL;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym->getName())<<","<<pos<<endl;
                //temp->pos=0;
                //pos++;
            }
            else
            {
                while(temp->next != NULL)
                {
                    temp = temp->next;
                    //temp->pos++;
                    pos++;
                }
                SymbolInfo *newSym;
		newSym = sym;
                //newSym->pos = temp->pos;
                //newSym->pos++;
                newSym->next = NULL;
                temp->next = newSym;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym->getName())<<","<<pos+1<<endl;

            }
            return true;
        }
        //int value = HashFunc(n);
        //SymbolInfo *head = NULL;
    }

    

    int getID()
    {
        return id;
    }

    void setID(int ID)
    {
        id = ID;
    }

    void printScopeTable(ofstream& stream)
    {
        cout<<"ScopeTable#"<<getID()<<endl;
	stream<<"ScopeTable#"<<getID()<<endl;
        for(int i = 0; i < k; i++)
        {
            SymbolInfo *temp = symbol[i];
	if(symbol[i]!= NULL){
            cout<<i<<":-->  ";
            stream<<i<<":-->  ";
            while(temp != NULL)
            {
                cout<<"<"<<temp->getName()<<","<<temp->getType()<<","<<temp->getvarType()<<","<<temp->getidType()<<">"<<" ";
               stream<<"<"<<temp->getName()<<","<<temp->getType()<<">"<<" ";
                temp = temp->next;
            }
            cout<<endl;
		stream<<endl;
        }
	}


    }

};
///*
class SymbolTable
{
public:
    ScopeTable *currentScope;
    int m;
    //int CurrentScope;
    int scopeTableNO;


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

    int getScopeNum(){
	return scopeTableNO;
    }

    bool insertSym(SymbolInfo *sym)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            return false;
        }
        bool a = currentScope->insertSymbol(sym);
        if(a == true)
        {
            // cout<<"Inserted in ScopeTable #"<<currentScope->getID()<<" at position "<<currentScope->HashFunc(sym.getName())<<","<<sym.getPos()<<endl;
            return true;
        }
        else
        {
            cout<<"<"<<sym->getName()<<","<<sym->getType()<<">"<<"already exists in current ScopeTable"<<endl;
            return false;
        }
    }

    

    SymbolInfo *lookUp(string sym,string id)
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
            temp = sc->lookUp(sym,id);
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

    SymbolInfo *paramlookUp(string sym,string id)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            //return false;
        }
        SymbolInfo *temp = new SymbolInfo();
        temp = currentScope->lookUp(sym,id);
        
            if(temp != NULL)
            {
                cout<<"Found in ScopeTable #"<<currentScope->getID()<<endl;
                
            }
            else{cout<<"Not found"<<endl;}
        /*if(temp == NULL){
            cout<<"Not found"<<endl;
        }*/
        return temp;
    }

    SymbolInfo *flookUp(string sym,string type,string id,string var)
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
            temp = sc->flookUp(sym,type,id,var);
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


    void enterScope(ofstream& stream)
    {
        int i = scopeTableNO;
        scopeTableNO++;
        ScopeTable *newScope = new ScopeTable(m,scopeTableNO);
        cout<<"New ScopeTable with id "<<newScope->getID()<<" created"<<endl;
        stream<<"New ScopeTable with id "<<newScope->getID()<<" created"<<endl;
        newScope->parentScope = currentScope;
        currentScope = newScope;

    }

    void exitScope(ofstream& stream)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            //return false;
        }
        else
        {
            cout<<"ScopeTable with id "<<currentScope->getID()<<" removed"<<endl;
	    stream<<"ScopeTable with id "<<currentScope->getID()<<" removed"<<endl;
            //scopeTableNO--;
            if(currentScope->parentScope != NULL)
            {
                currentScope = currentScope->parentScope;
            }
            else
            {
                currentScope = NULL;
            }
        }
        //free(currentScope);

        //currentScope = currentScope->parentScope;
    }

    void printCurrentScope(ofstream& stream)
    {
        if(currentScope != NULL)
        {
            currentScope->printScopeTable(stream);
        }
        else
        {
            cout<<"No ScopeTable is present"<<endl;
        }
    }

    void printAll(ofstream& stream)
    {
        ScopeTable *sc = new ScopeTable;
        sc = currentScope;
        while(sc != NULL)
        {
            sc->printScopeTable(stream);
            sc = sc->parentScope;
        }
    }


};

