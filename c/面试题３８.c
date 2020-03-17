/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cnt = 0;
void swap(char *p1, char *p2)
{
    char ch = *p1;
    *p1 = *p2;
    *p2 = ch;
}

bool isSwap(char *begin, char *end)
{
    char *ch;
    for (ch = begin; ch != end; ch++) {
        if (*ch == *end) {
            return false;
        }
    }

    return true;
}

void mypermutation(char *s, char *begin, char **arr, int sz)
{
    if (*begin == '\0') {
        memcpy(arr[cnt], s, sz);
        cnt++;
        return;
    }
    for (char *ch = begin; *ch != '\0'; ch++) {
        if (isSwap(begin, ch)) {
            swap(ch, begin);
            mypermutation(s, begin + 1, arr, sz);
            swap(ch, begin);
        }
    }
}

char** permutation(char* s, int* returnSize){
    int sz = strlen(s);
    char **arr = NULL;
    int i;

    cnt = 0;
    *returnSize = 1;
    for (i = 1; i <= sz; i++) {
        *returnSize *= i;
    }
    arr = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (sz + 1));
        memset(arr[i], 0, sizeof(char) * (sz + 1));
    }

    mypermutation(s, s, arr, sz);
    *returnSize = cnt;
    return arr;
}

