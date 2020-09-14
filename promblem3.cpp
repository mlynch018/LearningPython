#include <iostream>
#include <string>
#include <vector>

using namespace std;

void initalize(vector<string> & v);
void print(vector<string> & v);
int search(vector<string> & v, string s, int startPos);
bool searchExactLength(vector<string> & v, string s);
void elimination(vector<string> &v, int startPos);
void mt(vector<string> &v, int startPos);
void mp(vector<string> &v, int startPos);
void conjuction(vector<string> &v);

int main()
{
    vector<string> v;
    initalize(v);
    print(v);
 
    elimination(v,0);
    mt(v,0);
    conjuction(v);
    mp(v,0);
    elimination(v,0);
    conjuction(v);
    
    return 0;
}

void initalize(vector<string> & v)
{
    v.push_back("p=>q");
    v.push_back("r|s");
    v.push_back("s'=>t'"); 
    v.push_back("q'|s");
    v.push_back("s'");
    v.push_back("p'&r=>u");
    v.push_back("w|t");
    v.push_back("u&w");
}

void print(vector<string> & v)
{
    int s=v.size();
    cout<<endl<<"Current arguments: "<<endl;
    for (int i=0; i<(s-1);i++)
    {
        cout<<(i+1)<<")"<<v[i]<<endl;   
    }    
    cout<<"therefore  "<<v[s-1]<<endl<<endl;
}

int search(vector<string> & v, string s, int startPos)
{
    for (unsigned int i=startPos; i<v.size(); i++)
    {
        for (unsigned int j=0; j<=((v[i].length())-s.length()); j++)
        {
            if (v[i].substr(j,s.length())==s)
            {
                return i;
            }
        }
    }
    return -1;
}

bool searchExactLength(vector<string> & v, string s)
{
    for (int i=0; i<v.size(); i++)
    {
        if (v[i]==s)
            return true;
    }
    return false;   
}

void elimination(vector<string> &v, int startpos)
{
    int orVector=-1;
    orVector=search(v,"|",startpos); 
    
    if (orVector==-1)
    {
        return;   
    }
    else
    {
        string var1="";
        string var2="";
        string negvar1="";
        string negvar2="";
        
        int orPos=v[orVector].find("|");
        
        //initalizing var 1 and var 2
        //if first var is negated
        if (v[orVector][(orPos-1)]=='\'')
        {
            var1+=v[orVector][(orPos-2)];
            var1+=v[orVector][(orPos-1)];
        }
        else
        {
            var1+=v[orVector][(orPos-1)];
        }    
        
        //if second var is negated
        if (v[orVector][(orPos+2)]=='\'')
        {
            var2+=v[orVector][(orPos+1)];
            var2+=v[orVector][(orPos+2)];
        }
        else
        {
            var2+=v[orVector][(orPos+1)];
        }    
        
        //find negations of first two original vars
        if (var1.length()==2)
        {
            negvar1+=var1[0];
        }
        else 
        {
            negvar1+=var1[0];
            negvar1+="'";
        }
        if (var2.length()==2)
        {
            negvar2+=var2[0];
        }
        else 
        {
            negvar2+=var2[0];
            negvar2+="'";
        }
    
        //look for elimination possibility one: negvar2 concludes to var1    
        bool nv2=searchExactLength(v,negvar2);
        bool v1=searchExactLength(v,var1);
        bool nv1=searchExactLength(v,negvar1);
        bool v2=searchExactLength(v,negvar2);

        if (nv2 && v1)
        {
            v[orVector]=var1;   
            cout<<"After Elimination:";
            print(v);
        }
        else
        {
            if (v2 && nv2)
            {
                v[orVector]=var1;   
                cout<<"After Elimination:";
                print(v);
            }
        }
    
        //recursive call to search to find every or not just the first one
        orVector++;
        elimination(v,orVector);        
    }
    
    return;
}

