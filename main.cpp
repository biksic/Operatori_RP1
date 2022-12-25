#include <iostream>
#include <vector>
#include "program.h"
using namespace std;

int main() {

    vector<int> v = {1, 10, 50}; /* ekvivalentno: v.push_back(1); v.push_back(10); v.push_back(50); */
    memorija mem(v);

    mem[4]=5; 

    cout << mem[0] << " " << mem[1] << " " << mem[2] << " " << mem[3]<<" " <<mem[4] << endl; 
    cout<<endl; 

    program pr; 
    pr<<new inkrement(3)<<new pomak(1)<<new inkrement(2)<<new pomak(2)<<new inkrement(4)<<new pomak(-1)<< new inkrement(-2); 
    
    cout << mem[0] << " " << mem[1] << " " << mem[2] << " " << mem[3]<<" " <<mem[4] << endl; 
    int n=pr(mem); 

    cout<<n<<endl; 
    cout << mem[0] << " " << mem[1] << " " << mem[2] << " " << mem[3]<<" " <<mem[4] << endl; 

    inkrement k(0), r(0);
    k="65";
    r="42";
    program prog;
    int z=prog(mem); //nista se ne događa
    prog<<new pomak(1)<<&k<<&r; 


    cout << mem[0] << " " << mem[1] << " " << mem[2] << " " << mem[3]<<" " <<mem[4] << endl; 
    
    vector<int> w={3, 4 , 5}; 
    memorija memi(w); 
    int u=prog(memi); 

    cout << memi[0] << " " << memi[1] << " " << memi[2] <<endl; 






}
