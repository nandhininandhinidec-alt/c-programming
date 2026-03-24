#include <stdio.h>

struct Employee {
    char name[30];
    float basic, hra, da, gross;
};

void calcPayroll(struct Employee *e) {
    e->hra = e->basic * 0.15;
    e->da  = e->basic * 0.10;
    e->gross = e->basic + e->hra + e->da;
}

int main() {
    struct Employee emp[10];
    int i,n,choice;

    printf("How many employees : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nEnter name : ");
        scanf("%s", emp[i].name);
        printf("Enter basic salary : ");
        scanf("%f",&emp[i].basic);
        calcPayroll(&emp[i]);
    }

    do{
        printf("\n1.Show All\n2.Exit\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                for(i=0;i<n;i++){
                    printf("\n%s | Basic:%.2f | HRA:%.2f | DA:%.2f | Gross:%.2f",
                        emp[i].name, emp[i].basic, emp[i].hra, emp[i].da, emp[i].gross);
                }
                break;

            case 2:
                printf("Thank you\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while(choice!=2);

    return 0;
}