void mt(vector<string> &v, int startPos)
{
    int arrowVector=-1;
    arrowVector=search(v,"=>",startPos); 
    
    if (arrowVector==-1)
    {
        return;   
    }
    else
    {
        string var1="";
        string var2="";
        string negvar1="";
        string negvar2="";
        
        int arrowPos=v[arrowVector].find("=>");
        
        //initalizing var 1 and var 2
        //if first var is negated
        if (v[arrowVector][(arrowPos-1)]=='\'')
        {
            var1+=v[arrowVector][(arrowPos-2)];
            var1+=v[arrowVector][(arrowPos-1)];
        }
        else
        {
            var1+=v[arrowVector][(arrowPos-1)];
        }    
        
        //if second var is negated
        if (v[arrowVector][(arrowPos+3)]=='\'')
        {
            var2+=v[arrowVector][(arrowPos+2)];
            var2+=v[arrowVector][(arrowPos+3)];
        }
        else
        {
            var2+=v[arrowVector][(arrowPos+1)];
        }    
        
        //find negations of first two original vars
        if (var1.length()==2)
        {
            negvar1+=var1[0];
        }
        else 
        {
            negvar1+=var1[0];
            negvar1+="'";
        }
        if (var2.length()==2)
        {
            negvar2+=var2[0];
        }
        else 
        {
            negvar2+=var2[0];
            negvar2+="'";
        }
        
        bool nv2=searchExactLength(v,negvar2);
        bool v1=searchExactLength(v,var1);
        bool nv1=searchExactLength(v,negvar1);
        bool v2=searchExactLength(v,negvar2);
        
        if (nv1 && nv2)
        {
            v[arrowVector]=negvar1;
            int pos=search(v,negvar2,0);
            v[pos]="none";
            cout<<"After Modus Tollens: ";
            print(v);
        }
    
        arrowVector++;
        elimination(v,arrowVector);  
    }    
}

void mp(vector<string> &v, int startPos)
{
    int arrowVector=-1;
    arrowVector=search(v,"=>",startPos); 
    
    if (arrowVector==-1)
    {
        return;   
    }
    else
    {
        string var1="";
        string var2="";
        string negvar1="";
        string negvar2="";
        
        int arrowPos=v[arrowVector].find("=>");
        
        //initalizing var 1 and var 2
        //if first var is negated
        if (v[arrowVector][(arrowPos-1)]=='\'')
        {
            var1+=v[arrowVector][(arrowPos-2)];
            var1+=v[arrowVector][(arrowPos-1)];
        }
        else
        {
            var1+=v[arrowVector][(arrowPos-1)];
        }    
        
        //if second var is negated
        if (v[arrowVector][(arrowPos+3)]=='\'')
        {
            var2+=v[arrowVector][(arrowPos+2)];
            var2+=v[arrowVector][(arrowPos+3)];
        }
        else
        {
            var2+=v[arrowVector][(arrowPos+1)];
        }    
        
        //find negations of first two original vars
        if (var1.length()==2)
        {
            negvar1+=var1[0];
        }
        else 
        {
            negvar1+=var1[0];
            negvar1+="'";
        }
        if (var2.length()==2)
        {
            negvar2+=var2[0];
        }
        else 
        {
            negvar2+=var2[0];
            negvar2+="'";
        }
        
        bool nv2=searchExactLength(v,negvar2);
        bool v1=searchExactLength(v,var1);
        bool nv1=searchExactLength(v,negvar1);
        bool v2=searchExactLength(v,negvar2);
        
        if (v1 && v2)
        {
            v[arrowVector]=var2;
            int pos=search(v,var1,0);
            v[pos]="none";
            cout<<"After Modus Ponens: ";
            print(v);
        }
    
        arrowVector++;
        elimination(v,arrowVector);  
    }    
}

void conjuction(vector<string> & v)
{
    int numfound=0;
    string var1="";
    string var2="";
    int pos1=-1;
    int pos2=-1;
    for (int i=0; i<v.size(); i++)
    {
        if (numfound>=2)
            break;
        if (v[i].size()==1 || v[i].size()==2)
        {
            if (numfound==0)
            {
                numfound++;
                pos1=i;
                var1=v[i];
            }
            else 
            {
                numfound++;
                var2=v[i];
                pos2=i;
            }
        }
    }
    if (numfound>=2)
    {
        string s="";
        s+=var1;
        s+="&";
        s+=var2;
        v[pos1]=s;
        v[pos2]="none";
        cout<<"After conjuction: ";
        print(v);
    }
}

