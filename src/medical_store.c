#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// medical store program 

void addMed(){
    FILE *f = fopen("medicines.txt","a");
    if(f==NULL){
        printf("cant open file bro\n");
        return;
    }

    char mname[80], exd[30];
    int qt;
    float prc;

    printf("Enter Med Name : ");
    scanf(" %[^\n]", mname);

    printf("qty : ");
    scanf("%d",&qt);

    printf("exp date (dd/mm/yyy) : ");
    scanf(" %[^\n]", exd);

    printf("prize : ");
    scanf("%f",&prc);

    // storing
    fprintf(f,"%s  | q:%d | exp:%s | Rs:%.2f\n", mname, qt, exd, prc);

    fclose(f);
    printf("saved!!\n");
}

void viewMeds(){
    FILE *fp = fopen("medicines.txt","r");
    if(fp==NULL){
        printf("no recors found..\n");
        return;
    }

    char ln[250];
    printf("\n--- MED LIST ---\n");
    while(fgets(ln, sizeof(ln), fp)){
        printf("%s", ln);
    }

    fclose(fp);
}

void srchMed(){
    FILE *fff = fopen("medicines.txt","r");
    if(fff==NULL){
        printf("no data file bro...\n");
        return;
    }

    char key[60], buff[300];
    int fnd = 0;

    printf("search name : ");
    scanf(" %[^\n]", key);

    while(fgets(buff, sizeof(buff), fff)){
        if(strstr(buff, key)){
            printf(">>> %s", buff);
            fnd = 1;
        }
    }

    if(fnd==0){
        printf("no med by this name\n");
    }

    fclose(fff);
}

int main(){
    int ch;

    while(1){
        printf("\n=== medical menu ===\n");
        printf("1 add\n");
        printf("2 view\n");
        printf("3 search\n");
        printf("4 exit\n");
        printf("opt : ");
        scanf("%d",&ch);

        if(ch==1){
            addMed();
        } else if(ch==2){
            viewMeds();
        } else if(ch==3){
            srchMed();
        } else if(ch==4){
            printf("bye!!\n");
            break;
        } else {
            printf("wrong option yrr\n");
        }
    }

    return 0;
}