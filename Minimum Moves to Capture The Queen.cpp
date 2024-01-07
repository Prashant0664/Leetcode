class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if((a==e && a!=c ) || (b==f && b!=d) || (a==e && a==c && ((b>d && f>d) || (b<d && f<d)) || (b==f && b==d && ((a>c && e>c) || (a<c && e<c)))))
            return 1;
        int x=c,y=d;
        while(c<=8 && d<=8){
            c++;
            d++;
            if(c==a && d==b)break;
            if(c==e && d==f)return 1;
        }
        c=x,d=y;

        while(c>=0 && d>=0){
            c--;
            d--;
            if(c==a && d==b)break;
            if(c==e && d==f)return 1;
        }
        c=x,d=y;

        while(c>=0 && d<=8){
            c--;
            d++;
            if(c==a && d==b)break;
            if(c==e && d==f)return 1;
        }
        c=x,d=y;

        while(c<=8 && d>=0){
            c++;
            d--;
            if(c==a && d==b)break;
            if(c==e && d==f)return 1;
        }

        return 2;
    }
};