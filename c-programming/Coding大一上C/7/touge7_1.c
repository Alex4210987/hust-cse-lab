//① 输入每个学生的各项信息。
//② 输出每个学生的各项信息。
//③ 修改指定学生的指定数据项的内容。
//④ 统计每个同学的平均成绩（保留2位小数）。
//⑤ 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。
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
	struct doc *data; /* 数据域 */
	struct list *next; /* 指针域 */
};
void myExit(struct list **plist);
void inputInfo(struct list **plist);
void outputInfo(struct list **plist);
void changeInfo(struct list **plist);
void average(struct list **plist);
void outputAll(struct list **plist);
void create_list(struct list **headp);

void (*execute[])(struct list **) =
{myExit, inputInfo, outputInfo, changeInfo, average, outputAll};

int main() {
	struct list *head = NULL;
	char c;
	create_list(&head);
	while (c = getchar()) {
		if (c != '0') {
			execute[c - '0'](&head);
		} else
			break;
		getchar();
	}
	execute[0](&head);
	return 0;
}
void create_list(struct list **headp) {
	struct list *loc_head = NULL, * tail;
	int i = 0;
	loc_head = (struct list *)malloc(sizeof(struct list));/* loc_head指向动态分配的第一个结点 */
	tail = loc_head; /* tail指向第一个结点 */
	while (i < MAXN) {
		/* tail所指结点的指针域指向动态创建的结点 */
		tail->next = (struct list *)malloc(sizeof(struct list));
		tail = tail->next; /* tail指向新创建的结点 */
		i++;
	}
	tail->next = NULL; /* 对指针域赋NULL值 */
	*headp = loc_head; /* 使头指针headp指向新创建的链表 */
}
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

		for (int t = 0; t <= 3; t++) {
			scanf("%d", &tmpList->data->score[t]);
			tmpList->data->sum += (tmpList->data->score[t]);
			tmpList->data->aveScore = (double)(tmpList->data->sum) / 4;
		}
		tmpList->next = (struct list *)malloc(sizeof(struct list));
		tmpList = tmpList->next;
		j++;
	}
	tmpList->data = NULL;
	printf("完成了%d位同学的成绩输入\n", i);
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

		for (int t = 0; t <= 3; t++) {
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
			for (int t = 0; t <= 3; t++) {
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