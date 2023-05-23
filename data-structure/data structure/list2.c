#include "slink.h"
bool check(char *str)
{
    sqstack st;
    st.top = -1;
    int n = strlen(str);
    int flag = 1; // 判断是否匹配成功的标志
    for (int i = 0; i < n && flag == 1; i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.data[++st.top] = ch; // 左括号入栈
        }
        else if (ch == ')')
        {
            if (st.top == -1 || st.data[st.top] != '(')
            { // 出栈的元素不是匹配的左括号
                flag = 0;
            }
            else
            {
                st.top--;
            }
        }
        else if (ch == ']')
        {
            if (st.top == -1 || st.data[st.top] != '[')
            { // 出栈的元素不是匹配的左括号
                flag = 0;
            }
            else
            {
                st.top--;
            }
        }
        else if (ch == '}')
        {
            if (st.top == -1 || st.data[st.top] != '{')
            { // 出栈的元素不是匹配的左括号
                flag = 0;
            }
            else
            {
                st.top--;
            }
        }
    }
    if (st.top != -1)
    { // 栈非空，说明有左括号未匹配成功
        flag = 0;
    }
    return flag == 1;
}