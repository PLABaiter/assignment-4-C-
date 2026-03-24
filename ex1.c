#include <stdio.h>   // thư viện nhập xuất (printf)
#include <stdlib.h>  // thư viện cấp phát động (malloc, free)

/* Định nghĩa cấu trúc node */
struct node {
    int data;           // dữ liệu của node
    struct node* next;  // con trỏ trỏ đến node tiếp theo
};

/* Hiển thị danh sách */
void display(struct node* head) {
    struct node* p = head;     // tạo con trỏ p để duyệt từ đầu

    while (p != NULL) {        // lặp đến khi hết danh sách
        printf("%d ", p->data); // in dữ liệu node hiện tại
        p = p->next;            // chuyển sang node kế tiếp
    }

    printf("\n"); // xuống dòng
}

/* Thêm phần tử vào cuối */
struct node* addback(struct node* head, int data) {

    // cấp phát node mới
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;  // gán dữ liệu
    newnode->next = NULL;  // node cuối nên next = NULL

    // nếu danh sách rỗng
    if (head == NULL)
        return newnode; // node mới chính là head

    struct node* p = head; // bắt đầu từ đầu

    // tìm node cuối
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newnode; // nối node cuối với node mới

    return head; // trả về head
}

/* Tìm phần tử */
struct node* find(struct node* head, int data) {
    struct node* p = head; // bắt đầu từ đầu

    while (p != NULL) {    // duyệt toàn bộ danh sách
        if (p->data == data) // nếu trùng giá trị
            return p;        // trả về node tìm được

        p = p->next; // sang node tiếp
    }

    return NULL; // không tìm thấy
}

/* Xóa node */
struct node* delnode(struct node* head, struct node* pelement) {

    // kiểm tra rỗng hoặc phần tử không tồn tại
    if (head == NULL || pelement == NULL)
        return head;

    // nếu xóa node đầu
    if (head == pelement) {
        struct node* temp = head; // lưu node đầu
        head = head->next;        // dời head sang node tiếp
        free(temp);               // giải phóng bộ nhớ
        return head;
    }

    struct node* p = head;

    // tìm node đứng trước node cần xóa
    while (p->next != pelement) {
        p = p->next;
    }

    // bỏ qua node cần xóa
    p->next = pelement->next;

    free(pelement); // giải phóng node

    return head;
}

/* Hàm main để test */
int main() {

    struct node* head = NULL; // danh sách ban đầu rỗng

    // thêm phần tử
    head = addback(head, 1);
    head = addback(head, 2);
    head = addback(head, 3);

    printf("Danh sach: ");
    display(head);

    // tìm phần tử có giá trị 2
    struct node* p = find(head, 2);

    if (p != NULL)
        printf("Tim thay: %d\n", p->data);

    // xóa node vừa tìm
    head = delnode(head, p);

    printf("Sau khi xoa: ");
    display(head);

    return 0; // kết thúc chương trình
}