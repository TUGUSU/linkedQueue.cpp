#include "linkedQueue.h"
#include <iostream>

using namespace std;

void printqueue(LinkedQueue &qq) {
  cout << "[ ";
  item *ptr = qq.head;
  while (ptr != NULL) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << "] L:" << lengthqueue(qq) << endl;
}

struct item {
    int value;
    item *next;
};

struct LinkedQueue {
    item *head = NULL;
    item *tail = NULL;
};

void enqueue(LinkedQueue &qq, int n) {
    item *newItem = new item;
    newItem->value = n;
    newItem->next = NULL;

    if (qq.tail == NULL) {
        // queue hooson tul dvvl tolgoi hoyula shine item aa zaana
        qq.head = qq.tail = newItem;
    } else {
        // shine item aa queue iin svvld zalgaj svvlee shincilne
        qq.tail->next = newItem;
        qq.tail = newItem;
    }
}

int dequeue(LinkedQueue &qq) {
    if (qq.head == NULL) {
        // Queue hoosn bn
        cout << "Queue is empty!!" << endl;
        return -1;
    }

    // ehnii item iig ustgah
    item *temp = qq.head;
    int removedValue = temp->value;
    qq.head = qq.head->next;

    //  herve queue ni hooson bol svvlig mon null bolgono
    if (qq.head == NULL) {
        qq.tail = NULL;
    }

    delete temp; // memory goo cholooloh
    return removedValue;
}

int lengthqueue(LinkedQueue &qq) {
    int length = 0;
    item *ptr = qq.head;
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }
    return length;
}
