// 建立单链表
// 1.频度链表数据结构

//     struct ListNode // 结点结构，哈夫曼树与频度链表共用
// {
//     char c;                  // 结点的字符
//     int frequency;           // 字符的频度
//     char *code;              // 字符的编码(对哈夫曼树结点有效)
//     struct ListNode *parent; // 结点的双亲结点(对哈夫曼树结点有效)
//     struct ListNode *left;   // 结点的左子树(对哈夫曼树结点有效)
//     struct ListNode *right;  // 结点的右子树(对哈夫曼树结点有效)
//     struct ListNode *next;   // 结点的后继结点(对频度链表结点有效)
// } 2.若字符在频度链表中存在，则该字符的频度加1，否则创建新结点并将该结点插入到频度链表中

//     单链表排序
//         对所得到的频度链表进行排序，使得字符的频度按从高到低排列

//             编程要求
//                 根据提示，在右侧编辑器补充代码，建立频度链表并排序，从高到低输出各个字符的频度。 // Your code begin.
// // 示例仅供参考，你也可以自行修改设计
#include <stdio.h>
#include <stdlib.h>

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
            if (node_j->frequency >= node_i->frequency)
            { // 冒泡排序，按照频度从高到低排列
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

int main()
{
    // 建立频度链表并插入一些字符
    ListNode *head = NULL;
    // addNode(&head, 'a');
    char c;
    while ((c = getchar()) != EOF)
    {
        addNode(&head, c);
    }

    // 对频度链表排序
    sortList(&head);
    // 输出各个字符的频度
    ListNode *node = head;
    while (node != NULL)
    {
        if (node->c == '\n')
            printf("'\\n' %d\n", node->frequency);
        else
            printf("'%c' %d\n", node->c, node->frequency);
        node = node->next;
    }

    return 0;
}
