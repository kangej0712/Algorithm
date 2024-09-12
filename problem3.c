#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    double sum;
    double average;
    long student[100];
    double ans1, ans2;

    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;  // 0을 입력하면 프로그램 종료
        if (n > 100) {
            printf("학생 수는 최대 100명까지 가능합니다. 다시 입력하세요.\n");
            continue;
        }

        sum = 0;

        for (int i = 0; i < n; i++)
        {
            do
            {

                scanf("%ld", &student[i]);
                if (student[i] > 100000)
                {
                    printf("한 사람의 금액은 100,000 won을 넘을 수 없습니다. 다시 입력하세요.\n");
                }
            } while (student[i] > 100000);  // 100,000을 초과하면 재입력 요청

            sum += student[i];
        }

        average = round(sum / n * 0.1) / 0.1; // 10원 단위 반올림
        ans1 = 0;
        ans2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (student[i] - average >= 0)
            {
                ans1 += (double)(student[i] - average);
            }
            else
            {
                ans2 += (double)(average - student[i]);
            }
        }

        // 소수점 이하가 항상 .00이므로 정수로 변환하여 출력
        printf("%.0lf won\n", ans1 < ans2 ? ans1 : ans2);
    }

    return 0;
}