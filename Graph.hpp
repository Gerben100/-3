#include <iostream>
#include <vector>

template<class T>
class Graph
{
private:
    int size;
    std::vector<std::vector<T>> data;

public:
    Graph()
    {
        this->size = 0;
        std::vector<std::vector<int>> data(this->size, std::vector<int>(this->size));
    }

    Graph(int size)
    {
        this->size = size;
        std::vector<std::vector<int>> data(size, std::vector<int>(size));
    }

    int GetSize()
    {
        return this->size;
    }

    int Get(int i, int j)
    {
        return data[i][j];
    }

    std::vector<std::vector<int>> NewGraph(int size)
    {
        std::vector<std::vector<int>> data(size, std::vector<int>(size));

        for(int i = 0; i < size; i++)
        {
            for(int j = i; j < size; j++)
            {
                if(i == j)
                {
                    data[i][j]=INT_MAX;
                    continue;
                }
                T item;
                std::cout << "from dot " << i + 1 << " to dot " << j + 1 << std::endl;
                std::cin >> item;
                if(item == 0)
                {
                    data[i][j]=INT_MAX;
                    data[j][i]=INT_MAX;
                    continue;
                }
                data[i][j]=item;
                data[j][i]=item;
            }
        }
        this->data = data;
        this->size = size;
        return data;

    }
    int* FindWay(int c)
    {
        bool visited[this->size];
        int*t;
        int current[this->size];
        for(int i = 0; i<this->size; i++)
        {
            current[i] = this->Get(c, i);
            visited[i] = false;
        }
        current[c] = 0;
        int index = 0;
        int u = 0;
        for (int i = 0; i < this->size; i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < this->size; j++)
            {
                if (!visited[j] && current[j] < min)
                {
                    min = current[j];
                    index = j;
                }
            }
            u = index;
            visited[u] = true;
            for(int j = 0; j < this->size; j++)
            {
                if (!visited[j] && this->Get(u, j) != INT_MAX && (current[u] + this->Get(u, j) < current[j]))
                {
                    current[j] = current[u] + this->Get(u, j);
                }
            }
        }
        for (int i = 0; i < this->size; i++)
        {
            if (current[i] != INT_MAX)
                std::cout << c + 1<< " => " << i+1 << "\t" << current[i] << std::endl;
            else
                std::cout << c + 1 << " => " << i+1 << "\t" << "Error" << std::endl;
        }
        t=current;
        return t;
    }
};