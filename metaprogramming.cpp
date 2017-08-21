#include <iostream>
using namespace std;
 
template<int n> struct funStruct
{
    enum { val = n*funStruct<n-1>::val };
};
 
template<> struct funStruct<0>
{
    enum { val = 1 };
};
 
int main()
{
    cout << funStruct<4>::val << endl;
    return 0;
}
