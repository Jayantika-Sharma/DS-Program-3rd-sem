#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
    int coeff;
    int pow;
    Node* next;};
Node* createNode(int c, int p) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->coeff = c;
    n->pow = p;
    n->next = NULL;
    return n;}
void insrt(Node** head, int c, int p) {
    Node* newNode = createNode(c, p);
    if (*head == NULL) {
        *head = newNode;
        return;    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;}

void displayPoly(Node* head) {
    if (head == NULL) {
        cout << "Empty Polynomial\n";
        return;}
    while (head != NULL) {
        cout << head->coeff << "x^" << head->pow;
        head = head->next;
        if (head != NULL && head->coeff >= 0)
            cout << " + ";
        else if (head != NULL)
            cout << " ";}
     cout << endl;}
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insrt(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly2->pow > poly1->pow) {
            insrt(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insrt(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;}}
    while (poly1 != NULL) {
        insrt(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;}
    while (poly2 != NULL) {
        insrt(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;}
    return result;}
Node* multiplyPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (Node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            int coeffProd = ptr1->coeff * ptr2->coeff;
            int powSum = ptr1->pow + ptr2->pow;
            Node* temp = result;
            Node* prev = NULL;
            bool found = false;
            while (temp != NULL) {
                if (temp->pow == powSum) {
                    temp->coeff += coeffProd;
                    found = true;
                    break;}
                prev = temp;
                temp = temp->next;
            }
            if (!found) {
                Node* newNode = createNode(coeffProd, powSum);
                if (result == NULL)
                    result = newNode;
                else
                    prev->next = newNode;
            }}}
    return result;}
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL, *product = NULL;
    int n, coeff, pow;
    cout << "Enter number of terms for first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> pow;
        insrt(&poly1, coeff, pow);
    }
    cout << "Enter number of terms for second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and power: ";
        cin >> coeff >> pow;
        insrt(&poly2, coeff, pow);}
    cout << "\nPolynomial 1: ";
    displayPoly(poly1);
    cout << "Polynomial 2: ";
    displayPoly(poly2);
    sum = addPoly(poly1, poly2);
    cout << "\nSum of polynomials: ";
    displayPoly(sum);
    product = multiplyPoly(poly1, poly2);
    cout << "\nProduct of polynomials: ";
    displayPoly(product);
    return 0;}
