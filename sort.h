void * access(void * v, int i, int typeSize);
void swap(void * a, void * b, int typeSize);

void bubble(int vSize, void * v, int typeSize, int (* cmp)(const void * a, const void * b));
void quick(int size, void * v, int typeSize, int (* cmp)(const void * a, const void * b));