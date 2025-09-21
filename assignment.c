/* assignment_all_q1_q39.c
   Menu-driven program: Q1..Q39 in one file
   Compile: gcc assignment_all_q1_q39.c -o assign
   Run: ./assign
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

/* ---------- Helpers ---------- */

unsigned long long fact_ui(unsigned int n) {
    unsigned long long f = 1;
    for (unsigned int i = 2; i <= n; ++i) f *= i;
    return f;
}

unsigned long long fact_recursive(unsigned int n) {
    if (n == 0) return 1;
    return n * fact_recursive(n-1);
}

int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return 0;
    return 1;
}

long long gcd_ll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b;
    if (b == 0) return a;
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long lcm_ll(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return llabs(a / gcd_ll(a,b) * b);
}

unsigned long long nCr_mul(unsigned int n, unsigned int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;
    unsigned long long res = 1;
    for (unsigned int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return res;
}

/* ---------- Q1 - Q15 (from earlier) ---------- */

/* Q1: Biggest of four integers */
void Q1() {
    int a,b,c,d;
    printf("Enter four integers: ");
    if (scanf("%d %d %d %d",&a,&b,&c,&d)!=4) { printf("Invalid input\n"); return; }
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    printf("Biggest = %d\n", max);
}

/* Q2: Smallest of four integers */
void Q2() {
    int a,b,c,d;
    printf("Enter four integers: ");
    if (scanf("%d %d %d %d",&a,&b,&c,&d)!=4) { printf("Invalid input\n"); return; }
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    printf("Smallest = %d\n", min);
}

/* Q3: Marks, percentage and grade */
void Q3() {
    int m1,m2,m3;
    printf("Enter marks of 3 subjects (0-100): ");
    if (scanf("%d %d %d",&m1,&m2,&m3)!=3) { printf("Invalid\n"); return; }
    int total = m1 + m2 + m3;
    double percentage = total / 3.0;
    char grade[4];
    if (percentage >= 80) strcpy(grade, "O");
    else if (percentage >= 70) strcpy(grade, "A+");
    else if (percentage >= 60) strcpy(grade, "A");
    else if (percentage >= 50) strcpy(grade, "B");
    else if (percentage >= 40) strcpy(grade, "C");
    else strcpy(grade, "F");
    printf("Marks: %d/300\nPercentage: %.2f\nGrade: %s\n", total, percentage, grade);
}

/* Q4: Sum and average of n integers */
void Q4() {
    int n;
    printf("Enter n: ");
    if (scanf("%d",&n)!=1 || n<=0) { printf("Invalid n\n"); return; }
    long long sum = 0;
    for (int i=0;i<n;i++){
        int x;
        printf("Enter integer %d: ", i+1);
        if (scanf("%d",&x)!=1) { printf("Invalid\n"); return; }
        sum += x;
    }
    printf("Sum = %lld, Average = %.2f\n", sum, sum/(double)n);
}

/* Q5: Factorial */
void Q5() {
    int n;
    printf("Enter n (>=0): ");
    if (scanf("%d",&n)!=1 || n<0) { printf("Invalid n\n"); return; }
    printf("%d! = %llu\n", n, fact_ui((unsigned int)n));
}

/* Q6: Sum of odd factorials 1!+3!+... up to n */
void Q6() {
    int n; printf("Enter max n: ");
    if (scanf("%d",&n)!=1 || n<1) { printf("Invalid\n"); return; }
    unsigned long long sum = 0;
    for (int i=1;i<=n;i+=2) sum += fact_ui((unsigned int)i);
    printf("Sum = %llu\n", sum);
}

/* Q7: Sum of even factorials 2!+4!+... up to n */
void Q7() {
    int n; printf("Enter max n: ");
    if (scanf("%d",&n)!=1 || n<2) { printf("Invalid\n"); return; }
    unsigned long long sum = 0;
    for (int i=2;i<=n;i+=2) sum += fact_ui((unsigned int)i);
    printf("Sum = %llu\n", sum);
}

/* Q8: Sum = x + x^2/2! + ... + x^n/n! */
void Q8() {
    double x; int n;
    printf("Enter x and n: ");
    if (scanf("%lf %d",&x,&n)!=2 || n<1) { printf("Invalid\n"); return; }
    double sum = 0.0;
    for (int i=1;i<=n;i++) sum += pow(x,i) / (double)fact_ui((unsigned int)i);
    printf("Sum = %.8f\n", sum);
}

/* Q9: Sum odd powers: x + x^3/3! + ... */
void Q9() {
    double x; int n;
    printf("Enter x and max n (odd max): ");
    if (scanf("%lf %d",&x,&n)!=2 || n<1) { printf("Invalid\n"); return; }
    double sum = 0.0;
    for (int i=1;i<=n;i+=2) sum += pow(x,i) / (double)fact_ui((unsigned int)i);
    printf("Sum = %.8f\n", sum);
}

/* Q10: 10x10 multiplication table */
void Q10() {
    for (int i=1;i<=10;i++){
        for (int j=1;j<=10;j++) printf("%4d", i*j);
        printf("\n");
    }
}

/* Q11: Pattern 5 5 4 5 4 3 ... */
void Q11() {
    for (int i=1;i<=5;i++){
        for (int j=0;j<i;j++) printf("%d ", 5-j);
        printf("\n");
    }
}

/* Q12: Pattern 5 / 4 5 / 3 4 5 ... */
void Q12() {
    for (int start=5; start>=1; start--){
        for (int j=start; j<=5; j++) printf("%d ", j);
        printf("\n");
    }
}

/* Q13: Right-aligned triangular pattern */
void Q13() {
    int n = 5;
    for (int i=1;i<=n;i++){
        for (int s=0;s<(n-i)*3;s++) putchar(' ');
        int val = n;
        for (int j=1;j<=i;j++) printf("%d ", val--);
        printf("\n");
    }
}

/* Q14: Mirror of Q13 */
void Q14() {
    int n = 5;
    for (int i=n;i>=1;i--){
        for (int s=0;s<(i-1)*3;s++) putchar(' ');
        for (int j=i;j<=n;j++) printf("%d ", j);
        printf("\n");
    }
}

/* Q15: Pyramid mirrored numbers */
void Q15() {
    int n = 5;
    for (int i=1;i<=n;i++){
        for (int s=0;s<(n-i)*3;s++) putchar(' ');
        for (int j=0;j<i;j++) printf("%d ", n-j);
        for (int j=2;j<=i;j++) printf("%d ", n-(i-j));
        printf("\n");
    }
}

/* ---------- Q16 - Q39 ---------- */

/* Q16: Even numbers from 50 to 100 and their sum */
void Q16() {
    int sum = 0;
    for (int i=50;i<=100;i++){
        if (i%2==0) { printf("%d ", i); sum+=i; }
    }
    printf("\nSum = %d\n", sum);
}

/* Q17: Odd numbers from 50 to 100 and their count */
void Q17() {
    int count = 0;
    for (int i=50;i<=100;i++){
        if (i%2!=0) { printf("%d ", i); count++; }
    }
    printf("\nCount = %d\n", count);
}

/* Q18: Numbers divisible by 7 or 11 (50..100) and their sum */
void Q18() {
    int sum = 0;
    for (int i=50;i<=100;i++){
        if (i%7==0 || i%11==0) { printf("%d ", i); sum += i; }
    }
    printf("\nSum = %d\n", sum);
}

/* Q19: Prime numbers from 5 to 50 and their count */
void Q19() {
    int count = 0;
    for (int i=5;i<=50;i++){
        if (is_prime(i)) { printf("%d ", i); count++; }
    }
    printf("\nCount = %d\n", count);
}

/* Q20: Fibonacci sequence n terms */
void Q20() {
    int n;
    printf("Enter number of terms n: ");
    if (scanf("%d",&n)!=1 || n<=0) { printf("Invalid n\n"); return; }
    long long a=0,b=1;
    for (int i=1;i<=n;i++){
        printf("%lld ", a);
        long long next = a+b;
        a=b; b=next;
    }
    printf("\n");
}

/* Q21: Biggest and smallest in array of 10 */
void Q21() {
    int arr[10];
    printf("Enter 10 integers:\n");
    for (int i=0;i<10;i++) if (scanf("%d",&arr[i])!=1){ printf("Invalid\n"); return; }
    int max=arr[0], min=arr[0];
    for (int i=1;i<10;i++){ if (arr[i]>max) max=arr[i]; if (arr[i]<min) min=arr[i]; }
    printf("Max = %d, Min = %d\n", max, min);
}

/* Q22: Sort ascending 10 elements */
void Q22() {
    int a[10];
    printf("Enter 10 integers:\n");
    for (int i=0;i<10;i++) if (scanf("%d",&a[i])!=1){ printf("Invalid\n"); return; }
    for (int i=0;i<9;i++) for (int j=0;j<9-i;j++) if (a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
    printf("Sorted ascending:\n");
    for (int i=0;i<10;i++) printf("%d ", a[i]);
    printf("\nSmallest = %d, Biggest = %d\n", a[0], a[9]);
}

/* Q23: Sort descending 10 elements */
void Q23() {
    int a[10];
    printf("Enter 10 integers:\n");
    for (int i=0;i<10;i++) if (scanf("%d",&a[i])!=1){ printf("Invalid\n"); return; }
    for (int i=0;i<9;i++) for (int j=0;j<9-i;j++) if (a[j]<a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
    printf("Sorted descending:\n");
    for (int i=0;i<10;i++) printf("%d ", a[i]);
    printf("\nSmallest = %d, Biggest = %d\n", a[9], a[0]);
}

/* Q24: GCD of n integers */
void Q24() {
    int n;
    printf("Enter count of integers n: ");
    if (scanf("%d",&n)!=1 || n<=0) { printf("Invalid n\n"); return; }
    long long g=0;
    printf("Enter %d integers:\n", n);
    for (int i=0;i<n;i++){
        long long x; if (scanf("%lld",&x)!=1){ printf("Invalid\n"); return; }
        if (i==0) g = llabs(x); else g = gcd_ll(g, x);
    }
    printf("GCD = %lld\n", g);
}

/* Q25: LCM of n integers */
void Q25() {
    int n;
    printf("Enter count of integers n: ");
    if (scanf("%d",&n)!=1 || n<=0) { printf("Invalid n\n"); return; }
    long long res = 0;
    printf("Enter %d integers:\n", n);
    for (int i=0;i<n;i++){
        long long x; if (scanf("%lld",&x)!=1){ printf("Invalid\n"); return; }
        if (i==0) res = llabs(x); else res = lcm_ll(res, x);
    }
    printf("LCM = %lld\n", res);
}

/* Q26: Sum of diagonal elements of 3x3 matrix */
void Q26() {
    int mat[3][3];
    printf("Enter 3x3 matrix elements row-wise:\n");
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (scanf("%d",&mat[i][j])!=1){ printf("Invalid\n"); return; }
    int sum = 0;
    for (int i=0;i<3;i++) sum += mat[i][i];
    printf("Sum of diagonal elements = %d\n", sum);
}

/* Q27: Factorial iterative and recursive */
void Q27() {
    unsigned int n;
    printf("Enter n for factorial: ");
    if (scanf("%u",&n)!=1) { printf("Invalid\n"); return; }
    printf("Iterative: %u! = %llu\n", n, fact_ui(n));
    printf("Recursive: %u! = %llu\n", n, fact_recursive(n));
}

/* Q28: Sum 1! + 2! + ... + n! */
void Q28() {
    unsigned int n;
    printf("Enter n: ");
    if (scanf("%u",&n)!=1 || n==0) { printf("Invalid\n"); return; }
    unsigned long long sum = 0;
    for (unsigned int i=1;i<=n;i++) sum += fact_ui(i);
    printf("Sum = %llu\n", sum);
}

/* Q29: Sum odd factorials 1!+3!+... */
void Q29() {
    unsigned int n;
    printf("Enter max n: ");
    if (scanf("%u",&n)!=1 || n==0) { printf("Invalid\n"); return; }
    unsigned long long sum = 0;
    for (unsigned int i=1;i<=n;i+=2) sum += fact_ui(i);
    printf("Sum = %llu\n", sum);
}

/* Q30: Sum even factorials 2!+4!+... */
void Q30() {
    unsigned int n;
    printf("Enter max n: ");
    if (scanf("%u",&n)!=1 || n<2) { printf("Invalid\n"); return; }
    unsigned long long sum = 0;
    for (unsigned int i=2;i<=n;i+=2) sum += fact_ui(i);
    printf("Sum = %llu\n", sum);
}

/* Q31: Sum = x + x^2/2 + x^3/3 + ... + x^n/n */
void Q31() {
    double x; int n;
    printf("Enter x and n: ");
    if (scanf("%lf %d",&x,&n)!=2 || n<1) { printf("Invalid\n"); return; }
    double sum = 0.0;
    for (int i=1;i<=n;i++) sum += pow(x,i) / (double)i;
    printf("Sum = %.6f\n", sum);
}

/* Q32: Sum = x + x^2/2! + ... + x^n/n! */
void Q32() {
    double x; int n;
    printf("Enter x and n: ");
    if (scanf("%lf %d",&x,&n)!=2 || n<1) { printf("Invalid\n"); return; }
    double sum = 0.0;
    for (int i=1;i<=n;i++) sum += pow(x,i) / (double)fact_ui((unsigned int)i);
    printf("Sum = %.8f\n", sum);
}

/* Q33: Product = (Sum1 * Sum2) / Sum3 where Sum1=1..m, Sum2=1..n, Sum3=1..p */
void Q33() {
    int m,n,p;
    printf("Enter m n p: ");
    if (scanf("%d %d %d",&m,&n,&p)!=3) { printf("Invalid\n"); return; }
    long long s1=0,s2=0,s3=0;
    for (int i=1;i<=m;i++) s1 += i;
    for (int i=1;i<=n;i++) s2 += i;
    for (int i=1;i<=p;i++) s3 += i;
    if (s3 == 0) { printf("Division by zero\n"); return; }
    double prod = (double)s1 * (double)s2 / (double)s3;
    printf("Product = %.6f\n", prod);
}

/* Q34: p = a! * b! / c! */
void Q34() {
    unsigned int a,b,c;
    printf("Enter a b c: ");
    if (scanf("%u %u %u",&a,&b,&c)!=3) { printf("Invalid\n"); return; }
    unsigned long long A = fact_ui(a), B = fact_ui(b), C = fact_ui(c);
    if (C == 0) { printf("Division by zero\n"); return; }
    double p = (double)A * (double)B / (double)C;
    printf("p = %.6f\n", p);
}

/* Q35: k = a!*b!*c! / (a! + b!) */
void Q35() {
    unsigned int a,b,c;
    printf("Enter a b c: ");
    if (scanf("%u %u %u",&a,&b,&c)!=3) { printf("Invalid\n"); return; }
    unsigned long long A = fact_ui(a), B = fact_ui(b), C = fact_ui(c);
    unsigned long long denom = A + B;
    if (denom == 0) { printf("Division by zero\n"); return; }
    double k = (double)A * (double)B * (double)C / (double)denom;
    printf("k = %.6f\n", k);
}

/* Q36: K = (R1*R2)/(R1+R2) where R1=x*x+y+z and R2=x+y*y+z */
void Q36() {
    double x,y,z;
    printf("Enter x y z: ");
    if (scanf("%lf %lf %lf",&x,&y,&z)!=3) { printf("Invalid\n"); return; }
    double R1 = x*x + y + z;
    double R2 = x + y*y + z;
    if (R1 + R2 == 0) { printf("Division by zero\n"); return; }
    double K = (R1 * R2) / (R1 + R2);
    printf("K = %.6f\n", K);
}

/* Q37: R = (x*x + y + 2*z) * (x + y*y + z) / (x + y + z) */
void Q37() {
    double x,y,z;
    printf("Enter x y z: ");
    if (scanf("%lf %lf %lf",&x,&y,&z)!=3) { printf("Invalid\n"); return; }
    double num1 = x*x + y + 2*z;
    double num2 = x + y*y + z;
    double den = x + y + z;
    if (den == 0) { printf("Division by zero\n"); return; }
    double R = (num1 * num2) / den;
    printf("R = %.6f\n", R);
}

/* Q38: nCr */
void Q38() {
    unsigned int n,r;
    printf("Enter n and r: ");
    if (scanf("%u %u",&n,&r)!=2) { printf("Invalid\n"); return; }
    unsigned long long comb = nCr_mul(n,r);
    printf("C(%u,%u) = %llu\n", n, r, comb);
}

/* Q39: Marks table for 5 students using struct */
struct Student { int roll; char name[50]; int s1,s2,s3; };
void Q39() {
    struct Student s[5];
    printf("Enter details for 5 students (roll name sub1 sub2 sub3):\n");
    for (int i=0;i<5;i++){
        printf("Student %d: ", i+1);
        if (scanf("%d %49s %d %d %d", &s[i].roll, s[i].name, &s[i].s1, &s[i].s2, &s[i].s3) != 5) { printf("Invalid\n"); return; }
    }
    printf("\nMarks Table\nS.No Roll  Name       Sub1 Sub2 Sub3 Total  Per(%%)\n");
    for (int i=0;i<5;i++){
        int total = s[i].s1 + s[i].s2 + s[i].s3;
        double per = total / 3.0;
        printf("%-5d %-5d %-10s %-4d %-4d %-4d %-5d %-6.2f\n", i+1, s[i].roll, s[i].name, s[i].s1, s[i].s2, s[i].s3, total, per);
    }
}

/* ---------- Main menu (1-39) ---------- */
int main() {
    int choice;
    do {
        printf("\n--- MENU (1-39) ---\n");
        printf("1.Biggest  2.Smallest  3.Grade  4.SumAvg  5.Factorial\n");
        printf("6.SumOddFact 7.SumEvenFact 8.Sum_x_over_fact 9.Sum_x_odd_over_fact 10.Table\n");
        printf("11.Pat1 12.Pat2 13.Pat3 14.Pat4 15.Pat5\n");
        printf("16.Evens(50-100) 17.Odds(50-100) 18.Div7or11 19.Primes(5-50) 20.Fibonacci\n");
        printf("21.ArrayMinMax 22.SortAsc 23.SortDesc 24.GCD 25.LCM 26.DiagSum\n");
        printf("27.FactIterRec 28.SumFact 29.SumOddFactArr 30.SumEvenFactArr\n");
        printf("31.Series_x_i_over_i 32.Series_x_i_over_i_fact 33.ProductSums\n");
        printf("34.p = a!*b!/c! 35.k = a!*b!*c!/(a!+b!) 36.ExprK 37.ExprR 38.nCr 39.MarksTable\n");
        printf("0.Exit\nEnter choice: ");
        if (scanf("%d",&choice)!=1) { printf("Invalid input\n"); break; }
        switch(choice) {
            case 1: Q1(); break;
            case 2: Q2(); break;
            case 3: Q3(); break;
            case 4: Q4(); break;
            case 5: Q5(); break;
            case 6: Q6(); break;
            case 7: Q7(); break;
            case 8: Q8(); break;
            case 9: Q9(); break;
            case 10: Q10(); break;
            case 11: Q11(); break;
            case 12: Q12(); break;
            case 13: Q13(); break;
            case 14: Q14(); break;
            case 15: Q15(); break;
            case 16: Q16(); break;
            case 17: Q17(); break;
            case 18: Q18(); break;
            case 19: Q19(); break;
            case 20: Q20(); break;
            case 21: Q21(); break;
            case 22: Q22(); break;
            case 23: Q23(); break;
            case 24: Q24(); break;
            case 25: Q25(); break;
            case 26: Q26(); break;
            case 27: Q27(); break;
            case 28: Q28(); break;
            case 29: Q29(); break;
            case 30: Q30(); break;
            case 31: Q31(); break;
            case 32: Q32(); break;
            case 33: Q33(); break;
            case 34: Q34(); break;
            case 35: Q35(); break;
            case 36: Q36(); break;
            case 37: Q37(); break;
            case 38: Q38(); break;
            case 39: Q39(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n"); break;
        }
        /* flush remaining input newline to avoid issues */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF); 
    } while(choice != 0);
    return 0;
}
