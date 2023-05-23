#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    char c;
    int frequency;
    char *code;
    struct ListNode *parent;
    struct ListNode *left;
    struct ListNode *right;
    struct ListNode *next;
} ListNode, HuffmanTree;

void addNode(ListNode **head, char ch)
{
    ListNode *node = *head;
    while (node != NULL)
    {
        if (node->c == ch)
        {
            node->frequency++;
            return;
        }
        node = node->next;
    }

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

void sortList(ListNode **head)
{
    ListNode *node_i = *head;
    while (node_i != NULL)
    {
        ListNode *node_j = node_i->next;
        while (node_j != NULL)
        {
            if (node_j->frequency >= node_i->frequency)
            {
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
    int end = 1;
    while ((*head)->next != NULL && end == 1)
    {
        // 选择频度最小的两个结点
        // 其实是最大的节点，因为是从大到小排序的
        ListNode *min1 = *head, *min2 = (*head)->next;
        if (((*head)->next->next) != NULL)
            *head = (*head)->next->next;
        else
            end = 0;
        min1->next = NULL;
        min2->next = NULL;

        // 创建它们的双亲结点
        ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
        new_node->c = '\0';
        new_node->frequency = min1->frequency + min2->frequency;
        new_node->code = NULL;
        new_node->parent = NULL;
        new_node->left = min1;
        new_node->right = min2;

        // 设置它们的双亲指针
        min1->parent = new_node;
        min2->parent = new_node;

        // 将双亲结点插入频度链表
        ListNode *node = *head;
        if (new_node->frequency < node->frequency)
        {
            new_node->next = node;
            *head = new_node;
        }
        else
        {
            while (node->next != NULL && new_node->frequency >= node->next->frequency)
            {
                node = node->next;
            }
            new_node->next = node->next;
            node->next = new_node;
        }
    }
}

// 定义一个字符串数组来存储编码
char code_table[256][256];
int freq_table[256];
// 递归遍历Huffman树，生成编码
void generate_code(ListNode *node, char *code, int depth)
{
    if (!node)
    {
        return;
    }
    if (!node->left && !node->right)
    {
        // 当前节点是叶子节点，将对应字符的编码存储到code_table数组中
        code[depth] = '\0';
        strcpy(code_table[node->c], code);
        return;
    }
    code[depth] = '0';
    generate_code(node->left, code, depth + 1);
    code[depth] = '1';
    generate_code(node->right, code, depth + 1);
}

// 输出Huffman树编码
void print_huffman_code(ListNode *root)
{
    char code[256];
    generate_code(root, code, 0);
    for (int i = 0; i < 256; i++)
    {
        if (strlen(code_table[i]) > 0)
        {
            printf("'%c': %s\n", i, code_table[i]);
        }
    }
}
int calculateWPL(ListNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->frequency;
    int left_wpl = calculateWPL(root->left);
    int right_wpl = calculateWPL(root->right);
    return left_wpl + right_wpl + root->frequency;
}

int main()
{
    // 建立频度链表并插入一些字符
    ListNode *head = NULL;
    char c;
    while ((c = getchar()) != EOF)
    {
        addNode(&head, c);
    }
    // 对频度链表排序
    sortList(&head);

    // 建立哈夫曼树
    buildHuffmanTree(&head);
    ListNode *root = head;
    // 生成哈夫曼编码
    char *code = (char *)malloc(sizeof(char));
    *code = '\0';
    // 输出各个字符的哈夫曼编码
    // ListNode *node = head;
    // 计算带权路径长度并输出
    print_huffman_code(root);
    int wpl = calculateWPL(root);
    printf("WPL=%d\n", wpl);
    return 0;
}