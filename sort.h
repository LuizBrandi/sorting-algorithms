void * access(void * v, int i, int typeSize);
void swap(void * a, void * b, int typeSize);

void bubble(void * v, int vSize, int typeSize, int (* cmp)(const void * a, const void * b));
void quick(int size, int * v, int typeSize, int (* cmp)(const void * a, const void * b));