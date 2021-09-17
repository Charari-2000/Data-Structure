#include "Sort.h"
#include "Stack.h"

/****************************************************/
void InsertSort(DataType* a, int n, Cmp Order)
{
    int i = 0, j = 0, key = 0;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && Order(key, a[j], false))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void BInsertSort(DataType* a, int n, Cmp Order)
{
    int i = 0, j = 0, key = 0;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (key > a[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        for (j = i - 1; j > right; j--)
            a[j + 1] = a[j];
        a[right + 1] = key;
    }
}

void TwoWaysInsertSort(DataType* a, int n, Cmp Order)
{
    int first = 0, final = 0, subs = 0;
    int* tmp = (int*)malloc(n * sizeof(int));
    tmp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < tmp[first])				//小于最小
        {
            first = (int)((first - 1 + n) % n);
            tmp[first] = a[i];
        }
        else if (a[i] > tmp[final])		//大于最大
        {
            final++;
            tmp[final] = a[i];
        }
        else
        {
            subs = (int)((final + 1) % n);
            while (Order(a[i], tmp[(subs - 1 + n) % n], false))
            {
                tmp[subs] = tmp[(subs - 1 + n) % n];
                subs = (int)((subs - 1 + n) % n);
            }
            tmp[subs] = a[i];
            final = (int)((final + 1) % n);
        }
    }
    for (subs = 0; subs < n; subs++)
        a[subs] = tmp[(first + subs) % n];
    free(tmp);
}

void TableInsertSort(DataType* a, int n, Cmp Order)
{
    struct rc { int data; int next; };
    struct rc* Tbl;
    Tbl = (struct rc*)malloc((n + 1) * sizeof(struct rc));
    Tbl[0].data = Order(1, 2, true) ? INT_MIN : INT_MAX;
    Tbl[0].next = 1;
    Tbl[1].data = a[0];
    Tbl[1].next = null;
    for (int subs = 1; subs < n; subs++)
    {
        struct rc* ptr = Tbl;
        struct rc* pre = NULL;
        while (Order(ptr->data, a[subs], false))
        {
            pre = ptr;
            if (ptr->next != null)
                ptr = &Tbl[ptr->next];
            else
                break;
        }
        Tbl[subs + 1].data = a[subs];
        Tbl[subs + 1].next = pre->next;
        pre->next = subs + 1;
    }
    int next_subs = Tbl[0].next;
    for (int subs = 0; subs < n; subs++)
    {
        a[subs] = Tbl[next_subs].data;
        next_subs = Tbl[next_subs].next;
    }
    free(Tbl);
    Tbl = NULL;
}


/********************************************************/
static
void ShellInsert(DataType* a, int n, int dk, Cmp Order)
{
    int i = 0, j = 0, key = 0;
    for (int i = dk; i < n; i++)
    {
        key = a[i];
        j = i - dk;
        while (j >= 0 && Order(key, a[j], false))
        {
            a[j + dk] = a[j];
            j -= dk;
        }
        a[j + dk] = key;
    }
}

/* 表现优秀的步长序列：
 * Sedgewick：{ 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 64769, 146305, 260609, 587521, 1045505, 2354689, 4188161, 9427969, 16764929, 37730305, 67084289, 150958081, 268386305, 603906049, 1073643521, 2415771649, 4294770689, 9663381505, 17179475969 }
 * Fibonacci: { 1, 9, 34, 182, 836, 4025, 19001, 90358, 428481, 2034035, 9651787, 45806244, 217378076, 1031612713 }
 */
void ShellSort(DataType* a, int n, Cmp Order)
{
    int dk[] = { 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1 };
    int len_dk = sizeof(dk) / sizeof(dk[0]);
    for (int i = 0; i < len_dk; i++) {
        if ( dk[i] > n - 1 )
            continue;
        ShellInsert(a, n, dk[i], Order);
    }
}


/*************************************************/
void SelectSort(DataType* a, int n, Cmp Order)
{
    int extremum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        extremum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Order(a[j], a[extremum], false))
                extremum = j;
        }
        swap(&a[i], &a[extremum]);
    }
}


/******************************************************/
static
void _Adjust(DataType* a, int n, int root, Cmp Order)
{
    int cur = root;
    int child = cur * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && Order(a[child], a[child + 1], false))
            child++;
        if (Order(a[child], a[cur], false))
            break;
        swap(&a[child], &a[cur]);
        cur = child;
        child = cur * 2 + 1;
    }
}

static
void AdjustDown(DataType* a, int end, Cmp Order)
{
    int cur = 0;
    int child = cur * 2 + 1;
    while (child < end - 1)
    {
        if (child + 1 < end - 1 && Order(a[child], a[child + 1], false))
            child++;
        if (Order(a[child], a[cur], false))
            break;
        swap(&a[child], &a[cur]);
        cur = child;
        child = cur * 2 + 1;
    }
}

static
void HeapCreate(DataType* a, int n, Cmp Order)
{
    int pos = (int)((n - 2) / 2);
    while (pos >= 0)
    {
        _Adjust(a, n, pos, Order);
        pos--;
    }
}

void HeapSort(DataType* a, int n, Cmp Order)
{
    HeapCreate(a, n, Order);
    for (int i = 0; i < n - 1; i++)
    {
        swap(&a[0], &a[n - 1 - i]);
        AdjustDown(a, n - i, Order);
    }
}


/***********************************************/
void BubbleSort(DataType* a, int n, Cmp Order)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (Order(a[j + 1], a[j], false))
                swap(&a[j], &a[j + 1]);
        }
    }
}


/************************************************/

static void getPivot_random(DataType* a, int left, int right)
{
    srand((unsigned)time(NULL));
    int subs = rand() % (right - left + 1) + left;
    swap(&a[subs], &a[left]);
}

