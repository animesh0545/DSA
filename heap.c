// Max-Heap data structure in C

#include <stdio.h>

int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

int parent(int i)
{
  return (i - 1) / 2;
}

int lc(int i)
{
  return 2*i + 1;
}

int rc(int i)
{
  return 2*i + 2;
}

//MAX-HEAPIFY -> O(lgn)
void heapify(int array[], int size, int i)
{
  // Find largest among parent and children nodes and 
  if (size == 1)
  {
    return;
  }
  else
  {
    int largest = i;
    int l = lc(i);
    int r = rc(i);
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

//BUILD-MAX-HEAP -> O(n)
void buildHeap(int array[], int size)
{
  //Run heapify from the last internal node to the root node
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}

//HEAP-SORT
void heapSort(int array[], int size)
{
  for (int i = size - 1; i > 0; i--)
  {
    swap(&array[0], &array[i]);
    heapify(array, i, 0);
  }
}

//HEAP-MAXIMUM
int heapMax(int array[], int size)
{
  if (size == 0)
    return -1;
  return array[0];
}


//HEAP_EXTRACT_MAX
int heapExtractMax(int array[])
{
  if (size == 0)
  {
    printf("Heap underflow\n");
    return -1;
  }

  swap(&array[0], &array[size - 1]);
  size -= 1;
  heapify(array, size, 0);
  return array[size];
    
}

//HEAP-INCREASE-KEY
void heapIncreaseKey(int array[], int i, int key)
{
  if (key < array[i])
  {
    printf("New key is smaller\n");
    return;
  }

  array[i] = key;
  while(i > 0 && array[parent(i)] < array[i])
    {
      swap(&array[i], &array[parent(i)]);
      i = parent(i);
    }
}

//MAX-HEAP-INSERT
void maxHeapInsert(int array[], int key)
{
  size++;
  array[size - 1] = -1;
  heapIncreaseKey(array, size - 1, key);
  
  
}





//DELETE
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  buildHeap(array, size);
}

//SUM
int sum(int array[], int size, int i)
{
  if (i >= size)
    return 0;
  return array[i] + sum(array, size, lc(i)) + sum(array, size, rc(i));
    
}


void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10];

  maxHeapInsert(array, 3);
  maxHeapInsert(array, 4);
  maxHeapInsert(array, 9);
  maxHeapInsert(array, 5);
  maxHeapInsert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  // deleteRoot(array, 4);

  // printf("After deleting an element: ");
  // printf("Size = %d\n", size);

  // printArray(array, size);
  // printf("Sum: %d\n", sum(array, size, 0));

  // printf("Extract max: %d\n", heapExtractMax(array));

  // printf("Size = %d\n", size);
  // printArray(array, size);

  // heapSort(array, size);
  // printArray(array, size);

  printf("Max element = %d\n", heapExtractMax(array));
  printArray(array, size);
  heapIncreaseKey(array, 1, 8);
  printArray(array, size);
}