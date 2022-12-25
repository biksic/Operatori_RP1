#include <iostream> 
#include <vector> 
#include <sstream>

using namespace std; 

struct memorija{
    vector<int> V; 
    int index; 

    memorija(vector<int> A){
        V=A; 
        index=0; 
    }

    int &operator[](int i){
        return V[i]; 
    }
};

struct naredba{
    int argument;  
    virtual void operator()( memorija &A)=0; 

    operator int( ) const {
        return argument; 
    }


}; 

struct pomak : naredba
{
    pomak(int i){
        argument=i; 
    }

    void operator()(memorija &A){
        A.index+=argument; 
    }
};

struct inkrement : naredba
{
    inkrement(int i){
        argument=i; 
    }

    void operator()(memorija &A)
    {
        A.V[A.index]+=argument; 
    }

    inkrement &operator=(const char* p)
    {
        stringstream str; 
        str<<p; 
        int i; 
        str>>i; 

        int z=0, j=1; 
        while(i)
        {
            int t=i%10; 
            i/=10; 
            z+=t*j; 
            j*=8; 
        }
        argument=z;

        return *this;

    }
    
};



struct program 
{
    vector<naredba *> svi; 

    program &operator<<(naredba *n)
    {
        svi.push_back(n); 
        return *this; 
    }

    int operator()(memorija &A)
    {
        for(int i=0; i!=svi.size(); i++)
        {
            naredba *n=svi[i]; 
            (*n)(A); 
            
        }
        
        return A[0]; 
    }
};