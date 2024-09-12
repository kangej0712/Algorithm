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
        if (n == 0) break;  // 0�� �Է��ϸ� ���α׷� ����
        if (n > 100) {
            printf("�л� ���� �ִ� 100����� �����մϴ�. �ٽ� �Է��ϼ���.\n");
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
                    printf("�� ����� �ݾ��� 100,000 won�� ���� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
                }
            } while (student[i] > 100000);  // 100,000�� �ʰ��ϸ� ���Է� ��û

            sum += student[i];
        }

        average = round(sum / n * 0.1) / 0.1; // 10�� ���� �ݿø�
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

        // �Ҽ��� ���ϰ� �׻� .00�̹Ƿ� ������ ��ȯ�Ͽ� ���
        printf("%.0lf won\n", ans1 < ans2 ? ans1 : ans2);
    }

    return 0;
}