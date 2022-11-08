#include <iostream>
#include <cinttypes>

using namespace std;

#define MAXBUF 10000000
#define TARGET 1000000

int collatzlength[MAXBUF];

int compute(int64_t n){
    if(n < MAXBUF && collatzlength[n])
        return collatzlength[n];

    int64_t m = ((n&1)==0?(n>>1):3*n+1);

    int len = 1 + compute(m);

    if(n < MAXBUF)
        collatzlength[n] = len;

    return len;
}

int main()
{
    int maxlen = 1;
    int startwithmaxlen = 1;
    collatzlength[0] = collatzlength[1] = 1;
    for(int i = 2; i < TARGET; i++){
        int len = compute(i);
        if(len > maxlen){
            maxlen = len;
            startwithmaxlen = i;
        }
    }

    cout << startwithmaxlen << " length: " << maxlen << endl;

}