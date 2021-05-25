using namespace std;
#ifndef UNTITLED6_MAIN_H
#define UNTITLED6_MAIN_H

char* symbol = new char[200];
char* sign = new char [100];
char* defaults = new char[200];


void Read (char *symbol, char *sign, const char *defaults) {
    short i=0, n=0, l=0, k, skobcka;

    while ((defaults[i] != '\0') && (i < 200)) {
        if ((defaults[i] == '*') || (defaults[i] == '/') || (defaults[i] == '+') || (defaults[i] == '-')){
            sign[n] = defaults[i];
            n ++;}
        else if (defaults[i] == '(') {
            sign[n] = defaults[i];
            n ++;}
        else if (defaults[i] == ')'){
            k = n;
            while (sign[k-1] != '(') {k--;}
            skobcka = k - 1;
            n --;
            k = n;
            while (skobcka != n){
                if ((sign[n] == '*') || (sign[n] == '/')) {
                    symbol[l] = sign[n];
                    l++;}
                n--;}
            n = k;
            while (skobcka != n){
                if ((sign[n] == '+') || (sign[n] == '-')) {
                    symbol[l] = sign[n];
                    l++;}
                n --;}
            n = skobcka;
            if ((sign[n-1] == '*') || (sign[n-1] == '/')) {
                n--;
                symbol[l] = sign[n];
                l++;
            }}
        else{
        symbol[l] = defaults[i];
            l++;
           if ((defaults[i-1] == '*') || (defaults[i-1] == '/')) {
                symbol[l] = defaults[i-1] ;
                l++;
                n--;}
               if ((defaults[i+1] != '*') && (defaults[i+1] != '/') && (sign[n-1] == '-')){
                   n--;
                   symbol[l] =sign[n];
                   l++;}
           }
        i ++;}

    k = 0;
    n --;
    skobcka = n;
    while (k != n+1) {
        if ((sign[n] == '*') || (sign[n] == '/')){
            symbol[l] = sign[n];
            l++;}
        n--;}
    n = skobcka;
    while (k != n+1) {
        if  ((sign[n] == '-') || (sign[n] == '+')){
            symbol[l] = sign[n];
            l++;}
        n --;}
}

short Write( const char *symbol) {
    short i = 0, n = 0;
    int *steck = new int[200];

    while ((symbol[i] != '\0') && (i < 200)) {
        if (symbol[i] == '*') {
            steck[n - 2] = steck[n - 2] * steck[n - 1];
            n--;
        } else if (symbol[i] == '/') {
            steck[n - 2] = int(steck[n - 2] / steck[n - 1]);
            n--;
        } else if (symbol[i] == '+') {
            steck[n - 2] = steck[n - 2] + steck[n - 1];
            n--;
        } else if (symbol[i] == '-') {
            steck[n - 2] = steck[n - 2] - steck[n - 1];
            n--;
        } else {
            steck[n] = (int(symbol[i] - '0'));
            n++;
        }
        i++;
    }

    return steck[0];

}
#endif //UNTITLED6_MAIN_H
