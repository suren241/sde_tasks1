#include<stdio.h>
#define max 15
int cost[max][max],parent[max]={0},min,ne=1,totalmincost=0,a,b;
int find(int i){
	if(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main(){
	int n,v1,i,j,x;
	printf("Enter size of v and e : ");
	scanf("%d%d",&v1,&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cost[i][j]=999;
		}
	}
	printf("Enter v and c:\n");
	while(ne<=n){
		scanf("%d%d%d",&i,&j,&x);
		cost[i][j]=x;
		if(cost[i][j]==0)
			cost[i][j]=999;
		cost[j][i]=cost[i][j];
		ne++;
	}
	ne=1;
	while(ne<n){
		min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=i;
					b=j;
				}
			}
		}
		if(uni(find(a),find(b))){
			printf("E(%d,%d)\tC= %d\n",a,b,min);
			totalmincost+=min;
		}
		cost[a][b]=cost[b][a]=999;
		ne++;
	}
	printf("%d\n",totalmincost);
}
