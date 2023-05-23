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

void findAndPrintChangeStations(Graph g)
{
	int i;
	for (i = 0; i < g.num; i++)
	{
		if (g.adjlist[i]->in > 1 || g.adjlist[i]->out > 1)
		{
			printf("%s %d\n", g.adjlist[i]->name, g.adjlist[i]->in + g.adjlist[i]->out);
		}
	}
}
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
	findAndPrintChangeStations(g);
	return 0;
}