#include<stdio.h>
#include<conio.h>
#define MAX 10
void NhapN(int &n)
{
	do
	{
		printf("\nMoi ban nhap so luong phan tu n<1 va n>%d:",MAX);
		scanf("%d",&n);
		if(n<=0||n>MAX)
			printf("Ban nhap sai moi nhap lai!");
	}while(n<=0||n>MAX);
}
void NhapMang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void XuatMang(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%4d",a[i]);
}
void XuatChiaHetChoBa(int a[5],int n)
{
	printf("\nCac so chia het cho ba la:");
	for(int i=0;i<n;i++)
	{
		if(a[i]%3==0)
			printf("%d",a[i]);
	}
}
int LaSoNguyenTo(int k)
{
	int dem=0;
	for(int i=1;i<=k;i++)
	{
		if(k%i==0)
			dem++;
	}
	return (dem==2);
}
void XuatNguyenTo(int a[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		if(LaSoNguyenTo(a[i])==1)
			printf("%4d",a[i]);
	}
}
int DemNguyenTo(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(LaSoNguyenTo(a[i])==1)
			dem++;
	}
	return dem;
}
int TongCacSo(int a[],int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		s=s+a[i];
	}
	return s;
}
int TongCacSoNguyenTo(int a[],int n)
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(LaSoNguyenTo(a[i])==1)
			s=s+a[i];
	}
	return s;
}
double TrungBinhCongMang(int a[],int n)
{
	double s=0;
	for(int i=0;i<n;i++)
	{
		s=s+a[i];
	}
	return s/n;
}
double TrungBinhCongNguyenTo(int a[],int n)
{
	double s=0;
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(LaSoNguyenTo(a[i])==1)
		{
			s=s+a[i];
			dem++;
		}
	}
	if(dem==0) return 0;
	return s/dem;
}
int TimDuongDau(int a[],int n)
{
	for(int i=0;i<n;i++)
		if(a[i]>0)
			return a[i];
	return 0;
}
int TimDuongCuoi(int a[],int n)
{
	for(int i=n-1;i>=0;i--)
		if(a[i]>0)
			return a[i];
	return 0;
}
int GiaTriMax(int a[],int n)
{
	int max=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
int GiaTriMin(int a[],int n)
{
	int min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
	}
	return min;
}
int DemSoLon(int a[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(GiaTriMax(a,n)==a[i])
			dem++;
	}
	return dem;
}
void XuatViTriLon(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(GiaTriMax(a,n)==a[i])
			printf("%4d",i);
	}
}
void ThemDau(int a[],int &n,int k)
{
	for(int i=n-1;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	a[0]=k;
	n++;
}
void ThemViTri(int a[],int &n,int k,int &x)
{
	printf("\nMoi chon vi tri them");
	scanf("%d",&x);
	for(int i=n-1;i>=x;i--)
	{
		a[i+1]=a[i];
	}
	a[x]=k;
	n++;
}
void XoaDau(int a[],int &n)
{
	for(int i=0;i<n;i++)
		a[i]=a[i+1];
	n--;	
}
void XoaViTri(int a[],int &n,int k)
{
	for(int i=k;i<n;i++)
		a[i]=a[i+1];
	n--;	
}
int KiemTraMangTang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
			return 0;
	}
	return 1;
}
void TaoMangChan(int a[],int n,int b[],int &m)
{
	m=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
			b[m++]=a[i];
	}
}
int main()
{
	int n;
	int a[MAX];
	int b[MAX];
	NhapN(n);
	NhapMang(a,n);
	printf("\nMang ban vua nhap la:");
	XuatMang(a,n);
	XuatChiaHetChoBa(a,n);
	printf("\nCac so nguyen to la");
	XuatNguyenTo(a,n);
	int kq=DemNguyenTo(a,n);
	if(kq==0)
		printf("\nMang khong co so nguyen to!!!");
	else
		printf("\nSo luong so nguyen to trong mang la:%d",kq);
	int kq1=TongCacSo(a,n);
	printf("\nTong cac so co tong mang la:%d",kq1);	
	int kq3=TongCacSoNguyenTo(a,n);
	printf("\nTong cac so nguyen to co trong mang la:%d",kq3);
	double kq4=TrungBinhCongMang(a,n);
	printf("\nTrung binh cong cac so trong mang la:%.2lf",kq4);
	double kq5=TrungBinhCongNguyenTo(a,n);
	printf("\nTrung binh cong cac so nguyen to la:%.2lf",kq5);
	int kq6=TimDuongDau(a,n);
	if(kq6==0)
		printf("\nMang khong co so duong");
	else
		printf("\nSo duong dau tien la:%d",kq6);
	int kq7=TimDuongCuoi(a,n);
	if(kq7==0)
		printf("\nMang khong co so duong");
	else
		printf("\nSo duong cuoi la:%d",kq7);
	int kq8=GiaTriMax(a,n);
	printf("\nSo lon nhat la:%d",kq8);
	int kq9=GiaTriMin(a,n);
	printf("\nSo nho nhat la:%d",kq9);
	printf("\nSo luong so lon nhat la:%d",DemSoLon(a,n));
	printf("\nVi tri so lon nhat la:");
	XuatViTriLon(a,n);
	int k;
	printf("\nMoi ban nhap gia tri can them o dau:");
	scanf("%d",&k);
	ThemDau(a,n,k);
	printf("\nMang sau khi them la:");
	XuatMang(a,n);
	int x;
	printf("\nMoi ban nhap gia tri can them:");
	scanf("%d",&k);
	ThemViTri(a,n,k,x);
	printf("\nMang sau khi them la:");
	XuatMang(a,n);
	XoaDau(a,n);
	printf("\nMang sau khi xoa dau:");
	XuatMang(a,n);
	printf("\nMoi nhap vi tri can xoa:");
	scanf("%d",&k);
	XoaViTri(a,n,k);
	printf("\nMang sau khi xoa vi tri %d:",k);
	XuatMang(a,n);
	if(KiemTraMangTang(a,n)==1)
		printf("\nMang nay la mang tang!");
	else
		printf("\nMang khong tang!!!");
	int m;
	TaoMangChan(a,n,b,m);
	printf("\nMang sau khi tao:");
	XuatMang(b,m);
}
