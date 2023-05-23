#include "stdio.h"
#include "stdlib.h"

struct s_list {
	int data; /* ������ */
	struct s_list *next; /* ָ���� */
} ;
void create_list (struct s_list **headp, int *p);

int main(void) {
	struct s_list *head = NULL, *p;
	int s[] = {1, 2, 3, 4, 5, 6, 7, 8, 0}; /* 0Ϊ������� */
	create_list(&head, s); /* ���������� */
	p = head; /*����ָ��pָ����ͷ */
	while (p) {
		printf("%d\t", p->data); /* ����������ֵ */
		p = p->next; /*����ָ��pָ����һ��� */
	}
	printf("\n");
	return 0 ;
}
void create_list(struct s_list **headp, int *p) {
	struct s_list *loc_head = NULL, * tail, *tail_;

	if (p[0] == 0) /* �൱��*p==0 */;
	else {
		/* loc_headָ��̬����ĵ�һ����� */
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++; /* ��������ֵ */
		tail_ = tail = loc_head; /* tailָ���һ����� */
		while (*p) {
			/* tail��ָ����ָ����ָ��̬�����Ľ�� */
			tail = (struct s_list *)malloc(sizeof(struct s_list));
			tail->data = *p++;
			tail->next = loc_head; /* tailָ���´����Ľ�� */
			loc_head = tail; /* ���´����Ľ���������ֵ */
		}
		tail_->next = NULL; /* ��ָ����NULLֵ */
	}
	*headp = loc_head; /* ʹͷָ��headpָ���´��������� */
}