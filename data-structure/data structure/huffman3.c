// coding decoding of a huffman tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode // 结点结构，哈夫曼树与频度链表共用
{
    char c;                  // 结点的字符
    int frequency;           // 字符的频度
    char *code;              // 字符的编码(对哈夫曼树结点有效)
    struct ListNode *parent; // 结点的双亲结点(对哈夫曼树结点有效)
    struct ListNode *left;   // 结点的左子树(对哈夫曼树结点有效)
    struct ListNode *right;  // 结点的右子树(对哈夫曼树结点有效)
    struct ListNode *next;   // 结点的后继结点(对频度链表结点有效)
} ListNode, HuffmanTree;

// 将字符加入频度链表
void addNode(ListNode **head, char ch)
{
    ListNode *node = *head;
    while (node != NULL)
    {
        if (node->c == ch)
        { // 如果字符已存在，则频度加1
            node->frequency++;
            return;
        }
        node = node->next;
    }
    // 新建结点插入频度链表
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->c = ch;
    new_node->frequency = 1;
    new_node->code = NULL;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->next = *head;
    *head = new_node;
}

// 对频度链表进行排序
void sortList(ListNode **head)
{
    ListNode *node_i = *head;
    while (node_i != NULL)
    {
        ListNode *node_j = node_i->next;
        while (node_j != NULL)
        {
            if (node_j->frequency <= node_i->frequency)
            { // 冒泡排序，按照频度从低到高排列
                // 交换结点
                char temp_c = node_i->c;
                int temp_f = node_i->frequency;
                node_i->c = node_j->c;
                node_i->frequency = node_j->frequency;
                node_j->c = temp_c;
                node_j->frequency = temp_f;
            }
            node_j = node_j->next;
        }
        node_i = node_i->next;
    }
}
void buildHuffmanTree(ListNode **head)
{
    ListNode *node = *head;
    while (node->next != NULL)
    {
        // 从频度链表中取出频度最小的两个结点
        ListNode *node1 = node;
        ListNode *node2 = node->next;
        // 新建结点作为双亲结点
        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
        new_node->c = '\0';
        new_node->frequency = node1->frequency + node2->frequency;
        new_node->code = NULL;
        new_node->parent = NULL;
        new_node->left = node1;
        new_node->right = node2;
        new_node->next = node2->next;
        // 将双亲结点插入频度链表
        node = *head;
        if (node->frequency >= new_node->frequency)
        {
            new_node->next = node;
            *head = new_node;
        }
        else
        {
            while (node->next != NULL && node->next->frequency < new_node->frequency)
            {
                node = node->next;
            }
            new_node->next = node->next;
            node->next = new_node;
        }
        // 将双亲结点的左右孩指针指向两结点
        node1->parent = new_node;
        node2->parent = new_node;
        // 从频度链表中删除频度最小的两个结点
        node = *head;
        if (node == node1)
        {
            *head = node->next;
        }
        else
        {
            while (node->next != node1)
            {
                node = node->next;
            }
            node->next = node1->next;
        }
        node = *head;
        if (node == node2)
        {
            *head = node->next;
        }
        else
        {
            while (node->next != node2)
            {
                node = node->next;
            }
            node->next = node2->next;
        }
        node = *head;
    }
}
// 递归遍历Huffman树，生成编码，并利用散列表存储编码
char *bitmap[260];
void generate_code(ListNode *headH, char *code, int len)
{
    HuffmanTree *head = (ListNode *)headH;
    if (head->left != NULL)
    {
        code[len] = '0';
        generate_code(head->left, code, len + 1);
    }
    if (head->right != NULL)
    {
        code[len] = '1';
        generate_code(head->right, code, len + 1);
    }
    if (head->c != '\0')
    {
        int intchar = (int)head->c;
        bitmap[intchar] = (char *)malloc(sizeof(char) * (len + 1));
        head->code = (char *)malloc(sizeof(char) * (len + 1));
        for (int i = 0; i < len; i++)
        {
            head->code[i] = code[i];
            bitmap[intchar][i] = code[i];
        }
        head->code[len] = '\0';
        bitmap[intchar][len] = '\0';
    }
}
// 利用huffman树对字符串进行编码
char *encodeHuffmanTree(char *code)
{
    char *str = (char *)malloc(sizeof(char) * 10000);
    memset(str, '\0', sizeof(str));
    int i = 0;
    while (code[i] != '\0')
    {
        strcat(str, bitmap[code[i++]]);
    }
    str[strlen(str)] = '\0';
    printf("%s\n", str);
    return str;
}
void decodeHuffmanTree(char *code, ListNode *head)
{
    ListNode *node = head;
    int i = 0;
    while (code[i] != '\0')
    {
        if (code[i] == '0')
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        if (node->c != '\0')
        {
            printf("%c", node->c);
            node = head;
        }
        i++;
    }
    printf("%d", strlen(code));
}
char *read()
{
    char *str = (char *)malloc(sizeof(char) * 1000);
    char c;
    int i = 0;
    while ((c = getchar()) != EOF)
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    return str;
}
int main()
{
    int wpl = 0;
    // 建立频度链表并插入一些字符
    ListNode *head = NULL;
    // addNode(&head, 'a');
    ListNode *start = (ListNode *)malloc(sizeof(ListNode));
    char *c1 = "Data structure experiment";
    char *c2 = "HuffmanTree";
    char *c3 = "metro line";
    int i = 0;
    while (c1[i] != '\0')
    {
        addNode(&head, c1[i++]);
    }
    i = 0;
    addNode(&head, '\n');
    while (c2[i] != '\0')
    {
        addNode(&head, c2[i++]);
    }
    i = 0;
    addNode(&head, '\n');
    while (c3[i] != '\0')
    {
        addNode(&head, c3[i++]);
    }
    // 对频度链表排序
    sortList(&head);
    start = head;
    // 采用原址建立的方法，利用上一关得到的频度链表，将频度链表中的结点作为哈夫曼树中的结点，建立哈夫曼树。算法循环执行的每一次循环中，从还没有指定双亲指针的结点中选择频度最小的元素和频度次小的两结点。创建其二者的双亲结点并设置二者的双亲指针指向该结点，同时使双亲结点的左右孩指针指向两结点。之后将生成的双亲结点插入到频度链表中。循环执行至除根结点外的所有结点都具有双亲指针为止，哈夫曼树建立成功。
    // 先序遍历哈夫曼树，得到各个叶子结点的哈夫曼编码，并按上一关中的顺序输出相应的哈夫曼编码。
    // 并在最后一行输出哈夫曼树的带权路径长度，权重为字符的频度。
    // 根据提示，在右侧编辑器补充相应代码。
    buildHuffmanTree(&head);
    char code[100];
    int depth = 0;
    ListNode *node = head;
    while (node->right != NULL)
    {
        node = node->right;
        depth++;
    }
    // printf("%d", depth);
    generate_code(head, code, 0);
    ListNode *node1 = start;
    while (node1->next != NULL)
    {
        if (node1->c != '\0')
        {
            int len = strlen(node1->code);
            wpl += len * node1->frequency;
        }
        node1 = node1->next;
    }
    decodeHuffmanTree(encodeHuffmanTree(read()), head);
    return 0;
}
