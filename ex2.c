#include <stdio.h>   // nhập xuất
#include <stdlib.h>  // malloc, free

/* Cấu trúc node cây */
struct tnode {
    int data;             // giá trị node
    struct tnode* left;   // con trái
    struct tnode* right;  // con phải
};

/* Tạo node mới */
struct tnode* talloc(int data) {

    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode)); // cấp phát

    p->data = data;   // gán dữ liệu
    p->left = NULL;   // chưa có con trái
    p->right = NULL;  // chưa có con phải

    return p; // trả node
}

/* Thêm node vào cây (BST) */
struct tnode* addnode(struct tnode* root, int data) {

    // nếu cây rỗng → tạo node mới
    if (root == NULL)
        return talloc(data);

    // nếu nhỏ hơn → sang trái
    if (data < root->data)
        root->left = addnode(root->left, data);

    // nếu lớn hơn → sang phải
    else
        root->right = addnode(root->right, data);

    return root; // trả lại root
}

/* Duyệt Preorder (Node - Left - Right) */
void preorder(struct tnode* root) {

    if (root != NULL) {
        printf("%d ", root->data); // xử lý node
        preorder(root->left);      // duyệt trái
        preorder(root->right);     // duyệt phải
    }
}

/* Duyệt Inorder (Left - Node - Right) */
void inorder(struct tnode* root) {

    if (root != NULL) {
        inorder(root->left);       // trái
        printf("%d ", root->data); // node (kết quả tăng dần)
        inorder(root->right);      // phải
    }
}

/* Xóa toàn bộ cây */
int deltree(struct tnode* root) {

    if (root == NULL)
        return 0; // không có node

    // xóa cây con trái
    int left = deltree(root->left);

    // xóa cây con phải
    int right = deltree(root->right);

    free(root); // xóa node hiện tại

    return left + right + 1; // tổng số node đã xóa
}

/* Hàm main */
int main() {

    struct tnode* root = NULL; // cây rỗng

    int arr[] = {3,1,0,2,8,6,5,9}; // dữ liệu đề bài
    int n = sizeof(arr)/sizeof(arr[0]); // số phần tử

    // thêm từng phần tử vào cây
    for (int i = 0; i < n; i++) {
        root = addnode(root, arr[i]);
    }

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    // xóa cây
    int count = deltree(root);

    printf("\nDa xoa %d node\n", count);

    return 0;
}