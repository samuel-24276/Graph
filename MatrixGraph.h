#include<iostream>

const int MAXSIZE=10;

template<class T>
struct Vertex
{
    T data;
    bool visited;
    int weight;             //顶点权重
};

template<class T>
class MGraph
{
    Vertex<T> vertex[MAXSIZE];              //存储顶点
    int arc[MAXSIZE][MAXSIZE];              //E存储各顶点的关系，即弧
    int vNum, arcNum;               //存储顶点个数和边数（或弧数）
public:
    MGraph(T a[], int n, int e, int choice=0);          ///choice默认为0，建无向图，若是有向图则不为0
    void VertexShow();                  //顶点位置对照表
    void reset();                       //将遍历后数组的Visited[]还原
    void DFS(int index);                    //深度优先遍历
    void BFS(int index);                    //广度优先遍历
};

template<class T>
MGraph<T>::MGraph(T a[], int n, int e, int choice)
{
    vNum = n;
    arcNum = e;
    int i, j;
    for(int k=0; k<n; ++k)
    {
        vertex[k].data = a[k];
        vertex[k].visited = false;
    }
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
            arc[i][j] = 0;          //初始化边
    VertexShow();
    std::cout<<"请输入相关联的顶点在对照表中的下标：\n";
    for(int k=0; k<e; ++k)
    {
        std::cin>>i>>j;
        arc[i][j] = 1;
        if(choice == 0)
            arc[j][i] = arc[i][j];          ///这是无向图，无向图不需要这一步
    }
}

template<class T>
void MGraph<T>::DFS(int i)                          ///适用于稠密图，用于稀疏图的话该图至少有vNum-1条边
{
    std::cout<<vertex[i].data<<" ";
    vertex[i].visited = true;
    for(int j=0; j<vNum; ++j)
    {
        if(arc[i][j]==1 && vertex[j].visited==false)        ///寻找关联的未被访问过的结点
            DFS(j);
    }
    for(int j=0; j<vNum; ++j)                               ///寻找不关联但未被访问过的结点*************
    {
        if(arc[i][j]==0 && vertex[j].visited==false)
            DFS(j);
    }
}

template<class T>
void MGraph<T>::BFS(int i)
{
    int queue[MAXSIZE];
    int f=0, r=0;
    std::cout<<vertex[i].data<<" ";
    vertex[i].visited = true;
    queue[++r] = i;
    while(f!=r)             //队列不为空
    {
        i = queue[++f];     //队头出队
        for(int j=0; j<vNum; ++j)
        {
            if(arc[i][j]==1 && vertex[j].visited==false)
            {
                std::cout<<vertex[j].data<<" ";
                vertex[j].visited = true;
                queue[++r] = j;
            }
        }
    }
    for(int j=0; j<vNum; ++j)
    {
        if(arc[i][j]==0 && vertex[j].visited==false)
            BFS(j);
    }
}

template<class T>
void MGraph<T>::VertexShow()
{
    std::cout<<"============顶点与下标对照表============"<<std::endl;
    for(int i=0; i<vNum; ++i)
        std::cout<<vertex[i].data<<"   |";
    std::cout<<std::endl;
    for(int i=0; i<vNum; ++i)
        std::cout<<i<<"   |";
    std::cout<<"\n=================================="<<std::endl;
}

template<class T>
void MGraph<T>::reset()
{
    for(int k=0; k<vNum; ++k)
        vertex[k].visited = false;
}
