struct node *insertTail(struct node *h, struct node *t)
{
    if (h == NULL) // 如果链表为空，则插入结点为第一个结点
        return t;
    struct node *p = h;
    while (p->next != NULL) // 遍历到最后一个结点
        p = p->next;
    p->next = t; // 将新结点插入到链表尾部
    return h;    // 返回链表头结点指针
}

void delNode(struct node *h, int e)
{
    struct node *p = h, *pre = NULL;  // p为当前结点，pre为前驱结点
    while (p != NULL && p->data != e) // 遍历链表，查找要删除的结点
    {
        pre = p;
        p = p->next;
    }
    if (p == NULL) // 如果未找到要删除的结点，打印错误信息并退出函数
    {
        printf("error\n");
        return;
    }
    if (pre == NULL) // 如果要删除的结点是头结点
        h = h->next;
    else
        pre->next = p->next; // 删除要删除的结点
    free(p);                 // 释放要删除的结点的内存空间
}
