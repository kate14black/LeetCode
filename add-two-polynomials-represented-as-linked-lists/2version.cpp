
 // Definition for polynomial singly-linked list.
  struct PolyNode {
      int coefficient, power;
      PolyNode *next;
     PolyNode(): coefficient(0), power(0), next(nullptr) {};
     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
  };


class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* head = nullptr;
        PolyNode** indirect = &head;
        
        while (poly1 && poly2) {
            if (poly1->power == poly2->power) {
                poly1->coefficient += poly2->coefficient;
                if (poly1->coefficient != 0) {
                    *indirect = poly1;
                    indirect = &((*indirect)->next);
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            } else {
                PolyNode** ptr = (poly1->power > poly2->power) ? &poly1 : &poly2;
                *indirect = *ptr;
                *ptr = (*ptr)->next;
                indirect = &((*indirect)->next);
            }
        }
        *indirect = poly1 ? poly1 : poly2;

        return head;
    }
};
