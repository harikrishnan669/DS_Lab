#include <stdio.h>

struct poly {
    float coeff;
    int exp;
};
void readPolynomial(struct poly P[], int n) {
    printf("Enter the coefficients and exponents of the polynomial:\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: Coefficient: ", i + 1);
        scanf("%f", &P[i].coeff);
        printf("        Exponent   : ");
        scanf("%d", &P[i].exp);
    }
}

void displayPolynomial(struct poly P[], int n, const char* name) {
    printf("\n%s Polynomial: ", name);
    for (int i = 0; i < n; i++) {
        printf("%.2fx^%d ", P[i].coeff, P[i].exp);
        if (i < n - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}
void addPolynomials(struct poly P[], int m, struct poly Q[], int n, struct poly R[], int* r_size) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (P[i].exp == Q[j].exp) {
            R[k].coeff = P[i].coeff + Q[j].coeff;
            R[k].exp = P[i].exp;
            i++;
            j++;
            k++;
        } else if (P[i].exp > Q[j].exp) {
            R[k].coeff = P[i].coeff;
            R[k].exp = P[i].exp;
            i++;
            k++;
        } else {
            R[k].coeff = Q[j].coeff;
            R[k].exp = Q[j].exp;
            j++;
            k++;
        }
    }
    while (i < m) {
        R[k].coeff = P[i].coeff;
        R[k].exp = P[i].exp;
        i++;
        k++;
    }
    while (j < n) {
        R[k].coeff = Q[j].coeff;
        R[k].exp = Q[j].exp;
        j++;
        k++;
    }

    *r_size = k;
}

int main() {
    int m, n, r_size;
     
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &m);
    
    struct poly P[m];
    readPolynomial(P, m);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);

    struct poly Q[n];
    readPolynomial(Q, n);

    
    struct poly R[m + n];

    addPolynomials(P, m, Q, n, R, &r_size);

    displayPolynomial(P, m, "First");
    displayPolynomial(Q, n, "Second");
    displayPolynomial(R, r_size, "Sum");

    return 0;
}
