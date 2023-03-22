//
// Created by cxt2004 on 2023/3/16.
//

#ifndef HW4_AVL_H
#define HW4_AVL_H

#include <iostream>
#include <algorithm>
#include<Windows.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
using namespace std;

template<class K = unsigned, class V = unsigned>
struct node {
    K key;
    V value;
    int height = 0;
    node *left;
    node *right;
    node(){
        left = NULL;
        right = NULL;
        height = 0;
    }

    node(K k, V v) {
        height = 1;
        key = k;
        value = v;
        left = NULL;
        right = NULL;
    }
};

template<class K = unsigned, class V = unsigned>
class AVL{
public:
    AVL(){
        root = nullptr;
        num = 0;
    }
    node<>* root;
    int num;
    void insert(K k, V v){
        insertUtil(root, k, v);
    }
    void remove(K k){
        removeUtil(root, k);
        //   cout<<"delete:"<<x<<"  ";
    }

    node<> * search(K k){
        return searchUtil(root,k);
    }

    void inorder(){
        inorderUtil(root);
        cout<<endl;
    }

    int heightOfAvl(){
        return height(root);
    }

private:
    int height(node<> *& head){
        if(head == NULL) return 0;
        // return head->height;
        int rh = height(head->right);
        int lh = height(head->left);
        return max(lh,rh) + 1;
    }
    node<> * rightRotation(node<> *& head){//相当于LL情况
        node<> * newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;
        head->height = 1+max(height(head->left), height(head->right));
        newhead->height = 1+max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node<> * leftRotation(node<> *& head){//相当于RR情况
        node<> * newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;
        head->height = 1+max(height(head->left), height(head->right));
        newhead->height = 1+max(height(newhead->left), height(newhead->right));
        return newhead;
    }

    node<> * LR(node<> *& head){
        head->left = leftRotation(head->left);
        node<> * newhead = rightRotation(head);
        return newhead;

    }
    node<> * RL(node<> *& head){
        head->right = rightRotation(head->right);
        node<> * newhead = leftRotation(head);
        return newhead;
    }

    void inorderUtil(node<> *& head){
        if(head==NULL) return;
        inorderUtil(head->left);
        cout<<head->key<<" ";
        inorderUtil(head->right);
    }


    node<> * insertUtil(node<> *& head, const K &k, const V &v){
        if(!root){
            root = new node<>(k,v);
            return root;
        }
        if(head == NULL){
            head = new node<>(k,v);
            num++;//update the size of avlTree
            //      head->height = max(height(head->left), height(head->right)) + 1;
            // return head;
        }else if(k < head->key){
            insertUtil(head->left, k,v);
            if(height(head->left) - height(head->right) == 2){
                if(k < head->left->key)
                    head = rightRotation(head);
                else{
                    //  head->left = head->left->right;
                    head = LR(head);
                }
            }
        }else if(head->key < k){
            insertUtil(head->right, k,v);
            if(height(head->right) - height(head->left) == 2){
                if(k > head->right->key)
                    head = leftRotation(head);
                else{
                    //   head->right = head->right->left;
                    head = RL(head);
                }

            }
        }
        head->height = max(height(head->left), height(head->right)) + 1;
        return head;
    }

    bool removeUtil(node<> *& head, const K &k){
        bool stop = false;
        int balance;//delete head之前的平衡因子
        int sub;//1：delete node in left subTree,2:right subTree
        if(head == nullptr)
            return true;
        if(k < head->key){
            stop = removeUtil(head->left, k);
            sub = 1;
        }if(k > head->key){
            stop = removeUtil(head->right, k);
            sub = 2;
        }else if(head->left != nullptr && head->right != nullptr){
            node<> * tmp = head->right;
            while(tmp->left!= nullptr) tmp = tmp->left;
            head->key = tmp->key;
            stop = removeUtil(head->right,head->key);
            sub = 2;
        }else{
            node<> *old = head;
            head = (head->left != nullptr) ? head->left : head->right;
            delete old;
            return false;
        }
        if(stop)
            return true;

        switch (sub) {
            case 1:
                balance = height(head->left) - height(head->right);
                if(balance == -1)
                    return true;
                if(balance == 0)
                    return false;
                if(balance == -2){//head 左子树较矮
                    int bl = height(head->right->left) - height(head->right->right);
                    if(bl == 0){
                        leftRotation(head);
                        return true;
                    }else if(bl == -1){
                        leftRotation(head);
                        return false;
                    }else{
                        RL(head);
                        return false;
                    }
                }
                break;
            case 2:
                balance = height(head->left)- height(head->right);
                if(balance == 1) return true;
                if(balance == 0) return false;
                if(balance == 2){
                    int br = height(head->left->left) - height(head->left->right);
                    if(br == 0){
                        rightRotation(head);
                        return true;
                    }else if(br == 1){
                        rightRotation(head);
                        return false;
                    }else{
                        LR(head);
                        return false;
                    }
                }

        }
    }

    node<> * searchUtil(node<> * head, const K & x){
        if(head == NULL) return NULL;
        K k = head->key;
        if(k == x) return head;
        if(k > x) return searchUtil(head->left, x);
        if(k < x) return searchUtil(head->right, x);
    }
};


#endif //HW4_AVL_H
