#include <stdio.h>
#include<string.h>

#define MaxLength 40

typedef struct{
    char masv[11];
    char hoten[51];
    float lt;
    float th1; 
    float th2;
}SinhVien;

typedef struct{
    SinhVien A[MaxLength];
    int n;
}DanhSach;

void nhap(DanhSach *ds){
    scanf("%d",&ds->n);
    getchar();
    
    for(int i=0;i<ds->n;i++){
        fgets(ds->A[i].masv,sizeof(ds->A[i].masv), stdin);
        if(ds->A[i].masv[strlen(ds->A[i].masv)-1]=='\n') ds->A[i].masv[strlen(ds->A[i].masv)-1]='\0';

        
        fgets(ds->A[i].hoten,sizeof(ds->A[i].hoten), stdin);
         if(ds->A[i].hoten[strlen(ds->A[i].hoten)-1]=='\n') ds->A[i].hoten[strlen(ds->A[i].hoten)-1]='\0';

        
        scanf("%f %f %f", &ds->A[i].lt, &ds->A[i].th1,&ds->A[i].th2);
        getchar();
    }
}
void hienthi(DanhSach ds){
    for(int i=0;i<ds.n;i++){
        printf("%s - %s - %.2f - %.2f - %.2f\n",ds.A[i].masv,ds.A[i].hoten,ds.A[i].lt,ds.A[i].th1,ds.A[i].th2);
    }
}
void ketqua(DanhSach ds){
    int found = 0;

    // Đếm xem có bao nhiêu sv đạt
    for(int i = 0; i < ds.n; i++){
        float Tong = ds.A[i].lt + ds.A[i].th1 + ds.A[i].th2;
        if(Tong <= 4.0){
            found = 1;
            break;
        }
    }

    if(found){
        printf("Sinh vien KHONG DAT\n");   // In 1 lần duy nhất

        for(int i = 0; i < ds.n; i++){
            float Tong = ds.A[i].lt + ds.A[i].th1 + ds.A[i].th2;
            if(Tong <= 4.0){
                printf("%s - %s - %.2f - %.2f - %.2f\n", ds.A[i].masv, ds.A[i].hoten, ds.A[i].lt, ds.A[i].th1, ds.A[i].th2);
            }
        }
    }
    else{
        printf("Khong co sinh vien nao dat.\n");
    }
}

int main(){
    DanhSach L;
    nhap(&L);
    hienthi(L);
    ketqua(L);
    return 0;
}
