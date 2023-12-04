#include <stdio.h>
#include <string.h>
struct Contact{
    int id;
    char name[50];
    char phone[12];
    char address[50];
    int status;
};
typedef struct Contact contact;
void input(contact *temp){
    printf("nhap id:");
    scanf("%d",&temp->id);
    printf("nhap ten:");
    getchar();
    gets(temp->name);
    printf("nhap so dien thoai:");
    getchar();
    gets(temp->phone);
    printf("nhap dia chi:");
    getchar();
    gets(temp->address);
    printf("nhap trang thai:");
    scanf("%d",&temp->status);
}
void output( contact *temp){
    printf("ma so:%d, ten :%s, sdt :%s, dia chi:%s, trang thai:%d\n",temp->id, temp->name, temp->phone, temp->address, temp->status);
}
void name_sort(contact temp[], int index){
    for (int i=0; i<index-1; i++) {
		for (int j=0; j<index-i-1; j++) {
			if (temp[j].name > temp[j+1].name) {
				contact t = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
			}
		}
	}
}
int main(){
    int n,i;
    contact contactList[100];
    printf("nhap vao so nguoi co trong danh sach");
    scanf("%d",&n);
    for (i=0;i<n;i++)
        input(&contactList[i]);
    int index = n;
    int check;
	int choice;
    do{
       	printf("\n____________MENU_____________\n");
		printf("1. in toan bo danh sach contact co trong contactList tren cung 1 hang\n");
		printf("2. thuc hien chuc nang them moi contact vao vi tri cuoi cung cua contactList\n");
		printf("3. thuc hien chuc nang cap nhap thong tin cua 1 contact. Cho nguoi dung nhap vao ten contact muon sua, neu tim thay thi cho nguoi dung tien hanh nhap vao thong tin moi cho contact do, neu khogn tim thay in ra man hinh khong tim thay\n");
		printf("4. thuc hien chua nang xoa 1 contact, cho nguoi dung nhap vao ten contact muon xoa, neu tim thay thi cho nguoi dung xoa contact do, neu khong tim thay thi in ra man hinh khong tim thay\n");
		printf("5. thuc hien chuc nang sap xep noi bot, in ra contact da duoc sap xep\n");
		printf("6. thuc hien chuc nang tim kiem nhi phan in ra contact tren cung 1 hang\n");
		printf("7. thuc hien chuc nang tim kiem tuyen tinh\n");
		printf("8. thoat\n");
		printf("lua chon cua ban: ");
		
		scanf("%d", &choice);
        switch(choice){
            case 1:
                for (i=0;i<index;i++){
                    printf("%d:",i+1);
                    output(&contactList[i]);
                }
                break;
            case 2:
                input(&contactList[index]);
                index++;
                break;
            case 3:
			    check = 0;
                char update_name[50];
                
                printf("nhap vao ten muon cap nhat thong tin:");
                getchar();
                gets(update_name);
                for (i=0;i<index;i++){
                    if ( strcmp(contactList[i].name,update_name) == 0 ){
                        input(&contactList[i]);
                        check = 1;
                    }
                }
                if (check == 0) 
                    printf("khong tim thay ten muon cap nhap\n");
                break;
            case 4:
			    check = 0;
                char delete_name[50];
               
                printf("nhap ten nguoi muon xoa:");
                getchar();
                gets(delete_name);
                for (i=0;i<index;i++){
                    if ( strcmp(contactList[i].name,delete_name) == 0 ){
                        for (int j=i;j<index-1;j++)
                            contactList[j] = contactList[j+1];
                            check = 1;
                    }
                }
                index--;
                if (check == 0) 
                    printf("khong tim thay ten nguoi can xoa");
                break;
            case 5:
                name_sort(contactList,index);
                break;
            case 6:
               
                printf("nhap ten can tim kiem:"); 
				int find_name[50];
                getchar();
                gets(find_name);
                int start = 0;
                int end = index;
                int mid;
                while( start<=end ) {
                    mid = (start+end) / 2;
                    if ( strcmp(contactList[mid].name,find_name) == 0 ){
                        break;
                    } else if (contactList[mid].name < find_name) {
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }
                if ( strcmp(contactList[mid].name,find_name) == 0 ) {
                    output(&contactList[mid]);
                } else {
                    printf("Khong tim thay ten can tim ");
                }
                break;
            case 7:
			    check = 0;
                int find_status;
                
                printf("nhap vao gia tri status can tim:");
                scanf("%d",&find_status);
                for (i=0;i<index;i++){
                    if (find_status == contactList[i].status){
                        output(&contactList[i]);
                        check = 1;
                    }
                }
                if (check == 0 )
                    printf("khong tim thay gia tri can tim");
                break;
            case 8:
                printf("thoat\n");
            default:
                printf("khong hop le\n");
        }
    } while(choice != 8);   
}
