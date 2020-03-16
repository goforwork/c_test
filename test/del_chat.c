#include <stdio.h>

/*
* target:delete special charaters behand like space/tab the intputed sentence. 
* And delete sentence that made up by spaces
* Step1: make a function get the input sentences
* Step2: make a function delete somethings in target
*/

// read lines into s, return length
int getline(char s[], int lim);

int remove1(char s[]);

int main()
{
    int lim = 5,len;
    char s[lim];

    // while(getline(s, lim) > 0){
    //     if(remove1(s) > 0){
    //         printf("%s", s);
    //     }
    // }
    getline(s, lim);
    len = remove1(s);
    // printf("%d", len);
    // printf("%s", s);

    return 0;
}

int getline(char s[], int lim)
{
    // 迭代指针
    int c, i;

    // 从标准输入获取一行
    for(i = 0; (c = getchar()) != EOF && c != '\n'; i++){
        if(i < lim - 2){
            s[i] = c;
        } else {
            i--;
            break;
        }
    }
    if(c == '\n'){
        printf("b");
        s[++i] = c;
    }
    if(i > 0){
        s[++i] = '\0';
    }
    return i;
}

int remove1(char s[])
{
    int i;
    // printf("%s", s);
    i = 0;
    // 向后移动迭代指针到换行符前一位
    while(s[i] != '\n'){
        printf("a");
        i++;
    }
    --i;
    printf("%d", i);
    // 向前移动迭代指针到不是空格或者制表符的为止
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')){
        i--;
    }
    // 如果当前行全是空白符则直接返回当前行长度为0
    if(i >= 0){
        i++;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}







