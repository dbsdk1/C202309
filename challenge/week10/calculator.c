#include <stdio.h>

void summation(double* value1, double* value2, double* result) {  // 역참조-> value1의 값에 접근을 한다.
  *result = *value1 + *value2;
}
void subtraction(double* value1, double* value2, double* result) {
  *result = *value1 - *value2;
}
void multification(double* value1, double* value2, double* result) {
  *result = *value1 * *value2;
}
void division(double* value1, double* value2, double* result) {
  *result = *value1 / *value2;
}

int main() {
  double a = 2, b = 3;
  double result;
  summation(&a, &b, &result);  // &이므로 주소를 전달해준거다.
  printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

  subtraction(&a, &b, &result);
  printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

  multification(&a, &b, &result);
  printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

  division(&a, &b, &result);
  printf("%.0lf / %.0lf = %.2lf \n", a, b, result);
  return 0;
}