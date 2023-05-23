// 使用最短路径算法
// 在前两关的基础上建议使用Dijkstra算法，
// 完成最短路径的寻找

// 注意地铁线路中可能存在环路
// 存储站点并输出
// 考虑使用栈或队列依次存储途径站点最后做输出

// 思考
// 本题若不使用最短路径算法只将图做遍历也可得到最短的路径
// ，但在时间复杂度上差异较大。在处理的图较复杂时，
// 遍历的耗时将远远大于最短路径算法的耗时。
// 因而为了科学地完成本关，建议同学们放弃遍历，
// 使用合适算法得到最短路径。

// 编程要求
// 根据提示，在右侧编辑器补充代码，寻找两站点间的最短路径并依次输出途径站点与途径的总距离
// 输入形式：（地铁线路的建立信息的输入同第一关）
// 站点名1 站点名2 两站相隔的距离
// 站点名3 站点名4 两站相隔的距离
// 站点名1 站点名5 两站相隔的距离
// 注意：此处的站点1即为换乘站
// …………
// END！
// 起点名称 终点名称
// 输出形式：起点名称
// 途径节点1名称 途径节点2名称  …………
// 途径节点n名称 终点 途径的总距离
// 使用邻接表构成图来表达地铁线路，
// 存储武汉地铁若干站点在相邻站点的线路信息，
// 线路信息仅包含两相邻站点名称与其相距的距离。
// 其中地铁线路均为双向线路，不同线路中相同站名的地铁站为转乘车站
// 使用邻接表构造图
// 图的邻接表由两个部分组成：表头结点和边结点，因此创建有向图也分成两部分：一是创建表头结点，二是创建边结点构成的边表。

// 编程要求
// 根据提示，在右侧编辑器补充代码，根据给出的信息建立图
// 并输出所有的中转站点以及与其连接的站点个数
// 输入形式：在本关中用END！结束输入
// 站点名1 站点名2 两站相隔的距离
// 站点名3 站点名1 两站相隔的距离
// 站点名1 站点名5 两站相隔的距离 注意：此处的站点1即为换乘站
// …………
// END！
// 输出形式：
// 换乘站名称1  与换乘站1相邻的站点的个数k1
// 换乘站名称2  与换乘站1相邻的站点的个数k2
// ……
// 换乘站名称n  与换乘站1相邻的站点的个数kn
// 其中换乘站点的输出顺序与在输入信息出现的先后一致
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 20
typedef struct arc // 作为邻接表头节点所指向的边
{
    char name1[2000]; // 存储指向的节点
    float dist;
    struct arc *next;
} arc;
typedef struct node // 作为邻接表头节点
{
    char name[2000]; // 存储站点名称
    arc *add;
    int in, out;
} node;
typedef struct Graph // 图
{
    node *adjlist[MAXNUM];
    int num;
} Graph;
void initGraph(Graph *g) // 初始化图
{
    g->num = 0;
    for (int i = 0; i < MAXNUM; i++)
    {
        g->adjlist[i] = (node *)malloc(sizeof(node));
        g->adjlist[i]->add = NULL;
        g->adjlist[i]->in = 0;
        g->adjlist[i]->out = 0;
    }
}
int searchNode(Graph *g, char *name) // 查找站点名称
{
    for (int i = 0; i < g->num; i++)
    {
        if (strcmp(g->adjlist[i]->name, name) == 0)
            return i;
    }
    return -1;
}
int insertNode(Graph *g, char *name) // 插入节点
{                                    // return the index of the node
    if (g->num == MAXNUM)
        return -1;
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->add = NULL;
    newNode->in = 0;
    newNode->out = 0;
    g->adjlist[g->num] = newNode;
    g->num++;
    return g->num - 1;
}
void insertArc(Graph *g, char *name1,
               char *name2, float dist) // name1 out;name2 in;
{
    int nodeIndex = searchNode(g, name1);
    if (nodeIndex == -1)
    {
        nodeIndex = insertNode(g, name1);
    }
    arc *newArc = (arc *)malloc(sizeof(arc));
    strcpy(newArc->name1, name2);
    newArc->dist = dist;
    newArc->next = g->adjlist[nodeIndex]->add; // 头插法
    g->adjlist[nodeIndex]->add = newArc;
    g->adjlist[nodeIndex]->out++;
    nodeIndex = searchNode(g, name2);
    if (nodeIndex == -1)
    {
        nodeIndex = insertNode(g, name2);
    }
    newArc = (arc *)malloc(sizeof(arc));
    strcpy(newArc->name1, name1);
    newArc->dist = dist;
    newArc->next = g->adjlist[nodeIndex]->add; // 头插法
    g->adjlist[nodeIndex]->add = newArc;
    g->adjlist[nodeIndex]->in++;
}
void printShortestPath(Graph *g, char *name1, char *name2)
{
    int nodeIndex1 = searchNode(g, name1);
    int nodeIndex2 = searchNode(g, name2);
    if (nodeIndex1 == -1 || nodeIndex2 == -1)
        return;
    int *visited = (int *)malloc(sizeof(int) * g->num);    // 用于记录是否访问过
    float *dist = (float *)malloc(sizeof(float) * g->num); // 用于记录距离
    int *path = (int *)malloc(sizeof(int) * g->num);       // 用于记录路径
    for (int i = 0; i < g->num; i++)
    {
        visited[i] = 0;
        dist[i] = 1000000;
        path[i] = -1;
    }
    visited[nodeIndex1] = 1;
    dist[nodeIndex1] = 0;
    arc *p = g->adjlist[nodeIndex1]->add;
    while (p != NULL)
    {
        dist[searchNode(g, p->name1)] = p->dist;
        path[searchNode(g, p->name1)] = nodeIndex1;
        p = p->next;
    }
    int minIndex = nodeIndex1;
    for (int i = 0; i < g->num; i++)
    {
        float min = 1000000;
        for (int j = 0; j < g->num; j++)
        {
            if (visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        p = g->adjlist[minIndex]->add;
        while (p != NULL)
        {
            if (visited[searchNode(g, p->name1)] == 0 && dist[searchNode(g, p->name1)] > dist[minIndex] + p->dist)
            {
                dist[searchNode(g, p->name1)] = dist[minIndex] + p->dist;
                path[searchNode(g, p->name1)] = minIndex;
            }
            p = p->next;
        }
    }
    int *stack = (int *)malloc(sizeof(int) * g->num);
    int top = 0;
    int index = nodeIndex2;
    while (index != nodeIndex1)
    {
        stack[top++] = index;
        index = path[index];
    }
    stack[top++] = nodeIndex1;
    while (top > 0)
    {
        printf("%s ", g->adjlist[stack[--top]]->name);
    }
    printf("%.2f", dist[nodeIndex2]);
    return;
} // find the shortest path between name1 and name2
// use Dijkstra algorithm
int main()
{
    Graph g;
    initGraph(&g);
    char name1[2000], name2[2000];
    float dist;
    char end[8] = "END!";
    while (1)
    {
        scanf("%s", name1);
        if (strcmp(name1, end) == 0)
            break;
        scanf("%s", name2);
        scanf("%f", &dist);
        insertArc(&g, name1, name2, dist);
    }
    scanf("%s%s", name1, name2);
    printShortestPath(&g, name1, name2);
    return 0;
}