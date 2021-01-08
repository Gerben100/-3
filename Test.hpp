
#include "Graph.hpp"
void Test(Graph<int> graph)
{
    int size=4,a[4][4],pointer=0;

    a[0][0]=INT_MAX;
    a[0][1]=3;
    a[0][2]=2;
    a[0][3]=INT_MAX;
    a[1][0]=3;
    a[1][1]=INT_MAX;
    a[1][2]=1;
    a[1][3]=4;
    a[2][0]=2;
    a[2][1]=1;
    a[2][2]=INT_MAX;
    a[2][3]=5;
    a[3][0]=INT_MAX;
    a[3][1]=4;
    a[3][2]=5;
    a[3][3]=INT_MAX;


    for(int i = 0; i < graph.GetSize(); i++)
    {
        for(int j = 0; j < graph.GetSize(); j++)
        {
            if(graph.Get(i,j) == a[i][j]);
            else pointer=1;
        }
    }


    if(pointer==0)
        std::cout << "TESTS OK"<< std::endl;
    else std::cout << "ERROR" << std::endl;
}
