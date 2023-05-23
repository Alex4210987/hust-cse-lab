//�� ����ÿ��ѧ���ĸ�����Ϣ��
//�� ���ÿ��ѧ���ĸ�����Ϣ��
//�� �޸�ָ��ѧ����ָ������������ݡ�
//1
//5
//2021001 Jack 90 92 87 95
//2021002 Mike 85 70 75 90
//2021003 Joe 77 86 90 75
//2021004 Andy 95 97 92 95
//2021005 Rose 90 87 88 89
//6
//1 1
//0
//�� ͳ��ÿ��ͬѧ��ƽ���ɼ�������2λС������
//�� �����λͬѧ��ѧ�š����������ſγ̵��ܳɼ���ƽ���ɼ���
#include "stdio.h"
#include "stdlib.h"
#define MAXN 10

struct doc {
	int id;
	char *name;
	int score[4];
	double aveScore;
	int sum;
};

struct list {
	struct doc *data; /* ������ */
	struct list *next; /* ָ���� */
};
void myExit(struct list **plist) {
	free(*plist);
}
void inputInfo(struct list **plist) {
	int i, j = 0;
	struct list *tmpList;
	tmpList = *plist;
	scanf("%d", &i);
	while (j < i) {
		tmpList->data = (struct doc *)malloc(sizeof(struct doc));
		scanf("%d", &tmpList->data->id);
		tmpList->data->name = (char *)malloc(sizeof(char) * 256);
		scanf("%s", tmpList->data->name);
		tmpList->data->sum = 0;
int t = 0;
		for (t = 0; t <= 3; t++) {
			scanf("%d", &tmpList->data->score[t]);
			tmpList->data->sum += (tmpList->data->score[t]);
			tmpList->data->aveScore = (double)(tmpList->data->sum) / 4;
		}
		tmpList->next = (struct list *)malloc(sizeof(struct list));
		tmpList = tmpList->next;
		j++;
	}
	tmpList->data = NULL;
	printf("�����%dλͬѧ�ĳɼ�����\n", i);
	return;
}
//1
//3
//2021001 Jack 90 92 87 95
//2021002 Mike 85 70 75 90
//2021003 Joe 77 86 90 75
void outputInfo(struct list **plist) {
	struct list *tmpList;
	tmpList = *plist;
	while (tmpList->data != NULL) {
		printf("%d ", tmpList->data->id);
		printf("%s ", tmpList->data->name);
int t = 0;
		for (t = 0; t <= 3; t++) {
			printf("%d ", tmpList->data->score[t]);
		}
		printf("\n");
		tmpList = tmpList->next;
	}
}
//3
//2021003 2 96
void changeInfo(struct list **plist) {
	struct list *tmpList;
	int myId, item, t;
	char *k, c = 0;
	k = &c;
	scanf("%d%d", &myId, &item);
	tmpList = *plist;
	while (tmpList->data != NULL) {
		if (tmpList->data->id == myId) {
			if (item == 0) {
				scanf("%s", k);
				tmpList->data->name = k;

			} else {
				scanf("%d", &t);
				tmpList->data->score[item - 1] = t;
			}
			printf("%d ", tmpList->data->id);
			printf("%s ", tmpList->data->name);
			int t = 0;
			for (t = 0; t <= 3; t++) {
				printf("%d ", tmpList->data->score[t]);
			}
			printf("\n");
		}
		tmpList = tmpList->next;
	}
}
void average(struct list **plist) {
	struct list *tmpList;
	tmpList = *plist;
	while (tmpList->data != NULL) {
		printf("%d ", tmpList->data->id);
		printf("%s ", tmpList->data->name);
		printf("%.2lf\n", tmpList->data->aveScore);
		tmpList = tmpList->next;
	}
}
void strcate(char t[], char s[]) {
	int i = -1,  j = 0;
	while ( t[++i]) ;
	while ((t[i++] = s[j++] ) != '\0') ;
}

