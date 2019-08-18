#include "../header/code_medium.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l = l1;
    int num, tag = 0;
    
    num = l1->val + l2->val;
    if(num > 9){ tag = 1; }
    else{ tag = 0; }
    l1->val = num % 10;
    
    while(l1->next != NULL && l2->next != NULL){
      l1 = l1->next;
      l2 = l2->next;
      num = l1->val + l2->val + tag;
      if( num > 9){ tag = 1; }
      else{ tag = 0;}
      l1->val = num % 10;
    }
    if( tag == 0){
      if(l1->next == NULL){ l1->next = l2->next; }
    }
    else{
      if(l1->next==l2->next){
        l1->next=new ListNode(1); return l;
      }
      if(l1->next == NULL){ l1->next = l2->next;}
      while(tag != 0 && l1->next != NULL){
        l1=l1->next;
        num=l1->val+tag;
        if( num > 9){ tag = 1; }
        else{ tag = 0; }
        l1->val = num % 10;
      }
      if(tag != 0 && l1->next == NULL){
        l1->next = new ListNode(1);
      }
    }
    return l;
  }
};

ListNode* toListNode(int num){
  ListNode *l = new ListNode(0);
  ListNode *p = l;
  while(num){
    p->next = new ListNode(num % 10);
    p = p->next;
    num = num / 10;
  }
  return l->next;
}

bool show_2(int setwidth){
  const string title = "2.Add Two Numbers";

  int num1 = 342;
  int num2 = 465;
  int num3 = num1 + num2;
  ListNode *l1 = toListNode(num1);
  ListNode *l2 = toListNode(num2);
  ListNode *l3 = toListNode(num3);
  ListNode *output = NULL;

  Solution Program;

  output = Program.addTwoNumbers(l1,l2);
  bool result = true;

  while(l3 != NULL && output != NULL){
    if(l3->val != output -> val){ result = false; break; }
    l3 = l3->next; 
    output = output->next;
  }
  if(l3!=NULL || output!=NULL){ result = false; }

  string prompt = result ? "pass" : "fail";
  cout << setiosflags(ios::left) << setw(setwidth) << title << prompt << endl;
  return result;
}
