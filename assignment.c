#include <stdio.h>
#include <string.h>
#include <math.h>

// factorial helper
unsigned long long fact(int n) {
    unsigned long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

/* Q1 */
void Q1() {
    int a,b,c,d;
    printf("Enter four integers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    printf("Biggest = %d\n", max);
}

/* Q2 */
void Q2() {
    int a,b,c,d;
    printf("Enter four integers: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    printf("Smallest = %d\n", min);
}

/* Q3 */
void Q3() {
    int m1,m2,m3;
    printf("Enter marks of 3 subjects: ");
    scanf("%d %d %d",&m1,&m2,&m3);
    int total = m1+m2+m3;
    double percentage = total/3.0;
    char grade[4];
    if (percentage >= 80) strcpy(grade,"O");
    else if (percentage >= 70) strcpy(grade,"A+");
    else if (percentage >= 60) strcpy(grade,"A");
    else if (percentage >= 50) strcpy(grade,"B");
    else if (percentage >= 40) strcpy(grade,"C");
    else strcpy(grade,"F");
    printf("Marks: %d/300\nPercentage: %.2f\nGrade: %s\n", total, percentage, grade);
}

/* Q4 */
void Q4() {
    int n; printf("Enter n: "); scanf("%d",&n);
    long long sum=0; 
    for(int i=0;i<n;i++){ int x; scanf("%d",&x); sum+=x; }
    printf("Sum=%lld Avg=%.2f\n", sum, sum/(double)n);
}

/* Q5 */
void Q5() {
    int n; printf("Enter n: "); scanf("%d",&n);
    printf("%d! = %llu\n", n, fact(n));
}

/* Q6 */
void Q6() {
    int n; printf("Enter n: "); scanf("%d",&n);
    unsigned long long sum=0;
    for(int i=1;i<=n;i+=2) sum += fact(i);
    printf("Sum = %llu\n", sum);
}

/* Q7 */
void Q7() {
    int n; printf("Enter n: "); scanf("%d",&n);
    unsigned long long sum=0;
    for(int i=2;i<=n;i+=2) sum += fact(i);
    printf("Sum = %llu\n", sum);
}

/* Q8 */
void Q8() {
    double x; int n; printf("Enter x n: "); scanf("%lf %d",&x,&n);
    double sum=0;
    for(int i=1;i<=n;i++) sum += pow(x,i)/fact(i);
    printf("Sum = %.6f\n", sum);
}

/* Q9 */
void Q9() {
    double x; int n; printf("Enter x n: "); scanf("%lf %d",&x,&n);
    double sum=0;
    for(int i=1;i<=n;i+=2) sum += pow(x,i)/fact(i);
    printf("Sum = %.6f\n", sum);
}

/* Q10 */
void Q10() {
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++) printf("%4d", i*j);
        printf("\n");
    }
}

/* Q11 */
void Q11() {
    for(int i=1;i<=5;i++){
        for(int j=0;j<i;j++) printf("%d ",5-j);
        printf("\n");
    }
}

/* Q12 */
void Q12() {
    for(int i=5;i>=1;i--){
        for(int j=i;j<=5;j++) printf("%d ", j);
        printf("\n");
    }
}

/* Q13 */
void Q13() {
    int n=5;
    for(int i=1;i<=n;i++){
        for(int s=0;s<(n-i)*3;s++) putchar(' ');
        int val=n;
        for(int j=1;j<=i;j++) printf("%d ", val--);
        printf("\n");
    }
}

/* Q14 */
void Q14() {
    int n=5;
    for(int i=n;i>=1;i--){
        for(int s=0;s<(i-1)*3;s++) putchar(' ');
        for(int j=i;j<=n;j++) printf("%d ", j);
        printf("\n");
    }
}

/* Q15 */
void Q15() {
    int n=5;
    for(int i=1;i<=n;i++){
        for(int s=0;s<(n-i)*3;s++) putchar(' ');
        for(int j=0;j<i;j++) printf("%d ", n-j);
        for(int j=2;j<=i;j++) printf("%d ", n-(i-j));
        printf("\n");
    }
}

/* MAIN MENU */
int main() {
    int choice;
    do {
        printf("\n--- MENU (Q1-Q15) ---\n");
        printf("1.Biggest  2.Smallest  3.Grade  4.SumAvg  5.Factorial\n");
        printf("6.SumOddFact 7.SumEvenFact 8.Series1 9.SeriesOdd\n");
        printf("10.Table 11.Pattern1 12.Pattern2 13.Pattern3\n");
        printf("14.Pattern4 15.Pattern5 0.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:Q1();break;
            case 2:Q2();break;
            case 3:Q3();break;
            case 4:Q4();break;
            case 5:Q5();break;
            case 6:Q6();break;
            case 7:Q7();break;
            case 8:Q8();break;
            case 9:Q9();break;
            case 10:Q10();break;
            case 11:Q11();break;
            case 12:Q12();break;
            case 13:Q13();break;
            case 14:Q14();break;
            case 15:Q15();break;
            case 0:printf("Exiting...\n");break;
            default:printf("Invalid!\n");
        }
    } while(choice!=0);
    return 0;
}












