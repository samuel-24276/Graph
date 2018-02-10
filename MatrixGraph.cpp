#include "MatrixGraph.h"

int main()
{
    int index;
    char a[4] = {'a', 'b', 'c', 'd'};
    MGraph<char> G(a, 4, 2);
    std::cout<<"请输入深度优先遍历开始结点所在位置下标：";
    std::cin>>index;
    std::cout<<"深度优先遍历为：";
    G.DFS(index);
    G.reset();
    std::cout<<"\n请输入广度优先遍历开始结点所在位置下标：";
    std::cin>>index;
    std::cout<<"广度优先遍历为：";
    G.BFS(index);
    G.reset();
    return 0;
}



///丁宇飞 2018.2.9



///丁宇飞 2018.2.9
