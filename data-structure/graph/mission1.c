//Your code begin.
//示例仅供参考，你也可以自行修改设计。
#define _CRT_SECURE_NO_WARNINGS
#define MAX_VERTEX_NUM 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arcNode //作为邻接表头节点所指向的边
{
    char name1[50];          //存储指向的节点
    float dist;
    struct arcNode* next;
} arcNode;
typedef struct VNode //作为邻接表头节点
{
    char name[50]; //存储站点名称          
    arcNode* add;
    int start, end;
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;
    int vexnum;//当前结点数
}ALGraph;//存储图
void CreateGraph(ALGraph* G) {
    G->vexnum = 0;
    int i = 0, j = 0;
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        G->vertices[i].add = NULL;
        G->vertices[i].start = 0;
        G->vertices[i].end = 0;
    }//一开始不存在任何边
}//初始化图
int LocatedVex(ALGraph* G, char* str) {
    int i = 0;
    for (i = 0; i < G->vexnum; i++) {
        if (strcmp(G->vertices[i].name, str) == 0)
            return i;
    }
    return -1;
}//找到目标结点
int InsertVex(ALGraph* G, char* str) {
    strcpy(G->vertices[G->vexnum].name, str);
    (G->vexnum)++;
    return (G->vexnum) - 1;
}//插入结点
void InsertArc(ALGraph* G, char str1[], char str2[], float weight) {
    int i = LocatedVex(G, str1);//检查结点是否存在
    arcNode* p;
    if (i == -1) {
        i = InsertVex(G, str1);
    }//图中没有结点，创造结点
    G->vertices[i].start++;//作为起点次数+1
    p = G->vertices[i].add;
    if (p == NULL) {
        G->vertices[i].add = (arcNode*)malloc(sizeof(arcNode));
        p = G->vertices[i].add;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = (arcNode*)malloc(sizeof(arcNode));
        p = p->next;
    }
    strcpy(p->name1, str2);
    p->dist = weight;
    p->next = NULL;//处理完第一个

    i = LocatedVex(G, str2);//检查结点是否存在
    if (i == -1) {
        i = InsertVex(G, str2);
    }//图中没有结点，创造结点
    G->vertices[i].end++;//作为终点次数+1
    p = G->vertices[i].add;
    if (p == NULL) {
        G->vertices[i].add = (arcNode*)malloc(sizeof(arcNode));
        p = G->vertices[i].add;
    }
    else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = (arcNode*)malloc(sizeof(arcNode));
        p = p->next;
    }
    strcpy(p->name1, str1);
    p->dist = weight;
    p->next = NULL;
}//插入边
void Search_PrintRepeated(ALGraph* G) {
    int i = 0, min = 0;
    int number = 1;
    arcNode* p = NULL, * q = NULL;
    int flag = 0;
    for (i = 0; i < G->vexnum; i++ , number = 1) {
        p = G->vertices[i].add;
        while (p->next != NULL) {
            p = p->next;
            number++;
        }
        if (G->vertices[i].start + G->vertices[i].end > 2) {
            printf("%s %d\n", G->vertices[i].name, number);
        }
        else continue;
    }
}//找到并打印换乘站
int main(void)
{
    ALGraph* Graph = (ALGraph*)malloc(sizeof(ALGraph));
    char tmp1[50], tmp2[50];
    char end[8] = "END!";
    float weight;
    CreateGraph(Graph);//初始化图
    scanf("%s", tmp1);
    while (strcmp(tmp1, end) != 0) {
        scanf("%s %f", tmp2, &weight);
        InsertArc(Graph, tmp1, tmp2, weight);
        scanf("%s", tmp1);
    }//输入数据
    Search_PrintRepeated(Graph);//输出结果
    return 0;
}
//Your code end.
/*
循礼门 积玉桥 1.3
中山公园 积玉桥 0.9
积玉桥 江汉路 3.6
光谷广场 积玉桥 1.6
光谷广场 华中科技大学 2.4
宝通寺 积玉桥 4.4
大智路 宝通寺 1.1
街道口 宝通寺 0.8
昙华林 江汉路 1.8
中南路 江汉路 5.2
江汉路 光谷广场 2.7
光谷广场 珞雄路 3.1
宝通寺 光谷广场 3.6
END!*/