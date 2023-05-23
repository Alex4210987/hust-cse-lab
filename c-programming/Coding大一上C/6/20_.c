//将第一个元素保存
index = 0;
num[index++] = array[0][0];
flag = 0;
i = j = 0;
//进行扫描

while (i < n - 1

        && j < n - 1) { //进行上三角半部分扫描(对角线包括在内)   判定条件为<n-1 是因为在上三角部分遍历完在左下角顶点或者右上角订单点
	if (flag % 2 == 0) { //向右
		j++;//向右移动一位
		flag++;
		while (j >= 0) { //遍历左下
			num[index++] = array[i][j];
			i++;
			j--;
		}
		//将越界下标返回
		i--;
		j++;
	} else { //向下
		i++;//向下移动一位
		flag++;
		while (i >= 0) { //遍历右上
			num[index++] = array[i][j];
			i--;
			j++;
		}
		//将越界下标返回
		i++;
		j--;
	}
}

while (i < n && j < n) { //下三角半部分(与上三角半部分相反)
	if (flag % 2 == 0) { //向右
		i++;//向右移动一位
		flag++;
		while (i < n) { //遍历右上
			num[index++] = array[i][j];
			i++;
			j--;
		}
		//将越界下标返回
		i--;
		j++;
	} else { //向下
		j++;//向下移动一位
		flag++;
		while (j < n) { //遍历左下
			num[index++] = array[i][j];
			i--;
			j++;
		}
		//将越界下标返回
		i++;
		j--;
	}
}

for (i = 0; i < index; i++) {
	printf("%d ", num[i]);
}