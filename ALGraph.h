#include<iostream>

const int MAXSIZE=10;

struct ArcNode          ///弧结点
{
    int adjvex;         //邻接顶点所在表头的下标
    struct ArcNode* nextArc;       //下一条弧
};

template<class T>
struct VertexNode           ///表头结点
{
    T vertex;        //顶点
    ArcNode* firstArc;      //第一条弧
    bool visited;           ///判断是否遍历
};

template<class T>
class ALGraph
{
    VertexNode<T> adjList[MAXSIZE];        ///结点（顶点）表
    int vNum, arcNum;       //顶点个数和弧的数目
public:
    ALGraph(T a[], int n, int e, int arc[][2]);
    ALGraph(T a[], int n);              ///初始化有n个顶点的图
    void CreateGraph(int e);            ///进一步初始化成有e条弧的图，这两步分开是为了VertexShow()函数的实现，方便输入
    ~ALGraph();
    void VertexShow();
    void reset();                   ///用于将遍历后visited[]重置为false，即未访问过的状态
    void DFS(int i);
    void BFS(int i);
};

template<class T>
ALGraph<T>::ALGraph(T a[], int n, int e, int arc[][2])
{
    vNum = n;
    arcNum = e;
    for(int i=0; i<n; ++i)                  ///表头结点的初始化
    {
        adjList[i].vertex = a[i];
        adjList[i].firstArc = NULL;
        adjList[i].visited = false;
    }
    for(int k=0; k<e; ++k)                  ///弧结点初始化
    {
        int j = arc[k][0];
        ArcNode* s = new ArcNode;
        s->adjvex = arc[k][1];              //弧结点数据域保存邻接点所在下标
        s->nextArc = adjList[j].firstArc;       //头插法
        adjList[j].firstArc = s;
    }
}

template<class T>
ALGraph<T>::ALGraph(T a[], int n)            ///建立的是无向图还是有向图呢？？？
{
    vNum = n;
    for(int i=0; i<n; ++i)                  ///表头结点的初始化
    {
        adjList[i].vertex = a[i];
        adjList[i].firstArc = NULL;
        adjList[i].visited = false;
    }
}

template<class T>
void ALGraph<T>::CreateGraph(int e)
{
    arcNum = e;
    int i, j;
    std::cout<<"请输入关联顶点所在下标：\n";
    for(int k=0; k<e; ++k)
    {
        std::cin>>i>>j;     //输入顶点和其邻接顶点所在下标
        ArcNode* s = new ArcNode;
        s->adjvex = j;              //弧结点数据域保存邻接点所在下标
        s->nextArc = adjList[i].firstArc;       //头插法
        adjList[i].firstArc = s;
    }
}

template<class T>
ALGraph<T>::~ALGraph()
{
    ArcNode* p;
    //int cnt=0;
    for(int i=0; i<vNum; ++i)
        while(adjList[i].firstArc!=NULL)
        {
            p = adjList[i].firstArc;
            adjList[i].firstArc = p->nextArc;
            delete p;
            //std::cout<<cnt++<<"\n";测试析构了几条弧
        }
}

template<class T>
void ALGraph<T>::DFS(int i)
{
    std::cout<<adjList[i].vertex<<" ";
    adjList[i].visited = true;
    ArcNode* p = adjList[i].firstArc;
    while(p)
    {
        int j = p->adjvex;
        if(adjList[j].visited==false)
            DFS(j);
        p = p->nextArc;
    }
    for(int i=0; i<vNum; ++i)
        if(adjList[i].visited==false)
            DFS(i);
}

template<class T>
void ALGraph<T>::BFS(int i)
{
    ArcNode* p;
    int queue[MAXSIZE];
    int f=0, r=0;
    std::cout<<adjList[i].vertex<<" ";
    adjList[i].visited = true;
    queue[++r] = i;
    while(f!=r)
    {
        i = queue[++f];
        p = adjList[i].firstArc;
        while(p)
        {
            int j = p->adjvex;
            if(adjList[j].visited==false)
            {
                std::cout<<adjList[j].vertex<<" ";
                adjList[j].visited = true;
                queue[++r] = j;
            }
            p = p->nextArc;
        }
    }
    for(int i=0; i<vNum; ++i)
        if(adjList[i].visited==false)
            BFS(i);
}

template<class T>
void ALGraph<T>::reset()
{
    for(int i=0; i<vNum; ++i)
        adjList[i].visited = false;
}

template<class T>
void ALGraph<T>::VertexShow()
{
    std::cout<<"================顶点与下标对照表================\n";
    for(int i=0; i<vNum; ++i)
        std::cout<<adjList[i].vertex<<"   |";
    std::cout<<std::endl;
    for(int i=0; i<vNum; ++i)
        std::cout<<i<<"   |";
    std::cout<<"\n================================================\n";
}

///2018.2.9晚