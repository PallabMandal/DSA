#include<stdio.h>
#include<string.h>

struct unique {
    char str[100];
    int freq;
    char c;
};

int main() {

    int n;
    printf("Input the value of n: ");
    scanf("%d", &n);
    printf("\n");

    char str[100] = "10000100100111110000100101000";
    int strSize = strlen(str);

    char subStrs[100][100];
    int subStrsInd = 0;

    int strInd = 0;

    //a. generating substrings and storing them in 'subStrs' array
    while(strInd < strSize) {
        char arr[100];
        if(strInd+n-1 < strSize) {
            int flag = 1;
            for(int i = strInd+1; i <= strInd+n-1; i++) {
                if(str[i] != str[i-1]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                for(int i = 0; i < n; i++) {
                    arr[i] = str[i+strInd];
                }
                arr[n] = '\0';
                strInd += n;
            } else {
                for(int i = 0; i < n; i++) {
                    arr[i] = str[i+strInd];
                    if(arr[i] == '1') {
                        arr[i+1] = '\0';
                        strInd += i+1;
                        break;
                    }
                }
            }
        } else {
            int flag = 1;
            for(int i = strInd+1; i < strSize; i++) {
                if(str[i] != str[i-1]) {
                    flag = 0;
                    break;
                }
            }

            if(flag == 1) {
                for(int i = 0; i < n; i++) {
                    arr[i] = str[strInd];
                }
                arr[n] = '\0';
                strInd += n;
            } else {
                for(int i = 0; i < strSize; i++) {
                    arr[i] = str[strInd+i];
                    if(arr[i] == '1') {
                        arr[i+1] = '\0';
                        strInd += i+1;
                        break;
                    }
                }
            }
        }
        strcpy(subStrs[subStrsInd], arr);
        subStrsInd++;
    }

    int subStrsSize = subStrsInd;

    // printing generated substrings from input string
    printf("Substrings we get after partitioning the input string: \n");
    for(int i = 0; i < subStrsSize; i++) {
        printf("%s ", subStrs[i]);
    }
    printf("\n");
    printf("\n");

    // b. Generating all unique substrings and their corrospoinding character
    struct unique uniqueArr[n+2];     // array of struct unique
    int uniqueArrInd = 0;
    char c = 'A';
    for(int i = 0; i < n+2; i++) {
        char uniqueStr[n+1];
        if(i == n) {
            for(int i = 0; i < n; i++) {
                uniqueStr[i] = '0';
            }
            uniqueStr[n] = '\0';
        } else if(i == n+1) {
            for(int i = 0; i < n; i++) {
                uniqueStr[i] = '1';
            }
            uniqueStr[n] = '\0';
        } else {
            for(int j = 0; j < i; j++) {
                uniqueStr[j] = '0';
            }
            uniqueStr[i] = '1';
            uniqueStr[i+1] = '\0';
        }
        strcpy(uniqueArr[uniqueArrInd].str, uniqueStr);
        uniqueArr[uniqueArrInd].c = c;
        c++;
        uniqueArrInd++;
    }

    int uniqueArrSize = uniqueArrInd;

    // Printing all possible unique substrings with their corrosponding character value
    printf("All possible unique substrings and their replaced character value: \n");
    for(int i = 0; i < uniqueArrSize; i++) {
        printf("%c ", uniqueArr[i].c);
        printf("%s\n", uniqueArr[i].str);
    }
    printf("\n");

   // Storing frequencies
    for(int i = 0; i < uniqueArrSize; i++) {
        int freq = 0;
        for(int j = 0; j < subStrsSize; j++) {
            if(strcmp(uniqueArr[i].str, subStrs[j]) == 0) {
                freq++;
            }
            uniqueArr[i].freq = freq;
        }
    }

    for(int i = 0; i < uniqueArrSize; i++) {
        printf("Frequency of '%s': %d\n", uniqueArr[i].str, uniqueArr[i].freq);
    }
    printf("\n");

    // Computing the length of the string from unique substrings' frequencies
    int len = 0;
    for(int i = 0; i < uniqueArrSize; i++) {
        len += uniqueArr[i].freq*strlen(uniqueArr[i].str);
    }

    printf("Original length of the input string: %lu\n", strlen(str));
    printf("Length computed from frquencies of unique substrings: %d\n", len);
    printf("%lu extra characters added at the end of the input string in order to make partitions consisting of specified substrings\n", len-strlen(str));
    printf("\n");

    //c. Replacing substrings with their corrospoinding character value
    char replacdChar[subStrsSize+1];
    for(int i = 0; i < uniqueArrSize; i++) {
        for(int j = 0; j < subStrsSize; j++) {
            if(strcmp(uniqueArr[i].str, subStrs[j]) == 0) {
                replacdChar[j] = uniqueArr[i].c;
            }
        }
    }
    replacdChar[subStrsSize] = '\0';

    printf("Replacing substrings with their corrosponding character value we get: %s\n", replacdChar);
    printf("\n");

    // d.Calculating % reduction of length
    printf("Length of new string: %lu\n", strlen(replacdChar));
    float ans = ((strlen(str)-strlen(replacdChar))/(float)strlen(str)) * 100;
    printf("Reduction of length in percentage: %f", ans);
    char cc = '%';
    printf("%c",cc);
    return 0;
}
