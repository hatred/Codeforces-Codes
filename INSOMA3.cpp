#include<cstdio>
#include<cstring>
#include<cstdlib>


void merge(int* a, int p, int mid, int q, int& count)
{
	int* b = (int*)malloc((q-p)*sizeof(int));
	int index1=p;
	int index2=mid;
	int index3=0;
//	printf("%d %d %d anand\n",p,mid,q);

//	for(int i=index1;i<mid;i++){
//		printf("%d ",a[i]);
//	}
//	printf("\n");
//	for(int i=index2;i<q;i++){
//		printf("%d ",a[i]);
//	}
//	printf("\n");
	while(index1<mid && index2<q)
	{
		if(a[index1]>a[index2])
		{
			count+=(q-index2);
			b[index3++]=a[index2];
			index2++;
		}
		else
		{
			b[index3++]=a[index1];
			index1++;
		}
	}
	for(int i=index1;i<mid;i++){
		b[index3++]=a[i];
	}
	for(int i=index2;i<q;i++){
		b[index3++]=a[i];
	}

	index3=0;
	for(int i=p;i<q;i++){
		a[i]=b[index3++];
	}
}

void mergesort(int* a,int p,int q,int& count)
{
	if(q-p==1)
		return;
	int mid = (p+q)/2;
//	if(q-p>2) mid--;
//	printf("%d %d %d\n",p,mid,q);
	mergesort(a,p,mid,count);
	mergesort(a,mid,q,count);
	merge(a,p,mid,q,count);
}

int main(){
	int n;
	scanf("%d",&n);
	int* a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		//printf("%d",a[i]);
	}

	int count = 0;
	mergesort(a,0,n,count);
	printf("%d\n",count);
}