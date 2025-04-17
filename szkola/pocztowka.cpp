#include <cstdio>

using namespace::std;

int main()
{
    long long i,n,required,all_comb,invalid_comb=0,tmp,last=-1,arr_size; //myslalem ze dluzej mi zajmie to fajnie nazwalem
    bool flag=false;
    scanf("%lld %lld", &n, &required);
    all_comb=n*(n+1)/2; //jedno pytanie do chata i tyle mi dal wystarczylo wykozystac
    for(i=0;i<n;i++)
    {
        scanf("%lld", &tmp);
        if(tmp>=required)
        {
            arr_size=i-last-1;
            invalid_comb+=arr_size*(arr_size+1)/2; //prosty wzor okazalo sie
            last=i;
            flag=true;
        }
    }
    if(last!=i){
        arr_size=i-last-1;
        invalid_comb+=arr_size*(arr_size+1)/2;
    }
    if(flag)printf("%lld\n", all_comb - invalid_comb);
    else printf("%i\n", 0);
}