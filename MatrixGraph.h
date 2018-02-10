#include<iostream>

const int MAXSIZE=10;

template<class T>
struct Vertex
{
    T data;
    bool visited;
    int weight;             //����Ȩ��
};

template<class T>
class MGraph
{
    Vertex<T> vertex[MAXSIZE];              //�洢����
    int arc[MAXSIZE][MAXSIZE];              //E�洢������Ĺ�ϵ������
    int vNum, arcNum;               //�洢��������ͱ�����������
public:
    MGraph(T a[], int n, int e, int choice=0);          ///choiceĬ��Ϊ0��������ͼ����������ͼ��Ϊ0
    void VertexShow();                  //����λ�ö��ձ�
    void reset();                       //�������������Visited[]��ԭ
    void DFS(int index);                    //������ȱ���
    void BFS(int index);                    //������ȱ���
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
            arc[i][j] = 0;          //��ʼ����
    VertexShow();
    std::cout<<"������������Ķ����ڶ��ձ��е��±꣺\n";
    for(int k=0; k<e; ++k)
    {
        std::cin>>i>>j;
        arc[i][j] = 1;
        if(choice == 0)
            arc[j][i] = arc[i][j];          ///��������ͼ������ͼ����Ҫ��һ��
    }
}

template<class T>
void MGraph<T>::DFS(int i)                          ///�����ڳ���ͼ������ϡ��ͼ�Ļ���ͼ������vNum-1����
{
    std::cout<<vertex[i].data<<" ";
    vertex[i].visited = true;
    for(int j=0; j<vNum; ++j)
    {
        if(arc[i][j]==1 && vertex[j].visited==false)        ///Ѱ�ҹ�����δ�����ʹ��Ľ��
            DFS(j);
    }
    for(int j=0; j<vNum; ++j)                               ///Ѱ�Ҳ�������δ�����ʹ��Ľ��*************
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
    while(f!=r)             //���в�Ϊ��
    {
        i = queue[++f];     //��ͷ����
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
    std::cout<<"============�������±���ձ�============"<<std::endl;
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
