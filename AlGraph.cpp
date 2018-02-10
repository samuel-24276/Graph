#include "ALGraph.h"

int main()
{
    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    int arc[4][2] ={{0, 1}, {0, 2}, {2, 3}, {3, 2}};
    ///从已知获取参数的
    ALGraph<char> G2(a, 4, 4, arc);
    std::cout<<"\nDFS：";
    G2.DFS(0);
    G2.reset();
    std::cout<<"\nBFS:";
    G2.BFS(0);
    G2.reset();
    std::cout<<std::endl;
    ///手动输入参数的
    ALGraph<char> G1(a, 5);
    G1.VertexShow();
    G1.CreateGraph(3);
    std::cout<<"\nDFS：";
    G1.DFS(0);
    G1.reset();
    std::cout<<"\nBFS:";
    G1.BFS(0);
    G1.reset();
    return 0;
}




///  2018.2.9
