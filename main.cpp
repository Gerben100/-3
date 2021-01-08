#include <iostream>
#include <vector>
#include "Test.hpp"
int main() {


    int size;
    std::cout << "Enter size" << std::endl;
    std::cin >> size;
    Graph<int> graph = Graph<int>(size);
    graph.NewGraph(size);
    Test(graph);
    for(int i = 0; i < graph.GetSize(); i++)
    {
        for(int j = 0; j < graph.GetSize(); j++)
        {
            if(graph.Get(i,j) == INT_MAX)
            {
                std::cout << "0" << "\t";
                continue;
            }
            std::cout << graph.Get(i,j)<< "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "Enter start dot" << std::endl;
    int current;
    std::cin >> current;
    current--;
    graph.FindWay(current);

    return 0;


}