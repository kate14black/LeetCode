 // Definition for polynomial singly-linked list.
#include <cstddef>
  struct PolyNode {
      int coefficient, power;
      PolyNode *next;
     PolyNode(): coefficient(0), power(0), next(nullptr) {};
     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
  };


enum CalculationMethod {
    POLY1,
    POLY2,
    BOTH,
    NONE
};

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* result = NULL;
        if (poly1 != NULL || poly2 != NULL) {
            sumPoly(result, poly1, poly2);
        } 
        return result;
    }

    CalculationMethod sumCreation(PolyNode* &result, PolyNode* poly1, PolyNode* poly2) {
        if (result != NULL) {
            if (poly1 != NULL && poly1->power == result->power) {
                result->coefficient += poly1->coefficient;
                return CalculationMethod::POLY1;
            }
            if (poly2 != NULL && poly2->power == result->power) {
                result->coefficient += poly2->coefficient;
                return CalculationMethod::POLY2;
            }
        }
        if (poly1 == NULL && poly2 == NULL)
            return CalculationMethod::NONE;
        if (poly1 == NULL) {
            if (result == NULL) {
                result = new PolyNode(poly2->coefficient, poly2->power);
            } else {
                result->next = new PolyNode(poly2->coefficient, poly2->power);
            }
            return CalculationMethod::POLY2;
        }
        if (poly2 == NULL) {
            if (result == NULL) {
                result = new PolyNode(poly1->coefficient, poly1->power);
            } else {
                result->next = new PolyNode(poly1->coefficient, poly1->power);
            }
            return CalculationMethod::POLY1;
        }
        if (poly1->power == poly2->power) {
            const int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (result == NULL && sumCoeff != 0) {
                result = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
            }
            else if (sumCoeff != 0) {
                result->next = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
            }
            return CalculationMethod::BOTH;
        }
        else if (poly1->power > poly2->power) {
            if (result == NULL) {
                result = new PolyNode(poly1->coefficient, poly1->power);
            }
            else {
                result->next = new PolyNode(poly1->coefficient, poly1->power);
            }
            return CalculationMethod::POLY1;
        }
        else {
            if (result == NULL) {
                result = new PolyNode(poly2->coefficient, poly2->power);
            }
            else {
                result->next = new PolyNode(poly2->coefficient, poly2->power);
            }
            return CalculationMethod::POLY2;
        }
    }

    void sumPoly(PolyNode* &result, PolyNode* poly1, PolyNode* poly2) {
        CalculationMethod calculation = sumCreation(result, poly1, poly2);
        if (calculation == CalculationMethod::NONE)
            return;
        PolyNode* &nextNode = (result == NULL || result->next == NULL) ? result : result->next;
        if (calculation == CalculationMethod::POLY1)
            sumPoly(nextNode, poly1->next, poly2);
        else if (calculation == CalculationMethod::POLY2)
            sumPoly(nextNode, poly1, poly2->next);
        else
            sumPoly(nextNode, poly1->next, poly2->next);
    }
};
