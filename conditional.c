#import <stdio.h>

int main() {
    int temp;

    printf("What is the temperature? ");
    scanf("%d", &temp);

    if (temp >= 70) {
        printf("it's hot\n");
    } else if (temp >= 30) {
        printf("it's mild\n");
    } else {
        printf("it's cold\n");
    }

    return 0;
}