void strdelc(char s[], char c) {
	int j, k;
	for ( j = 0, k = 0 ; s[j] != '\0' ; j++)
		if (s[j] != c)
			s[k++] = s[j] ;
	s[k++] = 0 ;
}
void outputAll(struct list **plist) {
	struct list *tmpList;
	tmpList = *plist;
	while (tmpList->data != NULL) {
		printf("%d ", tmpList->data->id);
		printf("%s ", tmpList->data->name);
		printf("%d ", tmpList->data->sum);
		printf("%.2lf", tmpList->data->aveScore);
		printf("\n");
		tmpList = tmpList->next;
	}
}
void strsort(char *s[], int size) {
	char *temp ;
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if ( strcmp( s[j], s[j + 1]) > 0 ) {
				temp = s[j];
				s[j] = s[j + 1] ;
				s[j + 1] = temp;
			}
}
void sort(struct list **plist) {
	int sort_o, sort_w, num = 1;
	struct list *tmpList, * p, * k;
	k = *plist;
	while (k++->data != NULL)
		num++;
	tmpList = *plist;
	p = *plist;
	int m = -2;
	scanf("%d %d", &sort_o, &sort_w);
	if (sort_o == 0 && sort_w >=0) {//�����x��
		for (int i = 0; i <= num; i++) {
			for (int j = i; j <= num; j++) {
				if (tmpList->data->aveScore < p->data->aveScore)
					mySwap(&tmpList->data, &p->data);
				if (tmpList->next != NULL)
					tmpList = tmpList->next;
				else
					break;
			}
			if (p->next != NULL)
				p = p->next;
			else
				break;
			tmpList = p;
		}
	}
	if (sort_o == 1 && sort_w >= 0) {//�����x��
		for (int i = 0; i <= num+1; i++) {
			for (int j = i; j <= num+2; j++) {
				if (tmpList->data->aveScore > p->data->aveScore)
					mySwap(&tmpList->data, &p->data);
				if (tmpList->next != NULL)
					tmpList = tmpList->next;
				else
					break;
			}
			if (p->next != NULL)
				p = p->next;
			else
				break;
			tmpList = p;
		}
	}
	if (sort_o == 0 && sort_w*m== 1) { //����ð��
		for (int i = 0; i < num - 1 ; i++) {
			for (int j = i; j < num - 1; j++) {
				if (tmpList->next->data->aveScore < tmpList->data->aveScore)
					mySwap(&tmpList->data, &tmpList->next->data);
				if (j != num - 1)
					tmpList = tmpList->next;
			}
			tmpList = p;
		}
	}
	if (sort_o == 1 && sort_w*m == 1) { //����ð��
		for (int i = 0; i < num - 1; i++) {
			for (int j = i; j < num - 1 ; j++) {
				if (tmpList->next->data != NULL) {
					if (tmpList->next->data->aveScore > tmpList->data->aveScore)
						mySwap(&tmpList->data, &tmpList->next->data);
					if (j != num - 1)
						tmpList = tmpList->next;
				}
			}
			tmpList = p;
		}
	}
	while ((*plist)->data != NULL) {
		printf("%d ", (*plist)->data->id);
		printf("%s ", (*plist)->data->name);
		printf("%.2lf", (*plist)->data->aveScore);
		printf("\n");
		(*plist) = (*plist)->next;
	}
}
//�����Ӱ���ƽ���ɼ���������0��������1������ĺ�����
//д���ý������������ķ�������ĺ����������ָ����ѡ�񷨣�0����ð�ݷ���1����
void mySwap(struct doc **p_1, struct doc **p_2) {
	struct doc *t;
	t = *p_1;
	*p_1 = *p_2;
	*p_2 = t;
}
void create_list(struct list **headp) {
	struct list *loc_head = NULL, * tail;
	int i = 0;
	loc_head = (struct list *)malloc(sizeof(struct list)); /* loc_headָ��̬����ĵ�һ����� */
	tail = loc_head; /* tailָ���һ����� */
	while (i < MAXN) {
		/* tail��ָ����ָ����ָ��̬�����Ľ�� */
		tail->next = (struct list *)malloc(sizeof(struct list));
		tail = tail->next; /* tailָ���´����Ľ�� */
		i++;
	}
	tail->next = NULL; /* ��ָ����NULLֵ */
	*headp = loc_head; /* ʹͷָ��headpָ���´��������� */
}

void (*execute[])(struct list **) =
{ myExit, inputInfo, outputInfo, changeInfo, average, outputAll, sort };

int main() {
	struct list *head = NULL;
	char c = '0';
	create_list(&head);
	while (scanf("%c", &c)) {
		if (c != '0') {
			execute[c - '0'](&head);
		} else
			break;
		getchar();
	}
	execute[0](&head);
	return 0;
}

