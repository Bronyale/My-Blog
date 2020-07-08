#include <iostream>
using namespace std;
 
int n, m;
 
int partion(int* array, int low, int high)
{
	int index = low;
	int pivot = array[ index ];
	swap(array[ index ], array[ high ]);
	
	for(int i = low; i < high; i ++)
	{
		if(array[ i ] > pivot)
		{
			swap(array[ i ], array[ index ++ ]);
		} 
	}
	swap(array[ index ], array[ high ]);
	return index;
}
 
void quicksort(int* array, int low, int high)
{
	if(low >= high)
	{
		return;
	}
	
	int p = partion(array, low, high);
	quicksort(array, low, p - 1);
	quicksort(array, p + 1, high);	
}
 
int main()
{
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		int *num = new int[ n ];
		
		int i = 0;
		while(i < n)
		{
			scanf("%d", &num[ i ++ ]);
		}	
		quicksort(num, 0, n - 1);
		
		for(i = 0; i < m; i ++)
		{
			cout<<num[ i ];
			if(i != m - 1)
			{
				cout<<" ";		
			}
		}
		cout<<endl;
	
		delete num;
	}
	return 0;
}
