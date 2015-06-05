#include "stdio.h"
#include "stdlib.h"

int main(void) {
    int n, k, p, i, j, t, **ary, *kary, kcount, *ptemp, color, ans=0;
    scanf("%d %d %d", &n, &k, &p);
    ary = malloc(n*sizeof(int *) + n*2*sizeof(int));
    kary = calloc(k, sizeof(int));
    for (i=0, ptemp = (int *)(ary+n); i<n; i++, ptemp += 2){
        ary[i] = ptemp;
        scanf("%d %d", &ary[i][0], &ary[i][1]);
        kary[ary[i][0]]++;
    }
    
    for (i=0; i<n-1; i++) {
        color = ary[i][0];
        kcount = kary[color];
        kary[color]--;
        for (j=i+1; j<n; j++) {
            if (kcount == 1) break;
            if (color == -1) break;
            if (ary[j][0] != color) continue;
            for (t=i; t<=j; t++) {
                if (ary[t][1] <= p) {
                    ans += (kcount-1);
                    color = -1;
                    break;

                }
            }
            kcount--;
        }
    }
    
    printf("%d\n", ans);
    
    free(ary);
    free(kary);
    return 0;
}