static void getPivot_average(DataType* a, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[left] < a[mid])
        swap(&a[left], &a[mid]);
    if (a[right] < a[left])
        swap(&a[right], &a[left]);
    if (a[left] < a[mid])
        swap(&a[left], &a[mid]);
}
static typeof(void(*)(DataType*, int, int)) getPivot[2] = { getPivot_random, getPivot_average };

static int PartSort_hoare(DataType* a, int left, int right, Cmp Order)
{
    getPivot[0](a, left, right);
    DataType key = a[left];
    while (left < right)
    {
        while (left < right && Order(key, a[right], true))
            right--;
        swap(&a[left], &a[right]);
        while (left < right && Order(a[left], key, true))
            left++;
        swap(&a[left], &a[right]);
    }
    return left;
}

// Dig Hole Version
static int PartSort_digHole(DataType* a, int left, int right, Cmp Order)
{
    getPivot[0](a, left, right);
    DataType key = a[left];
    while (left < right) {
        while (left < right && Order(key, a[right], true))
            right--;
        a[left] = a[right];
        while (left < right && Order(a[left], key, true))
            left++;
        a[right] = a[left];
    }
    a[left] = key;
    return left;
}

// PrePost Pointer Version
static int PartSort_prePostPointer(DataType* a, int left, int right, Cmp Order)
{
    getPivot[1](a, left, right);
    DataType key = a[left];
    int prev = left;
    int cur = left + 1;
    while (cur <= right) {
        if (Order(a[cur], key, true)) {
            prev++;
            if (prev != cur)
                swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    swap(&a[left], &a[prev]);
    return prev;
}

static typeof(int(*)(DataType*, int, int, Cmp)) PartSort[3] = { PartSort_hoare, PartSort_digHole, PartSort_prePostPointer };

static void QuickSelect(DataType* a, int left, int right, Cmp Order)
{
    if (left >= right)
        return;
    if (right - left + 1 <= 5)
        TwoWaysInsertSort(a, right - left + 1, Order);
    int pos = PartSort[2](a, left, right, Order);
    QuickSelect(a, left, pos - 1, Order);
    QuickSelect(a, pos + 1, right, Order);
}

void QuickSort(DataType* a, int n, Cmp Order)
{
    QuickSelect(a, 0, n - 1, Order);
}

void QuickSortNonR(DataType* a, int n, Cmp Order)
{
    int left = 0, right = n - 1;
    Stack s;
    StackInit(&s);
    StackPush(&s, left);
    StackPush(&s, right);
    while (!StackEmpty(&s)) {
        right = StackTop(&s);
        StackPop(&s);
        left = StackTop(&s);
        StackPop(&s);
        if (right - left + 1 <= 1)
            continue;

        int pos = PartSort[2](a, left, right, Order);
        StackPush(&s, left);
        StackPush(&s, pos - 1);
        StackPush(&s, pos + 1);
        StackPush(&s, right);
    }
}


/*********************************************/
static void Merge(DataType* a, int left, int mid, int right, Cmp Order)
{
    int i = left, j = mid + 1, k = 0;
    DataType* tmp = (DataType*)malloc((right - left + 1) * sizeof(DataType));
    while (i <= mid && j <= right) {
        if (Order(a[i], a[j], false))
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    if (i <= mid) {
        while (k < right - left + 1)
            tmp[k++] = a[i++];
    }
    if (j <= right) {
        while (k < right - left + 1)
            tmp[k++] = a[j++];
    }
    memcpy(a + left, tmp, (right - left + 1) * sizeof(DataType));
    free(tmp);
}

static void divide(DataType* a, int left, int right, Cmp Order)
{
    if (right <= left)
        return;
    int mid = (left + right) / 2;
    divide(a, left, mid, Order);
    divide(a, mid + 1, right, Order);
    Merge(a, left, mid, right, Order);
}

void MergeSort(DataType* a, int n, Cmp Order)
{
    divide(a, 0, n - 1, Order);
}

void MergeSortNonR(DataType* a, int n, Cmp Order)
{
    for (int step = 1; step < n; step *= 2)
        for (int outset = 0; outset < n - step; outset += 2 * step)
            Merge(a, outset, outset + step - 1, (int)fmin(outset + step * 2 - 1, n - 1), Order);
}

/***********************************************/

static int Pow(int base, int index)
{
    if ( base == 0 )
        return 0;
    if ( index == 0 )
        return 1;
    int ret = 1;
    while ( index != 0 ) {
        if ( index & 1 ) {
            ret *= base;
        }
        base *= base;
        index >>= 1;
    }
    return ret;
}

static int getMaxDigits(const DataType* a, int n)
{
    if ( n == 0 )
        return 0;
    int max = a[0];
    int num = 1, ret = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( max < a[i] )
            max = a[i];
    }
    while ( num *= 10, ret++, max / num != 0 );
    return ret;
}

void RadixSort(DataType* a, int n, Cmp Order)
{
    Order = NULL;
    const int MAX = getMaxDigits(a, n);
    int buk[10][DATA_LEN] = { 0 };
    int end[10] = { 0 };
    int k = 0;
    for ( int index = 1; index <= MAX; index++ ) {
        int num = Pow(10, index);
        for ( int i = 0; i < n; i++ ) {
            int subs = a[i] / ( num / 10 ) % 10;
            buk[subs][end[subs]++] = a[i];
        }
        for ( int i = 0; i < 10; i++ ) {
            for ( int j = 0; j < end[i]; j++ ) {
                a[k++] = buk[i][j];
            }
        }
        memset(end, 0, 10 * sizeof(int));
        k = 0;
    }
}
