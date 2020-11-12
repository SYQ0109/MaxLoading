#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 21;
int w[N];
int x[N];
int bestx[N];
int found = 0;
int c, cw, bestw, r, n;

//�����Ͻ纯�� 
void backTrack(int i)				//������i���� 
{
	if(i>n)							//����Ҷ��� 
	{
		if(cw>bestw)
		{
			bestw=cw;				//��������ֵ 
		}
		return;
	}
	//�������� 
	r=r-w[i]; 
	if(cw+w[i] <= c)				//x[i]=1;���������� 
	{
		x[i]=1;
		cw+=w[i];
		backTrack(i+1);
		cw-=w[i];
	}
	if(cw+r > bestw)				//x[i]=0;���������� 
	{
		x[i]=0;
		backTrack(i+1);
	}
	r+=w[i];						//��λ 
	return;
 } 
 
 //�������Ž� 
 void BackTrack(int i)
 {
 	if (found)
 		return;
 	if (i>n)						//����Ҷ��� 
 	{
 		for(int j =1;j<=n;j++)
 		{
 			bestx[j]=x[j];
		 }
		 found=1;
		 return;
	 }
	 r-=w[i];
	 if (cw+w[i]<=c)				//���������� 
	 {
	 	x[i]=1;
	 	cw+=w[i];
	 	BackTrack(i+1);
	 	cw-=w[i];
	 }
	 if(cw+r>=bestw)				//���������� 
	 {
	 	x[i]=0;
	 	Backtrack(i+1);
	 }
	 r+=w[i];
	 return;
 }
 
 int main()
 {
 	int casenum=1;
 	int c1,c2;
 	int sum;
 	while(cin >> n)
 	{
 		r=0;
 		found=0;
	 	for(int i = 1;i <=n; i++)
	 	{
	 		cin >> w[i];
	 		r+=w[i];
	 		x[i]=0;
	 		bestx[i]=0;
		 }
		 sum = r;
		 cin >> c1 >> c2;
		 c = c1;
		 cw=0;
		 bestw=0;
		 backTrack(1);
		 cout << "Case " << casenum << endl;
		 if (sum-bestw > c2)
		 {
		 	cout << "NO" << endl;
		 }
		 else
		 {
		 	cout << bestw << " ";
		 	for (int i = 1; i <= n; i++)
		 	{
		 		x[i]=0;
			 }
			 cw=0;
			 r=sum;
			 maxLoading(1);
			 for (int i =1; i<=n;i++)
			 {
			 	cout << bestx[i];
			 }
			 cout << endl;
		 }
		 casenum++;
	 }
 	return 0;
	 
 }
