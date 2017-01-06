# jw_test_sort
지원정렬연습

## 사용법

```
gcc test_sort.c -o test_sort
./test_sort -a [bub|ins|sel] -o [same|asc|desc|rand] -s [size]

인자 순서 무관하게 입력 받을 수 있음
예시: ./test_sort -o asc -a bub -s 1002 

-a 옵션 없을 시 사용법 출력
-o 옵션 없을 시 random 데이터
-s 옵션 없을 시 기본 사이즈: 32768

출력방식
'정렬방법: 시간 ms'

Window와 Linux에서의 clock_t 출력 단위 다른 것 OS에 맞춰서 밀리초 단위로 출력하게 함

```
