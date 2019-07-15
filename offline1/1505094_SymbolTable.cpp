#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

int pos = 0;

class SymbolInfo
{
private:
    string name;
    string type;
    //SymbolInfo *next;
public:
    SymbolInfo *next;
    //int pos;
    SymbolInfo()
    {
        name = ' ';
        type = ' ';
        next = NULL;
        //pos = 0;
    }

    SymbolInfo(string n,string t)
    {
        name = n;
        type = t;
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

    string getName()
    {
        return name;
    }

    string getType()
    {
        return type;
    }
    /*
        int setPos(int p)
        {
            pos = p;
        }

        int getPos()
        {
            return pos;
        }*/
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

    SymbolInfo* lookUp(string sym)
    {
        int pos = 0;
        int value = HashFunc(sym);
        SymbolInfo *temp = symbol[value];
        while(temp != NULL)
        {
            //pos++;
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
                //temp->name = sym.getName();
                //temp->type = sym.getType();
                //cout<<"hello";
                symbol[value] = temp;
                temp->next = NULL;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym.getName())<<","<<pos<<endl;
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
                SymbolInfo *newSym = new SymbolInfo(sym.getName(),sym.getType());
                //newSym->pos = temp->pos;
                //newSym->pos++;
                newSym->next = NULL;
                temp->next = newSym;
                cout<<"Inserted in ScopeTable #"<<getID()<<" at position "<<HashFunc(sym.getName())<<","<<pos+1<<endl;

            }
            return true;
        }
        //int value = HashFunc(n);
        //SymbolInfo *head = NULL;
    }

    bool deleteSymbol(string sym)
    {
        int pos = 0;
        SymbolInfo *prevSym = lookUp(sym);
        if(prevSym == NULL)
        {
            cout<<"Not found"<<endl;
            return false;
        }
        else
        {
            SymbolInfo *prev;
            int value = HashFunc(sym);
            SymbolInfo *temp = symbol[value];
            while(temp != NULL)
            {
                if(temp == prevSym)
                {
                    break;
                }
                //break;
                prev = temp;
                temp = temp->next;
                pos++;
            }
            if(temp == symbol[value])
            {
                symbol[value] = symbol[value]->next;
                free(temp);
            }
            else
            {
                prev->next = temp->next;
                free(temp);
            }
            cout<<"Deleted entry at "<<HashFunc(sym)<<","<<pos<<" from current ScopeTable"<<endl;
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
        for(int i = 0; i < k; i++)
        {
            SymbolInfo *temp = symbol[i];
            cout<<i<<":-->  ";
            while(temp != NULL)
            {
                cout<<"<"<<temp->getName()<<","<<temp->getType()<<">"<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }


    }

};
///*
class SymbolTable
{
private:
    ScopeTable *currentScope;
    int m;
    //int CurrentScope;
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
            // cout<<"Inserted in ScopeTable #"<<currentScope->getID()<<" at position "<<currentScope->HashFunc(sym.getName())<<","<<sym.getPos()<<endl;
            return true;
        }
        else
        {
            cout<<"<"<<sym.getName()<<","<<sym.getType()<<">"<<"already exists in current ScopeTable"<<endl;
            return false;
        }
    }

    bool removeSym(string sym)
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            return false;
        }
        bool a = currentScope->deleteSymbol(sym);
        if(a == true)
        {
            //cout<<"Deleted entry at "<<currentScope->HashFunc(sym)<<","<<" from current ScopeTable"<<endl;
            return true;
        }
        else return false;
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


    void enterScope()
    {
        int i = scopeTableNO;
        scopeTableNO++;
        ScopeTable *newScope = new ScopeTable(m,scopeTableNO);
        cout<<"New ScopeTable with id "<<newScope->getID()<<" created"<<endl;
        newScope->parentScope = currentScope;
        currentScope = newScope;

    }

    void exitScope()
    {
        if(currentScope == NULL)
        {
            cout<<"No scopetable found"<<endl;
            //return false;
        }
        else
        {
            cout<<"ScopeTable with id "<<currentScope->getID()<<" removed"<<endl;
            scopeTableNO--;
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
//*/
int main()
{
    int a;
    //char c1,c2;
    cin>>a;
    //ScopeTable sc(a,1);
    SymbolTable st(a);

    while(1)
    {
        char ch;
        cin>>ch;
        if(ch=='I')
        {
            string a,b;
            cin>>a>>b;
            SymbolInfo *s = new SymbolInfo(a,b);
            //sc.insertSymbol(*s);
            st.insertSym(*s);
        }

        else if(ch=='D')
        {
            string a;
            cin>>a;
            //SymbolInfo *s = new SymbolInfo(a,b);
            st.removeSym(a);
        }
        else if(ch=='L')
        {
            string a;
            cin>>a;
            //SymbolInfo *s = new SymbolInfo(a);
            SymbolInfo *s1 = st.lookUp(a);
            if(s1 == NULL)
            {
                cout<<"Not found"<<endl;
            }
        }

        else if(ch=='S')
        {

            st.enterScope();
        }
        else if(ch=='P')
        {
            char c;
            cin>>c;
            if(c == 'C')
            {
                st.printCurrentScope();
            }
            if(c == 'A')
            {
                st.printAll();
            }
        }

        else if(ch == 'E')
        {
            st.exitScope();
        }

        //st.printCurrentScope();

    }


    return 0;
}
