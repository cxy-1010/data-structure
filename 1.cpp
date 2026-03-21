#include <iostream>
#include <iomanip>

using namespace std;

// 定义单链表节点结构
struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

/**
 * @brief 创建初始队列 (1 到 M)
 * @param m 总人数
 * @return Node* 返回链表头指针
 */
Node* createList(int m) {
    Node* head = new Node(0); // 哨兵头节点
    Node* tail = head;
    for (int i = 1; i <= m; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    return head;
}

/**
 * @brief 执行单轮约瑟夫环游戏
 * @param head 当前队列的头节点（带哨兵）
 * @param n 报数密码
 * @return Node* 返回本轮结束后的新队列头节点（带哨兵）
 */
Node* playRound(Node* head, int n) {
    if (!head->next) return head;

    // 1. 找到原链表尾部，并将其与第一个数据节点相连，形成循环链表
    Node* curr = head->next;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = head->next; // 首尾相连

    // 2. 准备新链表的容器
    Node* newHead = new Node(0);
    Node* newTail = newHead;

    Node* prev = curr;      // 报数起点的前驱节点
    curr = head->next;      // 报数起点

    // 3. 开始模拟报数
    while (curr->next != curr) {
        // 报数到 n，移动 n-1 次
        for (int i = 1; i < n; ++i) {
            prev = curr;
            curr = curr->next;
        }
        // 当前 curr 指向要出列的人
        newTail->next = new Node(curr->id);
        newTail = newTail->next;

        // 从循环链表中删除该节点
        prev->next = curr->next;
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    // 4. 处理最后一个留下来的人
    newTail->next = new Node(curr->id);
    delete curr;

    // 5. 释放旧的哨兵头节点并返回新链表
    delete head;
    return newHead;
}

/**
 * @brief 打印队列结果
 * @param head 链表头节点
 */
void printList(Node* head) {
    Node* curr = head->next;
    while (curr) {
        cout << setw(4) << curr->id;
        curr = curr->next;
    }
    cout << endl;
}

/**
 * @brief 释放链表内存
 */
void clearList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int M, N;
    
    // 输入总人数 M
    if (!(cin >> M)) return 0;

    // 初始化队列
    Node* listHead = createList(M);

    // 循环读入报数密码 N，每读入一个 N 玩一遍游戏
    while (cin >> N) {
        listHead = playRound(listHead, N);
    }

    // 输出最终结果
    printList(listHead);

    // 清理内存
    clearList(listHead);

    return 0;
}